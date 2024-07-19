#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

vector<bool> ToBin(unsigned num){
    vector<bool> res;
    if (num == 0) return res;
    while (num > 0){
        res.push_back(num%2);
        num/=2;
    }
    reverse(res.begin(),res.end());
    return res;
}

unsigned BinTo(vector<bool> bin){
    unsigned res = 0; unsigned p = 1;
    res += bin[bin.size()-1];
    for (int i = bin.size()-2; i >= 0; i--){
        res += bin[i]*2*p;
        p*=2;
    }
    return res;
}

vector<bool> ToUnar(unsigned num){
    vector<bool> res;
    for (unsigned i = 0; i < num; i++){
        res.push_back(1);
    }
    res.push_back(0);
    return res;
}

unsigned UnarTo(vector<bool> bin){
    unsigned k = 0;
    for (unsigned i = 0; i< bin.size(); i++){
        if (bin[i]==0){
            break;
        }
        else{
            k+=1;
        }
    }
    return k;
}

vector<bool> ToRaise(unsigned num, unsigned k){
    vector<bool> a;
    vector<bool> b;
    unsigned m = pow(2,k);  
    vector<bool> temp = ToBin(num%m);
    for (unsigned i = 0; i<log2(m);i++){
        if (i < temp.size()){
            b.push_back(temp[i]);
        }
        else{
            b.insert(b.begin(),0);
        }
    }
    a = ToUnar(num / m);
    b.insert(b.begin(),a.begin(),a.end());
    return b;
}

unsigned RaiseTo(vector<bool> vec, unsigned k){
    vector<bool> a;
    vector<bool> b = vec;
    unsigned m = pow(2,k);
    for (unsigned i = 0; i< vec.size()-1;i++){
        if (vec[i]==0){
            a.push_back(vec[i]);
            b.erase(b.begin());
            break;
        }
        else{
            b.erase(b.begin());
            a.push_back(vec[i]);
        }
    }
    unsigned g = UnarTo(a);
    for (unsigned i = 0;i<log2(m)-1;i++){
        if (b[0]==0){
            b.erase(b.begin());
        }
        else{
            break;
        }
    }
    return g*m+BinTo(b);
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

bool Test(){
    for (unsigned long long i = 0; i<1000; i++)
    {
        for (unsigned long long j = 1; j<7; j++)
        {
            if (RaiseTo(ToRaise(i,j),j) != i)
            {
                cout << "Test failed" << " i = " << i << " j = " << j << endl;
                return false;
            }
            else
            {
  
            }
        }
    }
    cout << "Test complited" <<endl;
    return true;
}

int main()
{
    
    Test();
    int numb1;
    int numb2;
    cout << "Enter your first number:" << endl;
    cin >> numb1;
    cout << "Enter your second number:" << endl;
    cin >> numb2;
    output(ToRaise(numb1,numb2));
    cout << "Your number is: "<< RaiseTo(ToRaise(numb1,numb2),numb2) << endl;
    return 1;
}