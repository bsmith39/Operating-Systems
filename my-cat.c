#include <stdlib.h>
#include <stdio.h>


int main (int argc, char ** argv) {
	int i = 1;
	while (argv[i] != NULL){
		int check = 0;
		
		FILE *fp = fopen(argv[i], "r");
		if (fp == NULL){
			printf("my-cat: cannot open file\n");
			exit(1);
		}
		char buffer[500];
		char *g = fgets(buffer, 500, fp);
		while (g != NULL){
			printf("%s", buffer);
			g = fgets(buffer, 500, fp);
			check = 1;
		}
		fclose(fp);
		if (check == 0){
			exit(0);
		}
		
		i = i + 1;
	}
	return 0;
}
