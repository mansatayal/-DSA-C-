#include <iostream>
#include <stack>
using namespace std;

// follows LIFO - last in first out 

int main(){
    stack<int> s;

    s.push(2);
    s.push(5);
    s.push(2);
    s.push(7);
    s.push(1);
    s.push(210);

    cout << s.size() << endl;
    s.pop();
    cout << s.top() << endl;
    cout << s.empty() << endl;
}


/*

STACK:
=> items - string, array
=> left to right 
=> most recent element  (next greater/ prev smallest)
=> matching / cancelling / cleaning
=> reverse 



- when to pop and what to pop
- when to push
- store result


types:
o- Simple:  normal 
o- Monotonic:   (increasing / decreasing) (sorting order) eg. {2,4,6,8..}
o- Greedy:      (monotonic + condition)     eg. prioroties p2 > p3 etc



*/