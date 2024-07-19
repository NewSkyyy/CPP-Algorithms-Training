#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<bool> ToBin(unsigned num){
    vector<bool> res;
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

string output(vector<bool> array){
    vector<bool> Result = array;
    string res;
    for (unsigned i = 0; i < Result.size(); i++){
        res += Result[i];
        cout << Result[i] << " " ;
    }
    cout << " "<< endl;
    return res;
}

vector<bool> ToOmegaE(unsigned num){
    vector<bool> res;
    res.push_back(0);
    vector<bool> group {0};
    unsigned counter = 0;
    if (num == 1)
        return res;
    else{
        
        vector<bool> vec = ToBin(num);
        for(unsigned i =0; i<ToBin(num).size(); i++){
            res.insert(res.begin(),vec[vec.size()-1-i]);
            ++counter;
        }
        while (counter != 2){
            int temp = counter - 1;
            counter = 0;
            vec = ToBin(temp);
            for(unsigned i =0; i<ToBin(temp).size(); i++){
                res.insert(res.begin(),vec[vec.size()-1-i]);
                ++counter;
            }
        } 
        }
    return res;
}

unsigned OmegaETo(vector<bool> vec){
    unsigned N = 1;
    while(vec.size()>0){
        bool firstbit = vec[0];
        vector<bool> res;
        if (firstbit == 1) {
            for(unsigned i = 0;i<N+1;i++)
                res.push_back(vec[i]);
            unsigned temp = N + 1;
            
            if(BinTo(res) != 0)
                N = BinTo(res);
            else
                return N;
            for(unsigned i = 0;i<temp;i++)
                vec.erase(vec.begin());
        }
        else 
            return N;
    }
    return 1;
}

bool Test1(){
    vector<bool> p1 = {1,0,1,1,1,0};
    vector<bool> p2 = {1,0,0};
    vector<bool> p3 = {1,1,1,1,0,1,0};
    vector<bool> p4 = {1,0,1,0,0,1,0,0,0,1,0};
    if ((OmegaETo({1,0,1,1,1,0}) == 7) && (OmegaETo({1,0,0}) == 2) &&
       (ToOmegaE(7) == (p1)) && (ToOmegaE(2) == (p2)) &&
       (OmegaETo({1,1,1,1,0,1,0}) == 13) && (OmegaETo({1,0,1,0,0,1,0,0,0,1,0}) == 17) &&
       (ToOmegaE(13) == p3) && (ToOmegaE(17) == p4)){
        cout<< "Test complited" << endl;
        return true;
    }
    else{
        cout<< "Test failed" << endl;
        return false;
    }
}
bool Test2(){
    for (unsigned i = 1; i<100000; i++)
    {
        if (OmegaETo(ToOmegaE(i)) != i)
        {
            cout << "Test 2 failed" << " i = " << i << endl;
            return false;
        }
        else
        {
            
        }
    }
    cout << "Test 2 complited" <<endl;
    return true;
}

int main()
{
    Test1()&&Test2();
    return 1;
}