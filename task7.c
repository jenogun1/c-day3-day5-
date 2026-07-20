#include <stdio.h>
#include <stdlib.h>

int main() {
    // 입력 문자열을 위한 동적 할당
    char *arr = (char *)malloc(1000 * sizeof(char));
    int n = 0;
    char c;

    // 문자열 입력 받기
    while (scanf("%c", &c) == 1 && c != '\n') {
        arr[n++] = c;
    }
    arr[n] = '\0';

    int depth = 0; // 현재 중첩 깊이
    int i = 0;
    while (i < n) {
        if (arr[i] == '<') {
            // 닫는 태그 확인
            if (arr[i + 1] == '/') {
                depth--;
                for (int l = 0; l < depth; l++){
                    printf("    ");
                }
                while (arr[i] != '>') printf("%c", arr[i++]);
                printf(">\n");
                i++;
            } 
            // 여는 태그 확인
            else {
                for (int l = 0; l < depth; l++){
                    printf("    ");
                }
                while (arr[i] != '>') printf("%c", arr[i++]);
                printf(">\n");
                depth++;
                i++;
            }
        } else {
            // 태그 사이의 텍스트 처리
            for (int l = 0; l < depth; l++){
                printf("    ");
            }
            while (i < n && arr[i] != '<'){
                printf("%c", arr[i++]);
            }
            printf("\n");
        }
    }

    // 구조 오류 체크 (depth가 0이 아니면 태그 짝이 안 맞는 것)
    if (depth != 0) {
        printf("ERROR\n");
    }

    return 0;
}

//<div><p>HELLO,<b>world</b>!</p></div>