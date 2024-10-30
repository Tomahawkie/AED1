#include <stdio.h>
#include <math.h>


typedef struct{
    double raio;
}Circ;

double calcular_area(Circ c){
    return M_PI*c.raio*c.raio;
}


int main(){
    Circ circulo;
    printf("Digite um raio\n");
    scanf("%lf", &circulo.raio);
    double area = calcular_area(circulo);
    printf("a area do seu circulo é: %lf \n", area);
    
    
    return 0;
}