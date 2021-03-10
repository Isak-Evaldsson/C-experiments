#ifndef BITARRAY_H_
#define BITARRAY_H_

/*  
    A simple struct incopsing an char array which contains the bytes,
    and a length attribute
*/
struct BitArray
{
    char* array;
    int length;
} typedef BitArray;

/*
    Methods for creating and destorying the BitArray
*/
BitArray* createBitArray(int length);
void destroyBitArray(BitArray* b);

/*
    Methods for reading and writing to the array
*/
void setBit(BitArray* array, int index, char value);
void setBitLow(BitArray* array, int index);
void setBitHigh(BitArray* array, int index);
char getBit(BitArray* array, int index);

/*
    Small convient help methods
*/
char* toString(BitArray* array);

#endif