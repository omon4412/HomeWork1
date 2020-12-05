#ifndef MENU_HPP
#define MENU_HPP

#include "rwFunc.hpp"

int Menu(Forest *forest ,std::string path);
void ShowData(Forest *forest, int size);
Forest AddRequest();
int DeleteRequest();
void DrawLine();
void ShowAbout();

#endif // MENU_HPP
