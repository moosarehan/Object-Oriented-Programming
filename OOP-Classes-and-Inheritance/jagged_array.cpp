// TASK 2
// A dynamically allocated jagged (ragged) 2D array.
#include<iostream>
using namespace std;

class JaggedArray
{
    int rowCount;
    int colCount;
    int** data;        // double pointer for the 2D jagged array
    int* colsPerRow;    // number of columns stored for each row

public:
    JaggedArray()
    {
        rowCount = 0;
        colCount = 0;
        colsPerRow = nullptr;
        data = nullptr;
    }

    JaggedArray& readFromUser()
    {
        cout << "ENTER THE NO OF ROWS :" << endl;
        cin >> rowCount;

        data = new int*[rowCount];
        colsPerRow = new int[rowCount];

        for (int i = 0; i < rowCount; i++)
        {
            cout << "ENTER THE NUMBER OF COLS FOR ROW " << i + 1 << endl;
            cin >> colCount;
            data[i] = new int[colCount];
            colsPerRow[i] = colCount;

            cout << "ENTER ELEMENTS FOR ROW " << i + 1 << endl;
            for (int j = 0; j < colCount; j++)
                cin >> data[i][j];
        }

        return *this; // enables method chaining
    }

    void display(JaggedArray& array)
    {
        cout << "THE JAGGED ARRAY IS :" << endl;
        for (int i = 0; i < array.rowCount; i++)
        {
            cout << "Row " << i + 1 << ": ";
            for (int j = 0; j < array.colsPerRow[i]; j++)
                cout << "|" << array.data[i][j] << " | ";
            cout << endl << "............................................." << endl;
        }
    }

    ~JaggedArray()
    {
        for (int i = 0; i < rowCount; i++)
            delete[] data[i];
        delete[] data;
        data = nullptr;
        delete[] colsPerRow;
        colsPerRow = nullptr;
    }
};

int main()
{
    JaggedArray array;
    array.readFromUser().display(array); // chained call on the modified object
    system("pause");
}