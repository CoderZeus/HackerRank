#include <bits/stdc++.h>

using namespace std;



int main()
{
    vector<vector<int>> arr(6);
    for (int i = 0; i < 6; i++) {
        arr[i].resize(6);

        for (int j = 0; j < 6; j++) {
            cin >> arr[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');   

    }


     int sum =0;
        int maxSum=0;
        bool isInitialised = false;
       for (int x = 0; x < 4; ++x )
        {
            for(int y = 0; y < 4; ++y )
                {
                  sum =0;
                  for(int z=0;z<3;++z)
                    {
                        for(int a=0;a<3;++a)
                        {
                            if((x+z<6 )&&(y+a<6))
                            {
                                //System.out.print(arr[x+z][y+a]+" ");
                                if(z==1)
                                {
                                if((a==1))
                                {
                                  sum = sum+arr[x+z][y+a];
                                }
                                }                            
                                else
                                {
                              sum = sum+arr[x+z][y+a];
                                }
                            }
                              
                        }
                        //System.out.println("");
                       
                    }
                   // System.out.println(" x y "+x+y+ "SUM "+sum);


                    if((sum>maxSum)||(!isInitialised))
                    { 
                        isInitialised = true;
                        maxSum= sum;
                       // sum =0;
                       // System.out.println(" x y "+x+y+ "SUM "+maxSum);
                    }
                 }                        
            }
            cout<<(maxSum);

    return 0;
}
