//BruteForceStringMatch
#include <iostream>
#include <stdlib.h>
#include<conio.h>
#include<vector>

using namespace std;

int main ()
{
int n, m, i, j, k;
system("cls");

n = 25;
m = 3;
//char T[n], P[m];
system("cls");
    char T[n] = {"PROJETO ANALISE ALGORITMO"};
    char P[m] = {"JET"};
    std::cout << "TEXTO: " << T << std::endl;
    std::cout << "TEXTO A SER PESQUISADO: " << P << std::endl;
for (i = 0; i < n - m; i++)
    {
    j = 0; 
    while (j < m && P[j] == T[i+j])
            {
                j = j + 1;
            }
    
    if (j == m)
        {
            k = i;
        }
    }
    
std::cout << "Posicao do texto pesquisado: " << k;
}
