#include <iostream> 
using namespace std;

int main(){

    int a, b;       // variables 
    cout << "enter value for a and b: ";     // output statement 
    cin >> a >> b;                           // input statement
    int c = a+b;    // + is one of an arithmatic operations in between + - / * %
    cout << c << endl;      


    // qn1 take 3 input numbers and print their product
    int x, y, z;
    cout << "enter values for x, y and z: ";
    cin >> x >> y >> z;
    int product = x * y * z;
    cout << "product:" << product << endl;


    // qn2 print average of two numbers
    int m , n;
    cout << "enter values for m and n:";
    cin >> m >> n;
    int avg = (m + n)/2;
    cout<< "average: " << avg << endl;



}