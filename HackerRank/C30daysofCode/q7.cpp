#include <iostream>
#include <string>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n =0;
    cin>>n;
    cin.ignore();
    string s1,sEven,sOdd;
    //cout<<" N is "<<n;
    for(int i =0;i<n;++i)
    {
        s1="";
      getline(cin,s1);
      //cout<<"read string is "<<s1;
      sEven ="";
      sOdd="";
      for(int i =0;i<s1.length();++i)
      {
          if(i%2==0)
            sEven.push_back(s1.at(i));
          else
            sOdd.push_back(s1.at(i));
      }
      cout<<sEven<<" "<<sOdd<<endl;
    }


    return 0;
}
