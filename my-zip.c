#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main (int argc, char ** argv) {
	int keep = 1;
	int cnt = 0;
	char n[1]= {"\n"};
	char *nl = n;
	if (argv[1] == NULL){
		printf("my-zip: file1 [file2 ...]\n");
		
		exit(1);
	}
	while(argv[keep] != NULL){
		FILE *fp = fopen(argv[keep], "r");
		char buffer[500];
		char *b = buffer;
		size_t bufsize = 500;
		char *g = fgets(b, bufsize, fp);
		int check = 0;
		char last[1]= {"\n"};
		while (g != NULL){
			int i;	
			if (nl[0] == b[0]){
				cnt = cnt + 1;
				fwrite(&cnt, sizeof(cnt),1, stdout);
				fwrite(&nl[0], sizeof(nl[0]),1, stdout);
				cnt = 0;
				g = fgets(b, bufsize, fp);
			}else if (check == 1){
				cnt = 1;
				fwrite(&cnt, sizeof(cnt),1, stdout);
				fwrite(&nl[0], sizeof(nl[0]),1, stdout);
				cnt = 0;
			}	
			for (i = 0; i < strlen(b); i++){
				cnt = cnt + 1;
				int j = i;
				while(b[j] == b[j+1]){
					cnt = cnt + 1;
					j = j + 1;
				}
				i = j;
				if (argv[keep + 1] == NULL && b[j] != nl[0]){
					fwrite(&cnt, sizeof(cnt),1, stdout);
					fwrite(&b[i], sizeof(b[i]),1, stdout);
					cnt = 0;
				}
				last[0] = b[j];
			}
			check = 1;
			g = fgets(b, bufsize, fp);
		}
		if (last[0] == nl[0]){
			cnt = 1;
			fwrite(&cnt, sizeof(cnt),1, stdout);
			fwrite(&nl[0], sizeof(nl[0]),1, stdout);
		}
		fclose(fp);
		keep = keep + 1;
	}

	
	return 0;
}
