#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

void
printMaxActivity (int start [], int end [], int n)
{

  int i, j ;
  i = 0;
  cout << i;
  
  for (j = 1; j < n; j++)
  {
    if (start[j] >= end [i]){
      cout<< j;
      i = j;
    }
  }

}

int main (){

  int  start [] = {1,3,0,5,8,5};
  int end [] = {2, 4, 6, 7, 9, 9};
  int n = 6;
  printMaxActivity (start, end, n);
  return 0;
}


 





