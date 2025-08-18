#include<stdio.h>
int main()
{
    double arr[] = {1,2,3,4,1,2,3,4,5};
    
    printf("Unique Numbers:\n");

    for(int i=0;i<9;i++)
    {
        int isDuplicate=0;
        for(int j=0;j<i;j++)
        {
            if(arr[i]==arr[j])
            {
                isDuplicate=1;
                break;
            }
        }

        if(isDuplicate==0)
        {
            printf("%f ",arr[i]);
        }
    }
    printf("\n");
    return 0;
}