#include<iostream>
#include<cstdlib>
#include <fstream>
#include "data_functions.h"
using namespace std;

void  menu_sort (Personal_inf *mass, int N)
{
    int choose;
    int order;
    Ptf ar[4]= {cmp_surname,cmp_date,cmp_experience,cmp_encouragement_collecting };
    cout<<"Выполнить сортировку: \n 1. - по фамилии \n 2. - по дате поступления \n 3. - по стажу \n 4.- по поощрениям/взысканиям"<<endl;
    cin>>choose;
    cout<<"Выполнить сортировку: \n 1. - по возрастанию \n 2. - по убыванию"<<endl;
    cin>>order;
    piramida_sorting(mass,N,ar[choose-1],order);
}
int main()
{
    int N; // кол-во строк в таблице
    cout<<"\n\n\n\n\n\n\n\n\n\n\n";
    cout.width(60);
    cout<<"MINI DATABASE \n\n";
    cout.width(69);
    cout<<"[Отдел кадров] ";
    cout.width(70);
    cout<<"\n\n\n\n\n\n\n\n\n\n\n Нажмите  1, чтобы сгенерировать базу данных.....";
    int choose;
    cin>>choose;
    if(choose==1)
    {
        clearscreen();
        cout<<" Введите количество строк в таблице: "<<endl;// количество строк в таблице данных
        cin>>N;
        clearscreen();
        Personal_inf *mass=new Personal_inf[N];
        create_data(mass,N);
        write_to_file(mass,N);
        cout<<endl<<endl;
        cout<<"Информация была успешно записана в файл."<<endl<<endl;
        read_from_file(mass,N);
        int choose1;
        cout.width(30);
        cout<<"Нажмите 1 ,чтобы вывести таблицу данных на экран"<<endl;;
        cin>>choose1;
        if(choose1==1)
        {
            clearscreen();
            output_table(mass,N);
        }
        menu_sort (mass,N);
        cout<<"Отсортированная база данных : "<<endl<<endl;
        output_table(mass,N);
        delete []mass;

    }

    return 0;
}
