#include "MagnasTareas.hpp"
#include "../drivers/Local.hpp"
#include <iostream>
//#include "curl/curl.h"

MagnasTareas::MagnasTareas()
{
	//Load Drivers
	localDriver=new LocalDriver();
	//curl_global_init(CURL_GLOBAL_ALL);
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
	std::vector<Category> vector;
	if(localDriver->IsEnabled())
	{
		std::vector<Category> catDriver=localDriver->GetCategories();
		vector.reserve(vector.size() + catDriver.size());
		vector.insert(vector.end(),catDriver.begin(),catDriver.end());
		catDriver.clear();
	}
	return vector;
}

void MagnasTareas::AddTask(std::string title, std::string description, std::string category, std::string categoryName)
{
	if(localDriver->IsEnabled())
		localDriver->AddTask(title,description,category,categoryName);
}

void MagnasTareas::RemoveTask(std::string uuid)
{
	if(localDriver->IsEnabled())
		localDriver->RemoveTask(uuid);
}
