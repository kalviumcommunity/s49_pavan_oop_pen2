#include <iostream>
#include <string>
using namespace std;

class Barrel {
private:
    string material;
    string color;

public:
    void setMaterial(string material) {
        this->material = material;
    }

    void setColor(string color) {
        this->color = color;
    }

    string getMaterial() const {
        return material;
    }

    string getColor() const {
        return color;
    }

    void displayBarrelInfo() const {
        cout << "Barrel Material: " << getMaterial() << endl;
        cout << "Barrel Color: " << getColor() << endl;
    }
};

class Pen {
private:
    string inkType;
    Barrel barrel;

public:
    void setInkType(string inkType) {
        this->inkType = inkType;
    }

    void setBarrel(Barrel barrel) {
        this->barrel = barrel;
    }

    string getInkType() const {
        return inkType;
    }

    Barrel getBarrel() const {
        return barrel;
    }

    void displayPenInfo() const {
        cout << "Ink Type: " << getInkType() << endl;
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

    cout << "\nPen's ink type using getter: " << myPen.getInkType() << endl;
    cout << "Barrel's material using getter: " << myPen.getBarrel().getMaterial() << endl;
    cout << "Barrel's color using getter: " << myPen.getBarrel().getColor() << endl;

    return 0;
}
