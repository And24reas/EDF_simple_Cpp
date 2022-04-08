#pragma once
#include "Task.h"
constexpr auto g_n_tasks = 3;

class EDF_Scheduler
{
public:
	EDF_Scheduler();
	virtual ~EDF_Scheduler(); // deconstruct should have allway virtual, I will explain later the reason. But remember!! Always!!
	Task* add_task(Task* task);
	Task assign_Task(Task* task_to_assign);
	Task* find_earliest(unsigned int lcm);
	const Task get_currently_assigned();
	void run_edf(unsigned int lcm);

private:
	Task* m_tasks[g_n_tasks];
	int m_deadlines[g_n_tasks] = { 0, }; // same. It is reset all variable as 0. But remember!! only '0' is possible. i.e. = { 1, }; it does not works!
	int m_array_index = 0;
	int m_currently_assigned = 0;
	Task* m_current = nullptr;
};




