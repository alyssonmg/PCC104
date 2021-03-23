# include < iostream >
using namespace std ;

int main (){
  int numero1 ;
  int numero2 ;
  int r;
  cout << "Digite␣o␣primeiro␣número:␣";
  cin >> numero1 ;
  cout << "Digite␣o␣segundo␣número:␣";
  cin >> numero2 ;
  r = numero1 + numero2 ;
  cout << "Adição␣dos␣números␣=␣" << r << endl ;
  r = numero1 - numero2 ;
  cout << "Subtração␣dos␣números ␣=␣" << r << endl ;
  r = numero1 * numero2 ;
  cout << "Multiplicação␣dos␣números ␣=␣" << r << endl ;
  r = numero1 / numero2 ;
  cout << "Divisão␣dos␣números ␣=␣" << r << endl ;
  r = numero1 % numero2 ;
  cout << "Resto␣da␣divisão␣=␣" << r << endl ;
  return 0;
 }
