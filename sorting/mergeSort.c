#include<stdio.h>
#include <stdlib.h>
#include <time.h>

void mergeSort(int*,int,int);
void merge(int*,int,int,int);

void mergeSort(int arr[],int low,int high) {
    if (low<high) {
        int mid=(low+high)/2;
        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);
        merge(arr,low,high,mid);
    }
}

void merge(int arr[],int low,int high, int mid){
    int i=low,j=mid+1,k=0;
    int b[high-low+1];
    while (i<=mid && j<=high) { //loop till end of array reached
        if (arr[i]<=arr[j]) {
            b[k++]=arr[i++]; //store sorted elements in temp array
        }
        else {
            b[k++]=arr[j++];
        }
    }
    while (i<=mid) { //store remaining elements that are left out
        b[k++]=arr[i++];
        //same as b[k]=arr[i]; k++; i++;
    }
    while (j<=high) {
        b[k++]=arr[j++];
    }
    for (i=low,k=0;i<=high;i++,k++) {
        arr[i]=b[k]; // again store the temp array values to main array
    }
}
int main() {
    int arr[6],i;
    int length=sizeof(arr)/sizeof(arr[0]);
    srand(time(0));
    for (i=0;i<length;i++) {
        arr[i]=rand()%100;
    }
    printf("-----MERGE SORT-----\n");
    printf("Array before sorting:\n");
    for (i=0;i<length;i++) {
        printf("%d ",arr[i]);;
    }
    mergeSort(arr,0,length-1);
    printf("\nArray after sorting:\n");
    for (i=0;i<length;i++) printf("%d ",arr[i]);
}
