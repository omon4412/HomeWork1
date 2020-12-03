#ifndef RWFUNC_HPP
#define RWFUNC_HPP

#include <iostream>

struct Forest
{
    int id;
    int lotNumber;
    std::string name;
    double square;
};

void ReadFile();
void WriteFile();

#endif // RWFUNC_HPP
