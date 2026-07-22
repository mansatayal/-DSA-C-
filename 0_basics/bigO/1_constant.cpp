#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


int main(){
    // vector 
    vector<int> nums = {1,2,3};

    nums.push_back(4);      //push to end 
    nums.pop_back();         //pop from end
    cout << nums[0]<< endl;     //lookup

    // HashMap
    unordered_map<string, int> hashMap;

    hashMap["key"] = 10;               // insert

    cout << hashMap.count("key") << endl; // lookup (exists)
    cout << hashMap["key"] << endl;       // lookup (value)

    hashMap.erase("key");              // remove

    return 0;
}