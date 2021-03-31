//SelectionSort
#include <iostream>
#include<vector>

template <typename T>
void printVector(std::vector<T>& v) //&referencia, não copia o vector
{
    for (auto i = v.begin(); i != v.end(); ++i)
    {
        std::cout << *i << ' ';
    }
    std::cout << std::endl;
}
int main()
{
    system("cls");
    int n, min, i, j, aux;
    std::vector<int> numeros = {12,34,9,78,56};
    n = 5;
    std::cout << "Elementos do vetor: ";
    printVector(numeros);

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
    std::cout << "Elementos ordenados: ";
    printVector(numeros);
}