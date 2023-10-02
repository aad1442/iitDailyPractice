#include<iostream>
using namespace std;

int main() {
    string s;
    string m ;
    cin >> s;
    int l = s.length();

    for (int i = 0; i < l; i++) {
        cout << s[i] << "  ";
    }
    if(l%2){
          m = s[l/2];
    }else{
        m = '\0';
    }
    cout<< "|"<< m<< "|";

}
