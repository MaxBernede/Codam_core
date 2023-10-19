#include <stdio.h>
#include <string.h>

void makeStringsEqualLength(char *str1, char *str2) {
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	if (len1 < len2){
		int diff = len2 - len1;
		for (int i = 0; i < diff; i++){
			
		}
	}
}

int main() {
    char str1[] = "123";
    char str2[] = "123456789";

    makeStringsEqualLength(str1, str2);

    printf("str1: %s\n", str1);
    printf("str2: %s\n", str2);

    return 0;
}