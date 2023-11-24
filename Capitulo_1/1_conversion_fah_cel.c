#include <stdio.h>


/*
    Curso C Libro KERNIGHAN & RITCHIE
    programa de conversión de Fahrenheit a Celsius

    Capitulo1, variables, expresiones e interaciones

*/

// imprime la tabla de F-C pra fahr=0,20, ... 300

main()
{
    int fahr,celsius;
    int lower,upper,step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;
 
    while (fahr<=upper) {
        celsius = 5 * (fahr-32)/9;
        printf("%d\t%d\n",fahr,celsius);
        fahr = fahr + step;

    }



}