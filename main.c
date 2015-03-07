#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** justDoIt(char **arr, size_t i){
    char *tmp_arr = NULL;
    char *check = NULL;
    tmp_arr = (char*)calloc(1, sizeof(char));

    if (!tmp_arr){
        return 0;
    }

    for (size_t x = 0; x < i; ++x) {
        size_t y = 0;

        size_t tmp_length = 0;

        y = 0;
        while(arr[x][y] != '\0'){
            if(!(arr[x][y] == ' ' && arr[x][y + 1] == ' ')){
                tmp_length++;

                check = NULL;
                check = (char*)realloc(tmp_arr, sizeof(char) * tmp_length);
                if(!check){
                    return 0;
                }
                tmp_arr = check;

                tmp_arr[tmp_length - 1] = arr[x][y];
            }
            y++;
        }

        tmp_length++;

        check = NULL;
        check = (char*)realloc(tmp_arr, sizeof(char) * tmp_length);
        if(!check){
            return 0;
        }
        tmp_arr = check;

        tmp_arr[tmp_length - 1] = '\0';

        check = NULL;
        check = (char*)realloc(arr[x], sizeof(char) * tmp_length);
        if(!check){
            return 0;
        }
        arr[x] = check;

        memcpy(arr[x], tmp_arr, tmp_length);

        check = NULL;
        check = (char*)realloc(tmp_arr, sizeof(char));
        if(!check){
            return 0;
        }
        tmp_arr = check;
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
        //free
        free(arr);
        printf("[error]");
        exit(-1);
    }

    while(1){
        char c = 0;
        int is_eof = 0;
        switch (scanf("%c", &c)) {
        case EOF: is_eof = 1; break;
        case 1 : break;
        default:
            free(arr);
            free(temp);
            printf("[error]");
            exit(-1);
        }

        if(is_eof) {
            temp[count - 1] = '\0';

            arr[i - 1] = (char*)calloc(count, sizeof(char));
            if(!(arr[i - 1])){
                //free
                for (size_t x = 0; x < i; ++x){
                    free(arr[x]);
                }
                free(arr);
                free(temp);
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
                //free
                for (size_t x = 0; x < i; ++x){
                    free(arr[x]);
                }
                free(arr);
                free(temp);
                printf("[error]");
                exit(-1);
            }
            memcpy(arr[i - 1], temp, count);

            i++;
            count = 1;

            char **check = NULL;
            check = (char**)realloc(arr, sizeof(char*) * i);

            if(!check){
                //free
                for (size_t x = 0; x < i; ++x){
                    free(arr[x]);
                }
                free(arr);
                free(temp);
                printf("[error]");
                exit(-1);
            }
            arr = check;

            arr[i - 1] = NULL;
        } else {
            temp[count - 1] = c;
            count++;

            char *check = NULL;
            check = (char*)realloc(temp, sizeof(char) * count);
            if (!check){
                //free
                for (size_t x = 0; x < i; ++x){
                    free(arr[x]);
                }
                free(arr);
                free(temp);
                printf("[error]");
                exit(-1);
            }
            temp = check;
        }
    }

    char **check = NULL;
    check = justDoIt(arr, i);
    if(check == 0){
        //free
        for (size_t x = 0; x < i; ++x){
            free(arr[x]);
        }
        free(arr);
        free(temp);
        printf("[error]");
        exit(-1);
    }
    arr = check;

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

