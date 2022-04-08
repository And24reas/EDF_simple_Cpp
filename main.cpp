#include <iostream>
#include "Task.h"
#include "EDF_Scheduler.h"

int calc_lcm(int a, int b);
int main() 
{
	EDF_Scheduler edf;
	

	int arr[] = { 3,12,4 };
	int lcm = calc_lcm(calc_lcm(3, 12), 4);

	std::cout << "Lowest common multiple: " << lcm << std::endl;
	Task task1(1, 3);
	Task task2(2, 12);
	Task task3(1, 4);
	//initialize Tasks
	edf.add_task(task1)->print_task();
	edf.add_task(task2)->print_task();
	edf.add_task(task3)->print_task();

	std::cout << std::endl;
	std::cout << "Starting Execution..............." << std::endl;
	edf.run_edf(lcm);
	std::cout << std::endl;
	std::cout << "Finished Execution..............." << std::endl;
	return 0;
}

int calc_lcm(int a, int b) 
{
	int lcm = 0;
	bool greater_flag = a > b;
	lcm = a * greater_flag + b * !greater_flag;

	while (lcm % a || lcm % b) {
		lcm += 1;
	}
	return lcm;
}