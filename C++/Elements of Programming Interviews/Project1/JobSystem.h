#ifndef JOB_SYSTEM_H
#define JOB_SYSTEM_H

#include <atomic>
#include <vector>
#include <future>

#include "IJob.h"
#include "JobThreadsJoiner.h"
#include "ThreadSafeQueue.h"

class JobSystem
{
public:
    JobSystem();
    ~JobSystem();

    void Init();
    void Run();
    void Wait();
    bool HasWork();

    /*std::future<typename std::invoke_result<IJob()>::type>
        Submit(IJob f)
    {
        typedef typename std::invoke_result<IJob()>::type result_type;
        std::packaged_task<result_type()> task(std::move(f));
        std::future<result_type> res(task.get_future());
        jobQueue.Push(std::move(task));
        return res;
    }*/

    //template <typename FunctionType>
    //std::future<typename std::invoke_result<FunctionType()>::type>
    //    Submit(FunctionType f)
    //{
    //    typedef typename std::invoke_result<FunctionType()>::type result_type;
    //    std::packaged_task<result_type()> task(std::move(f));
    //    std::future<result_type> res(task.get_future());
    //    jobQueue.Push(std::move(task));
    //    return res;
    //}

    //std::future<void> Submit(IJob f)
    //{
    //    std::packaged_task<void()> task(std::move(f));
    //    std::future<void> res(task.get_future());
    //    jobQueue.Push(std::move(task));
    //    return res;
    //}

    void Submit(IJob* f)
    {
        jobQueue.Push(std::move(f));
    }

private:
    std::atomic_bool done;
    ThreadSafeQueue<IJob*> jobQueue;
    std::vector<std::thread> threadPool;
    JobThreadsJoiner joiner;
};

#endif // JOB_SYSTEM_H