// O(root n)

#include <iostream>
#include <set>
#include <cmath>
using namespace std;

int main() {
    //Find all factors (divisors) of a number
    int n = 12;
    set<int> factors;
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            factors.insert(i);
            factors.insert(n / i);
        }
    }

    cout << "Factors of " << n << " are: ";
    for (int factor : factors) {
        cout << factor << " ";
    }
    cout << endl;
    return 0;
}