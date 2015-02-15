#ifndef CATEGORY_HPP
#define CATEGORY_HPP

#include <string>
#include "MagnasTareasDriver.hpp"

typedef struct{
	std::string name;
	DriverName driverName;
	std::string uuid;
} Category;

#endif