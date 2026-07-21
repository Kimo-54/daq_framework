#pragma once

#include <queue>
#include <memory>
#include <mutex>
#include <condition_variable>

template <typename T>
class ThreadSafeQueue {
public:
    void push(T item) {
        {
            std::lock_guard<std::mutex> lock(mtx_);
            queue_.push(std::move(item));
        }
        cv_.notify_one();
    }

    // Blocks until an item is available, or shutdown() is called.
    // Returns std::nullopt if the queue was shut down while waiting.
    // For unique_ptr T, "empty" is naturally expressed by the pointer itself,
    // but std::optional keeps the interface uniform for all T.
    bool wait_and_pop(T& out) {
        std::unique_lock<std::mutex> lock(mtx_);
        cv_.wait(lock, [this] { return !queue_.empty() || done_; });
        if (queue_.empty()) return false;   // shutdown
        out = std::move(queue_.front());
        queue_.pop();
        return true;
    }

    bool try_pop(T& out) {
        std::lock_guard<std::mutex> lock(mtx_);
        if (queue_.empty()) return false;
        out = std::move(queue_.front());
        queue_.pop();
        return true;
    }

    bool empty() const {
        std::lock_guard<std::mutex> lock(mtx_);
        return queue_.empty();
    }

    void shutdown() {
        {
            std::lock_guard<std::mutex> lock(mtx_);
            done_ = true;
        }
        cv_.notify_all();
    }

private:
    mutable std::mutex mtx_;
    std::condition_variable cv_;
    std::queue<T> queue_;
    bool done_ = false;
};