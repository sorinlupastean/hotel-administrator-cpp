#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <fstream>
#include <string>


using namespace std;

class Client
{
private:
	int id;
	string nume;
	string prenume;

public:
    Client();
	Client(int id, const string &nume, const string &prenume);

	int getId() const;
    void setId(int id);
    string getNume() const;
    void setNume(const string &nume);
    string getPrenume() const;
    void setPrenume(const string &prenume);
	void salveazaClient();

	static void afiseazaClienti();
	static void cautaClient(const string& cautare);

	friend istream &operator>>(istream &in, Client &client);
    friend ostream &operator<<(ostream &out, const Client &client);

	string getNumeComplet();
};


#endif // CLIENT_H
