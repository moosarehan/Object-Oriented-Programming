#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;

int SIZE1; // I DECLARE THIS GLOBAL VARIABLE TO STORE DYNAMIC ARRAY SIZE ONCE I INPUT DYNAMIC ARRAY SIZE IN ONE MEMBER FUNCTION I WILL STORE IN THIS SO
//I KNOW ABOUT THE SIZE OF MY HEAP ARRAY FOR OTHER MEMBER FUNCT:

struct employee
{
	int age;
	string name;
	int salary;
	string dept;

	void print()
	{
		cout << "THE EMPLOY RECORD ARE :" << endl;
		cout << "NAME IS :" << endl;
		cout << name << endl;
		cout << "AGE :" << endl;
		cout << age << endl;
		cout << "SALARY :" << endl;
		cout << salary << endl;
		cout << "DEPT IS :" << endl;
		cout << dept << endl;
	}

	void update()
	{
		cout << "ENTER NEW DETAILS OF EMPLOY :" << endl;
		cout << "NAME IS :" << endl;
		getline(cin, name);
		cout << "NAME:" << name << endl;
		cout << "AGE IS :" << endl;
		cin >> age;
		cout << " AGE:" << age << endl;
		cout << "SALARY IS :" << endl;
		cin >> salary;
		cout << "SALARY:" << salary << endl;
		cout << "DEPT IS :" << endl;
		cin >> dept;
		cout << "DEPT IS:" << dept << endl;
	}
};

struct EmployeeManagementSystem
{
	employee* ptr;

	void addemploy()
	{
		cout << "ENTER SIZE OF DYNAMIC STRUCT ARRAY:" << endl;
		int size, count = 0, employes;
		cin >> size;
		SIZE1 = size;
		ptr = new employee[size];
		employee s1;
		cout << "HOW MANY EMPLOYYES DO YOU WANT TO ADD?" << endl;
		cin >> employes; //after inputting an integer
		for (int i = 0; i < size; i++)
		{
			cout << "ENTER NEW DETAILS OF EMPLOYEE " << i + 1 << ":" << endl;
			cout << "NAME IS :" << endl;
			cin.ignore();
			getline(cin, ptr[i].name);
			cout << "AGE :" << endl;
			cin >> ptr[i].age;
			cin.ignore();
			cout << "SALARY :" << endl;
			cin >> ptr[i].salary;
			cin.ignore();
			cout << "DEPT IS :" << endl;
			cin.ignore(); // Clear newline character from previous input
			getline(cin, ptr[i].dept);
			count++;
			cout << "NEW EMPLOYEE ADDED IS " << i + 1 << ":" << endl;
			cout << ptr[i].name << endl;
			cout << ptr[i].age << endl;
			cout << ptr[i].salary << endl;
			cout << ptr[i].dept << endl;
			if (count == employes)
			{
				break;
			}
			cin.ignore();
		}
		//the loop will end when the no of indexes end
		//and if user wants to add more employ then no of indexes array size it wont be able to bcz loop will terminate when the size is reached
		//so the user can only add employ less than size for example array size is 5 user can enter 5 employs not more than 5 bcz there is no space to add another
		//so loop will terminate
	}

	void updateemploy()
	{
		bool check = true;
		cout << "ENTER THR NAME OF THE EMPLOY YOU WANT TO UPDATE :" << endl;
		string name;
		cin.ignore();
		getline(cin, name);
		for (int i = 0; i < SIZE1; i++)
		{
			if (name == ptr[i].name)
			{
				cout << "UPDATE THE EMPLOY DETAIL :" << endl;
				cout << "SALARY :" << endl;
				cin >> ptr[i].salary;
				cin.ignore();
				cout << "DEPT IS :" << endl;
				cin.ignore(); // Clear newline character from previous input
				getline(cin, ptr[i].dept);
				cout << "THE NEW EMPLOY DETAIL IS :" << endl;
				cout << "EMPLOY NO" << " " << i + 1 << " " << "DETAIL ARE :" << endl;
				cout << " NAME:" << ptr[i].name << endl;
				cout << "AGE:" << ptr[i].age << endl;
				cout << "SALARY:" << ptr[i].salary << endl;
				cout << "DEPT:" << ptr[i].dept << endl;
				cin.ignore();
				check = false;
				break;
				//the loop will terminate once the employee is found
				//if the employ is not found in the whole heap array so it he/she doesnt exsist
			}
		}
		if (check == true)
		{
			cout << "EMPLOY NOT FOUND:" << endl;
		}
	}

	void DELemploy()
	{
		bool flag = true;
		cout << "ENTER THE NAME OF THE EMPLOY YOU WANT TO DELETE :" << endl;
		string name;
		cin.ignore(); //clear newline character
		getline(cin, name);
		for (int i = 0; i < SIZE1; i++)
		{
			if (name == ptr[i].name)
			{
				//deleting that employ info
				ptr[i].name = "";
				ptr[i].dept = "";
				ptr[i].age = 0;
				ptr[i].salary = 0;
				flag = false;
				//break the loop once you have terminated the details of the employ
				break;
			}
		}
		if (flag == true)
		{
			cout << "EMPLOY NOT FOUND:" << endl;
		}
	}

	void displayemploy()
	{
		cout << "THE EMPLOY DETAILS ARE :" << endl;
		for (int i = 0; i < SIZE1; i++)
		{
			if (ptr[i].age == 0 && ptr[i].salary == 0 && ptr[i].dept == "" && ptr[i].name == "")
			{
				cout << "CANT DISPLAY EMPLOY INFORMATION DELETED:" << endl;
			}
			else
			{
				cout << "EMPLOY NO" << " " << i + 1 << " " << "DETAIL ARE :" << endl;
				cout << " NAME:" << ptr[i].name << endl;
				cout << "AGE:" << ptr[i].age << endl;
				cout << "SALARY:" << ptr[i].salary << endl;
				cout << "DEPT:" << ptr[i].dept << endl;
			}
		}
		deallocate();
	}

	void deallocate()
	{
		//free memory
		delete[] ptr;
		ptr = NULL;
	}
};

int main()
{
	employee employ1;
	EmployeeManagementSystem s2;
	employ1.age = 23;
	employ1.name = "moosa";
	employ1.salary = 23000;
	employ1.dept = "comp science";
	employ1.print();

	//now change this employ detail by user input
	employ1.update();

	int choice;
	while (true)
	{
		cout << "ENTER 1 FOR ADD EMPLOY :" << endl;
		cout << "ENTER 2 FOR UPDATE EXSIST EMPLOY :" << endl;
		cout << "ENTER 3 FOR DELETE EMPLOY :" << endl;
		cout << "ENTER 4 FOR DISPLAY EMPLOY RECORDS:" << endl;
		cout << "ENTER 5 TO EXIT FROM THE PROGRAM :" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			//when calling member function we call them by the object of the struct data type
		{
			s2.addemploy();
			break;
		}
		case 2:
		{
			s2.updateemploy();
			break;
		}
		case 3:
		{
			s2.DELemploy();
			break;
		}
		case 4:
		{
			s2.displayemploy();
			break;
		}
		case 5:
		{
			exit(0);
			//used to exit from the program
		}
		default:
			cout << "INVALID OPTION:" << endl;
			break;
		}
	}
}