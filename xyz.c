#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define memcpy_malloc(t,...) memcpy(malloc(sizeof t),t{__VA_ARGS__},sizeof t)
#define CAR(x) *(char**)((long)(x))
#define CDR(x) *(char**)((long)(x)+sizeof(char*))
#define RPLACD(x,y) (((CDR(x)=y),x))
#define cons(x,y) _cons((char*)(x),(char*)(y))
#define car(x) _car((char*)(x))
#define cdr(x) _cdr((char*)(x))
#define rplacd(x,y) _rplacd((char*)(x),(char*)(y))
#define princ(x) _princ((char*)(x))
#define print(x) terpri(princ(x))
char*  _cons(char*x,char*y){return memcpy_malloc((char*[2]),x,y);}
char*  _car (char*x){return x? *(char**)(x):0;}
char*  _cdr (char*x){return x? *(char**)(x+sizeof(char*)):0;}
char*  _rplacd(char*x,char*y){ *(char**)(x+sizeof(char*)) = y; return x; }
char*   terpri(char*x){puts("");return x;}
char*  _princ(char*x){
  return(((unsigned long)x < (unsigned long)1024)
    ?(printf("%lx",(long)x))
    :(printf( "(" ),_princ(CAR(x)),
      printf(" . "),_princ(CDR(x)),
      printf( ")" ))),x;}
char*xnreverse2(char*x,char*y){return(!x)?y:xnreverse2(cdr(x),  rplacd(x ,y));}
char* xreverse2(char*x,char*y){return(!x)?y:xnreverse2(cdr(x),cons(car(x),y));}
char*xnreverse (char*x       ){return     xnreverse2(x,0);}
char* xreverse (char*x       ){return      xreverse2(x,0);}
int main(){
  print(0);
  print(xnreverse(0));
  print(cons(1,0));
  print(xnreverse(cons(1,0)));
  print(cons(1,cons(2,0)));
  print(xnreverse(cons(1,cons(2,0))));
  //print(cons(1,cons(2,cons(3,0))));
  //print(xnreverse(cons(1,cons(2,cons(3,0)))));
  //print(cons(1,cons(2,cons(3,cons(4,0)))));
  //print(cons(1,cons(2,cons(3,cons(4,cons(5,0))))));
  //print(cons(1,cons(2,cons(2,cons(4,cons(5,cons(6,0)))))));
  //print(xnreverse(cons(1,cons(2,cons(2,cons(4,cons(5,cons(6,0))))))));
  return 0;}
