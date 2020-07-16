#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n=0;
    cin>>n;
    map<string,int>dataMap = map<string,int>();
    string name="";
    int value =0;
    for(int i=0;i<n;++i)
    {
        cin>>name>>value;
        // cin.gets(name);
      // cin.gets(value);

      // gets(cin,name);
       //gets(cin,value);

       dataMap.insert(std::pair<string,int>(name,value));
    }
    cin.ignore();
    map<string,int>::iterator it = dataMap.begin();
    while(getline(cin,name))
    {
        it = dataMap.find(name);
        if(it!=dataMap.end())
        cout<<name<<"="<<it->second<<endl;
        else
        cout<<"Not found"<<endl;
    }
    return 0;
}
