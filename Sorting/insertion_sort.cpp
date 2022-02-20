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

/**
 * @brief This function is used to do the insertion sort
 * 
 * @param arr -> The array
 * @param size -> The size of the array
 */

void insertionSort(int arr[], int size) {
    int key, j = 0;

    for(int i = 1; i < size; i++) {
        key = arr[i]; //2
        j = i - 1; //0
        while(j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

//Main Function

int main() {

    int n = 7;
    int arr[7] = {7,2,11,44,22,12,1};
    printArray(arr, n);
    insertionSort(arr, n);
    printArray(arr, n);
    return 0;
}