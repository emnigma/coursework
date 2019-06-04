#ifndef LIST_H
#define LIST_H

#include "film.h"

typedef struct {
    Film *head;
    int size;
} List;

List *makeList();

void add(Film *item, List *list); ///добавить запись

Film *get(int id, List *list); ///найти указатель на элемент по id

int delete(int id, List *list); ///удалить по id

void display(List *list); ///вывести список

void destroy(List *list); ///очистить память

#endif //LIST_H
