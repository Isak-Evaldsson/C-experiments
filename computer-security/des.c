/*
    An implenetation of DES for educational purposes. DO NOT USE THIS IMPLEMENATION,
    the author (Isak Evalddson) can not give an guarantees of correctness/safety of the algorithm
*/
#include <string.h>
#include <asset.h>

// Constants
#define KEY_SIZE 64
#define BLOCK_SIZE 64

// Tables
int initial_permutation_table[64] = {
    58, 50, 42, 34, 26, 18, 10, 2, 
    60, 52, 44, 36, 28, 20, 12, 4, 
    62, 54, 46, 38, 30, 22, 14, 6, 
    64, 56, 48, 40, 32, 24, 16, 8, 
    57, 49, 41, 33, 25, 17,  9, 1, 
    59, 51, 43, 35, 27, 19, 11, 3, 
    61, 53, 45, 37, 29, 21, 13, 5, 
    63, 55, 47, 39, 31, 23, 15, 7};

// Key genreation


// Main function
void DES(char* message, char* key) {
    // Input validation
    assert(strlen(message) != BLOCK_SIZE && strlen(key) != KEY_SIZE);
    
    //Input permutation
    char preoutput[64];
    
    for(int i = 0; i < 64; i++) {
        preoutput[i] = message[initial_permutation_table[i] - 1];
    }

    // Fiestal 
    }

}