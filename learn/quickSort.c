#include<stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low - 1;
    for(int j = low; j < high; j++){
        if(arr[j] <= pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[high]);
    return i + 1;                       //You forgot return i + 1;
}
void quickSort(int arr[], int low, int high){
    if(low < high){                             //And its just < not <=
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}
int main(){

    int n;
    printf("Enter the length od array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the array to be sorted: ");
    for(int i = 0; i < n; i++){
        scanf("%d",&arr[i]);
    }
    printf("Array before sorting: ");
    for(int i = 0; i<n; i++){
        printf("%d ", arr[i]);
    }
    quickSort(arr, 0, n);
    printf("Array after sorting: ");
    for(int i = 0; i<n; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}
