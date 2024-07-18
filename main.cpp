#include "Rezervare.h"
#include "Client.h"
#include "Camera.h"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

void afiseazaMeniuPrincipal()
{
    cout << "Meniu Principal:\n";
    cout << "1. Client\n";
    cout << "2. Administrator\n";
    cout << "3. Iesire\n";
    cout << "Alege rolul: ";
}

void afiseazaMeniuClient() {
    cout << "Meniu Client:\n";
    cout << "1. Vezi camerele disponibile\n";
    cout << "2. Iesire\n";
    cout << "Alege o optiune: ";
}

void afiseazaMeniuAdministrator()
{
    cout << "Meniu Administrator:\n";
    cout << "1. Rezerva camera\n";
    cout << "2. Anuleaza rezervare\n";
    cout << "3. Afiseaza toate rezervarile\n";
    cout << "4. Iesire\n";
    cout << "Alege o optiune: ";
}

int main()
{
    const string numarTelefon = "123-456-7890";
    Rezervare::initializeazaCamere();
    int optiune, rol;
    do
    {
        afiseazaMeniuPrincipal();
        cin >> rol;
        switch (rol)
        {
        case 1:     // Client
        {
            cout << "Intrat ca Client.\n";
            int optiuneClient;
            do
            {
                afiseazaMeniuClient();
                cin >> optiuneClient;
                switch (optiuneClient)
                {
                case 1:
                    Rezervare::afiseazaCamereDisponibile();
                    cout << "Pentru rezervari, sunati la: " << numarTelefon << endl;
                    break;
                case 2:
                    cout << "Iesire din meniul client.\n";
                    break;
                default:
                    cout << "Optiune invalida. Te rog sa alegi din nou.\n";
                }
            }
            while (optiuneClient != 2);
            break;
        }
        case 2:     // Administrator
        {
            cout << "Intrat ca Administrator.\n";
            do
            {
                afiseazaMeniuAdministrator();
                cin >> optiune;
                int clientId, nrCamera;
                string nume, prenume, tip;
                switch (optiune)
                {
                case 1:
                {
                    cout << "Introduce ID client: ";
                    cin >> clientId;
                    cin.ignore();
                    cout << "Introduce nume client: ";
                    getline(cin, nume);
                    cout << "Introduce prenume client: ";
                    getline(cin, prenume);
                    cout << "Introduce tipul camerei (single, double, twin, suite): ";
                    cin >> tip;
                    cout << "Introduce numarul camerei: ";
                    cin >> nrCamera;

                    Client client(clientId, nume, prenume);
                    client.salveazaClient();

                    Camera camera(nrCamera, tip);
                    camera.salveazaCamera();

                    if (Rezervare::efectueazaRezervare(client, tip, nrCamera))
                    {
                        cout << "Rezervare efectuata cu succes pentru " << client.getNumeComplet() << " la camera " << nrCamera << " de tip " << tip << ".\n";
                        Rezervare::salveazaRezervari();
                    }
                    else
                    {
                        cout << "Rezervarea nu a putut fi efectuata. Verifica disponibilitatea camerei.\n";
                    }
                    break;
                }
                case 2:
                    cout << "Introduce ID client pentru anulare: ";
                    cin >> clientId;
                    Rezervare::anuleazaRezervare(clientId);
                    Rezervare::salveazaRezervari();
                    break;
                case 3:
                    Rezervare::afiseazaRezervari();
                    break;
                case 4:
                    cout << "Iesire din program.\n";
                    return 0;
                default:
                    cout << "Optiune invalida. Te rog sa alegi din nou.\n";
                }
            }
            while (true);
            break;
        }
        case 3:     // Iesire
            cout << "Iesire din program.\n";
            return 0;
        default:
            cout << "Optiune invalida. Te rog sa alegi din nou.\n";
        }
    }
    while (true);

    return 0;
}

