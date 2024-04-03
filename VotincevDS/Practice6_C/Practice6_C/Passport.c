#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Passport.h"


void show_pass(Passport* pass) {

    printf("�����: %d \n", pass->seria);
    printf("�����: %d \n", pass->nomer);
    printf("��� �����: %s \n", pass->kem);
    printf("����� �����: %s \n", pass->kogda.str);
    printf("���� ��������: %s \n", pass->birthday.str);
    printf("��������: %s \n", pass->propiska);
    
}

void free_pass(Passport pass) {
    free_date(pass.birthday);
    free_date(pass.kogda);
    free(pass.kem);
    free(pass.propiska);
    
}

