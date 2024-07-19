#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

vector<bool> ToBin(unsigned num){
    vector<bool> res = {0};
    if (num == 0) return res;
    res = {};
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

vector<bool> ToExpG(unsigned num, unsigned k){
    vector<bool> a;
    vector<bool> b;
    vector<bool> res;
    unsigned w = 1 + floor(num/pow(2,k));
    unsigned f = floor(log2(1+num/pow(2,k)));
    a = ToUnar(f);
    b = ToBin(w);
    res.insert(res.begin(),b.end()-f,b.end());
    res.insert(res.begin(),a.begin(),a.end());
    b = ToBin(num);
    res.insert(res.end(),b.end()-k,b.end());
    return res;
}

unsigned ExpGTo(vector<bool> vec, unsigned k){
    unsigned f = 0;
    vector<bool> res = vec;
    while(res[0]!=0){
        f += 1;
        res.erase(res.begin());
    }
    unsigned r = BinTo(res);
    return (pow(2,f)-1)*pow(2,k)+r;
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
    for (unsigned i = 0; i<1000; i++)
    {
        for (unsigned j = 0; j<7; j++)
        {
            if (ExpGTo(ToExpG(i,j),j) != i)
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
    output(ToExpG(numb1,numb2));
    cout << "Your number is: "<< ExpGTo(ToExpG(numb1,numb2),numb2) << endl;
    return 1;
}