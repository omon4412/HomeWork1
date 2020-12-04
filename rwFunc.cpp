#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstring>
#include "rwFunc.hpp"

using std::cerr;
using std::endl;

void ReadFile(std::string fileName, Forest*& forest)
{
    std::string Str;
    std::fstream in(fileName, std::ios_base::in);

    if (!in.is_open())
    {
        cerr << "File " << fileName << " is not found!" << endl;
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
    in.open(fileName, std::ios_base::in);

    forest = new Forest[lineCount];

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
        forest[i].square = std::stod(temp[3]);
        i++;
    }
    in.close();
}

void WriteFile(std::string fileName, Forest *forest)
{
    if(forest != nullptr)
    {
        std::fstream out(fileName, std::ios_base::out);

        if (!out.is_open())
        {
            cerr << "File " << fileName << " is not found!" << endl;
            exit(EXIT_FAILURE);
        }
        for (int i = 0; i < 2; i++)
        {
            out << forest[i].id << ';' << forest[i].lotNumber << ';' << forest[i].name << ';' << std::fixed << std::setprecision(1) << forest[i].square << ";" << endl;
        }

        out.close();
    }
}
