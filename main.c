/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
# include <stdio.h>
# include "complexo.h"

int main() {
	complexo a, b, c;
	if (complexo_teste())
	    printf("passou os testes de unidade\n");
	else
	    printf("Não passou os testes!\n");
	    return 0;
	    
	a = complexo_le();
	b = complexo_le();
	c = complexo_soma(a, b);
	complexo_imprime(c);
	printf("%lf\n", complexo_absoluto(c));
	
	return 0;
 }