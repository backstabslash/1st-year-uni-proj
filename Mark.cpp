#include "Mark.h"

Mark::Mark(std::string subject, Type_of_Mark type_of_mark, int mark) 
{
	this->subject = subject;
	this->type_of_mark = type_of_mark;
	this->mark = mark;
}

std::ostream& operator<<(std::ostream& os, Mark& mark)
{
	os << "Subject: " << mark.subject <<
		"  Type of work: ";
	if (mark.type_of_mark == 1) { os << "Homework   "; }
	else if (mark.type_of_mark == 2) { os << "Test       "; }
	else if (mark.type_of_mark == 3) { os << "Independent"; }
	else if (mark.type_of_mark == 4){ os << "Exam       "; }
	else { os << "Final      "; }
	os << "  Mark " << mark.mark << ";\n";
	return os;
}