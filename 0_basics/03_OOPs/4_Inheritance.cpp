#include <iostream>
using namespace std;

/*
INHERITANCE:
when properties & member functions of base class are passed on to the derived class.    

MODE OF INHERITANCE:
.                                       DERIVED CLASS
BASE CLASS                 PRIVATE             PROTECTED             PUBLIC                              
    PRIVATE           :  not inherited       not inherited        not inherited
    PROTECTED CLASS   :     private             protected           protected
    PUBLIC CLASS      :     private             protected           public



TYPES OF INHERITANCE:
1. SINGLE INHERITANCE       - parent -> child
2. MULTILEVEL INHERITANCE   - parent -> parent -> parent -> child
3. MULTIPLE INHERITANCE     - parent -> child <- parent         eg: mother father child tree 
.                             class child : public father, public mother{}
4. HIERARCHIAL INHERITANCE  - child <- parent -> child          eg: vehicle class inherited by both two and four wheelers
5. HYBRID INHERITANCE       - mix of different types of inheritance          
*/


class Person{
public:
    string name;
    int age;

    Person(){
        // cout << "parent constructor\n";         // parent constructor will be called first
    }

    Person(string name, int age){
        this -> name = name;
        this -> age = age;
    }

    ~Person(){
        // cout << "parent destructor\n";          // parent destructor will be called off last
    }
};


class Student : public Person{      // inheritance
public:
    int roll_number;

    Student(){
        // cout << "child constructor\n";
    }

    Student(string name, int age, int rollnumber) : Person(name, age){
        // cout << "child constructor\n";
        this -> roll_number = rollnumber;
    }

    void getInfo(){
        cout << "name: " << name << endl;
        cout << "age: " << age << endl;
        cout << "roll_number: " << roll_number << endl;
    }

    ~Student(){
        // cout << "child destructor\n";

    }
};

class GradStudent : public Student{
public:
    string researchArea;

    // making a constructor is necessary as once you write any constructor in a class the compiler stops generating a free default one  
    GradStudent(){ }

    GradStudent(string name, int age, int rollnumber, string researchArea): Student(name, age, rollnumber){
        this->researchArea = researchArea;
    }

    void getInfo(){
        Student::getInfo();                              // prints name, age, roll_number
        cout << "research area: " << researchArea << endl;
    }
};

int main(){
    Student s1("Mansa", 21, 7);
    s1.getInfo();


    GradStudent s2;
    s2.name = "tony stark";
    s2.researchArea = "robotics";
    s2.getInfo();
}

