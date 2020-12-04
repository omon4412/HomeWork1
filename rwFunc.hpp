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

void ReadFile(std::string fileName, Forest *&forest);

void WriteFile(std::string fileName, Forest *forest);

#endif // RWFUNC_HPP
