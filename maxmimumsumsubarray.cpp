#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;



int
maximum (int a,int b, int c, int d, int e)
{
   int max1 = a > b?a:b;
   int max2 = c>d?c:d;
   int max3 = max1>max2?max1:max2;
   
    return max3>e ? max3:e;
    
    
}    

int 
maximum_subarray (int **A, int T, int start, int end,int sum)
{

   /* Base case */
   if (start == end)
     return A[T][start] + sum;  
    

   if (start>end)
    return sum;
    
   return maximum (maximum_subarray (A,T,start+1,end,sum + A[T][start]),
                   maximum_subarray (A,T,start+1,end,sum),
                   maximum_subarray (A,T,start,end-1,sum),
                   maximum_subarray (A,T,start,end-1,sum+A[T][end]),
                   maximum_subarray (A,T,start+1,end-1,sum+A[T][end]+A[T][start]));
          
}    
    


int 
main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    
    
    int T;
    int N;
    cin>>T;
    
    int i = 0;
    int loop_count = T;
    int **Array = new int* [T];
            
    for (int k = 0; k < loop_count; k++)
      {  
        cin>>N;
        Array[k] = new int [N];
        
        for (i = 0; i < N; i++)
          {
            cin >> Array[k][i];
         }
    
        cout<<maximum_subarray (Array,k,0,N-1,0);
      }
    
    
    
    return 0;
}

