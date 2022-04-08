#pragma once
#include <iostream>
class Task
{
public:
	Task();
	Task(unsigned int length, unsigned int period);
	virtual ~Task();
	void run();
	unsigned int get_period();
	unsigned int get_length();
	int get_bytes_sent();
	void print_task();
	bool get_valid();
	void set_valid();
private:
	unsigned int m_period;
	unsigned int m_execution_time;
	unsigned int m_bytes_sent;
	bool m_tlast;
	bool m_tvalid;
	bool m_tready;
};


