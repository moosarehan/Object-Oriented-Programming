#include<iostream>
#include<cstring>
using namespace std;

void* reverse_array(void* arr, int size, char type)
{
	cout << "ENTER i TO REVERSE INTEGER ARRAY \n" << "ENTER c TO REVERSE CHARACTER ARRAY \n" << "ENTER b TO REVERSE BOOLEAN ARRAY :" << endl;
	switch (type)
	{
	case 'i':
	{
		//assign the first index address to an int pionter
		int* pt = ((int*)arr);
		int* ptr = ((int*)arr) + size - 1; //assign last index address to a int pionter
		// use pionter arthiemtic and pionter decrement to swap elements at diff address
		//loop will iterate until it reaches center it will swap elements before center to elements after center
		if (arr == NULL)
		{
			cout << "runtime error " << endl;
		}
		if (size == 0)
		{
			cout << "cannot reverse empty array :" << endl;
		}
		else
		{
			for (int i = 0; i < size / 2; i++)
			{
				int temp = *ptr;
				*ptr = *pt;
				*pt = temp;
				ptr--;
				pt++;
			}
			//returning this reversed array
		}
		return arr;
		break;
	}
	case 'c':
	{
		//assign the first index address to an int pionter
		char* pt = ((char*)arr);
		char* ptr = ((char*)arr) + size - 1; //assign last index address to a int pionter
		// use pionter arthiemtic and pionter decrement to swap elements at diff address
		//loop will iterate until it reaches center it will swap elements before center to elements after center
		if (arr == NULL)
		{
			cout << "runtime error " << endl;
		}
		if (size == 0)
		{
			cout << "cannot reverse empty array :" << endl;
		}
		else
		{
			for (int i = 0; i < size / 2; i++)
			{
				int temp = *ptr;
				*ptr = *pt;
				*pt = temp;
				ptr--;
				pt++;
			}
		}
		//returning this reversed array
		return arr;
		break;
	}
	case 'b':
	{
		//assign the first index address to an int pionter
		bool* pt = ((bool*)arr);
		bool* ptr = ((bool*)arr) + size - 1; //assign last index address to a int pionter
		// use pionter arthiemtic and pionter decrement to swap elements at diff address
		//loop will iterate until it reaches center it will swap elements before center to elements after center
		if (arr == NULL)
		{
			cout << "runtime error " << endl;
		}
		if (size == 0)
		{
			cout << "cannot reverse empty array :" << endl;
		}
		else
		{
			for (int i = 0; i < size / 2; i++)
			{
				int temp = *ptr;
				*ptr = *pt;
				*pt = temp;
				ptr--;
				pt++;
			}
		}
		//returning this reversed array
		return arr;
		break;
	}
	default:
		cout << "INVALID TYPE ARRAY CANNOT BE REVERSED :" << endl;
		break;
	}
}

int main()
{
	int size;
	int arr[7];
	//intilizng the boolean array
	bool marks[5] = { true, false, false, true, false };
	char type;
	void* ptr = NULL; //creating this void pionter because when i return a pionter from the function this pionter will recieve it
	//depending on the function what will it send i will create three diff pionter first void pionter will recieve
	//then i will cast void pionter to these three diff pionter to print elements depending on what it send
	int* p1 = NULL;
	char* cpiont = NULL;
	bool* Pionter = NULL;

	cout << "ENTER THE ELEMENTS OF THE INTEGER ARRAY :" << endl;
	for (int i = 0; i < 7; i++)
	{
		cin >> arr[i];
	}
	cin.ignore();

	cout << "ENTER THE SIZE OF CHAR ARRAY :" << endl;
	cin >> size;
	cin.ignore();

	//dynamically allocating a heap char array
	char* piont = new char[size];
	//clear the newline character left for input
	cout << "ENTER THE ELEMENTS OF THE CHAR ARRAY :" << endl;
	cin.getline(piont, size);

	//calculating the length of the charcter array using the strlen function
	int length = strlen(piont);

	//now send array its length and type of array to the fuction
	//using swtich case to call function with diff types of array
	cout << endl << "ENTER i FOR INTEGER ARRAY \n" << "ENTER c FOR CHARACTER ARRAY \n" << "ENTER b FOR BOOLEAN ARRAY :" << endl;
	cout << "THE TYPE OF THE ARRAY IS :" << endl;
	cin >> type;

	switch (type)
	{
	case 'i':
	{
		//succesfully returned the array but it is in void so i cast it to an integer then print the elements
		ptr = reverse_array(arr, 7, 'i');
		p1 = ((int*)ptr);
		cout << "THE ARRAY INTEGER ELEMENTS IN REVERSE IS :" << endl;
		for (int i = 0; i < 7; i++)
		{
			cout << *p1++ << " ";
		}
		break;
	}
	case 'c':
	{
		ptr = reverse_array(piont, length, 'c');
		cpiont = ((char*)ptr);
		cout << "THE ELEMENTS OF CHARACTER ARRAY IN REVERSE IS :" << endl;
		for (int i = 0; i < length; i++)
		{
			cout << *cpiont++;
		}
		//dynamically free the memory of the char array
		delete[] piont;
		piont = NULL;
		break;
	}
	case 'b':
	{
		ptr = reverse_array(marks, 5, 'b');
		Pionter = ((bool*)ptr);
		cout << "THE BOOLEAN ARRAY ELEMENTS IN REVERSE ARE :" << endl;
		for (int i = 0; i < 5; i++)
		{
			cout << *Pionter++ << " ";
		}
		break;
	}
	default:
		cout << "INVALID TYPE ";
		break;
	}
}