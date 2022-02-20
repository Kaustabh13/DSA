#include <iostream>
#include <cmath>
using namespace std;

//Basic Functions

/**
 * @brief This function is used to convert the binary number to decimal number
 * 
 * @param binary -> The binary number input as string
 */

void convertBinaryToInt(string binary) {
    
    int j = binary.length();
    int number = 0;
    bool isBinaryNumber = true;

    for(int i = 0; i < binary.length(); i++) {
        int num = binary[i] - '0'; //Convert to int
        if(num > 1) { //Check if number is a valid binary digit 0 || 1
            isBinaryNumber = !isBinaryNumber;
            break;
        }
        number += num * pow(2,--j);
    }

    if(isBinaryNumber) {
        cout << "The decimal number is -> " << number << endl;
    } else {
        cout << "The provided string is not a valid binary number" << endl; 
    }
}

/**
 * @brief This function is used to convert a decimal number to a binary number
 * 
 * @param decimal -> The decimal number
 */

void convertIntToBinary(int decimal) {

    int binaryNumber[32]; //32-bits
    int i = 0;

    while(decimal > 0) {
        binaryNumber[i] = decimal % 2; //Store Remainder
        decimal = decimal/2;
        i++;
    }

    cout << "The binary number is -> ";
    for(int j = i -1; j >= 0; j--) {
        cout << binaryNumber[j] << " ";
    }
}

//Main Function

int main() {
    
    convertBinaryToInt("11");
    convertIntToBinary(3);
    return 0;
}