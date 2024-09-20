#include <iostream>
#include <string>
using namespace std;

class Barrel {
private:
    string material;
    string color;

public:
    void setMaterial(string materialType) {
        material = materialType;
    }

    void setColor(string barrelColor) {
        color = barrelColor;
    }

    string getMaterial() {
        return material;
    }

    string getColor() {
        return color;
    }

    void displayBarrelInfo() {
        cout << "Barrel Material: " << material << endl;
        cout << "Barrel Color: " << color << endl;
    }
};

class Pen {
private:
    string inkType;
    Barrel barrel;

public:
    void setInkType(string ink) {
        inkType = ink;
    }

    void setBarrel(Barrel barrelObj) {
        barrel = barrelObj;
    }

    string getInkType() {
        return inkType;
    }

    void displayPenInfo() {
        cout << "Ink Type: " << inkType << endl;
        barrel.displayBarrelInfo();
    }
};

int main() {
    Barrel myBarrel;
    myBarrel.setMaterial("Plastic");
    myBarrel.setColor("Blue");

    Pen myPen;
    myPen.setInkType("Gel");
    myPen.setBarrel(myBarrel);

    myPen.displayPenInfo();

    return 0;
}
