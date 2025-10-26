#include<stdio.h>

struct Element{
    int row;
    int col;
    int value;
};

void sparse(){

    int row,col; 
    printf("\nEnter the no of rows: ");
    scanf("%d",&row);
    printf("\nEnter the no of cols: ");
    scanf("%d",&col);

    int count;
    printf("\nEnter the no of non zero elements: ");
    scanf("%d",&count);

    struct Element tripletA[count+1]; //we will store meta-data on 0th index
    tripletA[0].row = row;
    tripletA[0].col = col;
    tripletA[0].value = count;

    //accepting the values of non-zero elements and storing their data in tripletA

    int r,c,ele;
    for(int i = 1; i <= count; i++){
        printf("\nEnter the item: ");
        scanf("%d",&ele);
        printf("\nEnter the row: ");
        scanf("%d",&r);
        printf("\nEnter the column: ");
        scanf("%d",&c);

        tripletA[i].row = r;
        tripletA[i].col = c;
        tripletA[i].value = ele;
    }

    //printing the tripletA 
    printf("\nPrinting the TripletA\n");
    for(int i = 0; i < tripletA[0].value + 1; i++){
        printf("%d\t%d\t%d\n",tripletA[i].row,tripletA[i].col,tripletA[i].value);
    }

    printf("\nPrinting the Matrix - A from triplet\n");

    row = tripletA[0].row;
    col = tripletA[0].col;
    int k = 1;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if((i == tripletA[k].row) && (j == tripletA[k].col)){
                printf("%d\t",tripletA[k].value);
                k++;
            }
            else{
                printf("0\t");
            }
        }
        printf("\n");
    }


    //Triplet-B making for it
    //     
    // 

    int row2,col2; 
    printf("\nEnter the no of rows: ");
    scanf("%d",&row2);
    printf("\nEnter the no of cols: ");
    scanf("%d",&col2);

    int count2;
    printf("\nEnter the no of non zero elements: ");
    scanf("%d",&count2);

    struct Element tripletB[count2+1]; //we will store meta-data on 0th index
    tripletB[0].row = row2;
    tripletB[0].col = col2;
    tripletB[0].value = count2;

    //accepting the values of non-zero elements and storing their data in tripletB

    
    for(int i = 1; i <= count2; i++){
        printf("\nEnter the item: ");
        scanf("%d",&ele);
        printf("\nEnter the row: ");
        scanf("%d",&r);
        printf("\nEnter the column: ");
        scanf("%d",&c);

        tripletB[i].row = r;
        tripletB[i].col = c;
        tripletB[i].value = ele;
    }

    //printing the tripletB 
    printf("\nPrinting the TripletB\n");
    for(int i = 0; i < tripletB[0].value + 1; i++){
        printf("%d\t%d\t%d\n",tripletB[i].row,tripletB[i].col,tripletB[i].value);
    }

    printf("\nPrinting the Matrix - B from triplet\n");

    row = tripletB[0].row;
    col = tripletB[0].col;
    k = 1;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if((i == tripletB[k].row) && (j == tripletB[k].col)){
                printf("%d\t",tripletB[k].value);
                k++;
            }
            else{
                printf("0\t");
            }
        }
        printf("\n");
    }


    //adding the two matrices based on the triplets

    if(row != row2 || col != col2){
        printf("\nDimension Mismatched...\n");
    }
    else{
        struct Element tripletC[tripletA[0].value + tripletB[0].value];
        int i = 1; 
        int j = 1; 
        int k = 1; 
        int rowCount = 1;
        tripletC[0].row = row;
        tripletC[0].col = col;
        
        while(i <= tripletA[0].value || j <= tripletB[0].value){
            if((tripletA[i].row < tripletB[j].row) || ((tripletA[i].row == tripletB[j].row) && (tripletA[i].col < tripletB[j].col))){
                tripletC[k].row = tripletA[i].row;
                tripletC[k].col = tripletA[i].col;
                tripletC[k].value = tripletA[i].value;
                i++;
                k++;
            }
            else if((tripletB[j].row < tripletA[i].row) || ((tripletB[j].row == tripletA[i].row) && (tripletB[j].col < tripletA[i].col))){
                tripletC[k].row = tripletB[j].row;
                tripletC[k].col = tripletB[j].col;
                tripletC[k].value = tripletB[j].value;
                j++;
                k++;
            }
            else if(((tripletA[i].row == tripletB[j].row) && (tripletA[i].col == tripletB[j].col))){
                int sum = tripletA[i].value + tripletB[j].value;
                if(sum != 0) {   // only store if non-zero
                    tripletC[k].row = tripletA[i].row;
                    tripletC[k].col = tripletA[i].col;
                    tripletC[k].value = sum;
                    k++;
                }
                i++; j++;
            }
        }
        tripletC[0].value = k-1;


        //printing the triplet of matrix c

         printf("\nPrinting the TripletC\n");
        for(int i = 0; i < tripletC[0].value + 1; i++){
            printf("%d\t%d\t%d\n",tripletC[i].row,tripletC[i].col,tripletC[i].value);
        }


        //printing the Matrix C

        row = tripletA[0].row;
        col = tripletA[0].col;
        printf("\nPrinting the Matrix - C from triplet\n");
        k = 1;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if((i == tripletC[k].row) && (j == tripletC[k].col)){
                    printf("%d\t",tripletC[k].value);
                    k++;
                }
                else{
                    printf("0\t");
                }
            }
            printf("\n");
        }

        //Transpose of Matrix - C
        struct Element tripletT[tripletC[0].value + 1];
        int n = tripletC[0].value;   // number of non-zeros

        // Step 1: swap dimensions
        tripletT[0].row = tripletC[0].col;
        tripletT[0].col = tripletC[0].row;
        tripletT[0].value = n;

        // Step 2: swap row and col for each element
        for(int k = 1; k <= n; k++) {
            tripletT[k].row = tripletC[k].col;
            tripletT[k].col = tripletC[k].row;
            tripletT[k].value = tripletC[k].value;
        }

        // Step 3: sort tripletT by row, then col (bubble sort)
        for(int i = 1; i <= n-1; i++) {
            for(int j = 1; j <= n-i; j++) {
                if((tripletT[j].row > tripletT[j+1].row) ||
                (tripletT[j].row == tripletT[j+1].row && tripletT[j].col > tripletT[j+1].col)) {
                    struct Element temp = tripletT[j];
                    tripletT[j] = tripletT[j+1];
                    tripletT[j+1] = temp;
                }
            }
        }

        // Now tripletT contains the transpose in correct sorted form
        printf("\nTranspose Triplet:\n");
        for(int k = 0; k <= n; k++) {
            printf("%d\t%d\t%d\n", tripletT[k].row, tripletT[k].col, tripletT[k].value);
        }

        row = tripletT[0].row;
        col = tripletT[0].col;
        printf("\nPrinting the Matrix - Transpose from triplet\n");
        k = 1;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if((i == tripletT[k].row) && (j == tripletT[k].col)){
                    printf("%d\t",tripletT[k].value);
                    k++;
                }
                else{
                    printf("0\t");
                }
            }
            printf("\n");
        }


    }

}

void main(){
    sparse();
}