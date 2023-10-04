#include<iostream>
#include<vector>
using namespace std;

vector<string> s;
vector<string>:: iterator iter;

int main(){
    s.push_back("A1B");
    for(iter= s.begin();iter != s.end();iter++){
        string u = *iter;
        
    }

}