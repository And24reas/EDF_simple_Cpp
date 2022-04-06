#include "EDF_Scheduler.h"
EDF_Scheduler::EDF_Scheduler() {

}

EDF_Scheduler::~EDF_Scheduler() {

}

// why the paramter Task is a pointer? You save(copy) this task instance not the address of task at the 'tasks' list.
// If you want to save the Task instance at the list, I recommend like this:
// Task EDF_Scheduler::add_task(Task &task) {
//		this->tasks[array_index] = task;

// Or you can the type of tasks as Task *. And save just the address of the task paramter
// And for what you need to return the parameter again? It seems like to be unnecessary
Task EDF_Scheduler::add_task(Task *task) {
	this->tasks[array_index] = *task;
	this->deadlines[array_index] = task->get_period(); // periode and deadlines is not same. Search more and rename
	array_index++;

	return this->tasks[array_index-1];
}

Task* EDF_Scheduler::find_earliest(unsigned int lcm) {
	int min = lcm + 1;	// min for what? I recommand rename as 'min_period'
	int temp = 0;		// You use this variable to save period. I recommand rename as 'temp_period' or 'period'
	bool valid = false;
	int temp_index = 0;	// I commend rename as 'latest_task_index'
	int i = 0;
	Task* to_return;

	// If you wanted to check that more than one is invalid, it is wrong.
	// You should write like this: 
	// if (!tasks[0].get_valid() || !tasks[1].get_valid() || !tasks[2].get_valid())
	// Your sentance means like this: 
	// if (!tasks[0].get_valid() && !tasks[1].get_valid() && !tasks[2].get_valid()))
	// It means that all tasks are invalid
	if (!(tasks[0].get_valid() || tasks[1].get_valid() || tasks[2].get_valid())) {
		return nullptr;
	}
	// You don't need 'else', because You did already 'return nullptr'
	//else 
	{
		// Use your code: n_tasks, 3 is a constance value. This is not good later to reuse this code
		// for(i = 0; i < n_tasks; i++)
		for (i = 0; i < 3; i++) {
			temp = this->tasks[i].get_period();
			valid = this->tasks[i].get_valid();
			//std::cout << temp << std::endl;
			if ((temp < min) && valid) {
				min = temp;
				temp_index = i;
			}
		}
	}
	
	currently_assigned = temp_index;
	to_return = &(this->tasks[temp_index]);
	return to_return;
}

Task EDF_Scheduler::assign_Task(Task *task) {
	//int task_length = task->get_length();
	//std::cout <<"Task length: "<< task_length<<std::endl;
	if (task == nullptr) {
		std::cout << "No task available" << std::endl;
		Task to_return(0, 0);
		for (int j = 0; j < n_tasks; j++) {
			deadlines[j]--;
			if (deadlines[j] == 0) {
				deadlines[j] = tasks[j].get_period();
				tasks[j].set_valid();
			}
			std::cout << "\nDeadline: " << deadlines[j] << " tvalid: " << tasks[j].get_valid();
		}
		return to_return;
	}
	else {
		for (int j = 0; j < n_tasks; j++) {
			deadlines[j]--;
			if (deadlines[j] == 0) {
				deadlines[j] = tasks[j].get_period();
				tasks[j].set_valid();
			}
			std::cout << "\nDeadline: " << deadlines[j] << " tvalid: " << tasks[j].get_valid();
		}
		task->running();

	}
	
	return *task;
}

 Task EDF_Scheduler::get_currently_assigned() {
	return tasks[currently_assigned];
}