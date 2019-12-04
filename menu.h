#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "parent.cpp"
#include "child.cpp"
#include "relation.cpp"

int choice; char repeat;
infoParent angkutan; string daerah;

void printBanner();
void addDatas(string x, listParent &LP, listChild &LC, listRel &LR);
void showDatas(string x, listParent &LP, listChild &LC, listRel &LR);
void updateDatas(string x, listParent &LP, listChild &LC, listRel &LR);
void deleteDatas(string x, listParent &LP, listChild &LC, listRel &LR);
void showMenu(string x, listParent &LP, listChild &LC, listRel &LR);


#endif // MENU_H_INCLUDED
