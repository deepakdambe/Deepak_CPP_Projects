
#include <iostream>
#include <thread>
#include <vector>
#include <deque>
#include <functional>
#include <mutex>

using namespace std;


class cThreadPool
{
    atomic_bool stop;
    int thread_count;
    vector<thread> threadList;
    //cJoiner tJoin;
    deque<std::function<void()>> taskList;
    mutex mu;
    condition_variable cond;

    void workerThread()
    {
        while (!stop)
        {
            // get the task.
            // execute the task
            // if task not found then yeild
            unique_lock<mutex> ulock(mu);
            cond.wait(ulock, [&] { return !taskList.empty() || stop; });
            if (stop && taskList.empty())
                return;
            function<void()> task = taskList.front();
            taskList.pop_front();
            ulock.unlock();
            cond.notify_all();
            if (task)
            {
                task();
            }
        }
    }

public:

    cThreadPool() = delete;

    cThreadPool(int count) : thread_count(count), stop(false)
    {
        for (size_t i = 0; i < thread_count; i++)
        {
            threadList.emplace_back(&cThreadPool::workerThread, this);
        }
    }

    ~cThreadPool()
    {
        stop = true;
        cond.notify_all();
        for (int i = 0; i < threadList.size(); ++i)
        {
            threadList[i].join();
        }
    }

    void Submit(function<void()> f)
    {
        // insert task into queue
        mu.lock();
        taskList.push_back(f);
        mu.unlock();
        cond.notify_one();
    }
};


int main()
{
    cThreadPool tpool(4);

    cout << "main started" << endl;

    for (size_t i = 0; i < 10; i++)
    {
        tpool.Submit([=] {
            //cout << "Printing " << i << " from thread " << this_thread::get_id() << endl;
            printf("Printing %u from %u \n", i, this_thread::get_id());
            this_thread::sleep_for(chrono::seconds(1));
            });
    }

    this_thread::sleep_for(chrono::seconds(4));
    cout << "main finished" << endl;
    return 0;
}

