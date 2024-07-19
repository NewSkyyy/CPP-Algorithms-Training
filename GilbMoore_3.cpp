#include <iostream>
#include <string>
#include<cmath>
#include <vector>
using namespace std;

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

vector<pair<string,string> > GilbertMoore(string str){
    vector<pair<string,double> > text = MakeADict(str);
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
        word.second = ToBin(chances[i]+text[i].second/2, ceil(-log2(text[i].second/2)));
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
    string str = "caaaaaabbb";
    vector<pair<string,string> > shenfan = GilbertMoore(str);
    vector<string> should = {"00001", "01", "110"};
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
    string str;
    cin >> str;
    output(GilbertMoore(str));
    return 1;
}