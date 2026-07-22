#include <iostream>
using namespace std;

int main(){
    int a = 12;
    if(a % 2 == 0 and a % 3 == 0){
        cout << "divisible by both 2 and 3" << endl;
    }
    else{
        cout << "not divisible" << endl; 
    }

    // qn1 - sum of 10 numbers;
    int sum = 0;
    for (int i = 1; i < 11; i++){
        sum += i;
    }
    cout << sum << endl;

    // qn2 - sum of even numbers between 20 and 40 (both included)
    int sum2 = 0;
    for(int i = 20; i < 41; i++){
        if(i % 2 == 0){
            sum2 += i;
        }
    }
    cout << sum2 << endl;
}