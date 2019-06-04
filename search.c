#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "list.h"

void getSearchListById(List *list, int id) {
    Film *current = list->head;
    int c = 0;
    while (current != NULL) {
        if(current->id == id) {
            printf("%d. Title: %s\nGenre: %s\nAge limit: %s\nViewer's count: %d\nPrice: %.2lf $\nRating: %.2lf\nRelease Date: %d.%d.%d\n", current->id,
               current->name, current->genre, current->age_limit, current->count, current->price, current->rating,
               current->date.day, current->date.month, current->date.year);
            puts("-----------------------");
            c++;
        }
        current = (Film *) current->next;
    }
    if(c == 0) {
        puts("List is empty");
    }
}

void getSearchListByName(List *list, char *name) {
    Film *current = list->head;
    int c = 0;
    while (current != NULL) {
        if(strcmp(current->name, name) == 0) {
            printf("%d. Title: %s\nGenre: %s\nAge limit: %s\nViewer's count: %d\nPrice: %.2lf $\nRating: %.2lf\nRelease Date: %d.%d.%d\n", current->id,
               current->name, current->genre, current->age_limit, current->count, current->price, current->rating,
               current->date.day, current->date.month, current->date.year);
            puts("-----------------------");
            c++;
        }
        current = (Film *) current->next;
    }
    if(c == 0) {
        puts("List is empty");
    }
}

void getSearchListByGenre(List *list, char *genre) {
    Film *current = list->head;
    int c = 0;
    while (current != NULL) {
        if(strcmp(current->genre, genre) == 0) {
            printf("%d. Title: %s\nGenre: %s\nAge limit: %s\nViewer's count: %d\nPrice: %.2lf $\nRating: %.2lf\nRelease Date: %d.%d.%d\n", current->id,
               current->name, current->genre, current->age_limit, current->count, current->price, current->rating,
               current->date.day, current->date.month, current->date.year);
            puts("-----------------------");
            c++;
        }
        current = (Film *) current->next;
    }
    if(c == 0) {
        puts("List is empty");
    }
}

void getSearchListByAgeLimit(List *list, char *description) {
    Film *current = list->head;
    int c = 0;
    while (current != NULL) {
        if(strcmp(current->age_limit, description) == 0) {
            printf("%d. Title: %s\nGenre: %s\nAge limit: %s\nViewer's count: %d\nPrice: %.2lf $\nRating: %.2lf\nRelease Date: %d.%d.%d\n", current->id,
               current->name, current->genre, current->age_limit, current->count, current->price, current->rating,
               current->date.day, current->date.month, current->date.year);
            puts("-----------------------");
            c++;
        }
        current = (Film *) current->next;
    }
    if(c == 0) {
        puts("List is empty");
    }
}

void getSearchListByCount(List *list, int count) {
    Film *current = list->head;
    int c = 0;
    while (current != NULL) {
        if(current->count == count) {
            printf("%d. Title: %s\nGenre: %s\nAge limit: %s\nViewer's count: %d\nPrice: %.2lf $\nRating: %.2lf\nRelease Date: %d.%d.%d\n", current->id,
               current->name, current->genre, current->age_limit, current->count, current->price, current->rating,
               current->date.day, current->date.month, current->date.year);
            puts("-----------------------");
            c++;
        }
        current = (Film *) current->next;
    }
    if(c == 0) {
        puts("List is empty");
    }
}

void getSearchListByPrice(List *list, double price) {
    Film *current = list->head;
    int c = 0;
    while (current != NULL) {
        if(current->price == price) {
            printf("%d. Title: %s\nGenre: %s\nAge limit: %s\nViewer's count: %d\nPrice: %.2lf $\nRating: %.2lf\nRelease Date: %d.%d.%d\n", current->id,
               current->name, current->genre, current->age_limit, current->count, current->price, current->rating,
               current->date.day, current->date.month, current->date.year);
            puts("-----------------------");
            c++;
        }
        current = (Film *) current->next;
    }
    if(c == 0) {
        puts("List is empty");
    }
}

void getSearchListByRating(List *list, double rating) {
    Film *current = list->head;
    int c = 0;
    while (current != NULL) {
        if(current->rating == rating) {
            printf("%d. Title: %s\nGenre: %s\nAge limit: %s\nViewer's count: %d\nPrice: %.2lf $\nRating: %.2lf\nRelease Date: %d.%d.%d\n", current->id,
               current->name, current->genre, current->age_limit, current->count, current->price, current->rating,
               current->date.day, current->date.month, current->date.year);
            puts("-----------------------");
            c++;
        }
        current = (Film *) current->next;
    }
    if(c == 0) {
        puts("List is empty");
    }
}

void getSearchListByDate(List *list, int day, int month, int year) {
    Film *current = list->head;
    int c = 0;
    while (current != NULL) {
        if((current->date.day == day) && (current->date.month == month) && (current->date.year == year)) {
            printf("%d. Title: %s\nGenre: %s\nAge limit: %s\nViewer's count: %d\nPrice: %.2lf $\nRating: %.2lf\nRelease Date: %d.%d.%d\n", current->id,
               current->name, current->genre, current->age_limit, current->count, current->price, current->rating,
               current->date.day, current->date.month, current->date.year);
            puts("-----------------------");
            c++;
        }
        current = (Film *) current->next;
    }
    if(c == 0) {
        puts("List is empty");
    }
}
