#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class student
{
private:
    string id, name, course, birth;
    double gpa;

public:
    friend istream &operator >> (istream &ins, student &a);
    friend ostream &operator << (ostream &extr, student a);
    friend void ins(student &a);
    friend void extr(student a);
    double getGpa();
    string getName();
    string getClass();
    void standardize();

};

istream &operator >> (istream &ins, student &a)
{
    a.id = "20139";
    cout << "\nStudent's name: ";
    cin.ignore();
    getline(cin, a.name);
    a.standardize();
    cout << "class: ";
    cin >> a.course;
    cout << "birth: ";
    cin >> a.birth;
    cout << "gpa: ";
    cin >> a.gpa;
    return ins;
}

ostream &operator << (ostream &extr, student a)
{
    cout << "Student's id: " << a.id << "\nStudent's name: " << a.name << "\nClass: " << a.course << "\nBirth: " << a.birth << "\nGPA: " << a.gpa << endl;
    return extr;
}

void ins(student &a)
{
    cout << "Student's name: ";
    getline(cin, a.name);

    cout << "class: ";
    cin >> a.course;

    cout << "birth: ";
    cin >> a.birth;
    if (a.birth[2] != '/' )
    {
        a.birth = "0" + a.birth;
    }
    if (a.birth[5] != '/')
    {
        a.birth.insert(3, "0");
    }


    cout << "gpa: ";
    cin >> a.gpa;

    cin.ignore();
}

void extr(student a)
{
    cout << "\nStudent's id: " << "213" << "\nStudent's name: " << a.name << "\nClass: " << a.course << "\nBirth: " << a.birth << "\nGPA: " << a.gpa << endl;
}

double student::getGpa()
{
    return this -> gpa;
}
string student::getName()
{
    return this -> name;
}

string student::getClass()
{
    return this -> course;
}

bool cmp(student a, student b)
{
    return a.getGpa() > b.getGpa();
}

void student::standardize()
{
    bool newWord = true;
    for (char &c : this->name)
    {
        if (newWord && isalpha(c))
        {
            c = toupper(c);
        }
        else{
            c = tolower(c);
        }
        newWord = (c == ' ');
    }
}

int main()
{
    int n;
    cout << "Number of students: ";
    cin >> n;
    vector <student> v(n);
    for (int i = 0 ; i < n; i ++)
    {
        cin >> v[i];
    }
    sort (v.begin(), v.end(), cmp);
    cout << "\nstudent with highest gpa: "<< v[0] << endl;

    int q;
    cout << "Number of times finding for class: ";
    cin >> q;
    while(q--)
    {
        string s;
        cout << "\nName of class: ";
        cin >> s;
        bool found = false;
        cout << "List of students in class: "<< s << endl;
        for (student x : v)
        {
            if (x.getClass() == s)
            {
                cout << x;
                found = true;
            }
        }

        if (!found)
        {
            cout << "There wasn't any student in this class\n";
        }
    }
    return 0;
}

