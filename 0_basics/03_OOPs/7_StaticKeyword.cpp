#include <iostream>
using namespace std;

/*
- static variables:
    in function variables declared as static in a function are created and intialised once for a lifetime of the program.

    in class variables are created and initialised once. they are shared by all the objects of the class 

- static object 
*/

// in function:
void static_variable_fun(){
    static int x = 0;
    cout << x << endl;
    x++;
}

// in class:
class staticVariableClass{
public:
    static int x;
    
    void incx() {
        cout << ++x << endl;
    }
};

int staticVariableClass::x = 0;


// static object:
class StaticObject{
public:
    StaticObject(){
        cout << "constructor \n";
    }

    ~StaticObject(){
        cout << "destructor \n";
    }
};

int main(){
    // in function:
    // the value of x increses everytime as 0 1 2 this is because in the stack memory whenever the function is called the variable gets deleted as the function end but when we set it to static the variable (x) initializes outside the stack and so even when the function gets terminated variable (x) exists with the value
    // global variable:         lives the whole program, visible everywhere
    // static local variable:   lives the whole program, visible only inside its function
    cout << "\nin function:\n";
    static_variable_fun();
    static_variable_fun();
    static_variable_fun();


    cout << "\nin class:\n";
    staticVariableClass c1;
    c1.x = 6;
    c1.incx();
    c1.incx();
    c1.incx();

    staticVariableClass c2;
    cout << "c2: "<< c2.x << endl;
    c2.x = 20;

    cout << "c1: "<< c1.x << endl;      // because of static variable
    cout << "c2: "<< c2.x << endl;      



    cout << "\nstatic object:\n";

    if (true){
        StaticObject s1;
    }
    cout << "outside the the if true loop without static object\n";

    if (true){
        static StaticObject s2;     // lives until the program ends, so its destructor runs last, after main finishes
    }
    cout << "outside the the if true loop with static object\n";    
}