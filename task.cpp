#include "Task.h"

Task::Task(unsigned int length, unsigned int period) {
	this->period = period;
	this->length = length;
	this->bytes_sent = 0;
	this->tlast = false;
	this->tready = false;
	this->tvalid = true;
}
Task::Task() {
	this->period = 0;
	this->length = 0;
	this->bytes_sent = 0;
	this->tlast = false;
	this->tready = false;
	this->tvalid = true;
}
Task::~Task() {
	//std::cout << "Deleting task" <<std::endl;
}

void Task::print_task() {
	std::cout << "Task Period: " << this->period<< "\nTask Length: " << this->length <<std::endl;
}

void Task::running() {
	if (bytes_sent < length) {
		(bytes_sent)++;
		std::cout << "\n\nBytes sent: " << bytes_sent;
		// Here 'return' or under line as 'else if'.
		// If 'if(bytes_sent < length)' is true, you don't need to execute the under if-statement 
		// return 
	} else if (bytes_sent == length) {
		bytes_sent = 0;
		tvalid = false;
		std::cout << "\nBytes sent. Resetting to bytes_sent to 0 and tvalid to false " << bytes_sent <<"\n";
	}	
}

unsigned int Task::get_length() {
	return this->length;
}

unsigned int Task::get_period() {
	return this->period;
}

int Task::get_bytes_sent() {
	return this->bytes_sent;
}

// You use sometimes 'this->' and sometimes not. I recommend that you don't use 'this->', 
// instead you can write the member variable like this to distinguish: m_tvaild
bool Task::get_valid() {
	return tvalid;
}

// set function normaly give a paramter. i.e. void Task::set_valid(bool enable)
void Task::set_valid() {
	tvalid = true;
}

// It is just my style, I like to write the scope of function like this: 
void Task::set_valid()
{
	tvalid = true;
}