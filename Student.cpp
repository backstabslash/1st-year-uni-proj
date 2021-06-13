#include "Student.h"

Student::Student() : Human() 
{
    grade = "����������";
}

Student::Student(std::string full_name, int age, int height, std::string grade) : Human(full_name, age, height) 
{
    this->grade = grade;
}

void Student::final_mark(std::string subject)
{
    int final_mark = 0, a = 0;
    for (size_t i = 0; i < marks.size(); i++) 
    {
        if (marks[i].subject == subject) 
        {
            ++a;
            final_mark += marks[i].mark;
        }
    }
    std::cout << "�������� ������ �������� " << this->full_name << " �� �������� " << subject << " ����� " << final_mark/a << ".\n";
}

void Student::print_marks() 
{
    std::cout << "��� ������ �������� " << this->full_name << ":\n";
    for (size_t i = 0; i < marks.size(); i++) 
    {
        std::cout << marks[i];
    }
    std::cout << '\n';
}

std::string Student::GetGrade() 
{
    return grade;
}

std::string Student::GetName()
{
    return full_name;
}