#include <bits/stdc++.h>
    using namespace std;
    
    int found = 0;
    string path="",path2="";
    void cfg(vector<string> &base, string output, string target, string currpath)
    {
        if (found==2)
            return;
        
        if(output.size()>target.size()+3)
        return;

        if (output.find('P') == string::npos && output != " ")
        {
            if(output.find('E')!=string::npos)
            {
                string temp = output.substr(0, output.find('E'));
                temp+=output.substr(output.find('E')+1);
                output=temp;
            }
            if (output == target)
            {
                found++;
                if(found=1)
                path = currpath;

                if(found=2)
                path2 = currpath;
            }
            if(found = 2)
                return;
        }
        
        for (string x : base)
        {
            if (output.find('P') != string::npos)
            {
                string temp = output.substr(0, output.find('P'));
                temp += x;
                temp += output.substr(output.find('P') + 1);
                x = temp;
            }
            cfg(base, x, target, currpath+"->"+x);
            if(found=2) return;
        }
    }
    
    int main()
    {
        vector<string> base = { "E", "aS", "aSbS" };
        string s;
        cin >> s;
        cfg(base, " ", s, path);
        (found==2) ? cout << "Yes" : cout << "no";
        cout<<endl;
        if(found==2)
        {
            if(path.find('E')!=string::npos){
            string temp = path.substr(0, path.find('E'));
            temp+=path.substr(path.find('E')+1);
            path=temp;
            }
            
            cout<<"S"+path<<endl;
        }
        cout<<"found"<<found<<path<<" " << path2<< "A"<<endl;
        return 0;
    }