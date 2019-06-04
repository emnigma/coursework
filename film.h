#ifndef FILM_H
#define FILM_H

typedef struct {
    int day;
    int month;
    int year;
} Date;

typedef struct {
    int id;                     // ����� � ������� ������
    char *name;                 // �������� ������
    char *genre;                // ���� ������
    char *age_limit;            // ���������� �����������: G, PG, PG-13, R, NC-17
    int count;                  // ��������� ��������� �������
    double price;               // ����
    double rating;              // ������� ������������
    Date date;                  // ���� ������
    struct Film *next;
} Film;

#endif // FILM_H_INCLUDED
