#include<stdio.h>
typedef char**nod;
const char*Cells[1024];
const char**Cell2=(void*)&Cells+sizeof(Cells);
int  Next = -1;
#define CAR(x) ((nod)(((nod)(x))[0]))
#define CDR(x) ((nod)(((nod)(x))[1]))
#define PUSHNOD(x) (Cells[++Next] = (char*)(x))
#define cons(x,y) _cons((nod)(x),(nod)(y))
#define rplaca(x,y) _rplaca((nod)(x),(nod)(y))
#define rplacd(x,y) _rplacd((nod)(x),(nod)(y))
#define nreverse(x) _nreverse((nod)(x))
#define car(x) _car((nod)(x))
#define cdr(x) _cdr((nod)(x))
#define consp(x) _consp((nod)(x))
#define princ(x) _princ((nod)(long)(x))
#define nreverse(x) _nreverse((nod)(x))
#define reverse(x) _reverse((nod)(x))
#define atom(x) !consp(x)
#define not(x) (!(x))
#define terpri() puts("")
nod _cons(nod x, nod y){return PUSHNOD(x),PUSHNOD(y),(nod)&Cells[Next-1];}
nod _car   (nod x){ return x?(nod)CAR(x):x;}
nod _cdr   (nod x){ return x?(nod)CDR(x):x;}
nod _rplaca(nod x,nod y){ x[0] = (void*)y; return x;}
nod _rplacd(nod x,nod y){ x[1] = (void*)y; return x;}
nod _consp (nod x){return(nod)(long)((x<(nod)(Cells))?0:
				     (x<(nod)(Cell2))?1:0);}
nod _xxreverse (nod x);
nod _xxreverse1(nod x,nod y);
nod _xxreverse2(nod x,nod y,nod z){  rplacd(y,z);  return _xxreverse1(x,y);}
nod _xxreverse1(nod x,nod y){             return not(x)?y:_xxreverse2(_cdr(x),x,y);}
nod _xxreverse (nod x){                            return _xxreverse1(x,0);}
nod _nreverse2(nod y,nod x){return not(x)?y:_nreverse2(_rplacd(x,y),_cdr(x));}
nod _nreverse (nod x){return _nreverse2(0,x);}
nod  _reverse2(nod y,nod x){return not(x)?y: _reverse2(_cons(_car(x),y),_cdr(x));}
nod  _reverse (nod x){return _nreverse2(0,x);}
nod _princ(nod x){
  if(atom(x))return printf("%ld", (long)x), x;
  printf("(");
  princ(x[0]);
  printf(" . ");
  princ(x[1]);
  printf(")");
  return x;}
int main(){
#define R(x) reverse(x)
#define N(x) _xxreverse(x)
  princ( (0));
  princ(R(0));
  princ(N(0));
  terpri();
  princ( (cons(1,0)));
  princ(R(cons(1,0)));
  princ(N(cons(1,0)));
  terpri();
  princ( (cons(1,cons(2,0))));
  princ(R(cons(1,cons(2,0))));
  princ(N(cons(1,cons(2,0))));
  terpri();
  princ( (cons(1,cons(2,cons(3,0)))));
  princ(R(cons(1,cons(2,cons(3,0)))));
  princ(N(cons(1,cons(2,cons(3,0)))));
  terpri();
  princ( (cons(1,cons(2,cons(3,cons(4,0))))));
  princ(R(cons(1,cons(2,cons(3,cons(4,0))))));
  princ(N(cons(1,cons(2,cons(3,cons(4,0))))));
  terpri();
  return 0;}
