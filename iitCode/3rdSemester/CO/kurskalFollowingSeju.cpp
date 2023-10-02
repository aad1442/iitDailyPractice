#include<iostream>
#include<vector>
#include<set>

using namespace std;

int numVertices, numEdges;
set<pair<int,pair<char,char>>> edges;
set<pair<int,pair<char,char>>> A;
vector<set<char>> sets;


int findSet(char u){
    int count = 0;
    for(auto a: sets){
        for(auto b:a ){
            if(b == u){
                return count;
            }
        }
        count++;
    }
}