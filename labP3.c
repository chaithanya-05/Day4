#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void countWordsAndLines(char filename[]);

int main() {
    char filename[] = "data.txt"; 
    countWordsAndLines(filename);
    return 0;
}

void countWordsAndLines(char filename[]) {
    FILE *file;
    char ch;
    int lines = 0, words = 0, inWord = 0;

    // Open the file for reading
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Could not open file %s\n", filename);
        return;
    }

    // Read the file character by character
    while ((ch = fgetc(file)) != EOF) {
        // Count lines
        if (ch == '\n') {
            lines++;
        }

        
        if (isspace(ch)) {
            if (inWord) {
                inWord = 0; 
            }
        } else {
            if (!inWord) {
                inWord = 1; 
                words++;
            }
        }
    }

   
    if (inWord) {
        words++;
    }

    // Close the file
    fclose(file);

    // Display the results
    printf("Total Lines: %d\n", lines + 1); 
    printf("Total Words: %d\n", words);
}
