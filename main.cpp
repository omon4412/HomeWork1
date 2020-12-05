#include <iostream>
#include <locale>
#include "rwFunc.hpp"
#include "menu.hpp"

int main()
{
    setlocale(LC_ALL,"Russian_Russia.1251");

    std::string path = "DB/forest.db";
    Forest *fo;

    return Menu(fo, path);
}
