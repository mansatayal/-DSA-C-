#include <iostream>
#include <cstring>
using namespace std;

/*
    A pointer is just a variable that holds a memory address.
*/


int main(){
    // POINTER -----------------------------------------------------------------------------------------------

    // pointer doesn't need to have a type (int , char etc) here ptr are is just a variablr which stores the address

    // all three are the same thing 
    void* ptr = 0;
    void* ptr2 = NULL;
    void* ptr3 = nullptr;


    int a = 5;
    // void* ptra = &a;
    // cout << ptra << endl;
    // *ptra = 10;        //error because the pointer is set as void hence the compiler doesn't know what type of data you're putting in and how many byte it needs eg(short will take 2 bytes int - 4 bytes and long - 8 bytes)

    int* ptra = &a;         // & : get the address of a 
    cout << " * : get the value of ptra: " << *ptra << endl;
    *ptra = 10;             // reassigning
    cout << a << endl;
    cout << *ptra << endl;

    

    // allocating memory
    char* buffer = new char[8];     // allocates 8 bytes of memory
    memset(buffer, 0, 8);           //fills 8 bytes of memory with 0

    char** ptr4 = &buffer;          // double pointer : points to the address of another pointer 

    delete[] buffer;                // free it 



}