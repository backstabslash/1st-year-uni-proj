#include <iostream>
#include <vector>
#include <fstream>
#include "Teacher.h"
#include "Student.h"
#include "Human.h"
#include "Mark.h"
using namespace std;

enum type_of_mark {
	HOME = 1,
	TEST = 2,
	INDEPENDENT = 3,
	EXAM = 4
};

int main() {
	Student sttest("Tim", 19, 180, "11-B");
	Student sttest2("Tim2", 19, 180, "11-B");
	Teacher tctest("Nikita", 91, 181, "History");

	tctest.add_student(sttest);
	tctest.add_new_mark(sttest, 1, 11);
	tctest.add_new_mark(sttest, 2, 8);
	tctest.add_new_mark(sttest, 3, 10);
	tctest.add_new_mark(sttest, 4, 7);

	tctest.add_student(sttest2);
	tctest.add_new_mark(sttest2, 1, 11);
	tctest.add_new_mark(sttest2, 2, 11);
	tctest.add_new_mark(sttest2, 3, 7);
	tctest.add_new_mark(sttest2, 4, 8);

	sttest.print_marks();

	sttest.final_mark("History");
	sttest2.final_mark("History");
	tctest.avg_mark();

	return 0;
}