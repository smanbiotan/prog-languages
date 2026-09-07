#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char title[64];
    char isbn[14];
    int copiesAvailable;
} Book;

typedef struct {
    Book *data;
    int size;
    int capacity;
} Catalog;

void catalog_init(Catalog *cat) {
    cat->data = NULL;
    cat->size = 0;
    cat->capacity = 0;
}

int catalog_grow_if_needed(Catalog *cat) {
    if (cat->size < cat->capacity)
        return 1;

    int newCapacity = (cat->capacity == 0) ? 4 : cat->capacity * 2;
    Book *temp = realloc(cat->data, newCapacity * sizeof(Book));

    if (temp == NULL) {
        printf("Memory allocation failed.\n");
        return 0;
    }

    cat->data = temp;
    cat->capacity = newCapacity;

    return 1;
}

int catalog_push(Catalog *cat, Book b) {
    if (!catalog_grow_if_needed(cat))
        return 0;

    cat->data[cat->size] = b;
    cat->size++;

    return 1;
}

int catalog_insertAt(Catalog *cat, int index, Book b) {
    if (index < 0 || index > cat->size)
        return 0;

    if (!catalog_grow_if_needed(cat))
        return 0;

    for (int i = cat->size; i > index; i--) {
        cat->data[i] = cat->data[i - 1];
    }

    cat->data[index] = b;
    cat->size++;

    return 1;
}

int main(void) {

    Catalog lib;
    catalog_init(&lib);
    catalog_push(&lib, (Book){"The Hobbit", "9780345339683", 3});
    catalog_push(&lib, (Book){"1984", "9780451524935", 5});

    Book newBook = {"Dune", "9780441013593", 2};
    catalog_insertAt(&lib, 1, newBook);

    for (int i = 0; i < lib.size; i++) {
        printf("%d: %s\n", i, lib.data[i].title);
    }

    int rejected = catalog_insertAt(&lib, 10, newBook);

    printf("out-of-range insert returned %d\n", rejected);

    free(lib.data);
    lib.data = NULL;

    return 0;
}