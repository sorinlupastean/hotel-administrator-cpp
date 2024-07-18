#include "Rezervare.h"
#include "Client.h"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

map<string, int> Rezervare::camereDisponibile;
vector<tuple<int, string, string, int>> Rezervare::rezervari;

void Rezervare::salveazaRezervari() {
    ofstream out("Rezervari.txt");
    if (out.is_open()) {
        for (const auto& rez : rezervari) {
            out << "Client ID: " << get<0>(rez) << ", Nume: " << get<1>(rez)
                << ", Tip: " << get<2>(rez) << ", Camera Nr.: " << get<3>(rez) << endl;
        }
        out.close();
    }
    else {
        cout << "Nu am putut deschide fisierul pentru a salva rezervarile." << endl;
    }
}


void Rezervare::initializeazaCamere() {
    camereDisponibile["single"] = 30;
    camereDisponibile["double"] = 30;
    camereDisponibile["twin"] = 20;
    camereDisponibile["suite"] = 20;
}

void Rezervare::afiseazaCamereDisponibile() {
    cout << "Camere disponibile:\n";
    for (const auto& pair : camereDisponibile) {
        cout << pair.first << ": " << pair.second << endl;
    }
}

bool Rezervare::efectueazaRezervare(const Client& client, const string& tip, int nrCamera) {
    if (camereDisponibile[tip] > 0) {
        camereDisponibile[tip]--;
        rezervari.emplace_back(client.getId(), client.getNumeComplet(), tip, nrCamera);
        cout << "Rezervare efectuata pentru " << client.getNumeComplet() << " (ID: " << client.getId() << ") in camera " << nrCamera << " de tip " << tip << ".\n";
        return true;
    }
    else {
        cout << "Nu sunt disponibile camere de tipul " << tip << ".\n";
        return false;
    }
}

void Rezervare::anuleazaRezervare(int clientId) {
    auto it = find_if(rezervari.begin(), rezervari.end(),
        [clientId](const auto& item) { return get<0>(item) == clientId; });
    if (it != rezervari.end()) {
        camereDisponibile[get<2>(*it)]++;
        cout << "Rezervare anulata pentru clientul cu ID " << clientId << ".\n";
        rezervari.erase(it);
        salveazaRezervari();
    }
    else {
        cout << "Nicio rezervare gasita pentru clientul cu ID " << clientId << ".\n";
    }
}

void Rezervare::afiseazaRezervari() {
    ifstream in("Rezervari.txt");
    if (!in.is_open()) {
        cout << "Nu am putut deschide fisierul pentru a citi rezervarile." << endl;
        return;
    }

    string line;
    cout << "Rezervari active:\n";
    while (getline(in, line)) {
        cout << line << endl;
    }
    in.close();
}


