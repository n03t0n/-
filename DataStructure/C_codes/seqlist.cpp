#include <stdio.h>
#define MAXL 100
typedef int KeyType;
typedef char InfoType;
typedef struct{
    KeyType key;
    InfoType data;
} RecType;


void swap(RecType &x, RecType &y){
    RecType tmp = x;
    x = y; y = tmp;
}

// Function to create a list
void CreateList(RecType R[], KeyType keys[], int n) {
    for (int i = 0; i < n; i++) {
        R[i].key = keys[i];
    }
}

// Function to display the list
void DispList(RecType R[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", R[i].key);
    }
    printf("\n");
}

// Function to create a list for heap sort (index starts from 1)
void CreateList1(RecType R[], KeyType keys[], int n) {
    for (int i = 1; i <= n; i++) {
        R[i].key = keys[i - 1];
    }
}

// Function to display the list for heap sort (index starts from 1)
void DispList1(RecType R[], int n) {
    for (int i = 1; i <= n; i++) {
        printf("%d ", R[i].key);
    }
    printf("\n");
}