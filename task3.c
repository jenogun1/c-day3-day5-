#include <stdio.h>
#include <stdlib.h>

int main() {
    int size1, size2;
    printf("N1, N2 Input : ");
    // 행의 개수(size1)와 열의 개수(size2)를 입력받음
    scanf("%d %d", &size1, &size2);
    
    // 2차원 배열을 동적 할당 (행 단위 할당)
    int **arr = (int **)malloc(size1 * sizeof(int *));
    for (int i = 0; i < size1; i++) {
        // 각 행에 대해 열 크기만큼 메모리 할당
        arr[i] = (int *)malloc(size2 * sizeof(int));
    }

    // 나선형으로 채우기 위한 변수 초기화
    int num = 1;
    int top = 0, bottom = size1 - 1, left = 0, right = size2 - 1;

    // 나선형 경로를 따라 숫자를 채워 넣는 루프
    while (top <= bottom && left <= right) {
        // 1왼쪽에서 오른쪽으로 행 채우기
        for (int i = left; i <= right; i++){
            arr[top][i] = num++;
        }
        top++; // 위쪽 경계 축소

        // 위에서 아래로 열 채우기
        for (int i = top; i <= bottom; i++){
            arr[i][right] = num++;
        }
        right--; // 오른쪽 경계 축소

        // 오른쪽에서 왼쪽으로 행 채우기
        if (top <= bottom) {
            for (int i = right; i >= left; i--){
                arr[bottom][i] = num++;
            }
            bottom--; // 아래쪽 경계 축소
        }

        // 아래에서 위로 열 채우기
        if (left <= right) {
            for (int i = bottom; i >= top; i--){
                arr[i][left] = num++;
            }
            left++; // 왼쪽 경계 축소
        }
    }

    // 완성된 배열 출력
    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            printf("%3d ", arr[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}