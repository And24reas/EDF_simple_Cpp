#pragma once
#include <iostream>
class Task
{
public:
	Task();
	Task(unsigned int length, unsigned int period);
	~Task();
	void running();
	unsigned int get_period();
	unsigned int get_length();
	int get_bytes_sent();
	void print_task();
	bool get_valid();
	void set_valid();
private:
	unsigned int period;
	unsigned int length;
	unsigned int bytes_sent;
	bool tlast;
	bool tvalid;
	bool tready;
};


