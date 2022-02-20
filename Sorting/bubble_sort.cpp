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

//Basic Function Without Making it adaptive

/**
 * @brief This function is used to perform the bubble sort to make the array sorted
 * 
 * @param arr -> The array
 * @param size -> The size of the array
 */


void bubbleSort(int arr[], int size) {

    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size - 1 - i; j++) {
            if(arr[j] > arr[j+1]) { // Ascending order, flip the operator to make it descending order
               swap(arr[j], arr[j+1]); //Swap if current number is larger than the next number
            }
        }
    }
}

//With Adaptive

/**
 * @brief This function is used to make the bubble sort adapative, so if an array is already sorted,
 *  it will just accomplish the result in the first pass or if there are 10 elements and last 5 are 
 *  already sorted then it will return in 5th pass which will reduce the TC.
 * 
 * @param arr 
 * @param size 
 */

void bubbleSortAdaptive(int arr[], int size) {

    int isSorted = false;

    for(int i = 0; i < size; i++) {
        isSorted = true;
        for(int j = 0; j < size - 1 - i; j++) {
            if(arr[j] > arr[j+1]) {
               swap(arr[j], arr[j+1]); //Swap if current number is larger than the next number
               isSorted = false;
            }
        }

        if(isSorted) { //Now, it is adaptive
            break;
        }
    }
}

//Main Function

int main() {

  int n = 7;
  int arr[7] = {7,2,11,44,22,12,1};
  printArray(arr, n);
  bubbleSort(arr, n);
  printArray(arr, n);

  return 0;
}