/* Local driver for MagnasTareas */
#ifndef LOCAL_HPP
#define LOCAL_HPP

#include "sqlite3.h"
#include "../core/MagnasTareasDriver.hpp"
#include "Task.hpp"
#include "Category.hpp"
#include <iostream>

class LocalDriver : public MagnasTareasDriver {
public:
	LocalDriver(){
		std::cout << "Local driver. Using SQlite: " << SQLITE_VERSION << std::endl;
	};
	~LocalDriver(){};
	bool IsEnabled(){
		return true; // Always true because local storage always works
	}
	std::vector<Category> GetCategories(){
		//Hacerlo bien en SQlite 3
		Category cat1;
		cat1.name="Categoria 1";
		//cat1.driverName=LOCAL;
		cat1.uuid="local-1";

		Category cat2;
		cat2.name="Categoria 2";
		//cat2.driverName=LOCAL;
		cat2.uuid="local-2";

		Category cat3;
		cat3.name="Categoria TONTA";
		cat3.uuid="local-3";

		Category cat4;
		cat4.name="SQLite";
		cat4.uuid="local-4";

		Task task1;
		task1.name="MagnasTareas 001";
		task1.description="Cargar tareas desde las categorias";
		task1.completed=false;
		task1.uuid="local-1";
		cat4.tasks.push_back(task1);

		std::vector<Category> vector;
		vector.push_back(cat1);
		vector.push_back(cat2);
		vector.push_back(cat3);
		vector.push_back(cat4);

		return vector;
	}

};

#endif