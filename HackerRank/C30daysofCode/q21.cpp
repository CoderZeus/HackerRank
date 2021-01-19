#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int a_i = 0; a_i < n; a_i++){
    	cin >> a[a_i];
    }
    // Write Your Code Here
    int swap_count =0;
    int swap_variable = 0;
    int array_size = a.size();
    for (int j=0; j< array_size;++j)
        for ( int i=0;i+1 < array_size; ++i)
        {
            if(a[i] > a[i+1])
            {
                swap_variable = a[i];
                a[i] = a[i+1];
                a[i+1]= swap_variable;
                swap_count++;
            }
        }
    cout<<"Array is sorted in "<<swap_count<<" swaps."<<endl;    
    cout<< "First Element: "<<a[0]<<endl;
    cout<<"Last Element: "<<a[array_size-1]<<endl;
        
    return 0;
}
