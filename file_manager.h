#ifndef MANAGER_H
#define MANAGER_H

#include <stdlib.h>
#include <stdio.h>
#include "list.h"

int getStringSize(char *string); ///длина строки

char *initStringField(char *string); ///создание строки

void readListFromFile(FILE *file, List *list); ///чтение списка из файли

void saveListToFile(FILE *file, List *list); ///сохранить лист в файл

#endif //FILE_MANAGER_H
