#include <stdio.h>
#include <stdlib.h>

void insert_sort(int *numbers, const int QUANTITY){
    int i, value;
    for(int j = 1; j < QUANTITY; j++){
        value = numbers[j];
        i = j - 1;
        while(i >= 0 && numbers[i] > value){
            numbers[i + 1] = numbers[i];
            i--;
        }
        numbers[i + 1] = value;
    }
}

void print_vector(int *numbers, const int QUANTITY){
    for(int i = 0; i < QUANTITY; i++)
        printf("%d ", numbers[i]);
}

int main(){
    const int LEN = 5;
    int *numbers;
    numbers = (int *) malloc(LEN * sizeof(int));
    for(int i = 0; i < LEN; i++)
        numbers[i] = 5 - i;
    insert_sort(numbers, LEN); 
    print_vector(numbers, LEN);
    return 0;
};
