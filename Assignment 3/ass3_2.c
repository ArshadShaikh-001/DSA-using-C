#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10000

// Bubble sort
void bubbleSort(int arr[], int n){
    for(int i = 0; i < n-1; i++)
        for(int j = 0; j < n-i-1; j++)
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
}

// Selection sort
void selectionSort(int arr[], int n){
    for(int i = 0; i < n-1; i++){
        int min_idx = i;
        for(int j = i+1; j < n; j++)
            if(arr[j] < arr[min_idx]) min_idx = j;
        int temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }
}

int main() {
    FILE *fp = fopen("data.txt", "r");
    if(!fp) { printf("Cannot open file\n"); return 1; }

    int arr[MAX], n = 0;
    while(fscanf(fp, "%d", &arr[n]) != EOF) n++;
    fclose(fp);

    int arr1[MAX], arr2[MAX];
    for(int i=0;i<n;i++){ arr1[i]=arr[i]; arr2[i]=arr[i]; }

    clock_t start, end;

    // Bubble sort timing
    start = clock();
    bubbleSort(arr1, n);
    end = clock();
    double bubbleTime = ((double)(end - start))/CLOCKS_PER_SEC;

    // Selection sort timing
    start = clock();
    selectionSort(arr2, n);
    end = clock();
    double selectionTime = ((double)(end - start))/CLOCKS_PER_SEC;

    printf("Bubble Sort Time: %.5f sec\n", bubbleTime);
    printf("Selection Sort Time: %.5f sec\n", selectionTime);

    // Save sorted data (optional)
    fp = fopen("bubble_sorted.txt", "w");
    for(int i=0;i<n;i++) fprintf(fp,"%d\n",arr1[i]);
    fclose(fp);

    fp = fopen("selection_sorted.txt", "w");
    for(int i=0;i<n;i++) fprintf(fp,"%d\n",arr2[i]);
    fclose(fp);

    // Save times for gnuplot
    fp = fopen("times.txt","w");
    fprintf(fp,"%d %.5f %.5f\n", n, bubbleTime, selectionTime);
    fclose(fp);

    return 0;
}
