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


void Interface(vector<Student> interfaceStudent, vector<Teacher> interfaceTeacher)
{
	while (1)
	{
		int choice = 0, choicecase1 = 0, choicecase2 = 0, counter = 1, counter2 = 1, subjectchoice = 0;
		cout << "Выберите подходящий вариант:\n";
		cout << "1 - Увидеть среднюю оценку поставленную учителем\n";
		cout << "2 - Увидеть все оценки студента\n";
		cout << "3 - Увидеть итоговую оценку студента\n";
		cout << "4 - Выход\n";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Какой учитель вам нужен?\n";
			cout << "1 - Радева Ольга Степановна, Математика\n";
			cout << "2 - Назаров Владимир Григорьевич, Физика\n";
			cout << "3 - Трофимов Владислав Андреевич, История\n";
			cin >> choicecase1;
			if (choicecase1 == 1)
			{
				interfaceTeacher[0].avg_mark(); cout << endl;
				break;
			}

			if (choicecase1 == 2)
			{
				interfaceTeacher[1].avg_mark(); cout << endl;
				break;
			}
			if (choicecase1 == 3)
			{
				interfaceTeacher[2].avg_mark(); cout << endl;
				break;
			}
		case 2:
			cout << "В каком классе учится студент?\n";
			cout << "1 - 11-А\n" << "2 - 11-Б\n";
			cin >> choicecase2;
			if (choicecase2 == 1) 
			{
				int studentchoice = 0;
				for (int i = 0; i < interfaceStudent.size(); i++)
				{
					if (interfaceStudent[i].GetGrade() == "11-А") {
						cout << "Введите " << counter << " если вы желаете увидеть оценки ученика " << interfaceStudent[i].GetName() << '\n';
						counter++;
					}
				}
				cin >> studentchoice;
				int minicounter = 1;
				for (int i = 0; i < interfaceStudent.size(); i++)
				{
					if (interfaceStudent[i].GetGrade() == "11-А") {
						if (minicounter == studentchoice) {
							interfaceStudent[i].print_marks();
						}
						minicounter++;
					}
				}
			}
			else
			{
				int studentchoice = 0;
				for (int i = 0; i < interfaceStudent.size(); i++)
				{
					if (interfaceStudent[i].GetGrade() == "11-Б") {
						cout << "Введите " << counter2 << " если вы желаете увидеть оценки ученика " << interfaceStudent[i].GetName() << '\n';
						counter2++;
					}
				}
				cin >> studentchoice;
				int minicounter = 1;
				for (int i = 0; i < interfaceStudent.size(); i++)
				{
					if (interfaceStudent[i].GetGrade() == "11-Б") {
						if (minicounter == studentchoice) {
							interfaceStudent[i].print_marks();
						}
						minicounter++;
					}
				}
			}
			break;
		case 3:
			cout << "По какому предмету вас интересует итоговая оценка?\n";
			cout << "1 - Математика\n" << "2 - Физика\n" << "3 - История\n";
			cin >> subjectchoice;
			cout << "В каком классе учится студент?\n";
			cout << "1 - 11-А\n" << "2 - 11-Б\n";
			cin >> choicecase2;
			if (choicecase2 == 1)
			{
				int studentchoice = 0;
				for (int i = 0; i < interfaceStudent.size(); i++)
				{
					if (interfaceStudent[i].GetGrade() == "11-А") {
						cout << "Введите " << counter << " если вы желаете увидеть итоговую оценку ученика " << interfaceStudent[i].GetName() << '\n';
						counter++;
					}
				}
				cin >> studentchoice;
				int minicounter = 1;
				for (int i = 0; i < interfaceStudent.size(); i++)
				{
					if (interfaceStudent[i].GetGrade() == "11-А") {
						if (minicounter == studentchoice) {
							if (subjectchoice == 1) {
								interfaceStudent[i].final_mark("Математика");
							}
							else if (subjectchoice == 2) {
								interfaceStudent[i].final_mark("Физика");
							}
							else { interfaceStudent[i].final_mark("История"); }
						}
						minicounter++;
					}
				}
			}
			else
			{
				int studentchoice = 0;
				for (int i = 0; i < interfaceStudent.size(); i++)
				{
					if (interfaceStudent[i].GetGrade() == "11-Б") {
						cout << "Введите " << counter2 << " если вы желаете увидеть итоговую оценку ученика " << interfaceStudent[i].GetName() << '\n';
						counter2++;
					}
				}
				cin >> studentchoice;
				int minicounter = 1;
				for (int i = 0; i < interfaceStudent.size(); i++)
				{
					if (interfaceStudent[i].GetGrade() == "11-Б") {
						if (minicounter == studentchoice) {
							if (subjectchoice == 1) {
								interfaceStudent[i].final_mark("Математика") ; 
							}
							else if (subjectchoice == 2) {
								interfaceStudent[i].final_mark("Физика"); 
							}
							else { interfaceStudent[i].final_mark("История");  }
						}
						minicounter++;
					}
				}
			}
			break;
		case 4:
			exit(0);
		}
	}
}


