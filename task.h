#pragma once
#include <iostream>
class Task
{
public:
	Task();
	Task(unsigned int length, unsigned int period);
	~Task();	// deconstruct should have allway virtual, I will explain later the reason. But remember!! Always!!
	void running();	// run is more common
	unsigned int get_period();
	unsigned int get_length();
	int get_bytes_sent();
	void print_task();
	bool get_valid();
	void set_valid();
private:
	unsigned int period;
	unsigned int length;		// What is length? You mean 'Execution Time'? then I recommend rename as 'm_exc_time'
	unsigned int bytes_sent;
	bool tlast;
	bool tvalid;
	bool tready;
};


