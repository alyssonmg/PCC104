#include <bits/stdc++.h>

int knapSack(int W, int weight[], int value[], int n){ 
    if (n == 0 || W == 0)
    {
        return 0;
    }
    if (weight[n - 1] > W)
    {
        return knapSack(W, weight, value, n - 1);
    }
    else{
        int a = value[n - 1] + knapSack(W - weight[n - 1], weight, value, n - 1);
        int b = knapSack(W, weight, value, n - 1);
        return (a > b) ? a : b;
    }
}

int main()
{
    system("cls");
    int value[] = { 1, 200, 35, 4, 55 };
    int weight[] = { 10, 20, 30, 40, 50 };
    int W = 40;
    int n = sizeof(value) / sizeof(value[0]);
    //std::cout << sizeof(value) << " " << sizeof(value[0]) << std::endl;
    std::cout << knapSack(W, weight, value, n);
    return 0;
}