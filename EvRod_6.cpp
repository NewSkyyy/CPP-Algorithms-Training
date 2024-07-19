#include <iostream>
#include <vector>
using namespace std;

vector<bool> ToBin(unsigned num){
    vector<bool> res;
    while (num > 0){
        res.push_back(num%2);
        num/=2;
    }
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

vector<bool> ToEvRod(int num){
    vector<bool> res;
    vector<bool> binary = ToBin(num);
    if (num == 0) return {0,0,0}; 
    else if (num == 1) return {0,0,1};
    else if (num == 2) return {0,1,0};
    else if (num == 3) return {0,1,1};
    else {
        while(binary.size() > 3) {
            vector<bool> iter = {};
            for (int i = 0; i<binary.size(); i++){
                iter.insert(iter.begin(),binary[i]);
            }
            res.insert(res.begin(),iter.begin(),iter.end());
            binary = ToBin(iter.size());
        } 
        for (int i = 0; i<binary.size(); i++){
            res.insert(res.begin(), binary[i]);
        }
        res.push_back(0);
    return res;
    }
}

int EvRodTo(vector<bool> num){
    vector<bool> a = {0,0,0};
    vector<bool> b = {0,0,1};
    vector<bool> c = {0,1,0};
    vector<bool> d = {0,1,1};
    if (num == a) return 0; 
    else if (num == b) return 1;
    else if (num == c) return 2;
    else if (num == d) return 3;
    else {
        int quantity = 3;
        num.erase(num.end()-1);
        vector<bool> binary = num;
        while (binary.size()>0){
            vector<bool> iter = {};
            for (int i = 0; i < quantity; i++){
                iter.push_back(binary[0]);
                binary.erase(binary.begin());
            }
            quantity = BinTo(iter);
        }
        return quantity;
    }
}

bool Test(){
    for (unsigned i = 1; i<10000; i++)
    {
        if (EvRodTo(ToEvRod(i)) != i)
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
    for (unsigned i = 0; i < Result.size(); i++){
    cout << Result[i];
    }
    cout << "" << endl;
    return true;
}

int main()
{
    Test();
    int num;
    cout << "Enter your number:" << endl;
    cin >> num;
    output(ToEvRod(num));
    cout << "Your number is: "<<EvRodTo(ToEvRod(num)) << endl;
    return 1;
}