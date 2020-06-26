#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include "header.h"
using namespace std;


void _2012(){                                                   //Конец света
    cout << "Sistemnaya owibka\n";
    exit(0);
}


istream& operator>>(istream &in, goods &a){                       //Перегрузка операторов ввода и вывода

    cout << "Vvedite nazvanie: ";
    cin >> a.name;
    cout << "Vvedite cenu: ";
    cin >> a.price;

    switch (a.type){
        case 1: cout << "Vvedite diagonal: "; cin >> a.diagonal; break;
        case 2: cout << "Vvedite vmestimost: "; cin >> a.capacity; break;
        case 3: cout << "Vvedite vmestimost: "; cin >> a.capacity; break;
    }

    return in;
}

ostream& operator<<(ostream &out, const goods a){
    out.write((char*)&a, sizeof(goods));
    return out;
}


ofstream get_newfile(char* TVfn, char* Fridgefn, char* Microwavefn, int type){                                 //возвращает файл на дефолтный аутпут
    ofstream f;

    switch (type){
        case 1: f.open(TVfn); break;
        case 2: f.open(Fridgefn); break;
        case 3: f.open(Microwavefn); break;
    }

    if (f.is_open()) return f;
    else _2012();
}

ifstream get_infile(char* TVfn, char* Fridgefn, char* Microwavefn, int type){                                //возвращает файл на считывание товаров
    ifstream f;

    switch (type){
        case 1: f.open(TVfn); break;
        case 2: f.open(Fridgefn); break;
        case 3: f.open(Microwavefn); break;
    }
    if (f.is_open()) return f;
    else  _2012();

}

void get_name(char* str){                                     //get_name
    cout << "Vvedite nazvanie: ";
    cin >> str;
}

void get_param(int* par, int* new_par,int type){                       //Функция для функции change, чтобы узнать параметр, который
    cout << "4to izmenit? Cena - 1, ";                                 //надо изменить и новое значение
    if (type == 1) cout << "diagonal - 2: ";
    else if (type == 2 || type == 3) cout << "Vmestimost - 2: ";
    cin >> *par;
    cout << "Vvedite novoe zna4enie: ";
    cin >> *new_par;
}

void load_data(char* TVfn, char* Fridgefn, char* Microwavefn, int len, int type, goods* a){                           //Загружает всю инфу в файл
    int i = 0;
    ofstream to_load = get_newfile(TVfn, Fridgefn, Microwavefn, type);
    to_load << len;
    for (i; i < len; i++) to_load << a[i];
    to_load.close();
}


void get_type(int* type){                                                //Считать тип товара, с которым будут оперировать функции
    cout << "Viberite type 1 - TV, 2 - Holodilnik, 3 - Microvalnovka ";
    while (cin >> *type && (*type < 1 || *type > 3)) cout << "Neverniy type! Davay ewe raz! ";
}

void add(char* TVfn, char* Fridgefn, char* Microwavefn){                                              //добавляет товар в файл, путем считывания первого элемента - кол-ва товара
                                                         //в файле, считыванием товаров в массив с последующим выгрузом кол-ва товара
    int type;                                            //и товара
    get_type(&type);
    ifstream to_read = get_infile(TVfn, Fridgefn, Microwavefn, type);
    int len = 0, i = 0;
    to_read >> len;
    goods *a = new goods[len + 1];

    while (to_read.read((char*)&a[i++], sizeof(goods))){}
    a[len].type = type;
    cin >> a[len];
    to_read.close();

    load_data(TVfn, Fridgefn, Microwavefn, len + 1, type, a);

    cout << "Tovar uspeshno dobavlen!\n";
}


void change(char* TVfn, char* Fridgefn, char* Microwavefn){                                         //Изменяет параметры товара по названию и типу, путем полного считывания и обратной загрузки,
                                                       //токо во время считывания в массив, в зависимости от совпадений
    int type;                                          //названий товаров в файле и названия введенного пользователем -
    get_type(&type);                                   //менять введенные параметры.
    char name[50];
    get_name(name);
    int par, new_par;
    get_param(&par, &new_par, type);

    ifstream to_read = get_infile(TVfn, Fridgefn, Microwavefn, type);
    int len = 0, i = -1;
    to_read >> len;
    goods *a = new goods[len + 1];

    while (to_read.read((char*)&a[++i], sizeof(goods))){
        if (!strcmp(a[i].name, name)){
            if (par == 1) a[i].price = new_par;
            else if (a[i].diagonal) a[i].diagonal = new_par;
            else if (a[i].capacity) a[i].capacity = new_par;
        }
    }
    to_read.close();

    load_data(TVfn, Fridgefn, Microwavefn, len, type, a);

    cout << "Parametr uspeshno izmenen!\n";

}


void dell(char* TVfn, char* Fridgefn, char* Microwavefn){                                          //Удалить товар в зависимости в навания и типа, введенных пользователем
                                                      //путем полного считывания и обратной загрузки
    int type, len, i = -1, m;;
    get_type(&type);
    char name[50];
    get_name(name);
    cout << "Skolko udalit? ";
    cin >> m;
    int nm = m;

    ifstream to_read = get_infile(TVfn, Fridgefn, Microwavefn, type);
    to_read >> len;

    goods *a = new goods[len];
    goods b;
    while (to_read.read((char*)&b, sizeof(goods))) if (strcmp(name, b.name) || (m-- <= 0)) a[++i] = b;
    to_read.close();

    load_data(TVfn, Fridgefn, Microwavefn, len - nm, type, a);

    cout << "Tovar uspeshno udalen!\n";
}


void show_params(goods a){                                               //show_params
    cout << "Cena " << a.price << endl;
    if (a.diagonal) cout << "Diagonal " << a.diagonal << endl;
    if (a.capacity) cout << "Vmestimost " << a.capacity << endl;
}

void seek(char* TVfn, char* Fridgefn, char* Microwavefn){                                    //Поиск товара по типу файла и названия товара, путем считывания из файла
                                                //в массив с параллельным подсчетом кол-ва этого товара
    int type;
    get_type(&type);
    char name[50];
    get_name(name);

    ifstream f = get_infile(TVfn, Fridgefn, Microwavefn, type);
    int len, p = 0;
    f >> len;
    goods a, b;

    while (f.read((char*)&a, sizeof(goods))) if (!strcmp(name, a.name) && ++p) break;
    while (f.read((char*)&b, sizeof(goods))) if (!strcmp(name, b.name)) p++;


    if (!p) cout << "Tovar ne nayden!\n";
    else {
        show_params(a);
        cout << "Kol-vo " << p << endl;
    }
}
