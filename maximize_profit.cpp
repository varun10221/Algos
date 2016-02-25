#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;




int 
max2 (int a, int b)
  {
    return a > b ? a : b;
}

int maximum (int a, int b, int c)
   {
    return max2 (max2(a,b),c);
    
}  

int
share_maximize (int  *A, int n, int shares, int profit,int end)
{
   /* Base case */ 
   if(n > end)
    return profit;
    
   if (n == 0)
     profit = profit + shares * A[n];
   else  
     profit = profit + shares * (A [n] -A[n-1]); 
    
   return maximum (share_maximize (A,n+1,shares,profit,end),
                   share_maximize (A,n+1,shares + 1,profit,end),
                   share_maximize (A,n+1,0,profit,end)); 
    
  
    
}    


    


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int N,T;
    int *values, *cases;
    cin >>T;
    cases = new int [T];
    
    int i,j;

    for (i=0; i<T; i++)
      {
         cin>>cases[i];
                 
         values = new int [cases[i]];
         for (j =0; j < cases[i]; j++)
            cin>>values[j];

        cout<<share_maximize (values,0,0,0,cases[i]-1)<<endl;
      }
    
    
    return 0;
}

