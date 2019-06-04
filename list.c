#include "stdlib.h"
#include "stdio.h"
#include "list.h"

List *makeList() {
    List *list = malloc(sizeof(List));
    if (!list) {
        return NULL;
    }
    list->head = NULL;
    list->size = 0;
    return list;
}

void add(Film *film, List *list) {
    Film *current = NULL;
    film->next = NULL;
    film->id = 0;

    if (list->head == NULL) {
        list->head = film;
    } else {
        film->id++;
        current = list->head;
        while (current->next != NULL) {
            film->id++;
            current = (Film *) current->next;
        }
        current->next = (struct Film *) film;
    }
}

Film *get(int id, List *list) {
    Film *current = list->head;
    while (current != NULL) {
        if (current->id == id) {
            return current;
        }
        current = (Film *) current->next;
    }
    return NULL;
}

int delete(int id, List *list) {
    Film *current = list->head;
    Film *previous = current;
    while (current != NULL) {
        if (current->id == id) {
            previous->next = current->next;
            //если это голова, то двинем ее
            if (current == list->head)
                list->head = (Film *) current->next;
            free(current);
            return 1; // 1 - если удалилось
        }
        //
        previous = current;
        current = (Film *) current->next;
    }
    return 0; // 0 - если нет
}

void display(List *list) {
    Film *current = list->head;
    if (current == NULL) {
        printf("List is empty\n");
        return;
    }

    while (current != NULL) {
        printf("%d. Title: %s\nGenre: %s\nAge limit: %s\nViewer's count: %d\nPrice: %.2lf $\nRating: %.2lf\nRelease Date: %d.%d.%d\n", current->id,
               current->name, current->genre, current->age_limit, current->count, current->price, current->rating,
               current->date.day, current->date.month, current->date.year);
        puts("-----------------------");
        current = (Film *) current->next;
    }
}

void destroy(List *list) {
    Film *current = list->head;
    Film *next = current;
    while (current != NULL) {
        next = (Film *) current->next;
        free(current);
        current = next;
    }
    free(list);
}
