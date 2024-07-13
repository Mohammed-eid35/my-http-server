#include "thread_pool.hpp"

// Constructor: Initializes the thread pool with a given number of threads.
ThreadPool::ThreadPool(size_t num_threads) : stop(false) {
    for (size_t i = 0; i < num_threads; ++i) {
        workers.emplace_back([this] {
            for (;;) {
                std::function<void()> task;
                {
                    std::unique_lock<std::mutex> lock(this->queue_mutex);
                    this->condition.wait(lock, [this] { return this->stop || !this->tasks.empty(); });
                    if (this->stop && this->tasks.empty()) {
                        return;
                    }
                    task = std::move(this->tasks.front());
                    this->tasks.pop();
                }
                task();
            }
        });
    }
}

// Destructor: Joins all the threads to ensure graceful shutdown.
ThreadPool::~ThreadPool() {
    stop.store(true);
    condition.notify_all();
    for (std::thread& worker : workers) {
        worker.join();
    }
}