#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** justDoIt(char **arr, size_t i){
    char *tmp_arr = NULL;
    tmp_arr = (char*)calloc(1, sizeof(char));

    for (size_t x = 0; x < i; ++x) {
        size_t y = 0;
        size_t length = 0;

        while (arr[x][y] != '\0'){
            length++;
            y++;
        }
        length = length + 1; // add '\0' symbol

        if (!tmp_arr){
            printf("[error]");
            exit(-1);
        }

        size_t tmp_length = 0;

        y = 0;
        while(arr[x][y] != '\0'){
            if(!(arr[x][y] == ' ' && arr[x][y + 1] == ' ')){
                tmp_length++;

                tmp_arr = (char*)realloc(tmp_arr, sizeof(char) * tmp_length);
                if(!tmp_arr){
                    printf("[error]");
                    exit(-1);
                }

                tmp_arr[tmp_length - 1] = arr[x][y];
            }
            y++;
        }

        tmp_length++;
        tmp_arr = (char*)realloc(tmp_arr, sizeof(char) * tmp_length);
        if(!tmp_arr){
            printf("[error]");
            exit(-1);
        }

        tmp_arr[tmp_length - 1] = '\0';

        arr[x] = (char*)realloc(arr[x], sizeof(char) * tmp_length);
        if(!arr[x]){
            printf("[error]");
            exit(-1);
        }

        memcpy(arr[x], tmp_arr, tmp_length);

        tmp_arr = (char*)realloc(tmp_arr, sizeof(char));
        if(!tmp_arr){
            printf("[error]");
            exit(-1);
        }
    }
    free(tmp_arr);
    return arr;
}

int main(void)
{
    char *temp = NULL, **arr = NULL;
    size_t count = 1;
    size_t i = 1;

    arr = (char**)calloc(i, sizeof(char*));
    if (!arr){
        printf("[error]");
        exit(-1);
    }

    temp = (char*)malloc(sizeof(char) * count);
    if (!temp){
        printf("[error]");
        exit(-1);
    }

    while(1){
        char c = 0;
        int tmp_scanf = 0;
        tmp_scanf = scanf("%c", &c);
        if(!tmp_scanf){
            printf("[error]");
            exit(-1);
        }

        if(feof(stdin)) {
            temp[count - 1] = '\0';

            arr[i - 1] = (char*)calloc(count, sizeof(char));
            if(!(arr[i - 1])){
                printf("[error]");
                exit(-1);
            }
            memcpy(arr[i - 1], temp, count);

            break;
        }

        if(c == '\n'){
            temp[count - 1] = '\0';

            arr[i - 1] = (char*)calloc(count, sizeof(char));
            if(!(arr[i - 1])){
                printf("[error]");
                exit(-1);
            }
            memcpy(arr[i - 1], temp, count);

            i++;
            count = 1;

            arr = (char**)realloc(arr, sizeof(char*) * i);
            if(!arr){
                printf("[error]");
                exit(-1);
            }

            arr[i - 1] = NULL;
        } else {
            temp[count - 1] = c;
            count++;
            temp = (char*)realloc(temp, sizeof(char) * count);
            if (!temp){
                printf("[error]");
                exit(-1);
            }
        }
    }

    for (size_t x = 0; x < i; ++x) {
        if(!arr[x]) {
            free(arr[x]);
            i--;
        }
    }

    arr = justDoIt(arr, i);

    for (size_t x = 0; x < i; ++x) {
        printf("%s\n", arr[x]);
    }

    free(temp);

    for (size_t x = 0; x < i; ++x){
        free(arr[x]);
    }
    free(arr);

    return 0;
}

