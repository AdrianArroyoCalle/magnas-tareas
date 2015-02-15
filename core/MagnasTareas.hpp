#ifndef MAGNASTAREAS_HPP
#define MAGNASTAREAS_HPP

#include <vector>
#include <string>
#include "Category.hpp"
#include "../drivers/Local.hpp"

/* The public API for GUI frontends. GUI frontends should only use this API */

class MagnasTareas {
	public:
		MagnasTareas();
		~MagnasTareas();
		std::string				GetVersion();
		std::vector<Category>	GetCategories();
private:
		std::vector<MagnasTareasDriver*> drivers;
		LocalDriver* localDriver;
};

#endif
