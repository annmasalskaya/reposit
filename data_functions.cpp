#include "data_functions.h"
#include<iostream>
#include<cstdlib>
#include <cstring>
#include <fstream>
using namespace std;

int clearscreen()
{
    return system("clear");
}
int cmp_surname (Personal_inf x, Personal_inf y)
{
    return strcmp(x.surname, y.surname);
}
int cmp_date (Personal_inf x,Personal_inf y)
{
    return (372*(x.date.year-1)+31*(x.date.month-1)+x.date.day)- (372*(y.date.year-1)+31*(y.date.month-1)+y.date.day);
}
int cmp_experience (Personal_inf x,Personal_inf y)
{
    return x.experience- y.experience;

}
int cmp_encouragement_collecting (Personal_inf x,Personal_inf y)
{
    return x.encouragement_collecting- y.encouragement_collecting;

}
void create_data(Personal_inf *mass,int N)
{
    fstream file;
    file.open("surname.txt");
    for(int i=0; i<N && !file.eof(); ++i)
    {
        file>>mass[i].surname;
    }
    for (int i=0; i<N; i++)
    {
        mass[i].date.day=rand()%31+1;
        mass[i].date.month=rand()%12+1;
        mass[i].date.year=rand()%5+2008;
        mass[i].experience=rand()%10+1;
        mass[i].encouragement_collecting=rand()%20-10;
    }

}
void write_to_file(Personal_inf *mass,int N)
{
    fstream file;
    file.open ("data.txt",ios::out|ios::binary);
    file.write((char *)&N,sizeof(N));
    file.write((char *)mass,N*sizeof(Personal_inf));
    file.close();
}
void read_from_file(Personal_inf *mass,int N)
{
    fstream file;
    file.open ("data.txt",ios::in|ios::binary);
    file.read((char *)&N,sizeof(int));
    file.read((char *)mass,N*sizeof(Personal_inf));
    file.close();

}
void draw_line () // линии для таблицы
{
    char simbol_horiz='-';
    {
        for ( int k=0; k<120; k++)
            cout<< simbol_horiz;
    }
}
void output_table(Personal_inf *mass,int N)
{

    fstream file;
    file.open ("data.txt",ios::in|ios::binary);
    draw_line();
    cout<<endl;
    char simbol_vert='|';
    cout<<simbol_vert<<"  ";
    cout.width(10);
    cout<<"ФАМИЛИЯ";
    cout.width(15);
    cout<<simbol_vert<<"  ";
    cout.width(10);
    cout<< "ДАТА ПОСТУПЛЕНИЯ";
    cout.width(10);
    cout<<simbol_vert<<"  ";
    cout.width(10);
    cout<<"СТАЖ(в годах)";
    cout.width(3);
    cout<<simbol_vert<<"  ";
    cout.width(7);
    cout<<"ПООЩРЕНИЯ/ВЗЫСКАНИЯ(в базовых величинах)";
    cout.width(2);
    cout<<simbol_vert<<endl;
    for (int i=0; i<N; ++i)
    {
        draw_line();
        cout<<endl;
        cout<<simbol_vert<<"  ";
        cout.width(10);
        cout<<mass[i].surname;
        cout.width(15);
        cout<<simbol_vert<<"     ";
        if (mass[i].date.day<10)
        {
            cout<< '0'<<mass[i].date.day;
        }
        else cout<< mass[i].date.day;
        cout<<".";
        if (mass[i].date.month<10)
        {
            cout<< '0'<<mass[i].date.month;
        }
        else cout<< mass[i].date.month;
        cout<<".";
        cout<< mass[i].date.year<<" г.";
        cout.width(10);
        cout<<simbol_vert;
        cout.width(10);
        cout<<mass[i].experience;
        cout.width(10);
        cout<<simbol_vert;
        cout.width(15);
        cout<<mass[i].encouragement_collecting;
        cout<<endl;
        if ( i==N-1)
        {
            draw_line();
            cout<<endl;
        }
    }
    file.close();
}

void swap (Personal_inf  &a, Personal_inf  &b)
{
    Personal_inf temp=a;
    a=b;
    b=temp;

}
void repair (Personal_inf *mass,int i, int N,Ptf cmp, int order) // восттановление пирамиды (са­мый боль­ший эле­мент  на­хо­дит­ся вна­ча­ле) по возрастанию
{

    int l=2*i+1; // левый потомок
    int r=2*i+2; // правый потомок
    int larg=i;
    if ( order==1)
    {
        if(l<N && cmp(mass[l],mass[i])>0)larg=l;
        if(r<N && cmp(mass[r], mass[larg])>0)larg=r;
    }
    else
    {
        if(l<N && cmp(mass[l],mass[i])<0)larg=l;
        if(r<N && cmp(mass[r], mass[larg])<0)larg=r;
    }
    if(larg!=i)
    {
        swap(mass[larg],mass[i]); //обменять местами mass[larg] & mass[i]
        repair(mass,larg,N,cmp,order);
    }

}

void build(Personal_inf *mass, int N,Ptf cmp,int  order) //построение пирамиды из массива. последние n/2 эл.становятся основанием пирамиды( у них нет потомков)
{
    for (int i=N/2; i>=0; --i) repair (mass,i,N,cmp, order);
}

void piramida_sorting(Personal_inf *mass, int N,Ptf cmp, int order)
{

    build (mass, N,cmp, order);
    for (  int i=N-1; i>=1; --i)
    {
        swap(mass[0],mass[i]); // в пирамиде 1 элемент( =0)  = макс.элемент(larg) - обменять местами mass[larg] & mass[i]
        --N;
        repair (mass, 0, N,cmp, order);
    }
}




