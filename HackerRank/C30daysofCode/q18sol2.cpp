#include <cmath>
#include <iostream>
#include <exception>
#include <stdexcept>
using namespace std;

//Write your code here
class Calculator
{
    public:
    int power(int n ,int p) 
    {
        int val =0;       
        
            if(n < 0 || p < 0 )
            {
              throw std::logic_error("n and p should be non-negative");//"test" ;
            }
            else
            {
                val = pow(n,p); 
               
            }       
               
       return val;
    }
};

int main()
{
    Calculator myCalculator=Calculator();
    int T,n,p;
    cin>>T;
    while(T-->0){
      if(scanf("%d %d",&n,&p)==2){
         try{
               int ans=myCalculator.power(n,p);
               cout<<ans<<endl; 
         }
         catch(exception& e){
             cout<<e.what()<<endl;
         }
      }
    }
    
}
