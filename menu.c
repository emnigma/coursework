#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include "list.h"
#include "file_manager.h"
#include "checks.h"
#include "search.h"
#include "sort.h"

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

Film *readItem(Film *film) {

    film->name = enterString("Write name of film: ");
    film->genre = enterString("Write genre of film: ");
    film->age_limit = enterString("Write age limit of film: ");

    film->count = enterInt("Write count of views: ");
    film->date.day = enterInt("Write day of release: ");
    film->date.month = enterInt("Write month of release: ");
    film->date.year = enterInt("Write year of release: ");

    film->price = enterDouble("Write ticket price: ");
    film->rating = enterDouble("Write film critics rating: ");

    return film;
}

void showAbout() {
    system(CLEAR);
    puts("-------INFO-------");
    puts("This project might be useful for those who wants to store");
    puts("info about movies, for example, the cinemas");
    puts("For each option there would be a brief explanation");
    puts("------------------");
    printf("Press anything to continue: ");
    getch();
}

void showAdd(List *list) {
    Film *film = malloc(sizeof(Film));

    system(CLEAR);
    puts("-------ADD MENU-------");
    readItem(film);

    add(film, list);
    puts("Item was added to library");
    printf("Press any button: ");
    getch();
}

void showEdit(List *list) {
    int id = 0;

    system(CLEAR);
    puts("-------EDIT MENU-------");

    id = enterInt("Write ID of note to edit: ");

    Film *film = get(id, list);

    if (film == NULL) {
        puts("There is no such id");
        printf("Press any button: ");
        getch();
    } else {
        readItem(film);

        puts("Item was edited");
        printf("Press any button: ");
        getch();
    }
}

void showDelete(List *list) {
    int id = 0;

    system(CLEAR);
    puts("-------DELETE MENU-------");
    id = enterInt("Write ID of note to delete: ");
    Film *film = get(id, list);

    if (film == NULL) {
        puts("There is no such id");
        printf("Press any button: ");
        getch();
    } else {
        delete(id, list);
        puts("Note was deleted");
        printf("Press any button: ");
        getch();
    }
}

void showList(List *list) {
    system(CLEAR);
    puts("-------YOUR LIST-------");
    display(list);
    printf("Press any button: ");
    getch();
}

void showSearchMenu(List *list) {
    int id = 0;
    system(CLEAR);
    puts("-------SEARCH MENU-------");
    puts("0. ID");
    puts("1. Name");
    puts("2. Genre");
    puts("3. Age limit");
    puts("4. Count");
    puts("5. Price");
    puts("6. Rating");
    puts("7. Release date");
    puts("-------------------------");
    id = enterInt("Write your field: ");

    if (id == 0) {
        id = enterInt("Write film id: ");
        puts("");
        getSearchListById(list, id);
    }
    else if (id == 1) {
        char *name = enterString("Write film's title: ");
        puts("");
        getSearchListByName(list, name);
    }
    else if (id == 2) {
        char *genre = enterString("Write film's genre: ");
        puts("");
        getSearchListByGenre
        (list, genre);
    }
    else if (id == 3) {
        char *age_limit = enterString("Write film's age limit: ");
        puts("");
        getSearchListByAgeLimit(list, age_limit);
    }
    else if (id == 4) {
        int count = enterInt("Write count of views: ");
        puts("");
        getSearchListByCount(list, count);
    }
    else if (id == 5) {
        double price = enterDouble("Write ticket price: ");
        puts("");
        getSearchListByPrice(list, price);
    }
    else if (id == 6) {
        double rating = enterDouble("Write film's rating: ");
        puts("");
        getSearchListByRating(list, rating);
    }
    else if (id == 7) {
        int day = enterInt("Write release day: ");
        int month = enterInt("Write release month: ");
        int year = enterInt("Write release year: ");
        puts("");
        getSearchListByDate(list, day, month, year);
    }
    printf("Press any button: ");
    getch();
}

void showSortMenu(List *list) {
    int id = 0;
    system(CLEAR);
    puts("-------SORT MENU-------");
    puts("0. ID");
    puts("1. Name");
    puts("2. Genre");
    puts("3. Age limit");
    puts("4. Viewer's count");
    puts("5. Price");
    puts("6. Rating");
    puts("7. Release Date");
    puts("-----------------------");
    id = enterInt("Write your field: ");

    if (id == 0) {
        sortById(list);
    }
    else if (id == 1) {
        sortByName(list);
    }
    else if (id == 2) {
        sortByGenre(list);
    }
    else if (id == 3) {
        sortByAgeLimit(list);
    }
    else if (id == 4) {
        sortByCount(list);
    }
    else if (id == 5) {
        sortByPrice(list);
    }
    else if (id == 6) {
        sortByRating(list);
    }
    else if (id == 7) {
        sortByDate(list);
    }

    puts("List was sorted");
    printf("Press any button: ");
    getch();
}

void showMenu(List *list) {
    int menu = 0;
    while (menu != 7) {
        system(CLEAR);
        puts("-------MAIN MENU-------");
        puts("0. About");
        puts("1. Add new note");
        puts("2. Edit note");
        puts("3. Delete note");
        puts("4. Show list");
        puts("5. Search");
        puts("6. Sort");
        puts("7. Exit");
        puts("-----------------------");
        menu = enterInt("Choose option: ");

        if (menu == 0) {
            showAbout();
        }
        else if (menu == 1) {
            showAdd(list);
        }
        else if (menu == 2) {
            showEdit(list);
        }
        else if (menu == 3) {
            showDelete(list);
        }
        else if (menu == 4) {
            showList(list);
        }
        else if (menu == 5) {
            showSearchMenu(list);
        }
        else if (menu == 6) {
            showSortMenu(list);
        }
    }
}
