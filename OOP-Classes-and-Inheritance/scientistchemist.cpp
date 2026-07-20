// TASK 8
// Demonstrates member function name hiding in inheritance,
// resolved with the scope resolution operator.
#include<iostream>
#include<string>
using namespace std;

class Scientist
{
    int id;
    string name;
    string dateOfBirth;
    string researchDomain;
    string graduatedFrom;

public:
    void input()
    {
        cout << "ENTER THE ID :" << endl;
        cin >> id;
        cout << "ENTER THE NAME :" << endl;
        cin.ignore();
        getline(cin, name);
        cout << "ENTER THE DOB :" << endl;
        getline(cin, dateOfBirth);
        cout << "ENTER THE PICKED DOMAIN :" << endl;
        getline(cin, researchDomain);
        cout << "ENTER THE GRADUATED FORM :" << endl;
        getline(cin, graduatedFrom);
    }

    void display()
    {
        cout << "THE NAME IS :" << name << endl;
        cout << "THE ID :" << id << endl;
        cout << "THE DOB IS :" << dateOfBirth << endl;
        cout << "THE DOMAIN IS :" << researchDomain << endl;
        cout << "THE GRADUATED FORM IS :" << graduatedFrom << endl;
    }
};

// Chemist publicly inherits Scientist. Because Chemist declares its own
// input()/display() with different signatures, those names HIDE the base
// class versions (this is name hiding, not "ambiguity" as originally
// commented) — the scope resolution operator is used to reach the
// hidden base-class methods explicitly.
class Chemist : public Scientist
{
    string favoriteChemical;
    string chemistRank;

public:
    void input(Chemist& self)
    {
        self.Scientist::input(); // explicitly call the hidden base method
        cout << "ENTER THE FAVOURTIE CHEMICAL :" << endl;
        getline(cin, favoriteChemical);
        cout << "ENTER THE CHEM RANK :" << endl;
        getline(cin, chemistRank);
    }

    void display(Chemist& self)
    {
        self.Scientist::display();
        cout << "THE FAVOURTIE CHEMICAL IS :" << favoriteChemical << endl;
        cout << " THE CHEM RANK IS :" << chemistRank << endl;
    }
};

int main()
{
    Chemist musa;
    musa.input(musa);
    musa.display(musa);
}