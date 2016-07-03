 #include <stdio.h>
 #define INFINITY 100000
 void merge(int A[], int start, int mid, int end)
 {
     int size_left = mid - start + 1; // since mid and start both gets subtracted, we include
                                     // 1 by adding +1
     int size_right = end - mid; // Right starts from mid + 1 so no need to add +1
     int Left[size_left + 1]; // + 1 is for the sentinal value
     int Right[size_right + 1];
     for(int i = 0; i< size_left; i++){
        Left[i] = A[start + i]; // start + i because start changes everytime
     }
     for(int i = 0; i < size_right; i++){
        Right[i] = A[mid + 1 + i]; // adding +1 since the partition starts from mid+1 not mid
     }
     Left[size_left] = INFINITY; // sentinal value
     Right[size_right] = INFINITY;
     int i , j;
     i = j = 0;
     for(int k = start; k <= end; k++){
        if(Left[i] <= Right[j])
            A[k] = Left[i++];
        else
            A[k] = Right[j++];
     }

 }
 void merge_sort(int A[],int start,int end)
 {
    if(start < end){ // This is the base condition when size of sub-problem is 1
        int mid = (start + end) / 2;
        merge_sort(A,start, mid);
        merge_sort(A,mid+1, end);
        merge(A,start,mid,end);
    }
 }
 int main()
 {
    int size;
    int arr[1000];
    printf("Enter the size of the array : ");
    scanf("%d",&size);
    for(int i = 0; i < size; i++){
        scanf("%d",&arr[i]);
    }
    merge_sort(arr,0,size-1);
    printf("Sorted Array : ");
    for(int i = 0; i < size ; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
 }
