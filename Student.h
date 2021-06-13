#pragma once
#include "Human.h"
#include "Mark.h"
#include "Teacher.h"
#include <string>
#include <vector>
#include <iostream>

class Student : public Human
{
private:
	std::string grade;
	std::vector<Mark> marks;
public:
	Student();
	Student(std::string full_name, int age, int height, std::string grade);
	void final_mark(std::string subject);
	void print_marks();
	friend class Teacher;
};

