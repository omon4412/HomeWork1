#include <conio.h>
#include <iomanip>
#include <windows.h>
#include "rwFunc.hpp"
#include "menu.hpp"

bool isOpen = false;

int Menu(Forest *forest, std::string path)
{
    int size = LengthOfForest(path);
    char n;
    std::string message = "��������� �������:\n"
                          "\t1 - ������� ����\n"
                          "\t2 - ��������� ����\n"
                          "\t3 - �������� � ������ ������\n"
                          "\t4 - ������� ������ �� ������\n"
                          "\t5 - ������� �� ����� ������\n"
                          "\t6 - � ���������\n"
                          "\tq - ����� �� ���������\n\n";

    while (true)
    {
        system("cls");
        std::cout<<message;
        std::cout<<"������� ����� �������: ";
        std::cin >> n;
        switch (n)
        {
        case 49: //1
            if(isOpen)
            {
                std::cerr << "���� ��� ������!" << std::endl;
                _getch();
                break;
            }
            ReadFile(path, forest, size);
            isOpen = true;
            std::cout<<"������� ���������!..."<<std::endl;
            _getch();
            break;
        case 50:
            if(isOpen == false)
            {
                std::cerr << "���� �� ������!" << std::endl;
                _getch();
                break;
            }
            WriteFile(path, forest, size);
            std::cout<<"������� ���������!..."<<std::endl;
            _getch();
            break;
        case 51:
            if(isOpen == false)
            {
                std::cerr << "���� �� ������!" << std::endl;
                _getch();
                break;
            }
            Add(forest, size, AddRequest());
            std::cout<<"������� ���������!..."<<std::endl;
            _getch();
            break;
        case 52:
            if(isOpen == false)
            {
                std::cerr << "���� �� ������!" << std::endl;
                _getch();
                break;
            }
            RemoveAt(forest, size, DeleteRequest() - 1);
            std::cout<<"������� ���������!..."<<std::endl;
             _getch();
            break;
        case 53:
            ShowData(forest ,size);
            _getch();
            break;
        case 54:
            break;
        case 113: //q
            return EXIT_SUCCESS;
        default:
            std::cerr<<"Error"<<std::endl;
            break;
        }

    }
    return 0;
}

void ShowData(Forest *forest, int size)
{
    if(isOpen == false)
    {
        std::cerr << "���� �� ������!" << std::endl;
        _getch();
        return;
    }
     system("cls");
     std::cout << "| �     |" << std::setw(10) <<std::right << "� ������� |"
               << std::setw(15) << "������� ���"
               << std::setw(31) << "| ������� �������(��) |" << std::endl;
     DrawLine();
     for (int i = 0; i < size ; i++ )
     {
         std::cout << '|' << std::setw(7) << forest[i].id << '|'
                   << std::setw(10) << forest[i].lotNumber << '|'
                   << std::setw(23) << forest[i].name << '|'
                   << std::setw(21) << forest[i].square << '|'
                   << std::endl;
         DrawLine();
     }
}

Forest AddRequest()
{
    int num;
    int square;
    std::string name;
    std::cout << std::endl << "������� ����� �������: ";
    std::cin >> num;
    std::cout << std::endl << "������� ������� ���: ";
    SetConsoleCP(1251);
    std::cin.ignore(32767, '\n');
    std::getline(std::cin, name);
    SetConsoleCP(866);
    std::cout << std::endl << "������� ������� �������(��): ";
    std::cin >> square;
    Forest slave;
    slave.id = 0;
    slave.lotNumber = num;
    slave.name = name;
    slave.square = square;
    return slave;
}

int DeleteRequest()
{
    std::cout << std::endl << "������� ����� ����� ��� ��������: ";
    int index;
    std::cin >> index;
    return index;
}

void DrawLine()
{
    for (int i = 0; i < 66; i++)
    {
        std::cout<<'-';
    }
    std::cout << std::endl;
}
