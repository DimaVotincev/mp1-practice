#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Passport.h"


void show_pass(Passport* pass) {

    printf("Серия: %d \n", pass->seria);
    printf("Номер: %d \n", pass->nomer);
    printf("Кем выдан: %s \n", pass->kem);
    printf("Когда выдан: %s \n", pass->kogda.str);
    printf("Дата рождения: %s \n", pass->birthday.str);
    printf("Прописка: %s \n", pass->propiska);
    
}
