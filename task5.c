#include <stdio.h>
#include <stdlib.h>

int main() {
    int size;
    int num = 1; 
    // 배열의 사이즈 입력
    printf("input N : ");
    scanf("%d",&size);
    // 2차원 배열 동적 할당
    int **arr = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) {
        arr[i] = (int *)malloc(size * sizeof(int));
    }

    // 배열 값 채우기
    for (int sum = 0; sum <= (size - 1) * 2; sum++) {
        for (int i = 0; i < size; i++) {
            int j = sum - i;
            if (j >= 0 && j < size) {
                arr[i][j] = num++;
            }
        }
    }

    // 배열 출력
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%3d ", arr[i][j]);
        }
        printf("\n");
    }


    return 0;
}