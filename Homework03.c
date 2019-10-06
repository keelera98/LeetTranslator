#include <stdio.h>
#include <malloc.h>
#include <string.h>

int main(int argc, char** argv){
	char read;
	FILE* out;
	FILE* fp;
	char* str;

	str = malloc(sizeof(char) * 4);

	if((fp = fopen(argv[1], "r")) && (out = fopen(argv[2], "w"))){
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
					fgets(str, 3, fp);
					if(!(strcmp(str, "ou")))
						fputc('U', out);
					else{
						fputs("y0", out);
					}
					break;
				default:
					fputc(read, out);
			}
		}
		fclose(fp);
		fclose(out);
	}
	printf("TRANSLATION COMPLETE\n");
	free(str);
}
