#include "EDF_Scheduler.h"
EDF_Scheduler::EDF_Scheduler() {}

EDF_Scheduler::~EDF_Scheduler() {}

Task* EDF_Scheduler::add_task(Task* task) 
{ 
	//now saves address instead of copying pointer
	m_tasks[m_array_index] = task;
	// [] it is also a operation, it means costs
	m_deadlines[m_array_index] = task->get_period(); // period == deadline at t0, since creating the tasks automatically sets tvalid to true
	m_array_index++;

	return m_tasks[m_array_index - 1];
}

Task* EDF_Scheduler::find_earliest(unsigned int lcm) 
{
	int earliest_deadline = lcm + 1;
	int tmp_period = 0;
	bool valid = false;
	int earliest_deadline_index = 0;
	Task* to_return;
	// all m_tasks are invalid
	if (!(m_tasks[0]->get_valid() || m_tasks[1]->get_valid() || m_tasks[2]->get_valid())) {
		return nullptr;
	}

	else
	{
		// for (i = 0; i < g_n_tasks; i++) {
		// 	tmp_period = m_tasks[i]->get_period();
		// 	valid = m_tasks[i]->get_valid();
		// 	if ((tmp_period < earliest_deadline) && valid) {
		// 		earliest_deadline = tmp_period;
		// 		earliest_deadline_index = i;
		// 	}
		// }
		
		// Your code is not wrong. It is another type. I wanted to show you.
		// Here is almost same performance, but if a count is big the under code is more efficient
		// search "Displacement addressing"
		// try to do this under code 'assign_Task'
		Task* p_task = (Task*)m_tasks;
		for(int i = 0; i < g_n_tasks; i++) {
			tmp_period = p_task->get_period();
			valid = p_task->get_valid();
			
			if ((tmp_period < earliest_deadline) && valid) {
		 		earliest_deadline = tmp_period;
		 		earliest_deadline_index = i;
		 	}
			p_task++;
		}
	}

	m_currently_assigned = earliest_deadline_index;
	to_return = m_tasks[earliest_deadline_index];
	return to_return;
}

Task EDF_Scheduler::assign_Task(Task* task) 
{
	if (task == nullptr) {
		std::cout << "No task available" << std::endl;
		Task to_return(0, 0);
		for (int j = 0; j < g_n_tasks; j++) {
			m_deadlines[j]--;
			if (m_deadlines[j] == 0) {
				m_deadlines[j] = m_tasks[j]->get_period();
				m_tasks[j]->set_valid();
			}
			std::cout << "\nDeadline: " << m_deadlines[j] << " tvalid: " << m_tasks[j]->get_valid();
		}
		return to_return;
	}
	else {
		for (int j = 0; j < g_n_tasks; j++) {
			m_deadlines[j]--;
			if (m_deadlines[j] == 0) {
				m_deadlines[j] = m_tasks[j]->get_period();
				m_tasks[j]->set_valid();
			}
			std::cout << "\nDeadline: " << m_deadlines[j] << " tvalid: " << m_tasks[j]->get_valid();
		}
		task->run();
	}
	return *task;
}

void EDF_Scheduler::run_edf(unsigned int lcm) 
{
	Task* to_assign;
	Task to_print;
	for (int i = 0; i < lcm; i++) {
		to_assign = find_earliest(lcm);
		to_print = assign_Task(to_assign);
		std::cout << "\n====================" << std::endl;
		std::cout << "\nAssigning" << std::endl;
		std::cout << "\n====================" << std::endl;
		std::cout << "\nIteration -> " << i << std::endl;
		to_print.print_task();
	}
}
const Task EDF_Scheduler::get_currently_assigned() 
{
	return *m_tasks[m_currently_assigned];
}