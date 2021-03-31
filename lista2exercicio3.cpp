//SequentialSearch2
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
    int n, min, i, j, K, aux;
    std::vector<int> numeros = {1, 23, 34, 56, 78, 901, 234};
    n = 7;
    std::cout << "Elementos do vetor: ";
    printVector(numeros);

std::cout << "Digite o numero a ser pesquisado na lista: ";
std::cin >> K;
numeros[n] = K;
i = 0;
while (numeros[i] != K) 
    {
        i = i +1;
    }
if (i < n) 
    {
        std::cout << "O numero " << K<< " esta na posicao " << i+1 << std::endl;
    }
else
    {
        std::cout << "O numero " << K<< " nao esta na lista" << std::endl;
    }
}