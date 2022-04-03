#pragma once
#include "Task.h"
constexpr auto n_tasks = 3;

class EDF_Scheduler
{
public:
	EDF_Scheduler();
	~EDF_Scheduler();
	Task add_task(Task *task);
	Task assign_Task(Task *task_to_assign);
	Task *find_earliest(unsigned int lcm);
	Task get_currently_assigned();
private:
	Task tasks[n_tasks];
	int deadlines[n_tasks] = { 0,0,0 };
	int array_index=0;
	int currently_assigned;
	Task *current = nullptr;
};




