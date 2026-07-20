#include <stdio.h>
#include <stdlib.h>

int main() {
    int size;
    printf("Input : ");
    scanf("%d", &size);

    // 입력받은 size가 짝수면 오류 메시지 출력
    if (size % 2 == 0) {
        printf("size error");
    } 
    else {
        // 2차원 배열을 동적 할당
        int **arr = (int **)malloc(size * sizeof(int *));
        for (int i = 0; i < size; i++) {
            arr[i] = (int *)malloc(size * sizeof(int));
        }

        int j = 1; // 배열에 채울 시작 숫자
        for (int i = 0; i < size; i++) {
            // 왼쪽에서 오른쪽으로 범위를 좁히며 채움
            if (i < size / 2) {
                for (int l = i; l < size - i; l++) {
                    arr[i][l] = j;
                    j++;
                }
            } 
            // 왼쪽으로 범위를 넓히며 채움
            else {
                for (int l = size - 1 - i; l <= i; l++) {
                    arr[i][l] = j;
                    j++;
                }
            }
        }

        // 결과 배열 출력
        for (int i = 0; i < size; i++) {
            for (int l = 0; l < size; l++) {
                printf("%2d ", arr[i][l]);
            }
            printf("\n");
        }
    }
    return 0;
}