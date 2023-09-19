#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_a{
    int size_resultat;
    int index_grand;
    char *a;
    char *b;
}   t_a;

int maxStringLength(const char *a, const char *b) {
    int lengthA = strlen(a);
    int lengthB = strlen(b);

    if (lengthA > lengthB) {
        return lengthA;
    } else {
        return lengthB;
    }
}

void str_cpy(t_a a, char *tocopy){
    if (a.index_grand == strlen(tocopy)){
        
    }
}

int main (int argc, char **argv){
    t_a a;
    if (argc != 3)
        return 0;
    a.index_grand = maxStringLength(argv[1], argv[2]);
    str_cpy(a.a, argv[1]);
    return 0
}