#include <iostream>
using namespace std;

class Student{
public:
    string name;
    double* cgpaptr;

    // constructor:
    Student(string name, double cgpa){
        this -> name = name;
        cgpaptr = new double;
        *cgpaptr = cgpa;
    }

    // partial copy constructor:
    // Student(Student &obj){
    //     this -> name = obj.name;
    //     this -> cgpaptr = obj.cgpaptr;
    // }

    // deep copy constructor:
    Student(Student &obj){
        this -> name = obj.name;
        cgpaptr = new double;
        *cgpaptr = *obj.cgpaptr;
    }

    void getInfo(){
        cout << "name: " << name << endl;
        cout << "cgpa: " << *cgpaptr << endl;
    }


    ~Student(){
        delete cgpaptr;
        cout << "destructor called" << endl;
    }
};


int main(){
    Student s1("Mansa", 7.7);
    Student s2(s1);


    cout << "s1: "; s1.getInfo();
    cout << "s2: "; s2.getInfo();

    *(s2.cgpaptr) = 8.9;        // this changes the s1 student's record too due to partial copy

    cout << "s1: "; s1.getInfo();
    cout << "s2: "; s2.getInfo();

}