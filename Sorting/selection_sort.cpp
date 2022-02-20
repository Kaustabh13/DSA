#include <iostream>
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
 * @brief This function is used to sort the array with help of selection sort
 * 
 * @param arr -> The array
 * @param size -> The size of the array
 */

void selectionSort(int arr[], int size) {

    int minIndex;
   //4 3 1 2 
    for(int i = 0; i < size - 1; i++) {
        minIndex = i;

        for(int j = i+1; j < size; j++) {
            if(arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        swap(arr[i], arr[minIndex]);
    }
}

//Main Function

int main() {

    int n = 7;
    int arr[7] = {7,2,11,44,22,12,1};
    printArray(arr, n);
    selectionSort(arr, n);
    printArray(arr, n);
    return 0;
    return 0;
}