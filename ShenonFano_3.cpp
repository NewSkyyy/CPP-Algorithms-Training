#include <iostream>
#include <string>
#include<cmath>
#include <vector>
using namespace std;

vector<pair<string,double> > SortByDec(vector<pair<string,double> > vec){
    pair<string,double> par;
    vector<pair<string,double> > res;
    for (unsigned i = 0; i < vec.size(); i++){
        double max = vec[i].second;
        unsigned maxind = i;
        for(unsigned j = i; j<vec.size();j++){
            if (vec[j].second > max){
                max = vec[j].second;
                maxind = j;
            }
        }
        res.push_back(vec[maxind]);
        par = vec[i];
        vec[i] = vec[maxind];
        vec[maxind] = par; 
    }
    return res;
}

string ToBin(double dec, int quantity){
    double num = dec;
    string res;
    for (int i = 0; i < quantity; i++){
        num = num * 2;
        if (num < 1) {
            res.push_back('0');
        }
        else if (num > 1) {
            num -= 1;
            res.push_back('1');
        }
        else if ((num - 1) <= 0.00001){
            num -= 1;
            res.push_back('1');
        }
        
    }
    return res;
}

vector<pair<string,double> > MakeADict(string text){
    pair<string,double> par;
    vector<pair<string,double> > res;
    par.first = text[0];
    res.push_back(par);
    for (unsigned i = 1; i < text.length(); i++){
        bool notindict = true;
        for (unsigned j = 0; j< res.size(); j++){
            if (res[j].first.find(text[i]) != string::npos){
                notindict = false;
            }
            else { }
        }
        if (notindict){
        par.first = text[i];
        res.push_back(par);
        }
    }
    for (unsigned i = 0; i < res.size(); i++){
        for (unsigned j = 0; j< text.size(); j++){
            if (res[i].first.find(text[j])!=string::npos)
                res[i].second += 1;
            else {}
        }
        res[i].second /= text.length();
    }
    return res;
}

vector<pair<string,string> > ShenonFano(string str){
    vector<pair<string,double> > text = SortByDec(MakeADict(str));
    vector<double> chances;
    vector<pair<string,string> > res;
    chances.push_back(0);
    for (unsigned i = 1; i < text.size(); i++) {
        chances.push_back(text[i-1].second + chances[i-1]);
    }
    pair<string,string> word;
    double kraft = 0;
    double k = 0;
    for (unsigned i = 0; i < text.size(); i++) {
        word.first = text[i].first;
        word.second = ToBin(chances[i], ceil(-log2(text[i].second)));
        k = word.second.length();
        kraft += pow(2, -k);
        res.push_back(word);
    }
    if (kraft<1){
        return res;
    }
    else {
        cout << "Lengths should satisfy Kraft unequality" << endl;
        cout << kraft << endl;
        pair<string,string> kraftt("error","error");
        return {kraftt};
    }
}

bool output(vector<pair<string,string> > array){
    vector<pair<string,string> > Result = array;
    for (unsigned i = 0; i < Result.size(); i++){
    cout << Result[i].first << " = " << Result[i].second <<  endl;
    }
    return true;
}

bool Test(){
    string str = "Cod Sennona-Fano";
    vector<pair<string,string> > shenfan = ShenonFano(str);
    vector<string> should = {"00", "010", "011", "1001", "1010", "1011", "1100","1101","1110","1111"};
    for (unsigned i = 0; i < should.size(); i++){
        if (shenfan[i].second != should[i]){
            cout << "Test failed" << endl;
            return false;
        }
        else{
            
        }
    }
    cout << "Test complited" << endl;
    return true;
}

int main()
{
    Test();
    string str = "Cod Sennona-Fano";
	cout << str << endl;
    output(ShenonFano(str));
    return 1;
}