int main() {
	setlocale(LC_ALL, "ru");
	// 11-A Students
	Student stVasB("Брагин Василий Петрович", 18, 180, "11-А");
	Student stPetrM("Максимов Пётр Павлович", 17, 182, "11-А");
	Student stDmiS("Соболев Дмитрий Григорьевич", 17, 176, "11-А");
	Student stVladS("Суворов Владислав Викторович", 19, 182, "11-А");
	Student stNikG("Гаврилов Никита Владимирович", 18, 178, "11-А");
	Student stMaksK("Ковалёв Максим Михайлович", 18, 177, "11-А");
	Student stIliaZ("Зайцев Илья Сергеевич", 18, 181, "11-А");
	Student stStepR("Рыбаков Степан Семенович", 17, 180, "11-А");
	Student stAnasF("Федосеева Анастасия Петровна", 18, 168, "11-А");
	Student stSofS("Сорокина София Дмитриевна", 17, 172, "11-А");
	// 11-B Students
	Student stTimS("Стрюков Тимофей Михайлович", 18, 180, "11-Б");
	Student stIvanS("Швергун Иван Сергеевич", 17, 182, "11-Б");
	Student stVladK("Климов Владислав Владимирович", 17, 176, "11-Б");
	Student stVladM("Маслоу Владислав Тимофеевич", 19, 182, "11-Б");
	Student stAndrF("Фёдоров Андрей Михайлович", 18, 178, "11-Б");
	Student stAndrO("Орехов Андрей Андреевич", 18, 177, "11-Б");
	Student stNikV("Костин Никита Владиславович", 18, 181, "11-Б");
	Student stAlexE("Ефремов Александр Григорьевич", 17, 180, "11-Б");
	Student stDarB("Быкова Дарья Семеновна", 18, 168, "11-Б");
	Student stSvetO("Орлова Светлана Степановна", 17, 172, "11-Б");
	// Teachers
	Teacher tcOlgaR("Радева Ольга Степановна", 43, 178, "Математика");
	Teacher tcVladN("Назаров Владимир Григорьевич", 45, 185, "Физика");
	Teacher tcVladT("Трофимов Владислав Андреевич", 51, 189, "История");
	// 1/10 11-A
	tcOlgaR.add_student(stVasB);
	tcOlgaR.add_new_mark(stVasB, 1, 10);
	tcOlgaR.add_new_mark(stVasB, 1, 9);
	tcOlgaR.add_new_mark(stVasB, 2, 12);
	tcOlgaR.add_new_mark(stVasB, 3, 8);
	tcOlgaR.add_new_mark(stVasB, 3, 10);
	tcOlgaR.add_new_mark(stVasB, 4, 9);

	tcVladN.add_student(stVasB);
	tcVladN.add_new_mark(stVasB, 1, 10);
	tcVladN.add_new_mark(stVasB, 1, 7);
	tcVladN.add_new_mark(stVasB, 2, 11);
	tcVladN.add_new_mark(stVasB, 3, 8);
	tcVladN.add_new_mark(stVasB, 3, 10);
	tcVladN.add_new_mark(stVasB, 4, 9);

	tcVladT.add_student(stVasB);
	tcVladT.add_new_mark(stVasB, 1, 5);
	tcVladT.add_new_mark(stVasB, 1, 9);
	tcVladT.add_new_mark(stVasB, 2, 11);
	tcVladT.add_new_mark(stVasB, 3, 8);
	tcVladT.add_new_mark(stVasB, 3, 10);
	tcVladT.add_new_mark(stVasB, 4, 9);
	// 2/10
	tcOlgaR.add_student(stPetrM);
	tcOlgaR.add_new_mark(stPetrM, 1, 10);
	tcOlgaR.add_new_mark(stPetrM, 1, 9);
	tcOlgaR.add_new_mark(stPetrM, 2, 4);
	tcOlgaR.add_new_mark(stPetrM, 3, 8);
	tcOlgaR.add_new_mark(stPetrM, 3, 10);
	tcOlgaR.add_new_mark(stPetrM, 4, 9);

	tcVladN.add_student(stPetrM);
	tcVladN.add_new_mark(stPetrM, 1, 10);
	tcVladN.add_new_mark(stPetrM, 1, 9);
	tcVladN.add_new_mark(stPetrM, 2, 11);
	tcVladN.add_new_mark(stPetrM, 3, 8);
	tcVladN.add_new_mark(stPetrM, 3, 5);
	tcVladN.add_new_mark(stPetrM, 4, 9);

	tcVladT.add_student(stPetrM);
	tcVladT.add_new_mark(stPetrM, 1, 10);
	tcVladT.add_new_mark(stPetrM, 1, 9);
	tcVladT.add_new_mark(stPetrM, 2, 7);
	tcVladT.add_new_mark(stPetrM, 3, 8);
	tcVladT.add_new_mark(stPetrM, 3, 10);
	tcVladT.add_new_mark(stPetrM, 4, 9);
	// 3/10
	tcOlgaR.add_student(stDmiS);
	tcOlgaR.add_new_mark(stDmiS, 1, 10);
	tcOlgaR.add_new_mark(stDmiS, 1, 9);
	tcOlgaR.add_new_mark(stDmiS, 2, 11);
	tcOlgaR.add_new_mark(stDmiS, 3, 8);
	tcOlgaR.add_new_mark(stDmiS, 3, 5);
	tcOlgaR.add_new_mark(stDmiS, 4, 9);

	tcVladN.add_student(stDmiS);
	tcVladN.add_new_mark(stDmiS, 1, 2);
	tcVladN.add_new_mark(stDmiS, 1, 9);
	tcVladN.add_new_mark(stDmiS, 2, 11);
	tcVladN.add_new_mark(stDmiS, 3, 8);
	tcVladN.add_new_mark(stDmiS, 3, 10);
	tcVladN.add_new_mark(stDmiS, 4, 9);

	tcVladT.add_student(stDmiS);
	tcVladT.add_new_mark(stDmiS, 1, 10);
	tcVladT.add_new_mark(stDmiS, 1, 9);
	tcVladT.add_new_mark(stDmiS, 2, 11);
	tcVladT.add_new_mark(stDmiS, 3, 4);
	tcVladT.add_new_mark(stDmiS, 3, 10);
	tcVladT.add_new_mark(stDmiS, 4, 9);
	// 4/10
	tcOlgaR.add_student(stVladS);
	tcOlgaR.add_new_mark(stVladS, 1, 11);
	tcOlgaR.add_new_mark(stVladS, 1, 9);
	tcOlgaR.add_new_mark(stVladS, 2, 11);
	tcOlgaR.add_new_mark(stVladS, 3, 8);
	tcOlgaR.add_new_mark(stVladS, 3, 10);
	tcOlgaR.add_new_mark(stVladS, 4, 9);

	tcVladN.add_student(stVladS);
	tcVladN.add_new_mark(stVladS, 1, 10);
	tcVladN.add_new_mark(stVladS, 1, 9);
	tcVladN.add_new_mark(stVladS, 2, 11);
	tcVladN.add_new_mark(stVladS, 3, 12);
	tcVladN.add_new_mark(stVladS, 3, 10);
	tcVladN.add_new_mark(stVladS, 4, 9);

	tcVladT.add_student(stVladS);
	tcVladT.add_new_mark(stVladS, 1, 10);
	tcVladT.add_new_mark(stVladS, 1, 9);
	tcVladT.add_new_mark(stVladS, 2, 11);
	tcVladT.add_new_mark(stVladS, 3, 8);
	tcVladT.add_new_mark(stVladS, 3, 10);
	tcVladT.add_new_mark(stVladS, 4, 9);
	// 5/10
	tcOlgaR.add_student(stNikG);
	tcOlgaR.add_new_mark(stNikG, 1, 11);
	tcOlgaR.add_new_mark(stNikG, 1, 9);
	tcOlgaR.add_new_mark(stNikG, 2, 11);
	tcOlgaR.add_new_mark(stNikG, 3, 8);
	tcOlgaR.add_new_mark(stNikG, 3, 10);
	tcOlgaR.add_new_mark(stNikG, 4, 7);

	tcVladN.add_student(stNikG);
	tcVladN.add_new_mark(stNikG, 1, 10);
	tcVladN.add_new_mark(stNikG, 1, 12);
	tcVladN.add_new_mark(stNikG, 2, 11);
	tcVladN.add_new_mark(stNikG, 3, 8);
	tcVladN.add_new_mark(stNikG, 3, 10);
	tcVladN.add_new_mark(stNikG, 4, 9);

	tcVladT.add_student(stNikG);
	tcVladT.add_new_mark(stNikG, 1, 10);
	tcVladT.add_new_mark(stNikG, 1, 9);
	tcVladT.add_new_mark(stNikG, 2, 11);
	tcVladT.add_new_mark(stNikG, 3, 8);
	tcVladT.add_new_mark(stNikG, 3, 10);
	tcVladT.add_new_mark(stNikG, 4, 6);
	// 6/10 
	tcOlgaR.add_student(stMaksK);
	tcOlgaR.add_new_mark(stMaksK, 1, 10);
	tcOlgaR.add_new_mark(stMaksK, 1, 9);
	tcOlgaR.add_new_mark(stMaksK, 2, 11);
	tcOlgaR.add_new_mark(stMaksK, 3, 8);
	tcOlgaR.add_new_mark(stMaksK, 3, 2);
	tcOlgaR.add_new_mark(stMaksK, 4, 9);

	tcVladN.add_student(stMaksK);
	tcVladN.add_new_mark(stMaksK, 1, 10);
	tcVladN.add_new_mark(stMaksK, 1, 9);
	tcVladN.add_new_mark(stMaksK, 2, 11);
	tcVladN.add_new_mark(stMaksK, 3, 3);
	tcVladN.add_new_mark(stMaksK, 3, 10);
	tcVladN.add_new_mark(stMaksK, 4, 9);

	tcVladT.add_student(stMaksK);
	tcVladT.add_new_mark(stMaksK, 1, 10);
	tcVladT.add_new_mark(stMaksK, 1, 9);
	tcVladT.add_new_mark(stMaksK, 2, 4);
	tcVladT.add_new_mark(stMaksK, 3, 8);
	tcVladT.add_new_mark(stMaksK, 3, 10);
	tcVladT.add_new_mark(stMaksK, 4, 9);
	// 7/10
	tcOlgaR.add_student(stIliaZ);
	tcOlgaR.add_new_mark(stIliaZ, 1, 2);
	tcOlgaR.add_new_mark(stIliaZ, 1, 9);
	tcOlgaR.add_new_mark(stIliaZ, 2, 11);
	tcOlgaR.add_new_mark(stIliaZ, 3, 8);
	tcOlgaR.add_new_mark(stIliaZ, 3, 11);
	tcOlgaR.add_new_mark(stIliaZ, 4, 9);

	tcVladN.add_student(stIliaZ);
	tcVladN.add_new_mark(stIliaZ, 1, 10);
	tcVladN.add_new_mark(stIliaZ, 1, 9);
	tcVladN.add_new_mark(stIliaZ, 2, 12);
	tcVladN.add_new_mark(stIliaZ, 3, 8);
	tcVladN.add_new_mark(stIliaZ, 3, 10);
	tcVladN.add_new_mark(stIliaZ, 4, 3);

	tcVladT.add_student(stIliaZ);
	tcVladT.add_new_mark(stIliaZ, 1, 10);
	tcVladT.add_new_mark(stIliaZ, 1, 9);
	tcVladT.add_new_mark(stIliaZ, 2, 11);
	tcVladT.add_new_mark(stIliaZ, 3, 8);
	tcVladT.add_new_mark(stIliaZ, 3, 10);
	tcVladT.add_new_mark(stIliaZ, 4, 9);
	// 8/10 
	tcOlgaR.add_student(stStepR);
	tcOlgaR.add_new_mark(stStepR, 1, 12);
	tcOlgaR.add_new_mark(stStepR, 1, 9);
	tcOlgaR.add_new_mark(stStepR, 2, 11);
	tcOlgaR.add_new_mark(stStepR, 3, 8);
	tcOlgaR.add_new_mark(stStepR, 3, 4);
	tcOlgaR.add_new_mark(stStepR, 4, 9);

	tcVladN.add_student(stStepR);
	tcVladN.add_new_mark(stStepR, 1, 10);
	tcVladN.add_new_mark(stStepR, 1, 9);
	tcVladN.add_new_mark(stStepR, 2, 5);
	tcVladN.add_new_mark(stStepR, 3, 8);
	tcVladN.add_new_mark(stStepR, 3, 10);
	tcVladN.add_new_mark(stStepR, 4, 12);

	tcVladT.add_student(stStepR);
	tcVladT.add_new_mark(stStepR, 1, 12);
	tcVladT.add_new_mark(stStepR, 1, 9);
	tcVladT.add_new_mark(stStepR, 2, 11);
	tcVladT.add_new_mark(stStepR, 3, 8);
	tcVladT.add_new_mark(stStepR, 3, 4);
	tcVladT.add_new_mark(stStepR, 4, 9);
	// 9/10
	tcOlgaR.add_student(stAnasF);
	tcOlgaR.add_new_mark(stAnasF, 1, 10);
	tcOlgaR.add_new_mark(stAnasF, 1, 9);
	tcOlgaR.add_new_mark(stAnasF, 2, 11);
	tcOlgaR.add_new_mark(stAnasF, 3, 12);
	tcOlgaR.add_new_mark(stAnasF, 3, 10);
	tcOlgaR.add_new_mark(stAnasF, 4, 9);

	tcVladN.add_student(stAnasF);
	tcVladN.add_new_mark(stAnasF, 1, 10);
	tcVladN.add_new_mark(stAnasF, 1, 9);
	tcVladN.add_new_mark(stAnasF, 2, 11);
	tcVladN.add_new_mark(stAnasF, 3, 8);
	tcVladN.add_new_mark(stAnasF, 3, 4);
	tcVladN.add_new_mark(stAnasF, 4, 9);

	tcVladT.add_student(stAnasF);
	tcVladT.add_new_mark(stAnasF, 1, 10);
	tcVladT.add_new_mark(stAnasF, 1, 9);
	tcVladT.add_new_mark(stAnasF, 2, 11);
	tcVladT.add_new_mark(stAnasF, 3, 8);
	tcVladT.add_new_mark(stAnasF, 3, 10);
	tcVladT.add_new_mark(stAnasF, 4, 9);
	// 10/10 
	tcOlgaR.add_student(stSofS);
	tcOlgaR.add_new_mark(stSofS, 1, 10);
	tcOlgaR.add_new_mark(stSofS, 1, 9);
	tcOlgaR.add_new_mark(stSofS, 2, 11);
	tcOlgaR.add_new_mark(stSofS, 3, 8);
	tcOlgaR.add_new_mark(stSofS, 3, 10);
	tcOlgaR.add_new_mark(stSofS, 4, 9);

	tcVladN.add_student(stSofS);
	tcVladN.add_new_mark(stSofS, 1, 10);
	tcVladN.add_new_mark(stSofS, 1, 9);
	tcVladN.add_new_mark(stSofS, 2, 11);
	tcVladN.add_new_mark(stSofS, 3, 8);
	tcVladN.add_new_mark(stSofS, 3, 10);
	tcVladN.add_new_mark(stSofS, 4, 9);

	tcVladT.add_student(stSofS);
	tcVladT.add_new_mark(stSofS, 1, 10);
	tcVladT.add_new_mark(stSofS, 1, 9);
	tcVladT.add_new_mark(stSofS, 2, 11);
	tcVladT.add_new_mark(stSofS, 3, 8);
	tcVladT.add_new_mark(stSofS, 3, 10);
	tcVladT.add_new_mark(stSofS, 4, 9);
	// 1/10 11-B
	tcOlgaR.add_student(stTimS);
	tcOlgaR.add_new_mark(stTimS, 1, 10);
	tcOlgaR.add_new_mark(stTimS, 1, 9);
	tcOlgaR.add_new_mark(stTimS, 2, 4);
	tcOlgaR.add_new_mark(stTimS, 3, 8);
	tcOlgaR.add_new_mark(stTimS, 3, 10);
	tcOlgaR.add_new_mark(stTimS, 4, 9);

	tcVladN.add_student(stTimS);
	tcVladN.add_new_mark(stTimS, 1, 10);
	tcVladN.add_new_mark(stTimS, 1, 9);
	tcVladN.add_new_mark(stTimS, 2, 11);
	tcVladN.add_new_mark(stTimS, 3, 8);
	tcVladN.add_new_mark(stTimS, 3, 3);
	tcVladN.add_new_mark(stTimS, 4, 9);

	tcVladT.add_student(stTimS);
	tcVladT.add_new_mark(stTimS, 1, 10);
	tcVladT.add_new_mark(stTimS, 1, 9);
	tcVladT.add_new_mark(stTimS, 2, 11);
	tcVladT.add_new_mark(stTimS, 3, 8);
	tcVladT.add_new_mark(stTimS, 3, 2);
	tcVladT.add_new_mark(stTimS, 4, 9);
	// 2/10
	tcOlgaR.add_student(stIvanS);
	tcOlgaR.add_new_mark(stIvanS, 1, 12);
	tcOlgaR.add_new_mark(stIvanS, 1, 12);
	tcOlgaR.add_new_mark(stIvanS, 2, 11);
	tcOlgaR.add_new_mark(stIvanS, 3, 8);
	tcOlgaR.add_new_mark(stIvanS, 3, 10);
	tcOlgaR.add_new_mark(stIvanS, 4, 9);

	tcVladN.add_student(stIvanS);
	tcVladN.add_new_mark(stIvanS, 1, 10);
	tcVladN.add_new_mark(stIvanS, 1, 12);
	tcVladN.add_new_mark(stIvanS, 2, 11);
	tcVladN.add_new_mark(stIvanS, 3, 8);
	tcVladN.add_new_mark(stIvanS, 3, 10);
	tcVladN.add_new_mark(stIvanS, 4, 9);

	tcVladT.add_student(stIvanS);
	tcVladT.add_new_mark(stIvanS, 1, 10);
	tcVladT.add_new_mark(stIvanS, 1, 9);
	tcVladT.add_new_mark(stIvanS, 2, 11);
	tcVladT.add_new_mark(stIvanS, 3, 8);
	tcVladT.add_new_mark(stIvanS, 3, 10);
	tcVladT.add_new_mark(stIvanS, 4, 9);
	// 3/10
	tcOlgaR.add_student(stVladK);
	tcOlgaR.add_new_mark(stVladK, 1, 10);
	tcOlgaR.add_new_mark(stVladK, 1, 12);
	tcOlgaR.add_new_mark(stVladK, 2, 11);
	tcOlgaR.add_new_mark(stVladK, 3, 8);
	tcOlgaR.add_new_mark(stVladK, 3, 10);
	tcOlgaR.add_new_mark(stVladK, 4, 9);

	tcVladN.add_student(stVladK);
	tcVladN.add_new_mark(stVladK, 1, 10);
	tcVladN.add_new_mark(stVladK, 1, 9);
	tcVladN.add_new_mark(stVladK, 2, 4);
	tcVladN.add_new_mark(stVladK, 3, 8);
	tcVladN.add_new_mark(stVladK, 3, 10);
	tcVladN.add_new_mark(stVladK, 4, 9);

	tcVladT.add_student(stVladK);
	tcVladT.add_new_mark(stVladK, 1, 10);
	tcVladT.add_new_mark(stVladK, 1, 9);
	tcVladT.add_new_mark(stVladK, 2, 3);
	tcVladT.add_new_mark(stVladK, 3, 8);
	tcVladT.add_new_mark(stVladK, 3, 10);
	tcVladT.add_new_mark(stVladK, 4, 9);
	// 4/10
	tcOlgaR.add_student(stVladM);
	tcOlgaR.add_new_mark(stVladM, 1, 10);
	tcOlgaR.add_new_mark(stVladM, 1, 9);
	tcOlgaR.add_new_mark(stVladM, 2, 11);
	tcOlgaR.add_new_mark(stVladM, 3, 8);
	tcOlgaR.add_new_mark(stVladM, 3, 2);
	tcOlgaR.add_new_mark(stVladM, 4, 9);

	tcVladN.add_student(stVladM);
	tcVladN.add_new_mark(stVladM, 1, 10);
	tcVladN.add_new_mark(stVladM, 1, 9);
	tcVladN.add_new_mark(stVladM, 2, 11);
	tcVladN.add_new_mark(stVladM, 3, 8);
	tcVladN.add_new_mark(stVladM, 3, 11);
	tcVladN.add_new_mark(stVladM, 4, 9);

	tcVladT.add_student(stVladM);
	tcVladT.add_new_mark(stVladM, 1, 10);
	tcVladT.add_new_mark(stVladM, 1, 9);
	tcVladT.add_new_mark(stVladM, 2, 11);
	tcVladT.add_new_mark(stVladM, 3, 8);
	tcVladT.add_new_mark(stVladM, 3, 10);
	tcVladT.add_new_mark(stVladM, 4, 9);
	// 5/10
	tcOlgaR.add_student(stAndrF);
	tcOlgaR.add_new_mark(stAndrF, 1, 10);
	tcOlgaR.add_new_mark(stAndrF, 1, 9);
	tcOlgaR.add_new_mark(stAndrF, 2, 11);
	tcOlgaR.add_new_mark(stAndrF, 3, 8);
	tcOlgaR.add_new_mark(stAndrF, 3, 12);
	tcOlgaR.add_new_mark(stAndrF, 4, 9);

	tcVladN.add_student(stAndrF);
	tcVladN.add_new_mark(stAndrF, 1, 10);
	tcVladN.add_new_mark(stAndrF, 1, 9);
	tcVladN.add_new_mark(stAndrF, 2, 11);
	tcVladN.add_new_mark(stAndrF, 3, 8);
	tcVladN.add_new_mark(stAndrF, 3, 10);
	tcVladN.add_new_mark(stAndrF, 4, 9);

	tcVladT.add_student(stAndrF);
	tcVladT.add_new_mark(stAndrF, 1, 10);
	tcVladT.add_new_mark(stAndrF, 1, 9);
	tcVladT.add_new_mark(stAndrF, 2, 11);
	tcVladT.add_new_mark(stAndrF, 3, 8);
	tcVladT.add_new_mark(stAndrF, 3, 12);
	tcVladT.add_new_mark(stAndrF, 4, 9);
	// 6/10 
	tcOlgaR.add_student(stAndrO);
	tcOlgaR.add_new_mark(stAndrO, 1, 11);
	tcOlgaR.add_new_mark(stAndrO, 1, 9);
	tcOlgaR.add_new_mark(stAndrO, 2, 11);
	tcOlgaR.add_new_mark(stAndrO, 3, 11);
	tcOlgaR.add_new_mark(stAndrO, 3, 11);
	tcOlgaR.add_new_mark(stAndrO, 4, 9);

	tcVladN.add_student(stAndrO);
	tcVladN.add_new_mark(stAndrO, 1, 10);
	tcVladN.add_new_mark(stAndrO, 1, 9);
	tcVladN.add_new_mark(stAndrO, 2, 11);
	tcVladN.add_new_mark(stAndrO, 3, 8);
	tcVladN.add_new_mark(stAndrO, 3, 10);
	tcVladN.add_new_mark(stAndrO, 4, 9);

	tcVladT.add_student(stAndrO);
	tcVladT.add_new_mark(stAndrO, 1, 10);
	tcVladT.add_new_mark(stAndrO, 1, 9);
	tcVladT.add_new_mark(stAndrO, 2, 11);
	tcVladT.add_new_mark(stAndrO, 3, 8);
	tcVladT.add_new_mark(stAndrO, 3, 10);
	tcVladT.add_new_mark(stAndrO, 4, 9);
	// 7/10
	tcOlgaR.add_student(stNikV);
	tcOlgaR.add_new_mark(stNikV, 1, 10);
	tcOlgaR.add_new_mark(stNikV, 1, 9);
	tcOlgaR.add_new_mark(stNikV, 2, 11);
	tcOlgaR.add_new_mark(stNikV, 3, 8);
	tcOlgaR.add_new_mark(stNikV, 3, 10);
	tcOlgaR.add_new_mark(stNikV, 4, 9);

	tcVladN.add_student(stNikV);
	tcVladN.add_new_mark(stNikV, 1, 10);
	tcVladN.add_new_mark(stNikV, 1, 9);
	tcVladN.add_new_mark(stNikV, 2, 11);
	tcVladN.add_new_mark(stNikV, 3, 8);
	tcVladN.add_new_mark(stNikV, 3, 10);
	tcVladN.add_new_mark(stNikV, 4, 9);

	tcVladT.add_student(stNikV);
	tcVladT.add_new_mark(stNikV, 1, 10);
	tcVladT.add_new_mark(stNikV, 1, 9);
	tcVladT.add_new_mark(stNikV, 2, 11);
	tcVladT.add_new_mark(stNikV, 3, 8);
	tcVladT.add_new_mark(stNikV, 3, 10);
	tcVladT.add_new_mark(stNikV, 4, 9);
	// 8/10 
	tcOlgaR.add_student(stAlexE);
	tcOlgaR.add_new_mark(stAlexE, 1, 10);
	tcOlgaR.add_new_mark(stAlexE, 1, 9);
	tcOlgaR.add_new_mark(stAlexE, 2, 11);
	tcOlgaR.add_new_mark(stAlexE, 3, 12);
	tcOlgaR.add_new_mark(stAlexE, 3, 10);
	tcOlgaR.add_new_mark(stAlexE, 4, 12);

	tcVladN.add_student(stAlexE);
	tcVladN.add_new_mark(stAlexE, 1, 10);
	tcVladN.add_new_mark(stAlexE, 1, 9);
	tcVladN.add_new_mark(stAlexE, 2, 11);
	tcVladN.add_new_mark(stAlexE, 3, 4);
	tcVladN.add_new_mark(stAlexE, 3, 10);
	tcVladN.add_new_mark(stAlexE, 4, 9);

	tcVladT.add_student(stAlexE);
	tcVladT.add_new_mark(stAlexE, 1, 10);
	tcVladT.add_new_mark(stAlexE, 1, 9);
	tcVladT.add_new_mark(stAlexE, 2, 11);
	tcVladT.add_new_mark(stAlexE, 3, 8);
	tcVladT.add_new_mark(stAlexE, 3, 7);
	tcVladT.add_new_mark(stAlexE, 4, 9);
	// 9/10
	tcOlgaR.add_student(stDarB);
	tcOlgaR.add_new_mark(stDarB, 1, 10);
	tcOlgaR.add_new_mark(stDarB, 1, 9);
	tcOlgaR.add_new_mark(stDarB, 2, 2);
	tcOlgaR.add_new_mark(stDarB, 3, 8);
	tcOlgaR.add_new_mark(stDarB, 3, 10);
	tcOlgaR.add_new_mark(stDarB, 4, 9);

	tcVladN.add_student(stDarB);
	tcVladN.add_new_mark(stDarB, 1, 10);
	tcVladN.add_new_mark(stDarB, 1, 9);
	tcVladN.add_new_mark(stDarB, 2, 3);
	tcVladN.add_new_mark(stDarB, 3, 8);
	tcVladN.add_new_mark(stDarB, 3, 10);
	tcVladN.add_new_mark(stDarB, 4, 9);

	tcVladT.add_student(stDarB);
	tcVladT.add_new_mark(stDarB, 1, 10);
	tcVladT.add_new_mark(stDarB, 1, 9);
	tcVladT.add_new_mark(stDarB, 2, 4);
	tcVladT.add_new_mark(stDarB, 3, 8);
	tcVladT.add_new_mark(stDarB, 3, 10);
	tcVladT.add_new_mark(stDarB, 4, 9);
	// 10/10 
	tcOlgaR.add_student(stSvetO);
	tcOlgaR.add_new_mark(stSvetO, 1, 10);
	tcOlgaR.add_new_mark(stSvetO, 1, 9);
	tcOlgaR.add_new_mark(stSvetO, 2, 2);
	tcOlgaR.add_new_mark(stSvetO, 3, 8);
	tcOlgaR.add_new_mark(stSvetO, 3, 10);
	tcOlgaR.add_new_mark(stSvetO, 4, 9);

	tcVladN.add_student(stSvetO);
	tcVladN.add_new_mark(stSvetO, 1, 10);
	tcVladN.add_new_mark(stSvetO, 1, 11);
	tcVladN.add_new_mark(stSvetO, 2, 11);
	tcVladN.add_new_mark(stSvetO, 3, 8);
	tcVladN.add_new_mark(stSvetO, 3, 11);
	tcVladN.add_new_mark(stSvetO, 4, 11);

	tcVladT.add_student(stSvetO);
	tcVladT.add_new_mark(stSvetO, 1, 10);
	tcVladT.add_new_mark(stSvetO, 1, 9);
	tcVladT.add_new_mark(stSvetO, 2, 11);
	tcVladT.add_new_mark(stSvetO, 3, 12);
	tcVladT.add_new_mark(stSvetO, 3, 10);
	tcVladT.add_new_mark(stSvetO, 4, 9);

	// For menu / Menu
	vector<Student> forInterfaceStudent =
	{ stVasB, stPetrM, stDmiS, stVladS, stNikG, stMaksK, stIliaZ, stStepR, stAnasF, stSofS,
	stTimS, stIvanS, stVladK, stVladM, stAndrF, stAndrO, stNikV, stAlexE, stDarB, stSvetO };
	vector<Teacher> forInterfaceTeacher = { tcOlgaR, tcVladN, tcVladT };
	Interface(forInterfaceStudent, forInterfaceTeacher);

	return 0;
}