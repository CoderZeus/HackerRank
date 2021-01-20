#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;



int getFine(int d1,int m1,int y1,int d2,int m2,int y2)
{
     if( y1 < y2)
      {
          return 0;
      }
      else if( y1 == y2)
      {
          if( m1 < m2 )
          {
              return 0;
          }
          else if( m1 ==m2 )
          {
              if( d1 <= d2)
              {
                  return 0 ;
              }
             
              else
              {
                  return int (float (d1-d2)*15 );
              }
          }
          else
          {
             return int (float (m1-m2)*500 );
          }           
          
      }
      else 
      
      {
          return 10000;
      }
      
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int d1,m1,y1; //return date
    int d2,m2,y2; //due date
    
    cin >>d1>>m1>>y1;
    cin >>d2>>m2>>y2;
    
    cout<<getFine(d1,m1,y1,d2,m2,y2);
    
    
    
    
    
    
     
    return 0;
}
