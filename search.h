#ifndef SEARCH_H
#define SEARCH_H

#include "list.h"

void getSearchListById(List *list, int id);

void getSearchListByName(List *list, char *name);

void getSearchListByGenre(List *list, char *genre);

void getSearchListByAgeLimit(List *list, char *age_limit);

void getSearchListByCount(List *list, int count);

void getSearchListByPrice(List *list, double price);

void getSearchListByRating(List *list, double rating);

void getSearchListByDate(List *list, int day, int month, int year);

#endif //SEARCH_H
