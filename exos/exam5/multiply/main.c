#include <stdio.h>
#include <unistd.h>

int iszero(char *str){
	char *ptr;

	ptr = *str;
	while (ptr++){
		if (*ptr != '0')
			return 0;
	}
	return 1;
}

char **multiply(char *n1, char *n2){
	if (iszero(n1) || iszero(n2))
		return ("0");
	int len1 = len()
}

int main(int argc, char **argv){
	if (argc != 3){
		printf("You need to give 2 args\n");
		return 0;
	}
	printf("%s\n", multiply(argv[1], argv[2]));
	return 0;
}