#include<iostream>
using namespace std;

struct Date
{
public:
	int day;
	int month;
	int year;
};

struct Student
{
public:
	char name[20];
	int roll_number;
	int marks[5];
	char major[30];
	Date var;
};

void printstructvar1(Student CSStudent)
{
	cout << endl;
	cout << "THE MEMBERS OF CSStudent object are :" << endl;
	cout << "THE NAME OF THE STUDENT IS :" << CSStudent.name << endl;
	cout << "THE ROLL NO OF THE STUDENT IS :" << CSStudent.roll_number << endl;
	cout << "THE MARKS OF THE STUDENT ARE :";
	for (int i = 0; i < 5; i++)
	{
		cout << CSStudent.marks[i] << " ";
	}
	cout << endl;
	cout << "THE MAJOR OF THE STUDENT IS :" << CSStudent.major << endl;
	cout << "THE DOB OF STUDENT IS :" << CSStudent.var.day << " _" << CSStudent.var.month << " _" << CSStudent.var.year;
}

void printstructvar2(Student CSStudentcopy)
{
	cout << endl;
	cout << "THE MEMBERS OF CSStudentcopy object are :" << endl;
	cout << "THE NAME OF THE STUDENT IS :" << CSStudentcopy.name << endl;
	cout << "THE ROLL NO OF THE STUDENT IS :" << CSStudentcopy.roll_number << endl;
	cout << "THE MARKS OF THE STUDENT ARE :";
	for (int i = 0; i < 5; i++)
	{
		cout << CSStudentcopy.marks[i] << " ";
	}
	cout << endl;
	cout << "THE MAJOR OF THE STUDENT IS :" << CSStudentcopy.major << endl;
	cout << "THE DOB OF STUDENT IS :" << CSStudentcopy.var.day << " _" << CSStudentcopy.var.month << "_ " << CSStudentcopy.var.year;
}

int main()
{
	Student CSStudent, CSStudentcopy;
	Date stu;

	cout << "ENTER THE NAME OF THE STUDENT :" << endl;
	cin.getline(CSStudent.name, 20);
	cin.ignore();
	//clear the newline character left for input

	cout << "ENTER THE ROLL NO OF THE STUDENT :" << endl;
	cin >> CSStudent.roll_number;
	cout << endl;

	cout << "ENTER THE MARKS OF THE STUDENT :" << endl;
	for (int i = 0; i < 5; i++)
	{
		cin >> CSStudent.marks[i];
	}
	cin.ignore();

	cout << "ENTER THE MAJOR OF THE STUDENT :" << endl;
	cin.getline(CSStudent.major, 30);
	cin.ignore();

	cout << "ENTER THE DOB OF STUDENT :" << endl;
	cin >> CSStudent.var.day >> CSStudent.var.month >> CSStudent.var.year;
	cout << endl;

	CSStudentcopy = CSStudent;

	printstructvar1(CSStudent); //now printing the members of csstudent struct using the function
	printstructvar2(CSStudentcopy);
}