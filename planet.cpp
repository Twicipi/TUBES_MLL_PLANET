#include "tata_surya.h"

void createList(ListParent &L)
{
    L.first = nullptr;
}

adrParent createParent(infotypeParent data)
{
    adrParent P = new ElmParent;
    P->info = data;
    P->next = nullptr;
    P->firstChild = nullptr;
    return P;
}

void insertParent(ListParent &L, adrParent P)
{
    if (L.first == nullptr)
    {
        L.first = P;
    }
    else
    {
        adrParent Q = L.first;
        while (Q->next != nullptr)
        {
            Q = Q->next;
        }
        Q->next = P;
    }
}

adrParent findParent(ListParent L, string namaPlanet)
{
    adrParent P = L.first;
    while (P != nullptr)
    {
        if (P->info.namaPlanet == namaPlanet)
        {
            return P;
        }
        P = P->next;
    }
    return nullptr;
}

void deleteParent(ListParent &L, string namaPlanet, adrParent &P)
{
    P = findParent(L, namaPlanet);
    if (P == nullptr)
    {
        cout << "[Info] Planet \"" << namaPlanet << "\" tidak ditemukan." << endl;
        return;
    }

    adrChild C = P->firstChild;
    while (C != nullptr)
    {
        adrChild tempChild = C;
        C = C->next;
        delete tempChild;
    }
    P->firstChild = nullptr;

    if (P == L.first)
    {
        L.first = P->next;
    }
    else
    {
        adrParent prev = L.first;
        while (prev->next != P)
        {
            prev = prev->next;
        }
        prev->next = P->next;
    }
    P->next = nullptr;
}

void printParent(ListParent L)
{
    if (L.first == nullptr)
    {
        cout << "Daftar planet masih kosong." << endl;
        return;
    }

    adrParent P = L.first;
    int no = 1;
    cout << "=== DAFTAR PLANET TATA SURYA ===" << endl;
    while (P != nullptr)
    {
        cout << no << ". " << P->info.namaPlanet
             << " | Tipe: " << P->info.tipePlanet
             << " | Jarak: " << P->info.jarakMatahari << " juta km"
             << " | Diameter: " << P->info.diameter << " km" << endl;
        P = P->next;
        no++;
    }
}

void printAll(ListParent L)
{
    if (L.first == nullptr)
    {
        cout << "Data tata surya masih kosong." << endl;
        return;
    }

    adrParent P = L.first;
    int no = 1;
    cout << "=== DATA EKSPLORASI TATA SURYA & SATELIT ===" << endl;
    while (P != nullptr)
    {
        cout << no << ". Planet: " << P->info.namaPlanet
             << " (" << P->info.tipePlanet << ")" << endl;
        cout << "   Jarak Matahari: " << P->info.jarakMatahari << " juta km"
             << " | Diameter: " << P->info.diameter << " km" << endl;
        printChild(P);
        cout << "------------------------------------------" << endl;
        P = P->next;
        no++;
    }
}
