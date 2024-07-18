#ifndef REZERVARE_H
#define REZERVARE_H

#include "Client.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <tuple>

using namespace std;

class Rezervare {
private:
    static map<string, int> camereDisponibile;
    static vector<tuple<int, string, string, int>> rezervari;
public:
    static void salveazaRezervari();
    static void initializeazaCamere();
    static void afiseazaCamereDisponibile();
    static bool efectueazaRezervare(const Client& client, const string& tip, int nrCamera);
    static void anuleazaRezervare(int clientId);
    static void afiseazaRezervari();
};



#endif // REZERVARE_H
