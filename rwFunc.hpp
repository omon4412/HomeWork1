#ifndef RWFUNC_HPP
#define RWFUNC_HPP

#include <iostream>

struct Forest
{
    int id;
    int lotNumber;
    std::string name;
    int square;
};

void ReadFile(std::string fileName, Forest *&forest, int size);

void WriteFile(std::string fileName, Forest *forest, int size);

int LengthOfForest(std::string path);

void Add(Forest *&owner, int &size, const Forest &slave);
void RemoveAt(Forest *&forest, int &size, int index);

#endif // RWFUNC_HPP
