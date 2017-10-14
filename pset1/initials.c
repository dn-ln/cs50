#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(void) {
    char* str_arr = NULL;
    if (malloc(sizeof(char) * 100) != NULL) {
        str_arr = malloc(sizeof(char) * 100);
    }
    fgets(str_arr, sizeof(char) * 100, stdin);
    size_t length = strlen(str_arr);
    if (str_arr[length - 1] == '\n') {
        str_arr[length - 1] = '\0';
    }
    char* name = malloc(sizeof(char) * length);
    strncpy(name, str_arr, length);
    memset(str_arr, 0, sizeof(char) * 100);
    int if_word = 0;
    int append_count = 0;
    for (int i = 0; i < length - 1; i++) {
        int new_if_word;
        if (name[i] == ' ') {
            new_if_word = 0;
        } else {
            new_if_word = 1;
        }
        if (if_word == 0 && new_if_word == 1) {
            str_arr[append_count] = toupper(name[i]);
            append_count += 1;
        }
        if_word = new_if_word;
    }
    printf("%s\n", str_arr);
    free(name);
    free(str_arr);
}
