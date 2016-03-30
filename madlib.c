#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* madlib(char* template, char* adjective, char* noun, char* verb) {
	int count = 0;
	for (int i = 0; strcmp(template + i, "\0") != 0; i++) {
		if (strchr(template + i, 37)) {
			i = strchr(template + i, 37) - template;
			count += 1;
		}
	}
	if (count > 3) {
		return "TOO MANY %%s SUBSTITUTES!!!";
	}

	char result[strlen(template) + strlen(adjective) + strlen(noun) + strlen(verb)];
	sprintf(result, template, adjective, noun, verb);
	return (result);
}

// int main(int argc, char** argv) {
// 	printf(madlib(argv[2], argv[3], argv[4], argv[5]));
// }
