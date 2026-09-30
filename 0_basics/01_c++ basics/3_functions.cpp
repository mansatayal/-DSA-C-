#include <iostream>
using namespace std;

int findSum(int n){
    int sum = 0;
    if(n == 0){
        return 0;
    }
    for(int i = 1; i < n+1; i++){
        sum += i;
    }

    return sum;
}

int findsum(int n){
    if(n == 0){
        return 0;
    }

    int res =( n * (n + 1))/2;
    return res;
}

int main(){
    cout << findSum(7) << endl;
    cout << findSum(3) << endl;
    cout << findSum(5) << endl;

    cout << "same function just optimized using a formula" << endl;
    cout << findsum(7) << endl;
    cout << findsum(3) << endl;
    cout << findsum(5) << endl;


}