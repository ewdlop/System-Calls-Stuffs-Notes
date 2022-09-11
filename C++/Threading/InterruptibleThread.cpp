#include "InterruptibleThread.h"

//void InterruptibleWait(std::condition_variable& conditonVariable, 
//	std::unique_lock<std::mutex>& lock)
//{
//	InterruptionPoint();
//	this_thread_interrupt_flag.SetConditionVariable(conditonVariable);
//	InterruptFlag::ClearConditionVariableDestruct guard;
//	InterruptionPoint();
//	conditonVariable.wait_for(lock, std::chrono::microseconds(1));
//	InterruptionPoint();
//}
//template<typename Predicate>
//void InterruptibleWait(std::condition_variable& conditonVariable, 
//	std::unique_lock<std::mutex>& lock,
//	Predicate pred)
//{
//	InterruptionPoint();
//	this_thread_interrupt_flag.SetConditionVariable(conditonVariable);
//	InterruptFlag::ClearConditionVariableDestruct guard;
//	while (!this_thread_interrupt_flag.isSet() && !pred())
//	{
//		conditonVariable.wait_for(lock, std::chrono::microseconds(1))
//	}
//	InterruptionPoint();
//}