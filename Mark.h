#pragma once
#include <string>
#include <fstream>

enum Type_of_Mark {
	HOME = 1,
	TEST = 2,
	INDEPENDENT = 3,
	EXAM = 4,
	FINAL = 5
};

struct Mark
{
	std::string subject;
	Type_of_Mark type_of_mark;
	int mark;
	Mark(std::string subject, Type_of_Mark type_of_mark, int mark);
	friend std::ostream& operator<<(std::ostream& os, Mark& mark);
};