#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"

/**
typedef struct hash_node_s {
    char *key;
    char *value;
    struct hash_node_s *next;
} hash_node_t;

typedef struct hash_table_s {
    unsigned long int size;
    hash_node_t **array;
} hash_table_t;

hash_table_t *hash_table_create(unsigned long int size);
unsigned long int hash_djb2(const unsigned char *str);
hash_node_t *hash_node_create(const char *key, const char *value);
int hash_table_set(hash_table_t *ht, const char *key, const char *value);

unsigned long int hash_djb2(const unsigned char *str) {
    unsigned long int hash = 5381;
    int c;
    while ((c = *str++) != 0) {
        hash = ((hash << 5) + hash) + c;
    }
    return hash;
}

hash_node_t *hash_node_create(const char *key, const char *value) {
    hash_node_t *node = malloc(sizeof(hash_node_t));
    if (node == NULL) {
        return NULL;
    }
    node->key = strdup(key);
    node->value = strdup(value);
    node->next = NULL;
    return node;
}

int hash_table_set(hash_table_t *ht, const char *key, const char *value) {
    if (ht == NULL || key == NULL || strlen(key) == 0) {
        return 0;
    }

    unsigned long int index = hash_djb2((const unsigned char *) key) % ht->size;

    hash_node_t *node = ht->array[index];
    while (node != NULL) {
        if (strcmp(node->key, key) == 0) {
            free(node->value);
            node->value = strdup(value);
            return 1;
        }
        node = node->next;
    }

    hash_node_t *new_node = hash_node_create(key, value);
    if (new_node == NULL) {
        return 0;
    }

    new_node->next = ht->array[index];
    ht->array[index] = new_node;
    return 1;
}

int main() {
    hash_table_t *hash_table = hash_table_create(10);
    if (hash_table == NULL) {
        printf("Failed to create hash table\n");
        return 1;
    }

    if (!hash_table_set(hash_table, "key1", "value1")) {
        printf("Failed to set key1 to value1\n");
    }

    if (!hash_table_set(hash_table, "key2", "value2")) {
        printf("Failed to set key2 to value2\n");
    }

    if (!hash_table_set(hash_table, "key1", "value3")) {
        printf("Failed to update key1 to value3\n");
    }

    return 0;
}

