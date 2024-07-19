#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <sstream>
#include <iterator>
using namespace std;

vector<unsigned> ToBin(unsigned num, unsigned n){
    vector<unsigned> res;
    while (num > 0){
        res.push_back(num%2);
        num/=2;
    }
    if (res.size()<(n+1))
        res.push_back(0);
    else { }
    return res;
}

unsigned BinTo(vector<unsigned> bin){
    unsigned res = 0; unsigned p = 1;
    res += bin[0];
    for (unsigned i = 1; i < bin.size(); i++){
        res += bin[i]*2*p;
        p*=2;
    }
    return res;
}

vector<unsigned> BinSum(vector<unsigned> bin1, vector<unsigned> bin2){     
    unsigned q=0, tmp;
    int i;
    vector<unsigned> c;
    if (bin1.size() > bin2.size()){
        bin2.resize(bin1.size());
        c.resize(bin1.size());
    }
    else {
        bin1.resize(bin2.size());
        c.resize(bin2.size());
    }
    for(i=bin2.size()-1;i>0;i--)
    {
        tmp=bin1[i]+bin2[i]+q;
        q = 0;
        if(tmp==2)
        {
            q=1;
            tmp=0;
        }
        else { }
        if(tmp==3)
        {
            q=1;
            tmp=1;
        } 
        else {}
        c[i]=tmp;
    }
    tmp=bin1[i]+bin2[i]+q;

    if (tmp==2){
        vector<unsigned> b;
        tmp=1;
        b.resize(c.size()+1);
        for (unsigned j=0; j<b.size(); j++){
            b[j]=c[(j-1+b.size())%b.size()];
        }
        c = b;
    }
    else{}
    if (tmp==3){
        vector<unsigned> b;
        q=1;
        b.resize(c.size()+1);
        for (unsigned j=0; j<b.size(); j++){
            b[j]=c[(j-1+b.size())%b.size()];
        }
        c = b;
        c[i+1] = 1;
    }
    else { }
    c[i]=tmp;
    return c;
}


string ToString(vector<unsigned> vec){
    ostringstream res;
    if(!vec.empty()){
        copy(vec.begin(), vec.end() - 1, ostream_iterator<unsigned>(res, ""));
        res << vec.back();
    }
    else { }
    return res.str();
}

bool output(vector<string> array){
    vector<string> Result = array;
    for (unsigned i = 0; i < Result.size(); i++){
    cout << Result[i] << " " ;
    }
    return true;
}

vector<string> shenon(vector<int> lengths){
    if (lengths.size()<1)
        return {"You should use more than 0 words"};
    vector<string> wordsVector;
    wordsVector.push_back(string(lengths[0], '0'));
    vector<unsigned> sum = {0,0,0};
    vector<unsigned> binary;
    double kraft = pow(2,-lengths[0]);
    for (unsigned i=1; i < lengths.size(); i++){
        kraft += pow(2, -(lengths[i]));
        if (lengths[i] < 1 || lengths[i]<lengths[i-1])
            return {"You should pick correct lengths"};
        unsigned s = pow(2,lengths[i-1]);
        vector<unsigned> p = ToBin(s,lengths[i]);
        p.erase(p.begin());
        binary = BinSum(sum,p);
        sum = BinSum(sum,p);
        string str = ToString(binary);
        wordsVector.push_back(str);
    }
    
    if (kraft<1){ 
        return wordsVector;
    }
    else {
        cout << kraft << endl;
        return {"Lengths should satisfy Kraft unequality"};
    }
}

bool Test(){
    vector<string> shen = shenon({3,3,3,4,4,4,4});
    vector<string> should = {"000", "001", "010", "0110", "0111", "1000", "1001"};
    if (shen == should){
        cout << "Test complited" << endl;
        return true;
    }
    else{
        cout << "Test failed" << endl;
        return false;
    }
}


int main()
{
    Test();
    cout << "Results for l1 = 3, l2 = 3, l3 = 3, l4 = 4, l5 = 4, l6 = 4, l7 = 4:"<< endl;
    output(shenon({3,3,3,4,4,4,4}));
    return 1;
}