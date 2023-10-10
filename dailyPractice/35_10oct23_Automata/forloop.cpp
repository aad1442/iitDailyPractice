#include <bits/stdc++.h>
using namespace std;

bool found = false;
string path;
void cfg(vector<string> &base, string output, string target, string currpath)
{
    if (found)
        return;

    if (output.size() > target.size() + 2)
        return;

    if (output.find('S') == string::npos && output != " ")
    {
        while(output.find('E') != string::npos)
        {

            if (output.find('E') != string::npos)
            {
                string temp = output.substr(0, output.find('E'));
                temp += output.substr(output.find('E') + 1);
                output = temp;
            }
        }

        if (output == target)
        {
            found = true;
            path = currpath;
        }
        return;
    }

    for (string x : base)
    {
        if (output.find('S') != string::npos)
        {
            string temp = output.substr(0, output.find('S'));
            temp += x;
            temp += output.substr(output.find('S') + 1);
            x = temp;
        }
        cout << x << endl;
        cfg(base, x, target, currpath + "->" + x);
        if (found)
            return;
    }
}

int main()
{
    vector<string> base = {"E", "aS", "aSbS"};
    string s;
    cin >> s;
    cfg(base, "S", s, path);
    found ? cout << "Yes" : cout << "no";
    cout << endl;
    if (found)
    {
        if (path.find('E') != string::npos)
        {
            string temp = path.substr(0, path.find('E'));
            temp += path.substr(path.find('E') + 1);
            path = temp;
        }

        cout << "S" + path << endl;
    }
    return 0;
}