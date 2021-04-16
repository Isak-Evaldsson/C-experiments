#include "bitArray.h"

#define BYTE_SIZE 8

//Create empty (only zeroes) bitarray of certain length
BitArray* createBitArray(int length) {
    BitArray* res = (BitArray*) malloc(sizeof(BitArray));
    res->array = (char*) calloc((length/8)*sizeof(char));
    res->length = length;
    return res; 
}

void destroyBitArray(BitArray* b) {
    free(b->array);
    free(b);
}

//Bit array operations
void setBit(BitArray* array, int index, char value){
    if(value == 0)
        setBitLow(array, index);
    else
        setBitHigh(array, index);    
}

void setBitLow(BitArray* array, int index){
}

void setBitHigh(BitArray* array, int index){
}

char getBit(BitArray* array, int index){
    int i = index / BYTE_SIZE;
    int p = index % BYTE_SIZE;
    char mask = 1 << p;

    return array->array[i] & mask;
}

char* toString(BitArray* array) {
    char str[array->length + 1];

    for (int i = 0; i < array->length; i++)
        str[i] = getBit(array, i);
    
    str[array->length] = '\0';
    return str;
}