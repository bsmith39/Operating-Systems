#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main (int argc, char ** argv) {
	int keep = 1;
	int cnt = 0;
	if (argv[1] == NULL){
		char err[50] = "my-zip: file1 [file2 ...]\n";
		fwrite(err, 1, 26, stdout);
		exit(1);
	}
	while(argv[keep] != NULL){
		FILE *fp = fopen(argv[keep], "r");
		char buffer[500];
		char *b = buffer;
		size_t bufsize = 500;
		while (fgets(b, bufsize, fp) != NULL){
			int i;	
			for (i = 0; i < strlen(b); i++){
				cnt = cnt + 1;
				int j = i;
				while(b[j] == b[j+1]){
					cnt = cnt + 1;
					j = j + 1;
				}
				i = j;
				if (argv[keep + 1] == NULL){
					fwrite(&cnt, 1, sizeof(cnt), stdout);
					fwrite(&b[i], 1, sizeof(b[i]), stdout);
					cnt = 0;
				}
			}
		}
		fclose(fp);
		keep = keep + 1;
	}
	return 0;
}
