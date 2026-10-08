#include <iostream>
using namespace std;

void increment(int value){
    // not passing by reference is same as int value = 5; hence this is local and works here only
    value++;
}

// pass by pointer
void increment2(int* value){
    // *value++;       // this will only increment the address ; moves the pointer, a untouched
    (*value)++;        //increment the int the pointer points to
}

// pass by reference
void increment3(int& value){
    value++;
}

int main(){
    // REFERENCE-------------------------------------------------------------------------

    int b = 5;
    int& refb = b;      // it's just a reference / alias for b

    cout << "refb: " << refb << endl;

    refb = 10;      //reassign
    cout << b << endl;


    // functions and references
    int a = 5;
    increment(a);
    cout << "increment: "<< a << endl;      // still 5 

    increment2(&a);
    cout << "increment2: " << a << endl;

    increment3(a);
    cout << "increment3: " << a << endl;


    // important:
    // you can't change the reference for eg:
    int c = 6;
    int d = 7;
    int& cref = c;
    cout << "c: " << c << " cref: " << cref << endl;
    cref = d;           // both c and cref are now contains the value of d (7 here)
    cout << "c: " << c << " cref: " << cref << endl;

    // int& dref;       // error: you can't set an empty reference you need to assign it to something
    // int& nref = NULL;    // error : can't be null too 


    // how to change the address?
    int* ref = &c;
    *ref = 2;
    ref = &d;
    *ref = 3;       // set c = 2 and d = 3
    cout << "c:" << c << " d: " << d << endl;



}