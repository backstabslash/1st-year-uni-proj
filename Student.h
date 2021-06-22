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
	int count_final_mark(const std::string& subject);
	void print_final_mark(const std::string& subject);
	bool already_has_final(const std::string& subject);
	void print_marks();
	std::string short_info();
	std::string GetGrade();
	friend class Teacher;
};

