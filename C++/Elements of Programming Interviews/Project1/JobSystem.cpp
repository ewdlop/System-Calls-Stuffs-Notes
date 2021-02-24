#include "JobSystem.h"

JobSystem::JobSystem()
    : done(false), joiner(threadPool)
{
}

JobSystem::~JobSystem()
{
    done = true;
}

void JobSystem::Init()
{
    auto numThreads = std::thread::hardware_concurrency();

    try
    {
        for (int i = 0; i < numThreads; ++i)
        {
            threadPool.push_back(std::thread(&JobSystem::Run, this));
        }
    }
    catch (...)
    {
        done = true;
        throw;
    }
}

bool JobSystem::HasWork()
{
    // TODO: maybe not needed
//    Job job;
//    if (jobQueue.pop_front(job))
//    {
//        return true;
//    }
    return false;
}

void JobSystem::Run()
{
    while (!done)
    {
        IJob* job;
        if (jobQueue.TryPop(job))
        {
            job->Call();
        }
        else
        {
            std::this_thread::yield();
        }
    }
}

void JobSystem::Wait()
{
    //Wait until all tasks are complete
    while (!jobQueue.Empty()) {}
    
    //Moved to JobThreadsJoiner
    //for (int i = 0; i < threadPool.size(); ++i)
    //{
    //    if (threadPool[i].joinable)
    //        threadPool[i].join;
    //}
}
