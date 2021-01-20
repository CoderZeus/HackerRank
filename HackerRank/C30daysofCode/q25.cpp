#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


bool checkPrime(int number)
{
    if(number == 1 || number ==0 )
    return false;
   //for (int i=2;i<= number/2; ++i )
   for(int i=2;i<=sqrt(number);++i)
   {
       if( number % i == 0)
         return false;
   }    
   return true;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int num_count =0;
    cin >>num_count;
    
    int number;
    for(int j=0;j< num_count;++j)
    {
        cin >>number;
        if(checkPrime(number) ==true)
          cout<<"Prime "<<endl;
        else 
          cout<<"Not prime"<<endl;
        
    }   
    return 0;
}
