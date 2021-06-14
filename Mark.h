#pragma once
#include <string>
#include <fstream>
#include <iomanip>

struct Mark
{
	std::string subject;
	int type_of_mark;
	int mark;
	Mark(std::string subject, int type_of_mark, int mark);
	friend std::ostream& operator<<(std::ostream& os, Mark& mark)
	{
		os << "Subject: " << mark.subject <<
			"  Type of work: ";
		if (mark.type_of_mark == 1) { os << "Homework   "; }
		else if (mark.type_of_mark == 2) { os << "Control    "; }
		else if (mark.type_of_mark == 3) { os << "Independent"; }
		else { os <<"Exam       "; }
		os << "  Mark " << mark.mark << ";\n";
		return os;
	}
};