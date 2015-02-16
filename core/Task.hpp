#ifndef TASK_HPP
#define TASK_HPP

typedef struct{
	std::string name;
	std::string description;
	std::string uuid;
	bool completed;
} Task;

#endif