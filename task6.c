#include<stdio.h>
#include<stdlib.h>


int main(){
    int size1, size2;
    printf("N1, N2 Input : ");
    // 행의 개수(size1)와 열의 개수(size2)를 입력받음
    scanf("%d %d", &size1, &size2);
    // 입력값 검증: 곱이 짝수이거나 행/열이 1인 경우 에러 메시지 출력
    if(size1*size2%2==0||size1==1||size2==1){
        printf("ERROR : size");
    }
    else{
         // 2차원 배열을 위한 행 포인터 배열 동적 할당 
        int **arr = (int **)malloc(size1 * sizeof(int *));
        for (int i = 0; i < size1; i++) {
            // 각 행에 대해 열 크기만큼 메모리 할당
            arr[i] = (int *)malloc(size2 * sizeof(int));
        }
        int num = 1;
        // 시작 위치를 배열의 중심 좌표로 설정
        int y=size1/2,x=size2/2;
        
        // 나선형으로 이동하며 숫자를 채우기 위한 반복문
        for(int n=1;n<=(size1+size1)/2;n++){
             
            for(int i=0;i<n;i++){
                // 아래방향 이동
               if(i==0){if(x<size2&&x>=0){
                    if(y>=0&&y<size1){
                        if(arr[y][x]==0){
                            arr[y][x]=num;
                            num++;
                            
                        }
                    }
               }
               y++;
               }
               // 오른쪽 아래방향 이동
                else{ 
                if(x<size2&&x>=0){
                    if(y>=0&&y<size1){
                        if(arr[y][x]==0){
                            arr[y][x]=num;
                            num++;
                            
                        }
                    }
                }
                x++;
                y++;
            }
            }
            //  오른쪽 위방향 이동 
            for(int i=0;i<n;i++){
                
                if(x<size2&&x>=0){
                    if(y>=0&&y<size1){
                        if(arr[y][x]==0){
                            arr[y][x]=num;
                            num++;
                        
                        }
                    }
                }
                x++;
                y--;
            }
            //  왼쪽 위 방향 이동 
            for(int i=0;i<n;i++){
        
                if(x<size2&&x>=0){
                    if(y>=0&&y<size1){
                        if(arr[y][x]==0){
                            arr[y][x]=num;
                            num++;
                        
                        }
                    }
                }
                x--;
                y--;
            }
            // 왼쪽 아래 방향 이동 
            for(int i=0;i<n;i++){
               
                if(x<size2&&x>=0){
                    if(y>=0&&y<size1){
                        if(arr[y][x]==0){
                            arr[y][x]=num;
                            num++;
                        
                        }
                    }
                }
                 x--;
                y++;
            }
        }
        // 완성된 배열을 화면에 출력
        for (int i = 0; i < size1; i++) {
            for (int j = 0; j < size2; j++) {
                printf("%3d ", arr[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}