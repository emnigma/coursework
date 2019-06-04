#ifndef LIST_H
#define LIST_H

#include "film.h"

typedef struct {
    Film *head;
    int size;
} List;

List *makeList();

void add(Film *item, List *list); ///�������� ������

Film *get(int id, List *list); ///����� ��������� �� ������� �� id

int delete(int id, List *list); ///������� �� id

void display(List *list); ///������� ������

void destroy(List *list); ///�������� ������

#endif //LIST_H
