#include <stdio.h>
#include <math.h>
/*estava pronto desde segunda, esqueci de mandar :(*/
typedef struct{
    double raio;
    double x;
    double y;
}circulo;

double calcular_area(circulo c){
    return M_PI*c.raio*c.raio;
}

double escalar(double e, double area){
    double a = e*area;
    return a;
}

int main(){
    circulo c;
    double e, area, area_escalar;
    printf("Digite o raio do ciruculo\n");
    scanf("%lf", &c.raio);
    printf("qual o escalar que deseja multiplicar\n");
    scanf("%lf", &e);
    printf("qual a coordenada x?\n");
    scanf("%lf", &c.x);
    printf("qual a coordenada y?\n");
    scanf("%lf", &c.y);
    
    area = calcular_area(c);
    printf("a area sem o escalar é: %lf", area);
    area_escalar = escalar(e, area);
    printf("area com o escalar %lf", area_escalar);
    return 0;
}