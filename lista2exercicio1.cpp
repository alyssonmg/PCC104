//BubbleSort
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
    std::vector<int> numeros = {123,34,90,78,56,111,2};
    n = 7;
    std::cout << "Elementos do vetor: ";
    printVector(numeros);

for (j = 1;j < n; j++){
    for (i = 0; i < n - 1; i++){
        if(numeros[i] > numeros[i + 1]){
            aux = numeros[i];
            numeros[i] = numeros [i + 1];
            numeros[i + 1] = aux;
        }
    }
}
    std::cout << "Elementos ordenados: ";
    printVector(numeros);
}