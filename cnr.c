#include<stdlib.h>
#include<string.h>
#define memcpy_malloc(t,...) memcpy(malloc(sizeof(t)),(t){x,y},sizeof(t))
typedef char*nod[2];
#define CAR(x) (*(char**)(x))
#define CDR(x) (*(char**)(x+sizeof(char*)))
char*pile[102400];
char**next=(void*)pile;
char* _cons(char*x,char*y){
  char**z = next;
  next += 1;
  z[0] = x;
  z[1] = y;
  return(char*)z;}
#define cons(x,y) _cons((char*)(long)(x),(char*)(long)(y))
char*   car(char*x       ){ return!x?x:CAR(x);}
char*   cdr(char*x       ){ return!x?x:CDR(x);}
char*rplaca(char*x,char*y){ return    (CAR(x)=y),x;}
char*rplacd(char*x,char*y){ return    (CDR(x)=y),x;}
char*xnreverse2 (char*x,char*y){return!x?y:xnreverse2(cdr(x), rplacd(  x,  y));}
char* xreverse2 (char*x,char*y){return!x?y: xreverse2(cdr(x), cons(car(x), y));}
char*xnreverse  (char*x       ){return     xnreverse2(    x,  0);}
char* xreverse  (char*x       ){return      xreverse2(    x,  0);}
#include<stdio.h>
char*terpri(char*x){puts(""); return x;}
char*princ(char*x){
  printf("<<%lx>>", (long)x);
  return x;}
char*_print(char*x){return terpri(princ(x));}
#define print(x) _print((char*)(long)(x))
int main(){
  print(0L);
  print(1L);
  print(2L);
  print(3L);
  print(4L);
  print(0L);
  //_cons(1L, 0L);
  //print(cons(1L, cons(2L, 0L)));
  //print(cons(1, cons(2, cons(3, 0))));
  //print(cons(1, cons(2, cons(3, cons(4, 0)))));
  //print(cons(1, cons(2, cons(3, cons(4, cons(5, 0))))));
  //print(cons(1, cons(2, cons(3, cons(4, cons(5, cons(6, 0)))))));
}
