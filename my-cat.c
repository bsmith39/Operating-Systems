#include <stdlib.h>
#include <stdio.h>


int main (int argc, char ** argv) {
	int i = 1;
	while (argv[i] != NULL){
		FILE *fp = fopen(argv[i], "r");
		char buffer[255];
		char *g = fgets(buffer, 255, fp);
		if (g != NULL){
			printf("%s", buffer);
			fclose(fp);
		}else{
			if (i == 1){
				exit(0);
			}
			exit(1);
		}
		i = i+1;
	}
	return 0;
}
