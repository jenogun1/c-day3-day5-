#include <stdio.h>
#include <stdlib.h>

int main(){
    int size1, size2;
    printf("N1, N2 Input : ");
    // 행의 개수(size1)와 열의 개수(size2)를 입력받음
    scanf("%d %d", &size1, &size2);

    // 2차원 배열을 동적 할당 
    int **arr = (int **)malloc(size1 * sizeof(int *));
    for (int i = 0; i < size1; i++) {
        // 각 행에 대해 열 크기만큼 메모리 할당
        arr[i] = (int *)malloc(size2 * sizeof(int));
    }

    printf("Enter a two-dimensional array\n");
    // 중첩 반복문을 통해 배열의 요소 입력받기
    for(int i = 0; i < size1; i++){
        for(int l = 0; l < size2; l++){
            scanf("%d", &arr[i][l]);
        }    
    }

    // 전치 행렬 출력 (열(size2)을 행으로, 행(size1)을 열로 바꾸어 출력)
    for(int i = 0; i < size2; i++){
        for(int l = 0; l < size1; l++){
            // 입력받은 배열의 [l][i] 위치를 출력하여 전치 효과 구현
            printf("%2d ", arr[l][i]);
        }    
        printf("\n");
    }
    return 0;
}