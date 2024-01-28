#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

//Estructura para poder pasar varios valores en una función.

typedef struct 
{
    unsigned long long base; // Tipo de número más apropiado para calcular potencias de números grandes.
    unsigned long long po;
} Result_Values;

//función de potencia
unsigned long long power(unsigned long long base, unsigned long long n)
{
    unsigned long long result = 1;
    for (int i=1; i<=n;i++)
    {
        
        result = result*base;
    }
    return result;
}

// Función para limpiar el buffer del teclado
void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

//Función personaliza el mensaje
unsigned long long askNumber(const char *string)

{
    unsigned long long number = 0;
    printf(string);
        while (1) 
        {
        unsigned long long c = getchar();
            if (isdigit(c)) 
            {
                ungetc(c, stdin); //Flujo de entrada
                scanf("%llu", &number); //unsigned long long number
                break;
            } else if (c == '\n' || c == EOF) {
                break;
            }
        }

    clearBuffer();
    return number;

}


//función de menu

Result_Values GetValues()
{
const char *pedirBase = "Introduce un número de base: "; //constante tipo cadena.
const char *pedirExponente = "Introduce el exponente: ";
Result_Values result;

result.base = askNumber(pedirBase);
result.po= askNumber(pedirExponente);

return result;

}

// Función que comprueba si el número pasado por argumento del programa es un número
unsigned long long checkNumber(const char *string)
{
    for (int i=0; string[i] != '\0'; i++)
    {
        if (!isdigit(string[i])) return 0; 
    }
    return 1;
}



int main(int argc, char *argv[])
{
    // si pasamos dos argumentos como números en la linea de comandos directamente los calcula.
    // el primer argumento siempre es el nombre de la aplicación
    if (argc == 3 && checkNumber(argv[1]) && checkNumber(argv[2])) 
    {
        // Si hay dos argumentos
        unsigned long long base = atoi(argv[1]);
        unsigned long long exponente = atoi(argv[2]);

        printf("El resultado de la potencia %llu elevado a %llu es: %llu\n", base, exponente, power(base, exponente));
    } else {
    
    
    char next;

    do
    {
    Result_Values result = GetValues();
    printf("El resultado de la potencia %llu elevado a %llu es: %llu\n",result.base,result.po , power(result.base,result.po)); 
    printf("¿Quieres calcular otra potencia? (s/n): ");
    scanf(" %c", &next);

    clearBuffer();
    } while (tolower(next) =='s'); //convierte los caracteres en minuscula.
    
    }
    return 0;
}