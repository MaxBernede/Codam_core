#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void equalizeStrings(char **a, char **b) {
    int lengthA = strlen(*a);
    int lengthB = strlen(*b);

    if (lengthA < lengthB) {
        int diff = lengthB - lengthA;
        char *temp = (char *)malloc(lengthB + 1);

        // Remplir temp avec des zéros
        memset(temp, '0', diff);
        temp[diff] = '\0';

        // Concaténer a à temp pour égaler les longueurs
        strcat(temp, *a);

        // Libérer l'ancienne valeur de a
        free(*a);

        // Mettre a à jour avec la nouvelle valeur
        *a = temp;
    } else if (lengthA > lengthB) {
        int diff = lengthA - lengthB;
        char *temp = (char *)malloc(lengthA + 1);

        // Remplir temp avec des zéros
        memset(temp, '0', diff);
        temp[diff] = '\0';

        // Concaténer b à temp pour égaler les longueurs
        strcat(temp, *b);

        // Libérer l'ancienne valeur de b
        free(*b);

        // Mettre b à jour avec la nouvelle valeur
        *b = temp;
    }
}

int main() {
    char str1 = substr("123");
    char str2 = substr("4567890");
    
    printf("Avant égalisation :\n");
    printf("str1 : %s\n", str1);
    printf("str2 : %s\n", str2);
    
    equalizeStrings(&str1, &str2);
    
    printf("\nAprès égalisation :\n");
    printf("str1 : %s\n", str1);
    printf("str2 : %s\n", str2);
    
    free(str1); // Libérer la mémoire allouée dynamiquement
    free(str2); // Libérer la mémoire allouée dynamiquement
    
    return 0;
}
