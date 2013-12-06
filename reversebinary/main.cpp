/*
|  main.cpp
|  reversebinary
|
|  Created by Bhargav Anand on 12/5/13.
|  Copyright (c) 2013 Bhargav Anand Annavajhala. All rights reserved.
*/

#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> toBinStr(unsigned int num, vector<int>res={}){
    if(num < 1){
        return res;
    }
    res.push_back(num%2);
    return toBinStr(num >> 1, res);
}

long toDecStr(vector<int> n){
    long sum = 0;
    for(int i=0;i<n.size();i++){
        sum = sum + n[n.size()-i-1]*pow(2,i);
    }
    return sum;
}

vector<int> padNum(vector<int> s, int n){
    long m = s.size();
    if(m == n) return s;
    for(int i=0;i<n-m;i++){
        s.push_back(0);
    }
    return s;
}

const unsigned int getBits(int num){
    int count = 0;
    while(num > 0){
        num = num >> 1;
        ++count;
    }
    return count;
}

int main(int argc, const char * argv[])
{
    int num;
    long decimal;
    vector<int> numbers;
    cout << "Please enter a positive number: ";
    cin >> num;
    
    if(num < 0){
        cout << "Invalid number. Please enter a positive number" <<endl;
        return 0;
    }

    const unsigned int n = getBits(num);
    numbers = padNum(toBinStr(num), n);
    decimal = toDecStr(numbers);
    cout << "The number you entered is: " << num << endl;
    cout << "The reversed binary equivalent is " << decimal << endl;
    cout << endl;
    return 0;
}

