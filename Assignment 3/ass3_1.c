#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    FILE *fp = fopen("data.txt", "w");
    if (!fp) {
        printf("Cannot open file.\n");
        return 1;
    }

    int N = 10000; // Change to 1000, 5000, 10000 etc.
    srand(time(0));

    for (int i = 0; i < N; i++) {
        fprintf(fp, "%d\n", rand() % 100000); // random numbers up to 100000
    }

    fclose(fp);
    printf("Data file created with %d integers.\n", N);
    return 0;
}
