#ifndef  IJOB_H
#define IJOB_H

class IJob
{
public:
    virtual void Call() {};
    virtual void operator()() { Call(); };
    virtual ~IJob() {}
};
#endif // IJOB_H