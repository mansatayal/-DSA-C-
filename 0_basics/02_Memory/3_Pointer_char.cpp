#include <iostream>
using namespace std;
int main(){
    char array1[] = "hello";

    char* location3 = &array1[3];
    char* location0 = &array1[0];

    cout << "location 3: " << (uintptr_t)location3 << endl;
    cout << "location 0: " << (uintptr_t)location0 << endl;
    cout << "difference: " << (uintptr_t)location3 - (uintptr_t)location0 << endl;

    // difference is 3 because char is 1 byte only and so it matches


    cout << "---------------------------------------------------------------" << endl;
    cout << "location 3: " << location3 << endl;
    cout << "location 0: " << location0 << endl;
    cout << "difference: " << location3 - location0 << endl;

    /*
    pointers behaves differently for different data types here:
        cout treats a char* as a C string, not as an address. When you print a char* directly, cout goes to that address and prints characters one after another until it hits a \0 (the string terminator).

        Your array in memory is:
        index:    0    1    2    3    4    5
        value:   'h'  'e'  'l'  'l'  'o'  '\0'

        So:
        location0 -> starts at 'h', prints "hello" until '\0'
        location3 -> starts at the second 'l', prints "lo" until '\0'

        Why the difference is still 3?
        location3 - location0 is pointer subtraction, which has nothing to do with printing. It counts elements between the two pointers, and there are 3 chars between them. That part behaves the same as with int*.
    */
}