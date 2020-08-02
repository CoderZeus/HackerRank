#include <bits/stdc++.h>

using namespace std;

string convertToString(int a)
{
    stringstream ss;
    ss<<a;
    return ss.str();
}


int main()
{
    int n;
    int value=0;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string pattern="";
    for (int i=n;i>=1;i=i/2)
    {
     value = i%2;
     pattern+=convertToString(value); 
    }
    
    value =-1;
    int max =0;
    int count =0;
    for(int i=0;i<pattern.length();++i)
    {
      if(pattern.at(i)=='1')
      {
        ++count;
      }
      else 
      {
          if(count>max)
           max =count;

          count =0;
          value = i;
      }    

    }
    if(count>max)
           max =count;
     cout<<max;
    return 0;
}
