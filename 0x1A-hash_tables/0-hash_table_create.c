#include <stdlib.h>
#include <stdio.h>

typedef struct hash_table_s {
    unsigned long int size;
    void **array;
} hash_table_t;

hash_table_t *hash_table_create(unsigned long int size) {
    if (size == 0) {
        return NULL;
    }

    hash_table_t *hash_table = malloc(sizeof(hash_table_t));
    if (hash_table == NULL) {
        return NULL;
    }

    hash_table->array = calloc(size, sizeof(void *));
    if (hash_table->array == NULL) {
        free(hash_table);
        return NULL;
    }

    hash_table->size = size;
    return hash_table;
}

int main() {
    hash_table_t *hash_table = hash_table_create(10);
    if (hash_table == NULL) {
        printf("Failed to create hash table\n");
    } else {
        printf("Hash table created successfully\n");
    }
    return 0;
}

