#include "Task.h"

Task::Task(unsigned int length, unsigned int period) 
{
	m_period = period;
	m_execution_time = length;
	m_bytes_sent = 0;
	m_tlast = false;
	m_tready = false;
	m_tvalid = true;
}
Task::Task() 
{
	m_period = 0;
	m_execution_time = 0;
	m_bytes_sent = 0;
	m_tlast = false;
	m_tready = false;
	m_tvalid = true;
}
Task::~Task() 
{
	//std::cout << "Deleting task" <<std::endl;
}

void Task::print_task()
{
	std::cout << "Task Period: " << m_period << "\nTask Length: " << this->m_execution_time << std::endl;
}

void Task::run() 
{
	if (m_bytes_sent < m_execution_time) {
		(m_bytes_sent)++;
		std::cout << "\n\nBytes sent: " << m_bytes_sent;
	}
	if (m_bytes_sent == m_execution_time) { //has to stay like this because _m_bytes_sent is incremented in the last if statement, so else if is not possible
		std::cout << "\n\nBytes sent " << m_bytes_sent << ". Resetting to bytes_sent to 0 and tvalid to false.\n";
		m_bytes_sent = 0;
		m_tvalid = false;
	}
}

const unsigned int Task::get_length() 
{
	return m_execution_time;
}

const unsigned int Task::get_period() 
{
	return m_period;
}

const int Task::get_bytes_sent() 
{
	return m_bytes_sent;
}

const bool Task::get_valid() 
{
	return m_tvalid;
}

void Task::set_valid()
{
	m_tvalid = true;
}