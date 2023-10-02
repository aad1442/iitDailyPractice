#include <iostream>
#include <fstream>
#include <map>
using namespace std;
#define max 20
int vertices;
int edges;
int graph[max][max] = {0};
map<int, string> m;

void read()
{
    ifstream file("kurskal.txt");
    if (!file)
    {
        cerr << "No file";
        exit(1);
    }
    file >> vertices >> edges;

    for (int i = 0; i < vertices; i++)
    {
        file >> m[i];
    }

    for (int i = 0; i < edges; i++)
    {
        string u, v;
        int x, y, w;
        file >> u >> v >> w;
        for (auto i : m)
        {
            if (i.second == u)
            {
                x = i.first;
            }
            if (i.second == v)
            {
                y = i.first;
            }
        }
        graph[x][y] = w;
    }
}

void print()
{
    cout << vertices << " " << edges << endl;
    for (auto i : m)
    {
        cout << i.second << " ";
    }
    cout << endl;

    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            if (graph[i][j] != 0)
            {
                cout << m[i] << " " << m[j] << " " << graph[i][j] << endl;
            }
        }
    }
}

int main(){
    read();
    print();
}


