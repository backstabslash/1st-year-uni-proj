#include "Teacher.h"

Teacher::Teacher() : Human() 
{
	subject = "Неизвестно";
};

Teacher::Teacher(std::string full_name, int age, int height, std::string subject) : Human(full_name, age, height) 
{
	this->subject = subject;
}

void Teacher::add_new_mark(Student& st, int type_of_mark, int mark) 
{
	st.marks.push_back(Mark(this->subject, type_of_mark, mark));
}

void Teacher::add_student(Student& st) 
{
	Student* p = &st;
	students.push_back(p);
}

void Teacher::avg_mark()
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
    std::cout << "Учитель " << this->full_name << " поставил(a) в среднем оценку " << sum / quant << ".\n";
}