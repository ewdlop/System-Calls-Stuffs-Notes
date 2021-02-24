#include "JobSystem.h"
#include "Job.h"
#include "Action.h"
#include "ThreadSafeQueue.h"
#include <iostream>


template <typename F, typename... Args>
Action<Args...>* MakeJob(F&& f, Args&&... args)
{
	//essentially this forward the parameters to Action's constuctor
	return new Action<Args...>(std::forward<F>(f), std::forward<Args>(args)...);
}

void test(int x) {
	std::cout << "test2" << std::endl;
}

int main()
{
	auto job = MakeJob([](int x) { std::cout << "test" << std::endl; }, 1);
	auto job2 = MakeJob(test,2);


	JobSystem jobSystem;
	jobSystem.Init();
	jobSystem.Submit(job);
	jobSystem.Submit(job);
	jobSystem.Submit(job);
	jobSystem.Submit(job);
	jobSystem.Submit(job);
	jobSystem.Submit(job);
	jobSystem.Submit(job);
	jobSystem.Submit(job);
	jobSystem.Submit(job);
	jobSystem.Wait();

	return 0;
}