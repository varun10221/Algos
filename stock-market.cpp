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
min2 (int a, int b)
  {
    return a < b ? a : b;
}

int minimum (int a, int b, int c)
   {
    return min2 (min2(a,b),c);
    
}

int
share_maximize (int  *A, int n, int shares, int profit,int end)
{
   /* Base case */ /* rows is no of shares, columns is share price and array is holding value*/
   int ** value;int i,j;
   value = new int* [end + 1]; 
   for (i=0;i<=end; i++)
       value[i] = new int [end+1];
    
    
    for (i=0; i<=end ;i++ )
      {  
        value [i][0] = i * A[j];            
      }
    for (j =1 ; j <=end; j++)
      {
        value [0][j] = 0;
    }  
    
   for (i=1; i<=end; i++)
      {
         for (j = 1; j<= end; j++)
            {
              if (j != end && i<=j+1)
                value [i][j] = (i) * A[j] + value [i][j-1];
              else if (i > j+1)
                  value[i][j] = 0;
              else value[i][j] = (i)*A[j];   
             
              //cout<<value[i][j] <<"  ";             
         }
              //cout<<endl;
      } 
    
    int **profits;
    profits = new int* [end + 1]; 
   for (i=0;i<=end; i++)
       profits[i] = new int [end+1];
    
    for (i=0; i<=end ;i++ )
      {  
        profits [i][0] = 0;            
      }
    for (j =1 ; j <=end; j++)
      {
        profits [j][0] = 0;
    }  
    
    for (i = 1; i<=end;i++ )
      {
        for (j =1; j <=end; j++)
          {
            profits[i][j] = (max2(value[i][j],value[i-1][j]) - min2(value[i-1][j-1],value[i][j-1]));
              
           //  cout<<profits[i][j]<<" ";   
        }
            //cout << endl;
    }
           
  int a = profits[end][end];  
  
    delete []value;
    delete [] profits;
    
    return a;
    
    
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

       int a =  share_maximize (values,0,0,0,cases[i]-1);
       
          if (a > 0)
             cout<<a<<endl;
          else cout<<0<<endl;
          
      }
    
    
    return 0;
}

