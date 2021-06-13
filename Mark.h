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
		os << "�������: " << mark.subject <<
			"  ��� ������: ";
		if (mark.type_of_mark == 1) { os << "��������       "; }
		else if (mark.type_of_mark == 2) { os << "�����������    "; }
		else if (mark.type_of_mark == 3) { os << "���������������"; }
		else { os <<"�������        "; }
		os << "  ������ " << mark.mark << ";\n";
		return os;
	}
};