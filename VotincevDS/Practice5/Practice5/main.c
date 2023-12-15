#include <stdio.h>
#include <windows.h>
#include <fileapi.h>
#include <time.h>
#include <string.h>

typedef struct  {
    char* first;
    int second;
} pair;

pair* get_way_files(char* way);

int count_files(char way[]);

void pr_files(pair* files_ns, int cf);

void make_way(char* way);

int check_way(char* way);

void merge(pair* a, int left, int mid, int right);

void mergesort(pair* a, int left, int right);

void sort(pair files_ns[], int left, int right, char el, int cf);

void cpy(pair* a, pair* b, int cf);

void select_sort(pair* files_ns, int cf);

void insert_sort(pair* files_ns, int cf);

int main() {
    system("chcp 1251");
    pair *files_ns; 
    // массив, содержащий информацию о файлах в каталоге
    // содержит имя и размер каждого файла
    while (1) {
        
        char way[255];
        int cw; // check way
        printf("\t\tВведите полный путь к папке\n");
        printf("\t (для завершения работы введите 0 )\n");
        scanf("%s", &way);
        if (way[0] == '0') {
            break;
        }
        make_way(&way);

        cw = check_way(&way);
        if (cw == 0) {
            printf("Неверный путь\n");
            continue;
        }

        // получение файлов по пути
        files_ns = get_way_files(&way);
        
        while (1) {
            clock_t start;
            clock_t end;
            
            double spenttime;
            int cf = count_files(way);
            char ans[10];
            
            printf("Какую сортировку будем использовать?\n");
            printf(" 2 - выбором | 3 - вставкой | 4 - слиянием\n");
            printf("(\tдля ввода нового пути введите 0  )\n");
            printf("(\tдля вывода исходного массива введите 9 )\n\n");
            printf("->");
            scanf("%s", &ans);
            printf("\n\n");
            int i = 0; 
            char el =  ans[0];
            if (el == '0') {
                break;
            }
            else if (el == '9') {
                pr_files(files_ns, cf);
                
            }

            pair* f = (pair*)malloc(cf * sizeof(pair));
            cpy(files_ns, f,cf);
            
            start = clock(); // начало отсчёта
            sort(f, 0, cf - 1,el, cf);
            end = clock(); // конец отсчёта
            spenttime = (double)(end - start) / CLOCKS_PER_SEC;
            if (el != '9') 
                printf("\n Время: %.5f сек \n\n\n", spenttime);
            
            
            free(f);
            
        }
    
        

        
        
        free(files_ns);
        printf("\n\n");
    }
    
    
}

void cpy(pair* a, pair* b,int cf) {
    int i = 0;
    for (i; i < cf;i++) {
        b[i].first = _strdup(a[i].first);
        b[i].second = a[i].second;
    }
}

void insert_sort(pair* files_ns, int cf) {
    for (int i = 1; i < cf; i++) {
        int key = files_ns[i].second;
        int j = i - 1;
        while (j >= 0 && files_ns[j].second > key) {
            files_ns[j + 1].second = files_ns[j].second;
            j--;
        }
        files_ns[j + 1].second = key;
    }
}

void select_sort(pair* files_ns, int cf) {
    int i = 0, j;
    for (i;i < cf-1; i++) {
        for (j = i + 1;j < cf; j++) {
            int *a = &files_ns[i].second;
            int *b = &files_ns[j].second;
            if (*a > *b) {
                int tmp = *a;
                *a = *b;
                *b = tmp;
            }
        }
    }
}


void sort(pair files_ns[], int left, int right, char el, int cf) {

    
    switch (el) {
    case '2':
        select_sort(files_ns, cf);
        break;
    case '3':
        insert_sort(files_ns, cf);
        break;
    case '4':
        
        mergesort(files_ns, 0, cf - 1);
        
        
        break;
    default:
        
        return;
    }
    pr_files(files_ns,cf);
}



void pr_files(pair* files_ns,int cf) {
    int i = 0;
    for (i;i < cf;i++) {
        printf("%s %d \n", files_ns[i].first, files_ns[i].second);
    }
}


void make_way(char* way) {
    int ln = strlen(way);
    if (way[ln - 1] != '*') {
        way[ln + 1] = way[ln];
        way[ln] = '*';

    }
}


int check_way(char* way) {

    WIN32_FIND_DATAA finddata;
    HANDLE hFind = FindFirstFileA(way, &finddata);
    if (hFind == INVALID_HANDLE_VALUE) {
        
        return 0;
    }
    return 1;
}



int count_files(char way[]) {
    WIN32_FIND_DATAA finddata;
    HANDLE hFind = FindFirstFileA(way, &finddata);
    int c = 0;
    do {
        c++;
    } while (FindNextFileA(hFind, &finddata) != NULL);
    return c;
}





pair* get_way_files(char* way) {
    int i = 0;
    int cf;
    pair* files_ns;
    WIN32_FIND_DATAA finddata;
    HANDLE hFind = FindFirstFileA(way, &finddata);
    if (hFind == INVALID_HANDLE_VALUE) {
        printf("Неверный путь\n");
        return 1;
    }
    cf = count_files(way);
    files_ns = (pair*)malloc(cf * sizeof(pair));
    
    do {
        char* filename = finddata.cFileName;
        int filesize = finddata.nFileSizeLow;
        
        files_ns[i].first = _strdup(finddata.cFileName);
        files_ns[i].second = filesize;
        
        
        i++;
        
    } while (FindNextFileA(hFind, &finddata) != NULL);
    FindClose(hFind);
        
    return files_ns;
}






void merge(pair* arr, int left, int middle, int right) {
    int i, j, k;
    int n1 = middle - left + 1;
    int n2 = right - middle;   
    pair* L = (pair*)malloc(n1 * sizeof(pair));
    pair* R = (pair*)malloc(n2 * sizeof(pair));   
    
    cpy(arr, L, n1);
   
    
    cpy(arr, R, n2);
   
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (L[i].second <= R[j].second) {
            arr[k].second = L[i].second;
            arr[k].first = L[i].first;
            i++;
        }
        else {
            arr[k].second = R[j].second;
            arr[k].first = R[j].first;
            j++;
        }
        k++;
    }   
    while (i < n1) {
        arr[k].second = L[i].second;
        arr[k].first = L[i].first;
        i++;
        k++;
    }
   while (j < n2) {
        arr[k].second = R[j].second;
        arr[k].first = R[j].first;
        j++;
        k++;
    }
}


void mergesort(pair* arr, int left, int right) {
    if (left < right) { 
        int mid = left + (right - left) / 2;
        mergesort(arr, left, mid);
        mergesort(arr, mid + 1, right);       
        merge(arr, left, mid, right);
    }
}
