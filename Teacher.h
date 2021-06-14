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
    void add_new_mark(Student& st, int type_of_mark, int mark); 
	void add_student(Student& st);
	void avg_mark();
	std::string GetName();
};

