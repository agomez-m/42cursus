#include "libft.h"
#include <stdio.h>


int main() {
    // IS_ALPHA
    char caracter = '7';
    char caracter1 = 'n';


    if (ft_isalpha(caracter)) {
        printf("%c es una letra del alfabeto.\n", caracter);
    } else {
        printf("%c no es una letra del alfabeto.\n", caracter);
    }
     if (ft_isalpha(caracter1)) {
        printf("%c es una letra del alfabeto.\n", caracter1);
    } else {
        printf("%c no es una letra del alfabeto.\n", caracter1);
    }

    //IS_DIGIT
    char caracter2 = 'A';
    char caracter3 = '7';

    if (ft_isdigit(caracter2)) {
        printf("%c es un dígito numérico.\n", caracter2);
    } else {
        printf("%c no es un dígito numérico.\n", caracter2);
    }
    if (ft_isdigit(caracter3)) {
        printf("%c es un dígito numérico.\n", caracter3);
    } else {
        printf("%c no es un dígito numérico.\n", caracter3);
    }

    //ISALNUM
    char caracter4 = 'A';
    char caracter5 = '7';
    char caracter6 = '#';

    if (ft_isalnum(caracter4)) {
        printf("%c es alfanumérico.\n", caracter4);
    } else {
        printf("%c no es alfanumérico.\n", caracter4);
    }

    if (ft_isalnum(caracter5)) {
        printf("%c es alfanumérico.\n", caracter5);
    } else {
        printf("%c no es alfanumérico.\n", caracter5);
    }

    if (ft_isalnum(caracter6)) {
        printf("%c es alfanumérico.\n", caracter6);
    } else {
        printf("%c no es alfanumérico.\n", caracter6);
    }


    return 0;
}