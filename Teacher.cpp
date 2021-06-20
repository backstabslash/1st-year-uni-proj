#include "Teacher.h"

Teacher::Teacher() : Human() 
{
	subject = "Unknown";
};

Teacher::Teacher(std::string full_name, int age, int height, std::string subject) : Human(full_name, age, height) 
{
	this->subject = subject;
}

void Teacher::add_new_mark(Student& st, Type_of_Mark type_of_mark, const int mark) 
{
	st.marks.push_back(Mark(this->subject, type_of_mark, mark));
}

void Teacher::add_student(Student& st) 
{
	students.push_back(&st);
}

int Teacher::count_avg_mark()
{
    int quant = 0, sum = 0;
    for (size_t i = 0; i < students.size(); i++)
    {
        for (size_t j = 0; j < students[i]->marks.size(); j++)
        {
            if (students[i]->marks[j].subject == this->subject)
            {
                quant++;
                sum += students[i]->marks[j].mark;
            }
        }
    }
    return sum / quant;
}

void Teacher::print_avg_mark()
{
    std::cout << "Teacher's " << this->full_name << " average given mark is " << count_avg_mark() << ".\n";
}

std::string Teacher::short_info() 
{
    std::string s = full_name + ", " + subject + "\n"; 
    return s;
}

std::string Teacher::GetName()
{
    return full_name;
}

std::string Teacher::GetSubject()
{
    return subject;
}