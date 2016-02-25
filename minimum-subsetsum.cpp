#include <iostream>


using namespace std;

bool
minimum_subsum (int *A, int start, int end, int sum)
{

  int i;
  bool sum_array [sum + 1][end + 1];
  for (i = 0; i <= end; i++)
     sum_array[0][i] = true;

  for (i = 1; i <= sum; i++)
    sum_array[i][0] = false;

  int j;
 
  for (i = 1; i <= sum; i++)
    {
      for (j = 1; j <= end; j++)
        {
           sum_array[i][j] = sum_array[i][j-1];
          
           if (i >= A[j-1])
             sum_array [i][j] = sum_array [i][j] || sum_array[i - A[j-1]][j-1];
         }
    }

    for (i = 0; i <= sum; i++)
     {
       for (j = 0; j <= end; j++)
          cout <<sum_array[i][j] <<"  ";

       cout<<endl;
     }



    return sum_array [sum][end];

}



int
main ()
{

  int sum, start, end;
  cout <<"Enter the sum:";
  cin  >> sum;
  cout << endl <<"Enter the no of elements";
  cin >> end;
  
  int *A = new int [end];

  if (!A)
   return 0;
 
  for (int i = 0; i < end; i++)
    cin>> A[i];

  
  cout<<minimum_subsum (A,0,end-1,sum);

  return 0;

}



  
  













