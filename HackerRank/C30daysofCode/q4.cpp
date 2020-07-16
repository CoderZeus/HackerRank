#include <bits/stdc++.h>

using namespace std;



int main()
{
    int N;
    cin >> N;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
     if((N>0)&&(N<101))
        {
           if(N%2==1)
            cout<<"Weird";
           else if ( (N>=2)&&(N<5) )
            cout<<"Not Weird";
            else if ( (N>=6)&&(N<=20) )
            cout<<"Weird";
             else if ( (N>20))
            cout<<"Not Weird";
            

        }
        else
          cout<<"Weird"; 
    return 0;
}
