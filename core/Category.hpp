#ifndef CATEGORY_HPP
#define CATEGORY_HPP

#include <string>
#include <vector>
#include "Task.hpp"
//#include "MagnasTareasDriver.hpp"

typedef struct{
	std::string name;
	//DriverName driverName;
	std::string uuid;
	std::vector<Task> tasks;
} Category;

#endif