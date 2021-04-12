#include <iostream>
#include <stack>
#include <stdlib.h>
using namespace std;
 
struct Point
{
    int x, y;
};
 
//Um ponto global necessário para pontos de classificação com referência ao primeiro ponto. Usado na função de comparação de qsort ()
Point p0;
 
// Uma função de utilidade para encontrar próximo ao topo de uma pilha
Point nextToTop(stack<Point> &S)
{
    Point p = S.top();
    S.pop();
    Point res = S.top();
    S.push(p);
    return res;
}
 
// Uma função de utilidade para trocar dois pontos
void swap(Point &p1, Point &p2)
{
    Point temp = p1;
    p1 = p2;
    p2 = temp;
}
 
//Uma função de utilidade para retornar o quadrado da distância entre p1 e p2
int distSq(Point p1, Point p2)
{
    return (p1.x - p2.x)*(p1.x - p2.x) +
          (p1.y - p2.y)*(p1.y - p2.y);
}
 
// Para encontrar a orientação do tripleto ordenado (p, q, r).
// A função retorna os seguintes valores
// 0 --> p, q, r são colineares
// 1 --> Sentido horário
// 2 --> Sentido anti-horário
int orientation(Point p, Point q, Point r)
{
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);
 
    if (val == 0) return 0;  // colinear
    return (val > 0)? 1: 2; // clock or counterclock wise
}
 
// Uma função usada pela função de biblioteca qsort () para classificar uma matriz de pontos em relação ao primeiro ponto
int compare(const void *vp1, const void *vp2)
{
   Point *p1 = (Point *)vp1;
   Point *p2 = (Point *)vp2;
 
   // Find orientation
   int o = orientation(p0, *p1, *p2);
   if (o == 0)
     return (distSq(p0, *p2) >= distSq(p0, *p1))? -1 : 1;
 
   return (o == 2)? -1: 1;
}
 
// Imprime o casco convexo de um conjunto de n pontos.
void convexHull(Point points[], int n)
{
   // Encontre o ponto mais baixo
   int ymin = points[0].y, min = 0;
   for (int i = 1; i < n; i++)
   {
     int y = points[i].y;
 
     // Escolha o ponto mais abaixo ou mais à esquerda em caso de empate
     if ((y < ymin) || (ymin == y &&
         points[i].x < points[min].x))
        ymin = points[i].y, min = i;
   }
 
   //  Coloque o ponto mais inferior na primeira posição
   swap(points[0], points[min]);
 
   // Sort n-1 points with respect to the first point.
   // A point p1 comes before p2 in sorted output if p2
   // has larger polar angle (in counterclockwise
   // direction) than p1
   p0 = points[0];
   qsort(&points[1], n-1, sizeof(Point), compare);
 
   // If two or more points make same angle with p0,
   // Remove all but the one that is farthest from p0
   // Remember that, in above sorting, our criteria was
   // to keep the farthest point at the end when more than
   // one points have same angle.
   int m = 1; // Initialize size of modified array
   for (int i=1; i<n; i++)
   {
       // Continue removendo i enquanto o ângulo de i e i + 1 é o mesmo em relação a p0
       while (i < n-1 && orientation(p0, points[i],
                                    points[i+1]) == 0)
          i++;
 
 
       points[m] = points[i];
       m++;  // Update size of modified array
   }
 
   // Se a matriz modificada de pontos tiver menos de 3 pontos, o casco convexo não é possível
   if (m < 3) return;
 
   // Cria uma pilha vazia e empurre os primeiros três pontos para ela.
   stack<Point> S;
   S.push(points[0]);
   S.push(points[1]);
   S.push(points[2]);
 
   // Process remaining n-3 points
   for (int i = 3; i < m; i++)
   {
      // Continue removendo o topo enquanto o ângulo formado pelos pontos próximo ao topo, topo e pontos [i] faz uma curva não para a esquerda
      while (S.size()>1 && orientation(nextToTop(S), S.top(), points[i]) != 2)
         S.pop();
      S.push(points[i]);
   }
 
   // Agora a pilha tem os pontos de saída, imprime o conteúdo da pilha
   while (!S.empty())
   {
       Point p = S.top();
       cout << "(" << p.x << ", " << p.y <<")" << endl;
       S.pop();
   }
}
 
// Programa de driver para testar as funções acima
int main()
{
    Point points[] = {{0, 3}, {1, 1}, {2, 2}, {4, 4}, {0, 0}, {1, 2}, {3, 1}, {3, 3}};
    int n = sizeof(points)/sizeof(points[0]);
    convexHull(points, n);
    return 0;
}