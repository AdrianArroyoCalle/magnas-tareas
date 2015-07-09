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
		void					AddTask(std::string title, std::string description, std::string category, std::string categoryName);
		void					RemoveTask(std::string uuid);
private:
		std::vector<MagnasTareasDriver*> drivers;
		LocalDriver* localDriver;
};

#endif
