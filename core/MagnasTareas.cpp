#include "MagnasTareas.hpp"
#include "../drivers/Local.hpp"

MagnasTareas::MagnasTareas()
{
	//Load Drivers
	localDriver=new LocalDriver();

}

MagnasTareas::~MagnasTareas()
{

}

std::string MagnasTareas::GetVersion()
{
	return "Magnas Tareas 0.1 - (C) Adrian Arroyo Calle 2015";
}

std::vector<Category> MagnasTareas::GetCategories()
{
	/*std::vector<Category> vector;
	if(localDriver->IsEnabled())
	{
		std::vector<Category> catDriver=localDriver->GetCategories();
		vector.insert(catDriver.end(),catDriver.begin(),catDriver.end());
	}
	return vector;*/
	return localDriver->GetCategories(); 
}