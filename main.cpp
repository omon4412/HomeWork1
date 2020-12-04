#include <iostream>
//#include <clocale>
#include "rwFunc.hpp"
#include "menu.hpp"

int main()
{
    //setlocale(LC_ALL, "Russian");
    Forest *fo = nullptr;

    ReadFile("DB/forest.db", fo);
    WriteFile("DB/forest.db", fo);
    Menu(fo);

    return 0;
}
