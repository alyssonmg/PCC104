
#include <iostream>

using namespace std;

int main ()
{
int n, i, j, aux, min;
cout << "Digite a quantidade de elementos para ordenar: ";
cout << "\n";
cin >> n;
double numeros[n];

for (i=0; i<n; i++)
    {
    cout << "Digite o " << i + 1<< "o. numero: ";
    cin >> numeros[i];
    }
cout << "Elementos ordenados conforme digitacao: ";
for (i = 0; i <n; i++)
    {
    cout << numeros[i] << " ";
    }
cout << "\n";
//Ordenando os elementos digitados
for (i = 0;i < n-1; i++)
    {
    min = i;
    for (j = i+1; j <= n; j++)
        {
        if(numeros[j] < numeros[min])
            {
            min = j;
            }
        }
    aux = numeros[min];
    numeros[min] = numeros [i];
    numeros[i] = aux;
    }
cout << "Elementos ordenados de forma crescente: ";
for (i = 0; i <n; i++)
    {
    cout << numeros[i] << " ";
    }
}
