#include <stdio.h>
#include <stdlib.h>
#include "string_vector.h"

//vector_create
StringVector* vector_create(size_t initial_capacity) {
    StringVector *vec = malloc(sizeof(StringVector));
    if (vec == NULL) {
        return NULL;
    }

    vec->data = malloc(initial_capacity * sizeof(char *));
    if (vec->data == NULL) {
        free(vec);
        return NULL;
    }

    vec->capacity = initial_capacity;
    vec->size = 0;

    return vec;
}

//vector_push
int vector_push(StringVector *vec, const char *str) {
    if (vec == NULL || str == NULL) {
        return 0;
    }

    //Resize if array is full
    if (vec->size == vec->capacity) {
        size_t new_capacity = (vec->capacity == 0) ? 1 : vec->capacity * 2;
        char **new_data = realloc(vec->data, new_capacity * sizeof(char *));
        if (new_data == NULL) {
            return 0; //Allocation failure
        }
        vec->data = new_data;
        vec->capacity = new_capacity;
    }

    //Calculate length manually without strlen()
    size_t len = 0;
    while (str[len] != '\0') {
        len++;
    }

    //Allocate memory for the string (plus null terminator)
    char *str_copy = malloc(len + 1);
    if (str_copy == NULL) {
        return 0; // Allocation failure
    }

    //Copy characters manually without strcpy()
    for (size_t i = 0; i <= len; i++) {
        str_copy[i] = str[i];
    }

    //Store pointer and increment size
    vec->data[vec->size] = str_copy;
    vec->size++;

    return 1; //Success
}

//vector_get
const char* vector_get(const StringVector *vec, size_t index) {
    if (vec == NULL || index >= vec->size) {
        return NULL;
    }
    return vec->data[index];
}

//vector_free
void vector_free(StringVector *vec) {
    if (vec == NULL) {
        return;
    }

    //Free each individual string
    for (size_t i = 0; i < vec->size; i++) {
        free(vec->data[i]);
    }

    //Free internal array and struct
    free(vec->data);
    free(vec);
}
