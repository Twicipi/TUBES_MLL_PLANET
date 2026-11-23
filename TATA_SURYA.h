#ifndef TATA_SURYA_H_INCLUDED
#define TATA_SURYA_H_INCLUDED
#include <iostream>
#include <string>

using namespace std;

struct Planet {
    string namaPlanet;
    string tipePlanet;
    double jarakMatahari;
    double diameter;
};

struct Satelit {
    string namaSatelit;
    double diameter;
    int tahunDitemukan;
};

typedef Planet infotypeParent;
typedef Satelit infotypeChild;

typedef struct ElmParent *adrParent;
typedef struct ElmChild *adrChild;

struct ElmChild {
    infotypeChild info;
    adrChild next;
};

struct ElmParent {
    infotypeParent info;
    adrParent next;
    adrChild firstChild;

struct ListParent {
    adrParent first;
};
// tambahh update child & planet ya nanti

void createList(ListParent &L);
adrParent createParent(infotypeParent data);
void insertParent(ListParent &L, adrParent P);
void deleteParent(ListParent &L, string namaPlanet, adrParent &P);
adrParent findParent(ListParent L, string namaPlanet);
void printParent(ListParent L);

adrChild createChild(infotypeChild data);
void insertChild(adrParent P, adrChild C);
void deleteChild(adrParent P, string namaSatelit, adrChild &C);
adrChild findChild(adrParent P, string namaSatelit);
void printChild(adrParent P);

void printAll(ListParent L);
int countSatelit(adrParent P);
adrChild findLargestSatelit(ListParent L);


#endif // TATA_SURYA_H_INCLUDED
