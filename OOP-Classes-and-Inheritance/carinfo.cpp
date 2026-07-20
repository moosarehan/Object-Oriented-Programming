// TASK 7
// Car class demonstrating a copy constructor.
#include<iostream>
#include<string>
using namespace std;

class Car
{
    string carName;
    string carModel;
    string plateNumber;
    string carColor;

public:
    Car(string name, string model, string plate, string color)
        : carName(name), carModel(model), plateNumber(plate), carColor(color)
    {
    }

    Car(Car& other)
    {
        cout << "using copy constructor to copy information:" << endl;
        carName = other.carName;
        carModel = other.carModel;
        plateNumber = other.plateNumber;
        carColor = other.carColor;
    }

    void displayCarInfo(const Car& car1, const Car& car2)
    {
        cout << "DISPLAYING INFO USING CAR 1 OBJECT :" << endl;
        cout << "CAR NAME :" << car1.carName << endl;
        cout << "PLATE NO :" << car1.plateNumber << endl;
        cout << "COLOR :" << car1.carColor << endl;
        cout << "MODEL:" << car1.carModel << endl;
        cout << endl;

        cout << "DISPLAYING INFORMATION USING CAR 2 OBJECT :" << endl;
        cout << "CAR NAME :" << car2.carName << endl;
        cout << "PLATE NO :" << car2.plateNumber << endl;
        cout << "COLOR :" << car2.carColor << endl;
        cout << "MODEL:" << car2.carModel << endl;
    }
};

int main()
{
    cout << "ENTER THE CAR NAME :" << endl;
    string carName;
    getline(cin, carName);

    cout << "ENTER THE CAR MODEL :" << endl;
    string carModel;
    getline(cin, carModel);

    cout << "ENTER THE CAR PLATE NO :" << endl;
    string carPlate;
    getline(cin, carPlate);

    cout << "ENTER THE CAR COLOR :" << endl;
    string carColor;
    getline(cin, carColor);

    Car car1(carName, carModel, carPlate, carColor);
    Car car2 = car1; // invokes the copy constructor
    car1.displayCarInfo(car1, car2);
}