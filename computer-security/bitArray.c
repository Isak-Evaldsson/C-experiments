
struct BitArray
{
    char* array;
    int length;
} typedef BitArray;

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