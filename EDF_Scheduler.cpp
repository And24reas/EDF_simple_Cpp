#include "EDF_Scheduler.h"
EDF_Scheduler::EDF_Scheduler() {

}

EDF_Scheduler::~EDF_Scheduler() {

}

Task EDF_Scheduler::add_task(Task *task) {
	this->tasks[array_index] = *task;
	this->deadlines[array_index] = task->get_period();
	array_index++;

	return this->tasks[array_index-1];
}

Task* EDF_Scheduler::find_earliest(unsigned int lcm) {
	int min = lcm + 1;
	int temp = 0;
	bool valid = false;
	int temp_index = 0;
	int i = 0;
	Task* to_return;
	if (!(tasks[0].get_valid() || tasks[1].get_valid() || tasks[2].get_valid())) {
		return nullptr;
	}
	else {
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