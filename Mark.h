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
		os << "Предмет: " << mark.subject <<
			"  Вид работы: ";
		if (mark.type_of_mark == 1) { os << "Домашняя       "; }
		else if (mark.type_of_mark == 2) { os << "Контрольная    "; }
		else if (mark.type_of_mark == 3) { os << "Самостоятельная"; }
		else { os <<"Экзамен        "; }
		os << "  Оценка " << mark.mark << ";\n";
		return os;
	}
};