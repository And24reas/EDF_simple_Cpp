#pragma once
#include <iostream>
class Task
{
public:
	Task();
	Task(unsigned int length, unsigned int period);
	virtual ~Task();
	
	const unsigned int get_period();
	const unsigned int get_length();
	const int get_bytes_sent();
	const bool get_valid(); // the return value of get_valid should not be rewritten, because it is just a function to read a value. In this case I recommand write 'const' to show the other programmer
	
	void set_valid();
	void print_task();
	void run();

private:
	unsigned int m_period;
	unsigned int m_execution_time;
	unsigned int m_bytes_sent;
	bool m_tlast;
	bool m_tvalid;
	bool m_tready;
};


