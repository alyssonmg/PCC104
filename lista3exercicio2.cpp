#include <bits/stdc++.h>
#include<iostream>

void printPermutation(int n)
{
    int a[n]; 
    //construir o vetor de n elementos  
    for (int i = 0; i < n; i++)
    {
        a[i] = i + 1;
        std::cout << a[i];
    }
    std::cout << endl;
  
    bool dir[n];
    // initially all directions are set to RIGHT TO LEFT i.e. 0.
    //for (int i = 0; i < n; i++)
        //dir[i] =  RIGHT_TO_LEFT;
  
    // for generating permutations in the order.
    //for (int i = 1; i < fact(n); i++)
        //printOnePerm(a, dir, n);
}

int main()
{
    int n = 4;
    printPermutation(n);
    return 0;
}