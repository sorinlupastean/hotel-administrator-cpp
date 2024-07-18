#include "Client.h"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>

Client::Client() : id(0), nume(""), prenume("") {}

Client::Client(int id, string nume, string prenume) : id(id), nume(nume), prenume(prenume) {}

int Client::getId() const { return id; }
void Client::setId(int id) { this->id = id; }

string Client::getNume() const { return nume; }
void Client::setNume(const string &nume) { this->nume = nume; }

string Client::getPrenume() const { return prenume; }
void Client::setPrenume(const string &prenume) { this->prenume = prenume; }


istream &operator>>(istream &in, Client &client) {
    cout << "Introduceti ID-ul clientului: ";
    in >> client.id;
    cout << "Introduceti numele clientului: ";
    in >> client.nume;
    cout << "Introduceti prenumele clientului: ";
    in >> client.prenume;
    return in;
}

ostream &operator<<(ostream &out, const Client &client) {
    out << "ID: " << client.id << ", Nume: " << client.nume << ", Prenume: " << client.prenume;
    return out;
}

string Client::getNumeComplet() const
{
    return nume + " " + prenume;
}

void Client::salveazaClient()
{
    ofstream out("Clienti.txt", ios::app);
    if (out.is_open())
    {
        out << "ID: " << id << ", Nume: " << nume << ", Prenume: " << prenume << endl;
        out.close();
    }
    else
    {
        cout << "Nu am putut deschide fisierul." << endl;
    }
}

void Client::afiseazaClienti()
{
    ifstream in("Clienti.txt");
    string linie;
    if (in.is_open())
    {
        while (getline(in, linie))
        {
            cout << linie << endl;
        }
        in.close();
    }
    else
    {
        cout << "Nu am putut deschide fisierul pentru citire" << endl;
    }
}

string toLowerCase(const string& str)
{
    string lowerCaseStr = str;
    transform(lowerCaseStr.begin(), lowerCaseStr.end(), lowerCaseStr.begin(), ::tolower);
    return lowerCaseStr;
}

void Client::cautaClient(const string& cautare)
{
    ifstream in("Clienti.txt");
    string linie, temp;
    string lowerCautare = toLowerCase(cautare);
    bool found = false;

    if (in.is_open())
    {
        while (getline(in, linie))
        {
            istringstream iss(linie);
            string id, nume, prenume;

            getline(iss, temp, ':');
            iss >> id;
            getline(iss, temp, ':');
            getline(iss, nume, ',');
            nume = nume.substr(1);
            getline(iss, temp, ':');
            getline(iss, prenume);
            prenume = prenume.substr(1);

            if (toLowerCase(nume) == lowerCautare || toLowerCase(prenume) == lowerCautare || toLowerCase(nume + " " + prenume) == lowerCautare || toLowerCase(prenume + " " + nume) == lowerCautare)
            {
                cout << "Client gasit: ID: " << id << ", Nume: " << nume << ", Prenume: " << prenume << endl;
                found = true;
            }
        }
        if (!found)
        {
            cout << "Niciun client gasit cu numele sau prenumele: " << cautare << endl;
        }
        in.close();
    }
    else
    {
        cout << "Nu am putut deschide fisierul pentru citire." << endl;
    }
}


