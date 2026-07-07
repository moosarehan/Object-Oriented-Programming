#include<iostream>
#include<cstring>
using namespace std;

void capitalizesentence(char** sentence)
{
	//calculate length of the function
	int length = strlen(*sentence);
	char* ptr = *sentence;
	if (*sentence == nullptr) //chekcs if the string is null if its empty cant be modified
	{
		cout << "CANNOT BE MODIFIED :" << endl;
		return;
	}
	if (islower(*ptr))
	{
		*ptr = *ptr - 32;
	}
	else
	{
		//do nothing
	}
	for (int i = 0; i < length; i++, ptr++) {
		if (*ptr == ' ')
		{
			ptr++;
			if (islower(*ptr))
			{
				*ptr = *ptr - 32;
			}
			else
			{
				//do nothing
			}
		}
	}
}

char** capitalizesentences(char** sentence, int rows, int cols)
{
	cout << "ENTER MULTIPLE SENTENCES:" << endl;
	for (int i = 0; i < rows; i++)
	{
		cin.getline(sentence[i], cols);
	}
	for (int i = 0; i < rows; i++)
	{
		capitalizesentence(&sentence[i]);
	}
	return sentence;
}

int main()
{
	int size;
	cout << "ENTER THE SIZE OF ARRAY :" << endl;
	cin >> size;
	cin.ignore();
	char* ptr = new char[size];
	cout << "ENTER THE ARRAY :" << endl;
	cin.getline(ptr, size);
	capitalizesentence(&ptr);
	cout << "THE MODIFIED STRING IS :" << endl;
	cout << ptr;

	int rows1, cols;
	cout << endl;
	cout << "ENTER NO OF ROWS :" << endl;
	cin >> rows1;
	cout << "ENTER NO OF COLS:" << endl;
	cin >> cols;
	cin.ignore();

	char** piont = new char* [rows1];
	for (int i = 0; i < rows1; i++)
	{
		piont[i] = new char[cols];
	}
	piont = capitalizesentences(piont, rows1, cols);

	//now output this array
	cout << "THE MULTIPLE SENTENCES CAPITLIZATION IS:" << endl;
	for (int i = 0; i < rows1; i++)
	{
		cout << piont[i] << endl;
	}

	//freeing the memory for single 1d heap array
	delete[] ptr;
	ptr = nullptr;
	for (int i = 0; i < rows1; i++)
	{
		delete piont[i];
	}
	delete[] piont;
	piont = nullptr;
}