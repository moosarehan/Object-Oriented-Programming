#include<iostream>
using namespace std;

void input(int** arr, int rows, int cols);
void transpose(int** arr, int rows, int cols);
void DELETE(int** arr, int rows, int cols);

void dynamic()
{
	int rows, cols;
	cout << "ENTER THE NUMBER OF ROWS :" << endl;
	cin >> rows;
	cout << "ENTER THE NUMBER OF COULMNS :" << endl;
	cin >> cols;

	int** arr = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		*(arr + i) = new int[cols];
	}
	input(arr, rows, cols);
}

void input(int** arr, int rows, int cols)
{
	//this function will input the dynamic array
	cout << "ENTER THE ELEMENTS OF THE DYNAMIC ARRAY :" << endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << "Enter element at position (" << i << ", " << j << "): ";
			cin >> arr[i][j];
			//the elements of the matrix are in the range [-1000,1000]
			while (arr[i][j] < -1000 || arr[i][j] > 1000)
			{
				cout << "ELEMENT OUT OF RANGE PLEASE ENTER AGIAN :" << endl;
				cin >> arr[i][j];
			}
		}
	}
	transpose(arr, rows, cols);
}

void transpose(int** arr, int rows, int cols)
{
	int temp = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = i + 1; j < cols; j++)
		{
			//starting from i+1 so swapping wont be done twice
			//this will succesfully take the transpose of the matrix
			temp = arr[i][j];
			arr[i][j] = arr[j][i];
			arr[j][i] = temp;
		}
	}
	cout << endl << "THE TRANSPOSE OF THE MATRIX IS :" << endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	DELETE(arr, rows, cols);
}

void DELETE(int** arr, int rows, int cols)
{
	//now deleting the dynamically allocated memory
	for (int i = 0; i < rows; i++)
	{
		delete arr[i];
	}
	delete[] arr;
	//pionting to the null pionter now
	arr = nullptr;
}

int main()
{
	//call function to dynamically allocate memory
	dynamic();
}