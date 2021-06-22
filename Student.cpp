#include "Student.h"

Student::Student() : Human() 
{
    grade = "Unknown";
}

Student::Student(std::string full_name, int age, int height, std::string grade) : Human(full_name, age, height) 
{
    this->grade = grade;
}

int Student::count_final_mark(const std::string& subject)
{
    int final_mark = 0, a = 0;
    for (size_t i = 0; i < marks.size(); i++) 
    {
        if (marks[i].subject == subject) 
        {
            if (marks[i].type_of_mark == 4) 
            {
                a+=2;
                final_mark += marks[i].mark;
                final_mark += marks[i].mark;
            }
            else 
            {
                a++;
                final_mark += marks[i].mark;
            }
           
        }
    }
    if (!already_has_final(subject))
    {
        marks.push_back(Mark(subject, FINAL, final_mark / a));
    }
    return final_mark / a;
}

void Student::print_final_mark(const std::string& subject) 
{
    std::cout << "Final mark of " << this->full_name << " on subject " << subject << " is " << count_final_mark(subject) << ".\n\n";
}

bool Student::already_has_final(const std::string& subject)
{
    bool already_has = false;
    for (int i = 0; i < marks.size(); i++) 
    {
        if (marks[i].type_of_mark == 5 && marks[i].subject == subject) 
        {
            already_has = true;
        }
    }
    return already_has;
}

std::string Student::short_info()
{
    std::string s = full_name + "\n";
    return s;
}

void Student::print_marks() 
{
    std::cout << "All marks of " << this->full_name << ":\n";
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