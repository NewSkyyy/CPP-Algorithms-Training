#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<bool> ToBini(unsigned num){
    vector<bool> res;
    if (num == 0) return res;
    while (num > 0){
        res.push_back(num%2);
        num/=2;
    }
    reverse(res.begin(),res.end());
    res.erase(res.begin());
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

unsigned log2n(unsigned x, unsigned n){
    if (n == 1) return floor(log2(x));
    else if (n > 1) return floor(log2(log2n(x,n-1)));
}

unsigned n(unsigned num){
    if (num == 0) return 0;
    else if (num > 0 and num < 6) return pow(2,n(num-1));
    else return 4294967295; //max value for unsigned integer
}

unsigned logx(unsigned x){
    int k = 0; 
    while (n(k) <= x){
        k+=1;
    }
    return k-1;
}

vector<bool> ToLev(unsigned num){
    vector<bool> vec = {0};
    if (num == 0) return vec;
    vec = ToBini(num);
    vector<bool> res = ToBini(floor(log2(num)));
    for (unsigned i = 0;i < ToBini(num).size();i++){
        res.push_back(vec[i]);
    }
    for (unsigned i = 2; i < logx(num); i++){
        vector <bool> temp = ToBini(log2n(num,i));
        for (unsigned j = 0;j<temp.size();j++){
            res.insert(res.begin(),temp[j]);
        }
    }
    res.insert(res.begin(),0);
    for (unsigned i = 0; i< logx(num);i++){
        res.insert(res.begin(),1);
    }
    return res;
}

unsigned LevTo(vector<bool> binary){
    unsigned quantity = 0;
    unsigned i = 0;
    vector<bool> vec = binary;
    while (binary[i] != 0) {
        quantity += 1;
        i += 1;
    }
    if (quantity == 0) return 0;
    else {
        for(i = 0; i< quantity+1; i++){
            vec.erase(vec.begin());
        }
        unsigned N = 1;
        int P = quantity - 1;
        while (P != 0){
            vector<bool> Z;
            Z.insert(Z.begin(),vec.begin(),vec.begin()+N);
            vec.erase(vec.begin(),vec.begin()+N);
            Z.insert(Z.begin(),1);
            N = BinTo(Z);
            P -= 1;
        }
        return N;
    }
}

bool Test(){
    for (unsigned long long i = 0; i<10000; i++)
    {
        if (LevTo(ToLev(i)) != i)
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
    int numb;
    cout << "Enter your number:" << endl;
    cin >> numb;
    output(ToLev(numb));
    cout << "Your number is: "<< LevTo(ToLev(numb)) << endl;
    return 1;
}