#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, num = 0, min, max;
    printf("How many elements are used to allocate? : ");
    // 배열의 크기를 입력받음
    scanf("%d", &n);

    // 입력받은 크기만큼 정수형 배열 동적 할당
    int *arr = (int*) malloc(n * sizeof(int));

    for(int i = 0; i < n; i++) {
        printf("Enter integer data :");
        scanf("%d", &arr[i]);

        // 첫 번째 입력 시 최댓값과 최솟값을 첫 번째 값으로 초기화
        if(i == 0) {
            min = arr[i];
            max = arr[i];
        }

        // 입력받은 값을 총합(num)에 누적
        num = num + arr[i];

        // 입력받은 값이 현재 최솟값보다 작으면 min 갱신
        min = (min > arr[i]) ? arr[i] : min;
        
        // 입력받은 값이 현재 최댓값보다 크면 max 갱신
        max = (arr[i] > max) ? arr[i] : max;
    }

    // 결과 출력
    printf("maximum: %d\nminimum : %d\noverall value : %d\nAverage: %f", max, min, num, (float)num / n);

    return 0;
}