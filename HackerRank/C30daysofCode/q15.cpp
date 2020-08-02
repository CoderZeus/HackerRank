#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Difference {
    private:
    vector<int> elements;
  
  	public:
  	int maximumDifference;


     Difference(vector<int> data)
     {
         elements = data;
     } 

     void computeDifference()
     {

        int maxValue=0;
        int minValue=0;
        for (int i =0;i< elements.size();++i)
        {
           if(elements[i]>elements.at(maxValue))
            maxValue = i;

           else if (elements[i]<elements.at(minValue))
            minValue = i;
        }

        maximumDifference = elements[maxValue]-elements[minValue];
     }

	// Add your code here
    

}; // End of Difference class

int main() {
    int N;
    cin >> N;
    
    vector<int> a;
    
    for (int i = 0; i < N; i++) {
        int e;
        cin >> e;
        
        a.push_back(e);
    }
    
    Difference d(a);
    
    d.computeDifference();
    
    cout << d.maximumDifference;
    
    return 0;
}