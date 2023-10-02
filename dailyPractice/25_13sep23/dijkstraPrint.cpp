#include <iostream>
#include <stdio.h>
#include <queue>
#include <string>
#include <vector>

using namespace std;

#define SIZE 100
#define INFINITY 1000000

int w[SIZE][SIZE], d[SIZE], previous[SIZE]; // Changed prv to previous
int n = 0;
bool flag[SIZE];
string name[SIZE];

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void initialize_single_source(int s)
{
    for (int v = 0; v < n; v++)
    {
        d[v] = INFINITY;
        previous[v] = -1;
    }
    d[s] = 0;

    pq.push(make_pair(0, s));
}

void relax(int u, int v)
{
    if (d[v] > d[u] + w[u][v])
    {
        d[v] = d[u] + w[u][v];
        previous[v] = u;

        pq.push(make_pair(d[v], v));
    }
}

int extract_min()
{
    int m = INFINITY, index = -1;

    for (int i = 0; i < n; i++)
    {
        if (flag[i] && m > d[i])
        {
            m = d[i];
            index = i;
        }
    }
    return index;
}

void dijkstra(int s)
{
    initialize_single_source(s);

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        for (int v = 0; v < n; v++)
        {
            if (w[u][v] > 0)
            {
                relax(u, v);
            }
        }
    }
}

void readInput()
{
    int u, v;
    string s;
    while (cin >> s)
    {
        if (s == "END")
            break;

        for (u = 0; u < n; u++)
        {
            if (name[u] == s)
                break;
        }
        if (u == n)
        {
            name[n] = s;
            n++;
        }

        cin >> s;
        for (v = 0; v < n; v++)
        {
            if (name[v] == s)
                break;
        }
        if (v == n)
        {
            name[n] = s;
            n++;
        }

        cin >> w[u][v];
    }
}

void printGraph()
{
    int u, v;
    for (u = 0; u < n; u++)
    {
        for (v = 0; v < n; v++)
        {
            cout << w[u][v] << " ";
        }
        cout << "\n";
    }
}

void printShortestPath(int source, int destination)
{
    if (d[destination] == INFINITY)
    {
        cout << "No path from " << name[source] << " to " << name[destination] << " exists." << endl;
        return;
    }

    cout << "Shortest path from " << name[source] << " to " << name[destination] << ": ";
    vector<int> path;
    int current = destination;

    while (current != source)
    {
        path.push_back(current);
        current = previous[current];
    }

    cout << name[source];
    for (int i = path.size() - 1; i >= 0; i--)
    {
        cout << " -> " << name[path[i]];
    }

    cout << " (Total distance: " << d[destination] << ")" << endl;
}

int main()
{
    freopen("input.txt", "r", stdin);
    readInput();
    printGraph();
    printf("sumon");

    int source, destination;
    cout << "Enter source and destination vertices: ";
    cin >> source >> destination;

    dijkstra(source);
    printShortestPath(source, destination);

    return 0;
}
