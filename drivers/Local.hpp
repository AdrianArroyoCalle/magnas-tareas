/* Local driver for MagnasTareas */
#ifndef LOCAL_HPP
#define LOCAL_HPP

#include "sqlite3.h"
#include "../core/MagnasTareasDriver.hpp"

class LocalDriver : public MagnasTareasDriver {
public:
	LocalDriver(){};
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

		std::vector<Category> vector;
		vector.push_back(cat1);
		vector.push_back(cat2);
		vector.push_back(cat3);

		return vector;
	}

};

#endif