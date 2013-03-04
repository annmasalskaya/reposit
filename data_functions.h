#ifndef DATA_FUNCTIONS_H
#define DATA_FUNCTIONS_H

struct Time // дата поступления
{
    int day;
    int month;
    int year;
};
struct Personal_inf
{
    Time date;
    char surname[30];  //фамилия
    int  experience; // стаж , в годах
    int encouragement_collecting; // поощрения / взыскания

};
typedef int (*Ptf)(Personal_inf, Personal_inf);
int clearscreen();
void draw_line (); // рисует линии для таблицы
//void menu_sort (Personal_inf *mass, int N);
int cmp_surname (Personal_inf x, Personal_inf y);
int cmp_date (Personal_inf x,Personal_inf y);
int cmp_experience (Personal_inf x,Personal_inf y);
int cmp_encouragement_collecting (Personal_inf x,Personal_inf y);
void create_data(Personal_inf *mass,int N);
void write_to_file(Personal_inf *mass,int N);
void read_from_file(Personal_inf *mass,int N);
void output_table (Personal_inf *mass,int N);
//void swap (Personal_inf  &a, Personal_inf  &b);
//void repair (Personal_inf *mass,int i, int N,Ptf cmp, int order);
//void build(Personal_inf *mass, int N, int choose,Ptf cmp, int order);
void piramida_sorting(Personal_inf *mass, int N,Ptf cmp, int order=1);

#endif

