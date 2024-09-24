#include <iostream>
#include <string>
using namespace std;

class Barrel {
private:
    string material;
    string color;
    static int totalBarrels; 

public:
    Barrel() {
        totalBarrels++; 
    }

    static int getTotalBarrels() {  
        return totalBarrels;
    }

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

int Barrel::totalBarrels = 0;

class Pen {
private:
    string inkType;
    Barrel barrel;
    static int totalPens; 

public:
    Pen() {
        totalPens++; 
    }

    static int getTotalPens() {  
        return totalPens;
    }

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


int Pen::totalPens = 0;

int main() {
    const int numPens = 2;
    Pen penArray[numPens];

    for (int i = 0; i < numPens; i++) {
        string inkType, barrelMaterial, barrelColor;

        cout << "\nEnter details for Pen " << i + 1 << ":" << endl;

        cout << "Enter ink type: ";
        cin >> inkType;
        penArray[i].setInkType(inkType);

        cout << "Enter barrel material: ";
        cin >> barrelMaterial;
        cout << "Enter barrel color: ";
        cin >> barrelColor;

        Barrel tempBarrel;
        tempBarrel.setMaterial(barrelMaterial);
        tempBarrel.setColor(barrelColor);

        penArray[i].setBarrel(tempBarrel);
    }

    for (int i = 0; i < numPens; i++) {
        cout << "\nPen " << i + 1 << " Information:\n";
        penArray[i].displayPenInfo();
    }
    cout << "\nTotal Pens created: " << Pen::getTotalPens() << endl;
    cout << "Total Barrels created: " << Barrel::getTotalBarrels() << endl;

    return 0;
}
