#include <stdlib.h>
#include <stdio.h>


int main (int argc, char ** argv) {
	if (argv[1] == NULL){
		printf("my-unzip: file1 [file2 ...]\n");
		exit(1);
	}
	FILE *fp;
        int cha;
        int cnt;
        size_t size;
	int keep = 1;
	while(argv[keep] != NULL){
		fp = fopen(argv[keep], "r");
		while ((size = fread(&cnt, sizeof(cnt), 1, fp)) == 1){
			cha = fgetc(fp);
			while(cnt > 0){
				printf("%c", cha);
				cnt = cnt - 1;
			}
		}
		fclose(fp);		
		keep = keep + 1;
	}
	return 0;
}
