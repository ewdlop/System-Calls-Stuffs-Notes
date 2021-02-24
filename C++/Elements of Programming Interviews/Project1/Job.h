#ifndef JOB_H
#define JOB_H

#include <functional>
#include <tuple>
#include <utility>
#include <memory>
#include "IJob.h"

template <typename F>
class Job : public IJob
{
    //struct ImplBase
    //{
    //    virtual void Call() = 0;
    //    virtual ~ImplBase() {}
    //};

    //struct ImplType : ImplBase
    //{
    //    
    //    ImplType(F&& f) : fn(std::move(f)) {}
    //    void Call() { fn(); }
    //};

    std::unique_ptr<F> func;

public:

    Job(F&& f)
    {
        func = std::move(f);
    }

    Job() = default;

    //Job(Job&& other)
    //    : impl(std::move(other.impl))
    //{
    //}

    //Job& operator=(Job&& other)
    //{
    //    impl = std::move(other.impl);
    //    return *this;
    //}

    //Job(const Job&) = delete;
    //Job(Job&) = delete;
    //Job& operator=(const Job&) = delete;

    void Call() override{ func(); }

    void operator()() override { Call(); }
};

#endif // JOB_H
