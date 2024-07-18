#ifndef CAMERA_H
#define CAMERA_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

class Camera {
private:
    int numar;
    string tip;

public:
    Camera(int numar, const string& tip);
    void salveazaCamera() const;
    static void afiseazaCamere();
    static void cautaCamera(int numar);
};

#endif // CAMERA_H
