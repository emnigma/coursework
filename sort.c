#include <string.h>
#include "list.h"
#include "file_manager.h"

void swap(Film *first, Film *second) {

    int id = first->id;
    char *name = initStringField(first->name);
    char *genre = initStringField(first->genre);
    char *age_limit = initStringField(first->age_limit);
    int count = first->count;
    double price = first->price;
    double rating = first->rating;
    Date date = first->date;

    first->id = second->id;
    first->name = second->name;
    first->genre = second->genre;
    first->age_limit = second->age_limit;
    first->count = second->count;
    first->price = second->price;
    first->rating = second->rating;
    first->date.day = second->date.day;
    first->date.month = second->date.month;
    first->date.year = second->date.year;

    second->id = id;
    second->name = name;
    second->genre = genre;
    second->age_limit = age_limit;
    second->count = count;
    second->price = price;
    second->rating = rating;
    second->date.day = date.day;
    second->date.month = date.month;
    second->date.year = date.year;
}

int compareDates(Date d1, Date d2) {
    if(d1.year > d2.year)
        return 1;
    else if(d1.year < d2.year)
        return 2;
    else {
        if(d1.month > d2.month)
            return 1;
        else if(d1.month < d2.month)
            return 2;
        else {
            if(d1.day > d2.day)
                return 1;
            else
                return 2;
        }
    }
}

void sortById(List *list) {
    int swapped;
    Film *film;
    Film *filmNext = NULL;

    if (list->head == NULL)
        return;

    do {
        swapped = 0;
        film = list->head;

        while (film->next != NULL) {
            filmNext = (Film *) film->next;
            if (film->id > filmNext->id) {
                swap(film, (Film *) film->next);
                swapped = 1;
            }
            film = (Film *) film->next;
        }
        film = filmNext;
    } while (swapped);
}

void sortByName(List *list) {
    int swapped;
    Film *film;
    Film *filmNext = NULL;

    if (list->head == NULL)
        return;

    do {
        swapped = 0;
        film = list->head;

        while (film->next != NULL) {
            filmNext = (Film *) film->next;
            if (strcmp(film->name, filmNext->name) > 0) {
                swap(film, (Film *) film->next);
                swapped = 1;
            }
            film = (Film *) film->next;
        }
        film = filmNext;
    } while (swapped);
}

void sortByGenre(List *list) {
    int swapped;
    Film *film;
    Film *filmNext = NULL;

    if (list->head == NULL)
        return;

    do {
        swapped = 0;
        film = list->head;

        while (film->next != NULL) {
            filmNext = (Film *) film->next;
            if (strcmp(film->genre, filmNext->genre) > 0) {
                swap(film, (Film *) film->next);
                swapped = 1;
            }
            film = (Film *) film->next;
        }
        film = filmNext;
    } while (swapped);
}

void sortByAgeLimit(List *list) {
    int swapped;
    Film *film;
    Film *filmNext = NULL;

    if (list->head == NULL)
        return;

    do {
        swapped = 0;
        film = list->head;

        while (film->next != NULL) {
            filmNext = (Film *) film->next;
            if (strcmp(film->age_limit, filmNext->age_limit) > 0) {
                swap(film, (Film *) film->next);
                swapped = 1;
            }
            film = (Film *) film->next;
        }
        film = filmNext;
    } while (swapped);
}

void sortByCount(List *list) {
    int swapped;
    Film *film;
    Film *filmNext = NULL;

    if (list->head == NULL)
        return;

    do {
        swapped = 0;
        film = list->head;

        while (film->next != NULL) {
            filmNext = (Film *) film->next;
            if (film->count > filmNext->count) {
                swap(film, (Film *) film->next);
                swapped = 1;
            }
            film = (Film *) film->next;
        }
        film = filmNext;
    } while (swapped);
}

void sortByPrice(List *list) {
    int swapped;
    Film *film;
    Film *filmNext = NULL;

    if (list->head == NULL)
        return;

    do {
        swapped = 0;
        film = list->head;

        while (film->next != NULL) {
            filmNext = (Film *) film->next;
            if (film->price > filmNext->price) {
                swap(film, (Film *) film->next);
                swapped = 1;
            }
            film = (Film *) film->next;
        }
        film = filmNext;
    } while (swapped);
}

void sortByRating(List *list) {
    int swapped;
    Film *film;
    Film *filmNext = NULL;

    if (list->head == NULL)
        return;

    do {
        swapped = 0;
        film = list->head;

        while (film->next != NULL) {
            filmNext = (Film *) film->next;
            if (film->rating > filmNext->rating) {
                swap(film, (Film *) film->next);
                swapped = 1;
            }
            film = (Film *) film->next;
        }
        film = filmNext;
    } while (swapped);
}

void sortByDate(List *list) {
    int swapped;
    Film *film;
    Film *filmNext = NULL;

    if (list->head == NULL)
        return;

    do {
        swapped = 0;
        film = list->head;

        while (film->next != NULL) {
            filmNext = (Film *) film->next;
            if (compareDates(film->date, filmNext->date) == 1) {
                swap(film, (Film *) film->next);
                swapped = 1;
            }
            film = (Film *) film->next;
        }
        film = filmNext;
    } while (swapped);
}
