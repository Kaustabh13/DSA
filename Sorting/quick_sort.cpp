#include<iostream>
using namespace std;

//Traversal

/**
 * @brief This function is used to print the elements of the array
 * 
 * @param arr -> The array
 * @param size -> The size of the array
 */

void printArray(int arr[], int size) {

    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;
}

//Basic Function

/**
 * @brief This function is used to do the partioning and return the partition index
 * 
 * @param arr -> The array
 * @param low -> The low value
 * @param high -> The high value
 * @return int -> The partition index
 */

int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low + 1;
    int j = high;

    do {

        while(arr[i] <= pivot) {
            i++;
        }

        while(arr[j] > pivot) {
            j--;
        }

        if(i < j) {
            swap(arr[i], arr[j]);
        }

    } while(i < j);

    swap(arr[low], arr[j]);
    return j;
}

/**
 * @brief The quick sort algorithm
 * 
 * @param arr -> The array
 * @param low -> The low value
 * @param high -> The high value
 */

void quickSort(int arr[], int low, int high) {

    int partitionIndex;

    if(high > low) {

    partitionIndex = partition(arr, low, high);
    quickSort(arr, low, partitionIndex - 1); //Left Sub Array
    quickSort(arr, partitionIndex+1, high); //Right Sub Array

    }
   
}

//Main Function

int main() {

    int n = 7;
    int arr[7] = {7,2,11,44,22,12,1};
    printArray(arr, n);
    quickSort(arr, 0, n-1);
    printArray(arr, n);
    return 0;
    return 0;
}