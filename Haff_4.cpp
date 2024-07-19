#include <iostream>
#include <string>
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

bool output(vector<pair<string,string> > array){
    vector<pair<string,string> > Result = array;
    for (unsigned i = 0; i < Result.size(); i++){
    cout << Result[i].first << " " << Result[i].second << endl; ;
    }
    return true;
}

vector<pair<string,string> > haff(string text){
    vector<pair<string,string> > res;
    vector<pair<string,double> > vec = MakeADict(text);
    pair<string,double> temp;
    unsigned count = vec.size();
    while(vec.size()>1){
        vec = SortByDec(vec);
        temp.first = vec[vec.size()-1].first + vec[vec.size()-2].first;
        temp.second = vec[vec.size()-1].second + vec[vec.size()-2].second;
        vec.erase(vec.end()-1);
        vec[vec.size()-1] = temp;
    }
    pair<string,string> parr;
    parr.first = vec[0].first;
    res.push_back(parr);
    while(res.size()<count){
        for(unsigned i = 0; i < res.size();i++){
            if (res[i].first.length() > 1){
               pair<string,string> temp1 = res[i];
               pair<string,string> temp2 = res[i];
               unsigned len = (res[i].first.length()/2)+(res[i].first.length()%2);
               temp1.first = res[i].first.substr(0,len);
               temp1.second += "0";
               temp2.first = res[i].first.substr(len,res[i].first.length()-1);
               temp2.second += "1";
               res.push_back(temp1);
               res.push_back(temp2);
               res.erase(res.begin()+i);
               break;
            }
            else {};
        }
    }
    return res;
}
bool Test(string str){
    vector<pair<string,string> > vec = haff(str);
    for (unsigned i = 0; i < vec.size(); i++)
        {
            for (unsigned j = i + 1; j < vec.size(); j++)
            {
                bool test = false;
                for (unsigned k = 0; k < vec[i].second.length(); k++)
                {
                    if (vec[i].second[k] != vec[j].second[k])
                        test = true;
                }
                if (!test)
                {
                    cout << "Test failed" << endl;
                    return false;
                }
            }
        }
    cout << "Test complited" << endl;
    return true;
}

int main()
{
    string str = "Is this work?";
    Test(str);
    cout << "Haffman code for string: " << str << endl;
    output(haff(str));
    return 1;
}