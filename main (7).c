#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to perform a linear search for a product in a list
int* linear_search_product(char** products, int numProducts, const char* targetProduct, int* numOccurrences) {
    int* indices = (int*)malloc(sizeof(int) * numProducts);
    *numOccurrences = 0;

    for (int i = 0; i < numProducts; i++) {
        if (strcmp(products[i], targetProduct) == 0) {
            indices[*numOccurrences] = i;
            (*numOccurrences)++;
        }
    }

    return indices;
}

int main() {
    // Sample list of products
    char* products[] = {"Apple", "Banana", "Orange", "Apple", "Grapes", "Apple"};

    int numProducts = 6;
    const char* targetProduct = "Apple";
    int numOccurrences;
    int* indices = linear_search_product(products, numProducts, targetProduct, &numOccurrences);

    if (numOccurrences > 0) {
        printf("'%s' found at the following indices: ", targetProduct);
        for (int i = 0; i < numOccurrences; i++) {
            printf("%d", indices[i]);
            if (i < numOccurrences - 1) {
                printf(", ");
            }
        }
        printf("\n");
    } else {
        printf("'%s' not found in the list.\n", targetProduct);
    }

    free(indices); // Don't forget to free the dynamically allocated memory
    return 0;
}
