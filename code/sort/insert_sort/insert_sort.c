#include <stdio.h>

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
    int numbers[5] = {5, 4, 3, 2, 1};
    insert_sort(numbers, LEN); 
    print_vector(numbers, LEN);
    return 0;
};
