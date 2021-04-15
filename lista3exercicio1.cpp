//InsertionSort
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
    int n, i, j, aux;
    std::vector<int> numeros = {5, 7, 4, 6, 2, 3, 1, 0, 9, 8};
    n = 10;
    std::cout << "Elementos do vetor: ";
    printVector(numeros);

    for (i = 1; i < n - 1; i++)
    {
     aux = numeros[i];
        j = i - 1;
     while (j >= 0 && aux < numeros[j])
        {
         numeros[j + 1] = numeros [j];
            j--;
        }
    numeros[j + 1] = aux;
    }
std::cout << "Elementos ordenados: ";
printVector(numeros);
}