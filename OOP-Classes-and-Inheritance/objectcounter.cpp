// TASK 3 - PART A
// A class that counts how many instances of itself have been created.
#include<iostream>
using namespace std;

class ObjectCounter
{
    int x;
    int y;
    int z;
    static int totalObjectsCreated;

public:
    ObjectCounter()
    {
        totalObjectsCreated++;
    }

    static void printTotalObjects()
    {
        cout << "THE TOTAL NUMBER OF OBJECTS CREATED ARE :" << totalObjectsCreated << endl;
    }
};

int ObjectCounter::totalObjectsCreated = 0;

int main()
{
    ObjectCounter* objectArrayPtr = nullptr;
    int numberOfObjects;

    cout << "HOW MANY OBJECTS DO YOU WANT TO CREATE ?" << endl;
    cin >> numberOfObjects;

    objectArrayPtr = new ObjectCounter[numberOfObjects];
    objectArrayPtr->printTotalObjects();

    delete[] objectArrayPtr;
    objectArrayPtr = nullptr;   // FIX: was "ptr-NULL;" (a no-op) in the original

    system("pause");
}