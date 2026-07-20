// TASK 3 - PART B
// Demonstrates const-correctness and static member function rules.
#include<iostream>
using namespace std;

class Counter
{
public:
    Counter(int startValue = 10) : value(startValue) {}

    // Read-only function: safe to increment a returned copy, not the member itself.
    int getIncrementedValue() const
    {
        return value + 1; // FIX: don't modify 'value' inside a const function
    }

    // Non-static so it can legally access the non-static 'value' member.
    int getInstanceCount()
    {
        cout << "value is :" << value << endl;
        return instanceCount;
    }

private:
    static int instanceCount;
    int value;
};

int Counter::instanceCount = 0;

int main()
{
    Counter c1(20);
    cout << "Incremented (non-mutating) value: " << c1.getIncrementedValue() << endl;
    cout << "Instance count check: " << c1.getInstanceCount() << endl;
}