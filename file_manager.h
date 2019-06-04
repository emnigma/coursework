#ifndef MANAGER_H
#define MANAGER_H

#include <stdlib.h>
#include <stdio.h>
#include "list.h"

int getStringSize(char *string); ///����� ������

char *initStringField(char *string); ///�������� ������

void readListFromFile(FILE *file, List *list); ///������ ������ �� �����

void saveListToFile(FILE *file, List *list); ///��������� ���� � ����

#endif //FILE_MANAGER_H
