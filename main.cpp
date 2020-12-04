#include <iostream>
#include "rwFunc.hpp"
#include <clocale>

int main()
{
    //setlocale(LC_ALL, "Russian");
    Forest *fo = nullptr;

    //ReadFile("DB/forest.db", fo);
    WriteFile("DB/forest.db", fo);
    return 0;
}
