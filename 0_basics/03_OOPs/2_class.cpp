#include <iostream>
using namespace std;

class Teacher{
private:
    double salary;

public:

    // charachteristics:
    string name;
    string dept;
    string subject;
    string role;

    // constructor:
    // 1. non parameterized constructor:
    Teacher(){          
        cout << "you've made a new object: " << name << endl;
        role = "teaching faculty";
    }

    // 2. parameterized constructor:
    Teacher(string name, string subject, string dept){
        this -> name = name;         // this -> refers to the characteristics of the class
        this -> subject = subject;
        this -> dept = dept;
        role = "teaching faculty";
    }

    // 3. copy constructor: 
    Teacher(Teacher &obj){  
        cout << "custom copy constructor called \n";
        this -> name = obj.name;
        this -> dept = obj.dept;
    }

    void get_info(){
        cout << "name:" << name << endl; 
        cout << "dept:" << dept << endl; 
        cout << "subject:" << subject << endl; 
        cout << "role:" << role << endl; 
    }

    // accessing private functions in public
    // setter function:
    void setSalary(double s){
        salary = s;
    }
    // getter function:
    double getSalary(){
        return salary;
    }
};

class Account{

private:
    double balance;         //data hiding
    string password;
public:
    string accountID;
    string username;
};

int main(){
    Teacher t1;
    t1.name = "Roopa";
    t1.dept = "Language";
    t1.subject = "Hindi";
    t1.setSalary(40000);

    cout << t1.name << endl;
    cout << t1.getSalary() << endl;

    Teacher t2("Megha", "English", "Language");
    
    t1.get_info();
    t2.get_info();

    Teacher t3(t2);     // default copy constructor invoked
    t3.get_info();
}