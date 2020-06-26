#include <iostream>
#pragma once



class goods{                                                     //класс для товаров
public:
    char name[50];
    int price = 0;
    int capacity = 0;
    int diagonal = 0;
    int type = 0;
    friend std::ostream& operator<<(std::ostream &out, const goods a);
    friend std::istream& operator>>(std::istream &in, goods &a);
};

void _2012();
std::ofstream get_newfile(char* TVfn, char* Fridgefn, char* Microwavefn, int type);
std::ifstream get_infile(char* TVfn, char* Fridgefn, char* Microwavefn, int type);
void get_name(char* str);
void get_param(int* par, int* new_par,int type);
void load_data(char* TVfn, char* Fridgefn, char* Microwavefn, int len, int type, goods* a);
goods get_goods(int type);
void get_type(int* type);
void add(char* TVfn, char* Fridgefn, char* Microwavefn);
void change(char* TVfn, char* Fridgefn, char* Microwavefn);
void dell(char* TVfn, char* Fridgefn, char* Microwavefn);
void show_params(goods a);
void seek(char* TVfn, char* Fridgefn, char* Microwavefn);
