/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void swap(int* a , int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void Heapify(int* a , int length , int root){
    int left = root * 2 + 1;
    int right = root * 2 + 2;
    int largest = root;
    if(left < length && a[left] > a[largest]){
        largest = left;
    }
    if(right < length && a[right] > a[largest]){
        largest = right;
    }
    if(largest != root){
        swap(&a[root],&a[largest]);
        Heapify(a,length,largest);
    }
}
void heap_sort(int* a , int size){
    for(int i = size / 2 - 1 ; i >= 0 ; i--){
        Heapify(a,size,i);
    }
    for(int i = size - 1 ; i >= 0 ; i--){
        swap(&a[i],&a[0]);
        Heapify(a,i,0);
    }
}
int* sortArray(int* nums, int numsSize, int* returnSize) {
    int* result = (int*)calloc(numsSize , sizeof(int));
    *returnSize = numsSize;
    for(int i = 0; i < numsSize; i++){
        result[i] = nums[i];
    }
    heap_sort(result,numsSize);
    return result;
}