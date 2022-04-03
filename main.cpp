#include <iostream>
#include "Task.h"
#include "EDF_Scheduler.h"

int calc_lcm(int a, int b);
int main() {
	//initialize Scheduler
	EDF_Scheduler edf;
	Task* to_assign;
	Task to_print;
	
	int arr[] = { 3,12,4 };
	int lcm = calc_lcm(calc_lcm(3,12), 4);
	int currently_assigned = 0;
	
	std::cout<<"Lowest common multiple: "<<lcm<<std::endl;
	
	//initialize Tasks
	edf.add_task(&Task(1, 3)).print_task();
	edf.add_task(&Task(2, 12)).print_task();
	edf.add_task(&Task(1, 4)).print_task();
	
	std::cout << std::endl;
	 
	for (int i = 0; i < lcm; i++) {
		to_assign = edf.find_earliest(lcm);		
		to_print=edf.assign_Task(to_assign);
		std::cout << "\n====================" << std::endl;
		std::cout << "\nAssigning" << std::endl;
		std::cout << "\n====================" << std::endl;
		to_print.print_task();
		
	}
	/*
	to_assign = edf.find_earliest(lcm);
	currently_assigned = edf.get_currently_assigned();
	edf.assign_Task(to_assign);
	*/
	std::cout << std::endl;
	
	return 0;
}

int calc_lcm(int a, int b) {
	int greater = 0;
	int lcm = 0;
	if (a > b) {
		greater = a;
	}
	else {
		greater = b;
	}
	while (true) {
		if ((greater % a == 0) && (greater % b == 0)) {
			lcm = greater;
			break;
			greater += 1;
		}
			
	}
	return lcm;
}