#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main (int argc, char ** argv) {
	int i = 2;
	if (argc < 2){
		printf("my-grep: searchterm [file ...]\n");
		exit(1);
	}

	while (argv[i] != NULL){
		FILE *fp = fopen(argv[i], "r");
		if (fp == NULL){
			printf("my-grep: cannot open file\n");
			exit(1);
		}
		char line[500];
		while(fgets(line, 500, fp) != NULL){
			if (strstr(line, argv[1]) != NULL)
				printf("%s", line);
		}
		fclose(fp);		
		i = i + 1;
	}
	if (argc == 2){
		char lin[500];
		while(fgets(lin,500,stdin)!=NULL){
			if (strstr(lin, argv[1])!=NULL)
				printf("%s", lin);
		}
	}
	return 0;
}
