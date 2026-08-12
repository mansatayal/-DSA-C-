#include <iostream>
using namespace std;
#include <map>
#include <unordered_map>

// unordered_map - stores key value in random sequence
// map - stores key value in the order they've been inserted    


void printmap(unordered_map<string,int>m){
    for(auto i : m){
        cout << i.first << " " << i.second << endl;
    }
}

void printm(unordered_map<string,int> m){
    unordered_map<string,int> :: iterator it = m.begin();

    while(it != m.end()){
        cout << it -> first << " " << it -> second << endl;
        it++;
    }
}

int main(){

    // create
    unordered_map <string, int> m;      // key is always unique

    // insertion

    // 1
    pair<string, int> p = make_pair("hello", 3);
    m.insert(p);

    // 2
    pair<string, int> p2("there", 2);
    m.insert(p2);

    // 3
    m["hi"] = 1; 

    // update
    m["hi"] = 5;

    // search
    cout<< m["hi"] << endl;
    cout << m.at("there") << endl;

    // acessing non exxistent key
    // cout << m.at("unknown") << endl;        // error
    cout<< m["unknown"] << endl;            // creates a key with value 0
    cout << m.at("unknown") << endl;        // gives 0 cause now a key is been added

    // size
    cout << m.size() << endl;

    // does the key exists?
    cout << m.count("bro") << endl;         // 1 - exists       0 - doesn't exist 

    // erase
    m.erase("there");
    cout << m.size() << endl;

    // printing the whole map
    printmap(m);
    printm(m);              // using iterator
}


/*
hashcode is a cpmpression technique used to compress the data and store in a array (bucket array) to ensure uniform distribution

eg. hello (we want to store this string as an int) we can use various code for eg
    sum of ascii value of each char and then take modulus of it with a certain number 
    ascii( h + e + l + l + o) % n (let say it's equal to 23)   - it'll be stored at the 23rd index
    hlloe will equate to the same code that is 23       [COLLISION]

    collision can be handled by:
    1. open hashing : create a linked list at the 23rd index and store all the 23rd hashcodes 
        the 23rd index will contain the head of the linked list 
    
    2. closed adressing : the same hashcode will  be stored at the next index if occupied 
        function: Hi(a) = h(a) + fi(a)

            linear probing: here i = 1
                eg. 23rd index is occupied so in case of another 23rd it'll be stored at 23 + 1 => 24
                    if 24th is also occupied ==> 24 + 1 => 25 

            quadratic probing: here i = i^2
                eg. if 23rd is occupied i = 1 hence i^2 = 1     go on 23 + 1 => 24 index
                    if 24th is also occupied i = 2 hence i^2 = 4    go on 24 + 4 => 28 index
            
            custom : you can create as you wish i = i^3 - 1;; i = 2 * i etc
    


*/