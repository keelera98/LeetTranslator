#include <stdio.h>
#include <malloc.h>
include <string.h>

int main(){
	char read;
	FILE* out;
	FILE* fp;
	char* fileInput;
	char* fileOutput;
	char* str;
	int pos = 0;

	str = malloc(sizeof(char) * 3);

	if((fileInput = malloc(sizeof(char) * 100)) && (fileOutput = malloc(sizeof(char) * 100))){
		printf("Enter a file name: ");
		fgets(fileInput, 99, stdin);
		
		strtok(fileInput, "\n");

		printf("Enter an output file name: ");
		fgets(fileOutput, 99, stdin);

		strtok(fileOutput, "\n");

		if((fp = fopen(fileInput, "r")) && (out = fopen(fileOutput, "w"))){
			while((read = fgetc(fp)) != EOF){
		
				switch(read){
					case 'A':
					case 'a':	
						fputc('4', out);
						break;
					case 'C':
					case 'c':
						fputc('(', out);
						break;
					case 'E':
					case 'e':
						fputc('3', out);
						break;
					case 'F':
					case 'f':
						fputs("ph", out);
						break;
					case 'I':
					case 'i':	
						fputc('1', out);
						break;
					case 'G':
					case 'g':
						fputc('6', out);
						break;
					case 'O':
					case 'o':
						fputc('0', out);
						break;
					case 'S':
					case 's':
						fputc('5', out);
						break;
					case 'T':
					case 't':
						fputc('7', out);
						break;
					case 'Y':
					case 'y':
						pos = ftell(fp);
						fgets(str, 2, fp);
						if(!(strcmp(str, "ou")))
							fputc('U', out);
						else{
							fseek(fp, pos, SEEK_SET);
						}
						break;
					default:
						fputc(read, out);
				}
			}
			fclose(fp);
			fclose(out);
		}else{
			perror("Error");
		}
	}
	printf("TRANSLATION COMPLETE\n");
	free(fileInput);
	free(fileOutput);
	free(str);
}

