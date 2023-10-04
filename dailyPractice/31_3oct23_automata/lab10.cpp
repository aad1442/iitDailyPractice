#include<iostream>
#include<map>
#include<vector>
using namespace std;
map<string,vector<string>>a;

int main(){
    a["S"].push_back("A1B");
    a["A"].push_back("0A");
    a["A"].push_back("e");
    a["B"].push_back("0B");
    a["B"].push_back("1B");
    a["B"].push_back("e");

   string input;
   cin>> input;
   int l = input.size();
   int index=l-1;
   for(int i=0;i<l;i++){
        if(input[i]=='1'){
            index = i;
            break;
        }
    
   }
   cout<< index<<endl;
   string A= input.substr(0,index);
   string B= input.substr(index+1,l);
   cout<< A<< "  "<< B<<endl;

   string left="A1B";
   cout<<"Leftmost"<<"-->"<<left<<"-->";
   for(int i=0;i<=A.size();i++){
    if(i==A.size()){
        left.replace(0+i,1,"");
        cout<<left<<"-->";
    }
    else{
        left.replace(0+i,1,"0A");
        cout<<left<<"-->";
    }
   }


   for(int i=0;i<=B.size();i++){
    if(i==B.size()){
        left.replace(A.length()+i+1,1,"");
        cout<<left<<endl;
    }
    else if(B[i]=='0'){
        left.replace(A.length()+i+1,1,"0B");
        cout<<left<<"-->";
    }
    else if(B[i]=='1'){
        left.replace(A.length()+i+1,1,"1B");
        cout<<left<<"-->";
    }

   }

 

   string right="A1B";
   cout<<"Rightmost"<<"-->"<<right<<"-->";
   


   for(int i=0;i<=B.size();i++){
    if(i==B.size()){
        right.replace(2+i,1,"");
        cout<<right<<"-->";
    }
    else if(B[i]=='0'){
        right.replace(2+i,1,"0B");
        cout<<right<<"-->";
    }
    else if(B[i]=='1'){
        right.replace(2+i,1,"1B");
        cout<<right<<"-->";
    }

   }

   for(int i=0;i<=A.size();i++){
    if(i==A.size()){
        right.replace(0+i,1,"");
        cout<<right<<endl;
    }
    else{
        right.replace(0+i,1,"0A");
        cout<<right<<"-->";
    }
   }





}
