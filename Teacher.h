#pragma once
#include "Student.h"
#include "Human.h"
#include "Mark.h"
#include <string>
#include <vector>
#include <iostream>

class Student;

class Teacher : public Human
{
private:
	std::string subject;
	std::vector<Student*> students;
public:
	Teacher();
	Teacher(std::string full_name, int age, int height, std::string subject);
    void add_new_mark(Student& st, Type_of_Mark type_of_mark, const int mark);
	void add_student(Student& st);
	int count_avg_mark();
	void print_avg_mark();
	std::string short_info();
	std::string GetSubject();
};

