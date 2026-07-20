// TASK 1
// Student & Section management system.
#include<iostream>
#include<string>
using namespace std;

class Student
{
private:
    string name;
    int cnic;
    string gender;
    float cgpa;

public:
    void setStudentInfo(string studentName, int studentCnic, string studentGender, float studentCgpa)
    {
        name = studentName;
        cnic = studentCnic;
        gender = studentGender;
        cgpa = studentCgpa;
    }

    void setCgpa(float newCgpa) // separate setter since updates only change CGPA
    {
        cgpa = newCgpa;
    }

    string getName() const { return name; }
    int getCnic() const { return cnic; }
    string getGender() const { return gender; }
    float getCgpa() const { return cgpa; }
};

class Section
{
private:
    static const int MAX_STUDENTS_PER_SECTION = 40;
    static const int MAX_SECTIONS = 100;

    Student studentArray[MAX_STUDENTS_PER_SECTION];
    string professorName;
    string sectionName;
    int studentCountPerSection[MAX_SECTIONS]; // tracks number of students per section

public:
    void editSectionAttributes(Section* sections, int numberOfSections)
    {
        for (int i = 0; i < numberOfSections; i++)
        {
            cin.ignore();
            cout << "ENTER THE PROFESSOR NAME :" << endl;
            getline(cin, sections[i].professorName);
            cout << "ENTER THE SECTION NAME :" << endl;
            getline(cin, sections[i].sectionName);
        }
    }

    void addStudents(Section* sections, int numberOfSections)
    {
        string name, gender;
        int cnic;
        float gpa;

        for (int i = 0; i < numberOfSections; i++)
        {
            cout << "HOW MANY STUDENTS DO YOU WANT TO ADD IN " << i + 1 << " SECTION?" << endl;
            int numToAdd;
            cin >> numToAdd;

            while (numToAdd > MAX_STUDENTS_PER_SECTION)
            {
                cout << "CANNOT ADD MORE THAN 40 STUDENTS ENTER AGAIN :" << endl;
                cin >> numToAdd;
            }

            int addedCount = 0;
            int slot = 0;
            static int sectionIndex = 0; // tracks which section's count we're filling

            while (true)
            {
                cin.ignore();
                cout << "ENTER THE NAME :" << endl;
                getline(cin, name);
                cout << "ENTER THE GENDER :" << endl;
                getline(cin, gender);
                cout << "ENTER THE CNIC :" << endl;
                cin >> cnic;
                cin.ignore();
                cout << "ENTER CGPA :" << endl;
                cin >> gpa;

                sections[i].studentArray[slot].setStudentInfo(name, cnic, gender, gpa);
                addedCount++;
                slot++;

                if (addedCount == numToAdd)
                {
                    studentCountPerSection[sectionIndex] = addedCount;
                    sectionIndex++;
                    break;
                }
            }
        }
    }

    void updateStudentCgpa(int numberOfSections, Section* sections)
    {
        int targetCnic;
        cout << "ENTER THE ID OF THE PERSON YOU WANT TO UPDATE ?" << endl;
        cin >> targetCnic;

        bool found = false;
        for (int i = 0; i < numberOfSections; i++)
        {
            for (int j = 0; j < studentCountPerSection[i]; j++)
            {
                if (targetCnic == sections[i].studentArray[j].getCnic())
                {
                    cout << "STUDENT FOUND :" << endl;
                    float newCgpa;
                    cout << "ENTER NEW CGPA :" << endl;
                    cin >> newCgpa;
                    sections[i].studentArray[j].setCgpa(newCgpa);
                    cout << "THE NEW CGPA OF " << sections[i].studentArray[j].getName()
                         << " IS :" << sections[i].studentArray[j].getCgpa() << endl;
                    found = true;
                }
            }
        }

        if (!found)
            cout << "STUDENT NOT FOUND !" << endl;
    }

    void printAllStudents(int numberOfSections, Section* sections)
    {
        for (int i = 0; i < numberOfSections; i++)
        {
            cout << "THE STUDENTS IN " << sections[i].sectionName << " SECTION ARE " << endl;
            for (int j = 0; j < studentCountPerSection[i]; j++)
            {
                cout << "THE NAME OF STUDENT IS :" << sections[i].studentArray[j].getName() << endl;
                cout << "THE CNIC OF STUDENT IS :" << sections[i].studentArray[j].getCnic() << endl;
                cout << "THE CGPA OF STUDENT IS :" << sections[i].studentArray[j].getCgpa() << endl;
                cout << "THE GENDER OF STUDENT IS :" << sections[i].studentArray[j].getGender() << endl;
            }
        }
    }

    void printAllSections(int numberOfSections, Section* sections)
    {
        for (int i = 0; i < numberOfSections; i++)
        {
            cout << "SECTION " << i + 1 << " DETAIL IS :" << endl;
            cout << "SECTION NAME ARE :" << sections[i].sectionName << endl;
            cout << "SECTION PROFESSOR ARE :" << sections[i].professorName << endl;
        }
    }
};

int main()
{
    int numberOfSections;
    cout << "ENTER THE NO OF SECTIONS ?" << endl;
    cin >> numberOfSections;

    Section* sections = new Section[numberOfSections];
    int choice;

    while (true)
    {
        cout << "MENU:" << endl;
        cout << "1. Edit Section Attributes" << endl;
        cout << "2. Add Student in a Section" << endl;
        cout << "3. Update Student of a Section" << endl;
        cout << "4. Print List of Students of a Section" << endl;
        cout << "5. Print List of Sections" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            sections->editSectionAttributes(sections, numberOfSections);
            break;
        case 2:
            sections->addStudents(sections, numberOfSections);
            break;
        case 3:
            sections->updateStudentCgpa(numberOfSections, sections);
            break;
        case 4:
            sections->printAllStudents(numberOfSections, sections);
            break;
        case 5:
            sections->printAllSections(numberOfSections, sections);
            break;
        case 6:
            delete[] sections;
            sections = nullptr;
            exit(0);
        default:
            cout << "INVALID CHOICE:" << endl;
            break;
        }
    }
}