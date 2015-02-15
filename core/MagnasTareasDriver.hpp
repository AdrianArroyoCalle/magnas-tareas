/* API for MagnasTareas Drivers */
#ifndef MAGNAS_TAREAS_DRIVER_HPP
#define MAGANS_TAREAS_DRIVER_HPP
#pragma once

#include "../core/Category.hpp"

typedef enum{
	LOCAL,
	GOOGLE_TASKS
} DriverName;

class MagnasTareasDriver {
public:
	MagnasTareasDriver(){};
	~MagnasTareasDriver(){};
	virtual bool IsEnabled(){return false;};
	virtual std::vector<Category> GetCategories(){std::vector<Category> cat; return cat;};
};

#endif
