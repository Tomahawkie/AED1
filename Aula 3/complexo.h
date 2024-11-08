#include <stdio.h>
#include <math.h>
typedef struct {
  double real;
  double imag;
} complexo;


complexo complexo_novo(double real, double imag){
    complexo novo;
    novo.real = real;
    novo.imag = imag;
    return novo;
}

complexo complexo_le(){
    double real, imag;
    printf("digite a parte real e a imaginaria");
    scanf("%lf %lf", &real, &imag);
    return complexo_novo(real, imag);
}
complexo complexo_soma (complexo a, complexo b){
    return complexo_novo( a.real+b.real , a.imag+b.imag);
}

complexo complexo_multiplicacao (complexo a, complexo b){
    double real, imag;
    real = a.real*b.real+(a.imag*b.imag*(-1));
    imag = a.imag*b.real+b.imag*a.real;
    return complexo_novo(real, imag);
}
double complexo_absoluto (complexo a){
    double modulo = sqrt(a.real*a.real+a.imag*a.imag);
    return modulo;
}
void complexo_imprime(complexo a) {
    if (a.imag >= 0)
        printf("%.1lf + %.1lfi\n", a.real, a.imag);
    else
        printf("%.1lf - %.1lfi\n", a.real, -a.imag);
}

int complexos_iguais(complexo a, complexo b){
    if (a.real == b.real && a.imag == b.imag){
        return 1;
    }else return 0;

}
complexo  complexo_conjugado(complexo  a){
    printf("%1.lf-%1.lfi", a.real, a.imag);
    return complexo_novo(a.real, (-1)*a.imag);
}

int complexo_teste() {
  complexo a, b, c;
  double r = 0.0;
  int resp_soma, resp_multiplicacao, resp_absoluto;
  a.real = 3.5;
  a.imag = 2.0;
  complexo_imprime (a);
  b.real = 0.0;
  b.imag = -1.0;
  c = complexo_soma (a, b);
  complexo_imprime (c);
  resp_soma = complexos_iguais(c, complexo_novo(3.5, 1.0)); // 3.5+1.0i
  c = complexo_multiplicacao (a, b);
  complexo_imprime (c);
  resp_multiplicacao = complexos_iguais(c, complexo_novo(2.0, -3.5)); // 2.0-3.5i
  r = complexo_absoluto (b);
  resp_absoluto = ((int)r - 1 == 0? 1: 0);
  printf("Modulo (b): %f\n", r); 
  return resp_soma * resp_multiplicacao * resp_absoluto;
} 