/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <math.h>
using namespace std;

class Point{
    public:
    double x, y;
    void import(){
       cin >> x >> y; 
    }
};
 class Line { 
    public:
    double a, b;
    Line ( Point P1, Point P2){
        a=(P1.y-P2.y)/(P1.x-P2.x);
        b=(P1.y-P1.x*a);
    }
};
 void findIntersectionPoint (Line L1, Line L2){
     if (L1.a==L2.a&&L1.b==L2.b){
         cout<< "MANY";
     }else if(L1.a==L2.a&&L1.b!=L2.b){
         cout <<"NO";
     }else{
         double x,y;
         x=(L1.b-L2.b)/(L2.a-L1.a);
         y=(L1.a*x-L1.b);
        printf("%.2f %.2f",x,y);
     }     
}
int main(){
    Point A, B, C, D;
    A.import();
    B.import();
    C.import();
    D.import();
    
     Line AB(A,B);
     Line CD(C,D);
    
    findIntersectionPoint(AB, CD);
    
    return 0;
}