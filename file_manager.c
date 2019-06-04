#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "list.h"

int getStringSize(char *string) {
    int i = 0;
    while (string[i] != '\0') {
        i++;
    }
    return i + 1;
}

Date parseDate(char* string) {
    Date date;
    char* istr;

    istr = strtok(string, ".");
    date.day = atoi(istr);
    istr = strtok(NULL, ".");

    date.month = atoi(istr);
    istr = strtok(NULL, ".");

    date.year = atoi(istr);
    istr = strtok(NULL, ".");

    return date;
};

char *initStringField(char *string) {
    int len = getStringSize(string);
    char *str = (char *) malloc(len * sizeof(char));

    strcpy(str, string);
    return str;
}

void readListFromFile(FILE *file, List *list) {
    if (file != NULL) {
        char scanner[1024];
        while (fgets(scanner, 1024, file)) {
            Film *item = malloc(sizeof(Film));
            int count = 0;
            char *words = strtok(scanner, ";");
            while (words != NULL) {
                if(count == 0) {
                    item->name = initStringField(words);
                }
                else if(count == 1) {
                    item->genre = initStringField(words);
                }
                else if(count == 2) {
                    item->age_limit = initStringField(words);
                }
                else if(count == 3) {
                    item->count = atoi(words);
                }
                else if(count == 4) {
                    item->price = atof(words);
                }
                else if(count == 5) {
                    item->rating = atof(words);
                }
                else if(count == 6) {
                    item->date = parseDate(words);
                }

                count++;
                words = strtok(NULL, ";,");
            }

            add(item, list);
        }
    }
}

void saveListToFile(FILE *file, List *list) {
    Film *current = list->head;
    if (current == NULL)
        return;

    while (current != NULL) {
        fprintf(file, "%s;%s;%s;%d;%.2lf;%.2lf;%d.%d.%d;\n", current->name, current->genre, current->age_limit, current->count, current->price, current->rating,
        current->date.day, current->date.month, current->date.year);
        current = (Film *) current->next;
    }
}
