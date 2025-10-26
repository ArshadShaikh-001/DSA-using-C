#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_LEN 50

int main() {
    FILE *inFile, *outFile;
    char words[MAX_WORDS][MAX_LEN];
    int count = 0;

    // Open input file
    inFile = fopen("input.txt", "r");
    if (inFile == NULL) {
        printf("Cannot open input file.\n");
        return 1;
    }

    // Read words from file
    while (fscanf(inFile, "%s", words[count]) != EOF) {
        count++;
        if (count >= MAX_WORDS) break;
    }
    fclose(inFile);

    // Sort words alphabetically (simple bubble sort)
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (strcmp(words[i], words[j]) > 0) {
                char temp[MAX_LEN];
                strcpy(temp, words[i]);
                strcpy(words[i], words[j]);
                strcpy(words[j], temp);
            }
        }
    }

    // Write sorted words to output file
    outFile = fopen("output.txt", "w");
    if (outFile == NULL) {
        printf("Cannot open output file.\n");
        return 1;
    }

    for (int i = 0; i < count; i++) {
        fprintf(outFile, "%s\n", words[i]);
    }
    fclose(outFile);

    printf("Words sorted and saved to output.txt\n");
    return 0;
}
