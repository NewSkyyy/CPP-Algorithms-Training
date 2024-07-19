#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<bool> ToBin(unsigned num){
    vector<bool> res;
    if (num == 0) return res;
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

vector<bool> ToLevG(unsigned num){
    if (num == 0) return {0};
	else{
    vector<bool> binary = ToBin(num);
    vector<bool> res;
    for (unsigned i = 0; i < (binary.size()-1); i++){
        res.push_back(0);
        res.push_back(binary[i]);
    }
    res.push_back(1);
    return res;
	}
}

unsigned LevGTo(vector<bool> binary){
    vector<bool> vec = {0};
    if (binary == vec) return 0;
	else{
    unsigned res;
    vec = {};
    for (unsigned i = 1; i < (binary.size() - 1); i = i + 2){
        vec.push_back(binary[i]);
    }
    vec.push_back(1);
    reverse(vec.begin(),vec.end());
    return BinTo(vec); 
	}
}

bool Test(){
    for (unsigned long long i = 0; i<100; i++)
    {
        if (LevGTo(ToLevG(i)) != i)
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
    output(ToLevG(numb));
    cout << "Your number is: "<< LevGTo(ToLevG(numb)) << endl;
    return 1;
}