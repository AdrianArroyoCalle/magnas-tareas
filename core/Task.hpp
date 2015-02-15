#ifndef TASK_HPP
#define TASK_HPP

typedef struct{
	std::string name;
	std::string description;
	DriverName driverName;
	bool completed;
} Task;

#endif