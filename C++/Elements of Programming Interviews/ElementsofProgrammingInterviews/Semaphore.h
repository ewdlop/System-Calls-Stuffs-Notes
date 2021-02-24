#pragma once
#include "Semaphore.h"
#include <mutex>
#include <condition_variable>
class Semaphore {
public:
	Semaphore(int max_available) : max_available_(max_available), taken_(0) {}

	void Acquire() {
		std::unique_lock<std::mutex> lock(mx_);
		while (taken_ == max_available_)
		{
			cond_.wait(lock);
		}
		++taken_;
	}

	void Release() {
		std::lock_guard<std::mutex> lock(mx_);
		--taken_;
		cond_.notify_all();
	}

private:
	int max_available_;
	int taken_;
	std::mutex mx_;
	std::condition_variable cond_;
};

