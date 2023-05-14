#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define swap(a, b) a = a + b; \
                    b = a - b;\
                    a = a - b;


void BubbleSort(int *arr, int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - 1 - i; ++j) {
            if (arr[j + 1] < arr[j]) {
                swap(arr[j + 1], arr[j])
            }
        }
    }
}

/*--------------------------------------------------------------------------------------------------------------------*/


void rand_arr(int *arr, int len, int max_element) {
    for (int i = 0; i < len; ++i) {
        arr[i] = rand() % max_element;
    }
}


// Вспомогательная функция для вывода на экран массива размера n
void print_arr(int *arr, int len) {
    for (int i = 0; i < len; ++i) {
        printf("%d ", arr[i]);
    }
    putchar('\n');
}

void validate_arg(int argc, char **argv, int *max_element, int *num_elements, int *cycles) {
    if (argc != 4) {
        printf("Use BubbleSort <num elements> <max element> <num sort cycles>");
        exit(1);
        return;
    }
    *num_elements = atoi(argv[1]);
    *max_element = atoi(argv[2]);
    *cycles = atoi(argv[3]);
    if (!(*max_element >= 0 && *max_element <= 2147483647 || *num_elements >= 0 && *num_elements <= 1000000 || *cycles >= 0 && *cycles <= 1000000)) {
        puts("Check u values!");
        exit(1);
        return;
    }
}

/*--------------------------------------------------------------------------------------------------------------------*/

int main(int argc, char **argv) {
    srand(time(NULL));

    double time_spent = 0.0;
    int *arr, max_element, num_elements, cycles;
    time_t begin, end;

    validate_arg(argc, argv, &max_element, &num_elements, &cycles);

    arr = malloc(sizeof(int) * num_elements);

    for (int i = 0; i < cycles; ++i) {
        rand_arr(arr, num_elements, max_element);

        begin = clock();
        //print_arr(arr, num_elements);
        BubbleSort(arr, num_elements);
        //print_arr(arr, num_elements);
        end = clock();

        time_spent += (double) (end - begin) / CLOCKS_PER_SEC;
    }


    printf("The elapsed time is %f seconds", time_spent / cycles);


    free(arr);
    return 0;
}
