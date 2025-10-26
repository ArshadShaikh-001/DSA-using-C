#include<stdio.h>

void removeDuplicates(){
    int size;
    printf("\nEnter the size of array: ");
    scanf("%d",&size);
    int arr[size];
    printf("\nEnter the %d elements: ",size);
    //Accepting the elements
    for(int i = 0; i < size; i++){
        scanf("%d",&arr[i]);
    }

    int newArray[size];
    //newArray[0] = arr[0];
    int flag = 1;
    int unique = 0;
    for(int i = 0; i < size; i++){
        for(int j = 0; j < unique; j++){
            if(arr[i] == newArray[j]){
                flag = 0;
            }
        }
        if(flag != 0){
            newArray[unique] = arr[i];
            unique++;
        }
        flag = 1;
    }

    // printing new array
    printf("\nUnique Elements:\n");
    for(int i = 0; i < unique; i++){
        printf("%d\t",newArray[i]);
    }
}

void main(){
    removeDuplicates();
}