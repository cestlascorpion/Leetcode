//
// Created by cestl on 2018/5/9 0009.
//
#pragma once
#ifndef LEETCODE_THREADPOOL_H
#define LEETCODE_THREADPOOL_H

#include "config.h"

template<typename T>
class SyncQueue {
public:
    SyncQueue(int MaxSize) : m_maxSize(MaxSize), m_needStop(false) {}

    void Put(const T &x) { Add(x); }

    void Put(T &&x) { Add(x); }

    void Take(std::list<T> &list) {
        std::unique_lock<std::mutex> locker(m_mutex);
        m_notEmpty.wait(locker, [this] { return m_needStop || NotEmpty(); });
        if (m_needStop)
            return;
        list = std::move(m_queue);
        m_notFull.notify_one();
    }

    void Take(T &t) {
        std::unique_lock<std::mutex> locker(m_mutex);
        m_notEmpty.wait(locker, [this] { return m_needStop || NotEmpty(); });
        if (m_needStop)
            return;
        t = m_queue.front();
        m_queue.pop_front();
        m_notFull.notify_one();
    }

    void Stop() {
        {
            std::lock_guard<std::mutex> locker(m_mutex);
            m_needStop = true;
        }
        m_notFull.notify_all();
        m_notEmpty.notify_all();
    }

    bool Empty() {
        std::lock_guard<std::mutex> locker(m_mutex);
        return m_queue.empty();
    }

    bool Full() {
        std::lock_guard<std::mutex> locker(m_mutex);
        return m_queue.size() == m_maxSize;
    }

    size_t Size() {
        std::lock_guard<std::mutex> locker(m_mutex);
        return m_queue.size();
    }

    int Count() {
        return m_queue.size();
    }

private:
    bool NotFull() const {
        bool full = m_queue.size() >= m_maxSize;
        if (full)
            cout << "buffer overflow." << endl;
        return !full;
    }

    bool NotEmpty() const {
        bool empty = m_queue.empty();
        if (empty)
            cout << "buffer underflow." << endl;
        return !empty;
    }

    template<typename F>
    void Add(F&&x) {
        std::unique_lock<std::mutex> locker(m_mutex);
        m_notFull.wait(locker, [this] {return m_needStop || NotFull(); });
        if (m_needStop)
            return;
        m_queue.push_back(std::forward<F>(x));
        m_notEmpty.notify_one();
    }
private:
    std::list<T> m_queue;
    std::mutex m_mutex;
    std::condition_variable m_notEmpty;
    std::condition_variable m_notFull;
    int m_maxSize;
    bool m_needStop;

};

const int MaxTaskCount = 100;
class ThreadPool {
public:
    using Task = std::function<void()>;
    ThreadPool(int numThreads = std::thread::hardware_concurrency()) :m_queue(MaxTaskCount) {
        Start(numThreads);
    }
    ~ThreadPool(void) {
        Stop();
    }
    void Stop() {
        std::call_once(m_flag, [this] {StopThreadGroup(); });
    }
    void AddTask(Task&&task) {
        m_queue.Put(std::forward<Task>(task));
    }
    void AddTask(const Task& task) {
        m_queue.Put(task);
    }
private:
    void Start(int numThreads) {
        m_running = true;
        for (int i = 0; i < numThreads; ++i) {
            m_threadgroup.push_back(std::make_shared<std::thread>(&ThreadPool::RunInThread, this));
        }
    }
    void RunInThread() {
        std::list<Task> list;
        m_queue.Take(list);
        for (auto& task : list) {
            if (!m_running)
                return;
            task();
        }
    }
    void StopThreadGroup() {
        m_queue.Stop();
        m_running = false;
        for (auto thread : m_threadgroup) {
            if (thread)
                thread->join();
        }
        m_threadgroup.clear();
    }
private:
    std::list<std::shared_ptr<std::thread>> m_threadgroup;
    SyncQueue<Task> m_queue;
    atomic_bool m_running;
    std::once_flag m_flag;
};

#endif //LEETCODE_THREADPOOL_H
