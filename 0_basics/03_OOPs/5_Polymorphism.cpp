#include <iostream>
using namespace std;

/*
POLIMORPHISM:
ability of objects to take on different forms or behave in different ways depending on the context in which they are used.

TYPES OF POLYMORPHISM:
1. COMPILE TIME     :   output is decided on compile time only 
    eg.             -   constructor overloading
    .               -   function overloading    
    .               -   operator overloading         
2. RUNTIME          :   output is decided on runtime
    eg.             -   function overriding : parent and child both contain the same function with different implementation. the parent class function is said to be overridden
    .               -   vitual function : it's a member function that you expect to be redefined in derived classes; these are dynamic in nature; defined by the keyword "virtual" inside the base class and are always declared with a base class and overridden by child class 

*/


// compile time:
class sayHello{
public:

    // constructor overloading:
    sayHello(){
        cout << "me non parameterized constructor" << endl;
    }
    sayHello(int num){
        cout << "me parameterized constructor" << endl;
    }



    // function overloadin:
    void hello(){
        cout << "hello" << endl;
    }

    void hello(int num){
        for(int i = 0; i < num; i++){
            cout << i << " hello" << endl;
        }
    }

    string hello(int num, int num2){
        return "hiiiieeee";
    }
};


// runtime
class Parent{
public:
    void fun(){
        cout << "me parent class me gets override :(( " << endl;
    }
};

class Child{
public:
    void fun(){
        cout << "me child class me is priority ;)) " << endl;
    }
};




int main(){
    cout << "\nconstructor overloading:" << endl;
    sayHello h1;
    sayHello h2(2);

    cout << "\nfunction overloading: " << endl;
    h1.hello();
    h1.hello(3);
    cout << h1.hello(3,2) << endl;


    // runtime
    cout << "\nfunction overridding:\n";
    Child c1;
    c1.fun(); 
}