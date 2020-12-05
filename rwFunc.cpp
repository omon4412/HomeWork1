#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstring>
#include "rwFunc.hpp"

using std::cerr;
using std::endl;

void ReadFile(std::string fileName, Forest*& forest, int size)
{
    std::string Str;
    std::fstream in(fileName, std::ios_base::in);

    forest = new Forest[size];

    int i = 0;
    while (!in.eof())
    {
        getline(in, Str);
        std::string temp[4];
        if (Str.empty()) continue;

        std::stringstream ss(Str);
        std::string item;
        int k = 0;
        while (std::getline(ss, item, ';'))
        {
            temp[k] = item;
            k++;
        }
        forest[i].id = std::stoi(temp[0]);
        forest[i].lotNumber = std::stoi(temp[1]);
        forest[i].name = temp[2];
        forest[i].square = std::stoi(temp[3]);
        i++;
    }
    in.close();
}

void WriteFile(std::string fileName, Forest *forest, int size)
{
        std::fstream out(fileName, std::ios_base::out);

        if (!out.is_open())
        {
            cerr << "File " << fileName << " is not found!" << endl;
            exit(EXIT_FAILURE);
        }
        for (int i = 0; i < size; i++)
        {
            out << forest[i].id << ';' << forest[i].lotNumber << ';' << forest[i].name << ';' << forest[i].square << ";" << endl;
        }

        out.close();
}

int LengthOfForest(std::string path)
{
    std::fstream in(path, std::ios_base::in);

    if (!in.is_open())
    {
        cerr << "File " << path << " is not found!" << endl;
        exit(EXIT_FAILURE);
    }

    char str [200];
    int lineCount = 0;

    while (!in.eof())
    {
        in.getline(str, 1024, '\n');
        if (strlen(str) != 0)
        {
            lineCount++;
        }
    }
    in.close();
    return lineCount;
}

void Add(Forest *&owner, int &size, const Forest &slave)
{
    Forest *temp = new Forest[size + 1];
    for (int i = 0; i < size; i++ )
    {
        temp[i].id = owner[i].id;
        temp[i].lotNumber = owner[i].lotNumber;
        temp[i].name = owner[i].name;
        temp[i].square = owner[i].square;
    }
    temp[size].id = owner[size - 1].id + 1;
    temp[size].lotNumber = slave.lotNumber;
    temp[size].name = slave.name;
    temp[size].square = slave.square;
    delete owner;
    owner = temp;
    size++;
}

void RemoveAt(Forest *&forest, int &size, int index)
{
    Forest *temp = new Forest[size - 1];
    for (int i = 0; i < index; i++ )
    {
        temp[i].id = forest[i].id;
        temp[i].lotNumber = forest[i].lotNumber;
        temp[i].name = forest[i].name;
        temp[i].square = forest[i].square;
    }
    for (int i = index + 1; i < size; i++ )
    {
        temp[i - 1].id = forest[i].id;
        temp[i - 1].lotNumber = forest[i].lotNumber;
        temp[i - 1].name = forest[i].name;
        temp[i - 1].square = forest[i].square;
    }
    size--;
    delete forest;
    forest = temp;
}
