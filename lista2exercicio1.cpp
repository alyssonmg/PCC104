#include <iostream>

using namespace std;

int main ()
{
const int n = 6;
double numeros[n];
int i, j, aux;
cout << "Digite seis numeros aleatorios:\n";
for (i=0; i<n; i++)
    {
    cout << "Digite o " << i + 1<< "o. numero: ";
    cin >> numeros[i];
    }
cout << "Elementos ordenados conforme digitacao: ";
for (i = 0; i <n; i++){
    cout << numeros[i] << " ";
}
cout << "\n";
for (j = 1;j < n; j++){
    for (i = 0; i < n - 1; i++){
        if(numeros[i] > numeros[i + 1]){
            aux = numeros[i];
            numeros[i] = numeros [i + 1];
            numeros[i + 1] = aux;
        }
    }
}
cout << "Elementos ordenados de forma crescente: ";
for (i = 0; i <n; i++){
    cout << numeros[i] << " ";
}
}