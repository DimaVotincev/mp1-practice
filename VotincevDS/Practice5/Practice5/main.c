#include <stdio.h>
#include <windows.h>

struct pair {
    char* first[255];
    int second;
};

int main() {
    char* a[255];
    // https://learn.microsoft.com/ru-ru/windows/win32/api/fileapi/nf-fileapi-getfilesizeex
    scanf("%s", a);
    printf("%p",FindFirstFileA(a, NULL));
}