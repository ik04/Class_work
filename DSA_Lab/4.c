#include<stdio.h>
void insetElement(int arr[],int nod,int x,int pos){
    for(int i=nod-1;i>=pos;i--){
        arr[i+1] = arr[i];
        arr[pos] = x;
    }
}

int findElement(int arr[],int nod,int key);

int deleteElement(int arr[],int nod,int key){
    int pos = findElement(arr,nod,key);
    if(pos == -1){
        printf("element not found");
    }
    
}

int findElement(int arr[],int nod,int key){
    int i;
    for (i = 0; i < nod; i++)
    {
        if(arr[i] == key)
            return i;
            return -1;
    }
}

int main(){
    int arr[100];
    int i, nod;
    printf("Enter the number of digits: ");
    scanf("%d",&nod);
    printf("Enter Numbers");
    for ( i = 0; i < nod; i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("\n");
    int n = sizeof(arr)/sizeof(arr[0]);
    int key;
    printf("\n");
    printf("Enter Element to be deleted");
    scanf("%d",&key);
    printf("\n");
    printf("Before Deletion: ");
    for (int i = 0; i < nod; i++)
    {
        printf("%d",arr[i]);
        printf("\n");
    }
    printf("After Deletion: ");
    for (int i = 0; i < nod-1; i++)
    {
        printf("%d",arr[i]);
        printf("\n");
    }
    int x,pos;
    printf("Enter Element to be inserted: ");
    scanf("%d",&x);
    printf("Enter position to be inserted into: ");
    scanf("%d",&pos);
    printf("\n");
    insetElement(arr, nod, x, pos);
    n++ ;
    printf("After Insertion: ");
    for (int i = 0; i < nod; i++)
    {
        printf("%d",arr[i]);
    }
    return 0;
}