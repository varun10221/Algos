#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>

using namespace std;


int minimum2 (int x,int y) { 
    return x<y ?x:y;
}

int minimum3 (int x,int y,int z) {
    return minimum2 (minimum2(x,y),z);
}

int
editDistance (string s1, string s2, int m, int n)
{
  
   if(m == 0)
     return n;

   if (n == 0)
     return m;

   if (s1[m] == s2[n])
     return editDistance (s1,s2, m-1,n-1);

   
   return (1 + minimum3 ((editDistance (s1,s2,m,n-1)),
                    (editDistance (s1,s2,m-1,n)),
                    (editDistance (s1,s2,m-1,n-1)))); 
 
     
}

int
main ()
{
  
  string s1 = "Piedpiper";
  string s2 = "liedleeper";
  
  cout<< editDistance (s1, s2 , s1.length(), s2.length());
  
  return 0;

}

