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

vector<bool> ToGammaE(unsigned num){
    if (num == 0) {
        cout << "There is no code for zero" << endl;
        return {};
    }
    else{
        vector<bool> vecb = ToBin(num);
        vecb.erase(vecb.begin());
        vector<bool> veca = ToBin(pow(2,vecb.size()));
        reverse(veca.begin(),veca.end());
        vecb.insert(vecb.begin(),veca.begin(),veca.end());
        return vecb;
    }
}

unsigned GammaETo(vector<bool> binary){
    vector<bool> vec = {0};
    if (binary == vec) {  
        cout << "There is no code for zero" << endl;
        return 0;
    }
    else {
        vector<bool> vecb;
        vector<bool> veca;
        for (unsigned i = binary.size()-1; i>0;i--){
            vecb.push_back(binary[i]);
            veca = ToBin(pow(2,vecb.size()));
            if ((vecb.size()+veca.size())==binary.size()){
                break;
            }
            else {
            }
        }
        reverse(vecb.begin(),vecb.end());
        vecb.insert(vecb.begin(),1);
        return BinTo(vecb);
    }
}

bool Test(){
    for (unsigned long long i = 1; i<10000; i++)
    {
        if (GammaETo(ToGammaE(i)) != i)
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
    output(ToGammaE(numb));
    cout << "Your number is: "<< GammaETo(ToGammaE(numb)) << endl;
    return 1;
}