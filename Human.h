#pragma once
#include<string>

class Human
{
protected:
	std::string full_name;
	int age;
	int height;
public:
	Human();
	Human(std::string full_name, int age, int height);
};


