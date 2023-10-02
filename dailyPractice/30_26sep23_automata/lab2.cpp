#include <iostream>
#include <map>

using namespace std;

int main() {
    string s,m;
    cin >> s;
    int l = s.length();

    map<string, string> arr;
    arr["e"] = "p";
    arr["0"] = "p";
    arr["1"] = "p";
    arr["0p0"] = "p";
    arr["1p1"] = "p";


    if(l%2){
          m = s[l/2];
    }else{
        m = 'e';
    }
    //cout<<s<<endl;
    cout<< l<< endl;
    cout<< m << endl;
    cout << arr[m]<<endl;
    cout<< s.substr(0,l/2)<<endl;
    cout<< s.substr(l/2+1,l)<<endl;
    s = s.substr(0, l / 2) + arr[m] + s.substr(l / 2 + 1, l);
    cout<< s;

    return 0;
}
