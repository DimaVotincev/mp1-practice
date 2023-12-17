#include <stdio.h>
#include <windows.h>
#include <fileapi.h>
#include <time.h>
#include <string.h>

typedef struct  {
    char* first;  
    UINT64 second;
} pair;

pair* get_way_files(char* way,int cf);

void qsort(pair* files_ns, int n);

int count_files(char way[]);

void pr_files(pair* files_ns, int cf);

void make_way(char* way);

int check_way(char* way);

void merge(pair* a, int left, int mid, int right);

void mergesort(pair* a, int left, int right);

int sort(pair files_ns[], int left, int right, char el, int cf);

void cpy(pair* a, pair* b, int cf);

void select_sort(pair* files_ns, int cf);

void insert_sort(pair* files_ns, int cf);

void swap(pair* files_ns,int i ,int j);

int main() {
    system("chcp 1251");
    pair *files_ns; 
    // ������, ���������� ���������� � ������ � ��������
    // �������� ��� � ������ ������� �����
    while (1) {
        
        char way[255];
        int cw; // check way
        int cf;
        printf("\t\t������� ������ ���� � �����\n");
        printf("\t (��� ���������� ������ ������� 0 )\n");
        scanf("%s", &way);
        if (way[0] == '0') {
            break;
        }
        make_way(&way);

        cw = check_way(&way);
        if (cw == 0) {
            printf("�������� ����\n");
            continue;
        }
        cf =  count_files(way);
        // ��������� ������ �� ����
        files_ns = get_way_files(&way,cf);
        
        while (1) {
            clock_t start;
            clock_t end;
            int check;
            double spenttime;
            
            char ans[10];
            printf("\n\n");
            printf("����� ���������� ����� ������������?\n");
            printf(" 2 - ������� | 3 - �������� | 4 - �������� | 5 - �������\n");
            printf("(\t��� ����� ������ ���� ������� 0  )\n");
            printf("(\t��� ������ ��������� ������� ������� 9 )\n\n");
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
            
            start = clock(); // ������ �������
            check = sort(f, 0, cf - 1,el, cf);
            end = clock(); // ����� �������
            spenttime = (double)(end - start) / CLOCKS_PER_SEC;
            if (check) 
                printf("\n �����: %.8f ��� \n\n\n", spenttime);
            
            
            free(f);
            
        }
    
        

        
        
        free(files_ns);
        printf("\n\n");
    }
    
    
}

void swap(pair* files_ns,int i, int j) {
    UINT64* a = &files_ns[i].second;
    UINT64* b = &files_ns[j].second;
    
    if (*a > *b) {
        UINT64 tmp = *a;  
        char* tmpw = files_ns[i].first;

        *a = *b;   
        files_ns[i].first = files_ns[j].first;
        *b = tmp;
        files_ns[j].first = tmpw;

        
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
        UINT64 key = files_ns[i].second;
        char* keyw = files_ns[i].first;
        int j = i - 1;
        while (j >= 0 && files_ns[j].second > key) {
            files_ns[j + 1].second = files_ns[j].second;
            files_ns[j + 1].first = files_ns[j].first;
            j--;
        }
        files_ns[j + 1].second = key;
        files_ns[j + 1].first = keyw;
    }
}

void select_sort(pair* files_ns, int cf) {
    int i = 0, j;
    for (i;i < cf-1; i++) {
        for (j = i + 1;j < cf; j++) {
            
            swap(files_ns,i,j);
        }
    }
}


int sort(pair files_ns[], int left, int right, char el, int cf) {

    
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
    case '5':
        qsort(files_ns,cf);
        break;
    default:
        
        return 0;
    }
    pr_files(files_ns,cf);
    return 1;
}



void pr_files(pair* files_ns,int cf) {
    int i = 0;
    for (i;i < cf;i++) {
        printf("%s %llu \n", files_ns[i].first, files_ns[i].second);
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
        if (finddata.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
            continue;
        }
        c++;
    } while (FindNextFileA(hFind, &finddata) != NULL);
    return c;
}





pair* get_way_files(char* way,int cf) {
    int i = 0;
    pair* files_ns;
    WIN32_FIND_DATAA finddata;
    HANDLE hFind = FindFirstFileA(way, &finddata);
    
    
    files_ns = (pair*)malloc(cf * sizeof(pair));
    
    do {
        char* filename = finddata.cFileName;       
        ULARGE_INTEGER fullsize;
        fullsize.HighPart = finddata.nFileSizeHigh;
        fullsize.LowPart = finddata.nFileSizeLow;
        UINT64 filesize = fullsize.QuadPart;
        
        if (!(finddata.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
            files_ns[i].first = _strdup(finddata.cFileName);
            
            files_ns[i].second = filesize;
            
            i++;
            continue;
            
        } 

        

        // FILE_ATTRIBUTE_DIRECTORY
        
        
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
    
    for (i = 0; i < n1; i++) {
        L[i].second = arr[left + i].second;
        L[i].first = arr[left + i].first;
    }
    for (j = 0; j < n2; j++) {
        R[j].second = arr[middle + 1 + j].second;
        R[j].first = arr[middle + 1 + j].first;
    }
   
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


void qsort(pair* a, int n) {


    int i = 0, j = n - 1;
    UINT32 pivot = a[(n - 1) / 2].second;

    while (i <= j) {
        while (a[i].second < pivot) {
            i++;
        }
        while (a[j].second > pivot) {
            j--;
        }
        if (i <= j) {
            UINT64 tmp = a[i].second;
            char* tmpw = a[i].first;

            a[i].second = a[j].second;
            a[i].first = a[j].first;
            a[j].second = tmp;
            a[j].first = tmpw;
            i++;
            j--;
        }
    }

    if (j > 0) {
        qsort(a, j + 1);
    }
    if (i < n - 1) {
        qsort(&a[i], n - i);
    }
}