

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){

	if(argc != 2){
		printf("usage: %s <filename>\n", argv[0]);
		exit(0);
	}

	FILE *fp = fopen(argv[1], "r");
	if(fp == NULL){
		fprintf(stderr, "Error when trying to open file %s\n", argv[1]);
		exit(0);
	}

	unsigned int c = 0;
	int cnt = 0;
	int ascii[128] = {0};

	while ((c = fgetc(fp)) != EOF){

		if(c > 127)
			continue;

		cnt++;
		ascii[c]++;
	}

	int i;
	for (i = 0; i < 128; i++){
		
		if(ascii[i] > 0)
			printf("%3d %6.2f\n", i, (ascii[i] *100.0) / cnt);
	}

	fclose(fp);

	return 0;
}
