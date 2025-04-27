#include<stdio.h>
#define MAX 100
int A[MAX];
int n=0;
void swap(int *a, int *b) {
    int temp=*a;
    *a=*b;
    *b=temp;
}
void insert(int val) {
    A[++n]=val;
    int i=n;
    while (i>1) {
        int parent=i/2;
        if (A[parent]>A[i]) {
            swap(&A[parent],&A[i]);
            i=parent;
        }
        else return;
    }
}

int delete(){
    int delVal=A[1];
    A[1]=A[n--];
    int i=1;
    while (i<=n/2) {
        int left=2*i;
        int right=2*i+1;
        int smallest=left;
        if (right<=n && A[right]<A[left]) {
            smallest=right;
        }
        if (A[i]>A[smallest]) {
            swap(&A[i],&A[smallest]);
            i=smallest;
        }
        else break;
    }
    return delVal;

}

void display() {
    for (int i=1;i<=n;i++) {
        printf("%d ",A[i]);
    }
    printf("\n");
}
int main() {
    int choice, val,noOfVals,i;
    printf("|-MIN HEAP-|\n");
    printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
    while (1) {
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch (choice) {
            case 1:
                printf("Enter number of values to insert:");
            scanf("%d",&noOfVals);
            printf("Enter %d elements:",noOfVals);
            for (i=0;i<noOfVals;i++) {
                scanf("%d",&val);
                insert(val);
            }
            printf("The given values are inserted.\n");
            break;
            case 2:
                if (n!=0) {
                    int delVal=delete();
                    printf("The root node with value %d is deleted.\n",delVal);
                }
                else printf("Heap is empty.\n");
            break;
            case 3:
                display();
            break;
            case 4:
                return 0;
            default: printf("Invalid choice!\n");
        }
    }
}
