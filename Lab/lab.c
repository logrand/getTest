
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#define MAXWORDS 50
#define WORDLEN 12
#define MAXROWS 61
#define MAXCOL 61
#define DEBUG 0  // set to 0 to disable debug output

// reads words from the file
// into wl and trims the whitespace off of the end
int readWords(char* wl[MAXWORDS], char* filename); 

//modifies s to trim white space off the right side
void trimws(char* s);

//fills grid with random letters


//generates random letters
char randLetter();

int randNum (int x);

int main() {

	srand(time(NULL));
	char* wordlist[MAXWORDS];
	char* sentence[80];
	int wordCount;
	char grid[MAXROWS][MAXCOL];
	char word[20];
	char file[30];
	//char filename;
	int i = 0;
	int j = 0;
	int x = 0;
	int y = 0;
	int w = 0;
	int numX = 0;
	int numY = 0;
	int numWord = 0;
	int setWord = 0;
	int z = 0;
	int t = 0;
	

	printf("Enter dimensions max of 60 and file \n");
	scanf("%d %d %s", &x, &y, &file);
	 
	wordCount = readWords(wordlist, file);
	
	
	//printf("%d %d", x, y);
	
	
	//fill(grid[y][x], x, y);
	
	for(i = 0; i < y; ++i){
		for(j = 0; j < x; ++j){
			grid[i][j] = ' ';
		}
	} 
	

	//printf("%c", randLetter(x));
	
	//TEST START
	for(w = 0; w < wordCount; ++w){
		strcpy(word, wordlist[w]);
		numWord = strlen(word);
		
		for(i = 0; i <= 100; ++i){
			numX = randNum(x);
			numY = randNum(y);
			t = 0;
			if((x - numX) > numWord){
				for(z = 0; z < numWord; ++z){
					if(grid[numY][numX + z] != ' '){
						t = 1;
					}
				}
				if(t == 0){
					for(j = 0; j < numWord; ++j){
						grid[numY][numX +j] = word[j];
					}
				}
			break;
			}
			else if((y - numY) > numWord){
				for(z = 0; z < numWord; ++z){
					if(grid[numY + z][numX] != ' '){
						t = 1;
					}
				}
				if(t == 0){
					for(j = 0; j < numWord; ++j){
						grid[numY + j][numX] = word[j];
					}
				}
			break;
			}
		}
	}
	if(DEBUG == 0){
	for(i = 0; i < y; ++i){
		for(j = 0; j < x; ++j){
			if(grid[i][j] == ' '){ 
				grid[i][j] = randLetter();
			}
		}
	}
	}
	
	for(i = 0; i < y; ++i){
		for(j = 0; j < x; ++j){
			printf("%c ", grid[i][j]);
		}
		printf("\n");
	}
	
	
    return 0;
	}

void trimws(char* s) {
	int i = 0;
	int max = 0;
	max = strlen(s);
	
	for(i =0; i <= max; ++i) {
		if(isspace(s[i]) != 0){
			s[i] = '\0';
		}
	}
}

int readWords(char* wl[MAXWORDS], char* filename) {
	int i;
	FILE* t;
	char line[15];
	int length = 0;
	int word = 0;
	t = fopen(filename, "r");
	for(i = 0; i <= (MAXWORDS - 1); ++i) {
		if (feof(t) != 0) {
			break;
		}
		fscanf(t, "%s", line);
		trimws(line);
		length = strlen(line);
		wl[i] = malloc(sizeof(char*) * (length + 1));
		strcpy(wl[i], line);
		
		++word;
		//printf("%s\n", wl[i]);
	}
	fclose(t);
	
	
	return word;
}

char randLetter(){
	char c = c;
	c = 'A' + (rand() % 26);
	return c;
}

int randNum (int x){
	int n;
	n = (rand() % x);
	return n;
}

	
	