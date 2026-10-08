#include <iostream>
using namespace std;

int main(){
    int a[10];      // int is 4bytes hence 40 bytes of interupted memory used to represent this array

    int* location6 = &a[6];     // a variable that holds the address of the 6th element of the array
    int* location0 = &a[0];

    cout << "location 6: " << location6 << endl;
    cout << "location 0: " << location0 << endl;
    cout << "Difference: " << location6 - location0 << endl;

    // (uintptr_t) => Unsigned INTeger big enough for PoinTeR       "type" (naming convection)
    cout << "---------------------------------" << endl;
    cout << "location 6: " << (uintptr_t)location6 << endl;
    cout << "location 0: " << (int)location0 << endl; //So (int) works for me only because the compiler happens to be 32-bit. uintptr_t is the version that stays correct everywhere, which is the whole reason it exists.
    cout << "Difference without type: " << (uintptr_t)location6 - (uintptr_t)location0 << endl;
    cout << "Difference with type(int): " << location6 - location0 << endl;

    /*
    why difference 6 and 24??
        A pointer is not just an address. 
        It's an address + int* means "address of an int"

        Pointer subraction is defined as "how many elements apart are these two" not "how many bytes apart"
        so the compiler does:
            (address6 - address0) / sizeof(int)
            = 24 / 4
            = 6
        
        By declaring the variables as int* (can be any other type too) is how the compiler knows the step size (in this case +4). It's the same reason location0 + 1 moves forward 4 bytes and not 1 byte

        char* can also be used as it's also 1 byte 
    */

    cout << "-----------------------------------------------------------------------" << endl;
    int a2[10] = {2,4,6,8,10,12,14,16,18,20};
    int *plocation0 = a2;   // a2 or a2[0] is the same thing as both means the start of teh array

    for(int i = 0; i < 10; i++){
        // a2 + i differs by 4 because of int values
        // cout << a2 + i << " = " << *(a2 + i) << endl;

        // OR
        
        cout << plocation0 << " = " << *plocation0 << endl;
        plocation0++;
    }
 
}