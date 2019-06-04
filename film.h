#ifndef FILM_H
#define FILM_H

typedef struct {
    int day;
    int month;
    int year;
} Date;

typedef struct {
    int id;                     // номер в порядке выхода
    char *name;                 // название фильма
    char *genre;                // жанр фильма
    char *age_limit;            // возрастное ограничение: G, PG, PG-13, R, NC-17
    int count;                  // количесво проданных билетов
    double price;               // цена
    double rating;              // рейтинг кинокритиков
    Date date;                  // дата выхода
    struct Film *next;
} Film;

#endif // FILM_H_INCLUDED
