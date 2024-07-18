#include "Camera.h"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

Camera::Camera(int numar, const string& tip) : numar(numar), tip(tip) {}

void Camera::salveazaCamera() const {
    ofstream file("Camera.txt", ios::app);
    file << numar << "," << tip << "\n";
    file.close();
}

void Camera::afiseazaCamere() {
    ifstream file("Camera.txt");
    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }
    file.close();
}

void Camera::cautaCamera(int numar) {
    ifstream file("Camera.txt");
    string line;
    bool found = false;
    while (getline(file, line)) {
        stringstream ss(line);
        string temp;
        getline(ss, temp, ',');
        if (stoi(temp) == numar) {
            cout << "Camera gasita: " << line << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Camera cu numarul " << numar << " nu a fost gasita." << endl;
    }
    file.close();
}
