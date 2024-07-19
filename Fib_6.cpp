#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<bool> ToFib(unsigned num)
{
    unsigned fib1 = 1, fib2 = 1, fib = 0 ,i = 0; 
    while(num >= fib2){
        fib = fib2 + fib1; // 2 3 5 8 13 21 34 55 ...
        fib1 = fib2;       // 1 2 3 5 8 13 21 34 ...
        fib2 = fib;        // 2 3 5 8 13 21 34 55 ...
        i+=1;
    }
    num -= fib1; 
    vector<bool> res(i,0);
    res[res.size()-i] = 1;
    while (num > 0){
        i = 0;
        fib = 0;
        fib1 = 1;
        fib2 = 1;
        while(num >= fib2){
            fib = fib2 + fib1; // 2 3 5 8 13 21 34 55 ...
            fib1 = fib2;       // 1 2 3 5 8 13 21 34 ...
            fib2 = fib;        // 2 3 5 8 13 21 34 55 ...
            i+=1;
        }
        num -= fib1;
        res[res.size() - i] = 1;     
   }
   return res;
} 

unsigned FibTo(vector<bool> num)
{
    unsigned res = 0, fib1 = 1, fib2 = 1, fib = 0;
    
    while (num.size()>0){
        fib = fib2 + fib1; // 2 3 5 8 13 21 34 55 ...
        fib1 = fib2;       // 1 2 3 5 8 13 21 34 ...
        fib2 = fib;        // 2 3 5 8 13 21 34 55 ...
        res += fib1 * num[num.size()-1];
        num.erase(num.end());
    }
    return res;
}

vector<bool> ToFibonachi(unsigned num){
    vector<bool> res = ToFib(num);
    reverse(res.begin(),res.end());
    res.push_back(1);
    return res;
}

unsigned FibonachiTo(vector<bool> vec){
    vector<bool> res = vec;
    vec.erase(vec.end());
    reverse(vec.begin(),vec.end());
    return FibTo(vec);
}

bool Test(){
    for (unsigned long long i = 1; i<10000; i++)
    {
        if (FibonachiTo(ToFibonachi(i)) != i)
        {
            cout << "Test failed" << " i = " << i << endl;
            return false;
        }
        else
        {
            
        }
    }
    cout << "Test complited" <<endl;
    return true;
}

bool output(vector<bool> array){
    vector<bool> Result = array;
    string res;
    for (unsigned i = 0; i < Result.size(); i++){
        res += Result[i];
        cout << Result[i];
    }
    cout << "" << endl;
    return true;
}

int main()
{
    Test();
    int numb1;
    cout << "Enter your number:" << endl;
    cin >> numb1;
    output(ToFibonachi(numb1));
    cout << "Your number is: "<< FibonachiTo(ToFibonachi(numb1)) << endl;
    return 1;
}