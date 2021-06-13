#include "Student.h"

Student::Student() : Human() 
{
    grade = "Unknown";
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
            if (marks[i].type_of_mark != 2)
            {
                final_mark += (marks[i].mark * 3) / 4; //все работы кроме контрольных оцениваются на 75%, кр на 125%
            }
            else 
            { 
                final_mark += (marks[i].mark * 5) / 4;
            }
        }
    }
    final_mark /= a;
    std::cout << "Student's " << this->full_name << " final mark is: " << final_mark << ".\n";
}

void Student::print_marks() 
{
    std::cout << "All marks that student " << this->full_name << " have: \n";
    for (size_t i = 0; i < marks.size(); i++) 
    {
        std::cout << marks[i];
    }
    std::cout << '\n';
}