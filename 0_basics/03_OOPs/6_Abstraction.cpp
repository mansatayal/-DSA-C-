#include <iostream>
using namespace std;

/*
ABSTRACTION:
hiding all unnecessary details & showing only the important parts. 

HOW??
1. ACCESS MODIFIERS:
    public          : for access across anything and everything
    private         : for only in class access
    protected       : access only for inheritting


2. ABSTRACT CLASSES:   
it's a class that doesn't allow creating any object and is only inherited by other classes.
    - are used to provide a base class from which other classes can be derived.
    - they can't be instantiated (create object (instance means object)) and are meant to be    inherited.
    - are typically used to define an interface for derived classes.

*/

class shape{
    virtual void draw()= 0;         // pure virtual function
};

class circle : public shape{
public:
    void draw(){
        cout << "drawing a circle" << endl;
    }
};



int main(){
    // shape s1;        // error because abstract class can't create objects
    circle c1;
    c1.draw();
}