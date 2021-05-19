#include<stdio.h>
typedef char**nod;
char*Cells[1024];
char**Cell2=(void*)&Cells+sizeof(Cells);
int  Next = -1;
#define cons(x,y) _cons((nod)(x),(nod)(y))
nod _cons(nod x, nod y){
  Cells[++Next] = (char*)x;
  Cells[++Next] = (char*)y;
  return (nod)&Cells[Next-1];}
nod _atom(nod x){
  if(x < (nod)(Cells)) return (nod)1;
  if(x < (nod)(Cell2)) return (nod)0;
  return (nod)1;}
nod _rplacd(nod x,nod y){
  x[1] = (void*)y;
  return x;}
nod _nreverse2(nod x,nod y){
  if(!x) return y;
  nod ox = (void*)x[1];
  return _nreverse2((void*)ox,_rplacd(x,y));}
nod _nreverse (nod x){return _nreverse2(x,0);}
#define terpri() puts("")
#define princ(x) _princ((nod)(x))
nod _princ(nod x){
  if(_atom(x))
    printf("%ld", (long)x);
  else{
    printf("(");
    princ(x[0]);
    printf(" . ");
    princ(x[1]);
    printf(")");}
  return x;}
int main(){
#define N(x) _nreverse(x)
  printf("Cells = %p\n", Cells);
  printf("Cell2 = %p\n", Cells+1024);
  printf("Cell2 = %p\n", Cell2);
  princ( (0));
  princ(N(0));
  terpri();
  princ( (cons(1,0)));
  princ(N(cons(1,0)));
  terpri();
  princ( (cons(1,cons(2,0))));
  princ(N(cons(1,cons(2,0))));
  terpri();
  princ( (cons(1,cons(2,cons(3,0)))));
  princ(N(cons(1,cons(2,cons(3,0)))));
  terpri();
  princ( (cons(1,cons(2,cons(3,cons(4,0))))));
  princ(N(cons(1,cons(2,cons(3,cons(4,0))))));
  terpri();
  //princ(_nreverse(cons(1,0)));
  printf("SDGSDFG\n");
  return 0;}
