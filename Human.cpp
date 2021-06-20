#include "Human.h"

Human::Human() 
{
	full_name = "Unknown";
	age = 0;
	height = 0;
}

Human::Human(std::string full_name, int age, int height)
{
	this->full_name = full_name;
	this->age = age;
	this->height = height;
}

std::string Human::GetName()
{
	return full_name;
}