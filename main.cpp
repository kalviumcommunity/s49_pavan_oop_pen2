#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Base class: Item
class Item {
protected:
    string material;
    string color;

class Barrel {
private:
    string material;  
    string color;  
    static int totalBarrels;  

public:
    Item() : material("Unknown"), color("Unknown") {}

<<<<<<< HEAD
    Item(string material, string color) {
        this->material = material;
        this->color = color;
        totalBarrels++;
    }

    static int getTotalBarrels() {
    static int getTotalBarrels() {  
        return totalBarrels;
    }

    void setMaterial(const string& material) {  
        this->material = material;
    }

    void setColor(const string& color) {  
=======
    Item(string material, string color) : material(material), color(color) {}

    void setMaterial(const string& material) {
        this->material = material;
    }

    void setColor(const string& color) {
>>>>>>> cd281cc (polymorphism11/13)
        this->color = color;
    }

    string getMaterial() {  
        return material;
    }

    string getColor()  {  
        return color;
    }

<<<<<<< HEAD

    void displayItemInfo() const {
=======
    virtual void displayItemInfo() const {
>>>>>>> cd281cc (polymorphism11/13)
        cout << "Material: " << getMaterial() << endl;
        cout << "Color: " << getColor() << endl;
    }
};

// Derived class: Barrel
class Barrel : public Item {
private:
    static int totalBarrels;

public:
    Barrel() : Item() {
        totalBarrels++;
    }

    Barrel(string material, string color) : Item(material, color) {
        totalBarrels++;
    }

    static int getTotalBarrels() {
        return totalBarrels;
    }

    void displayBarrelInfo() const {
<<<<<<< HEAD
        cout << "Barrel Info:" << endl;
        displayItemInfo(); 
    void displayBarrelInfo() {  
        cout << "Barrel Material: " << getMaterial() << endl;
        cout << "Barrel Color: " << getColor() << endl;
=======
        cout << "Barrel Info:\n";
        displayItemInfo();
>>>>>>> cd281cc (polymorphism11/13)
    }

    void incrementTotalBarrels() {  
        totalBarrels++;  
    }
};

int Barrel::totalBarrels = 0;

// Derived class: Pen
class Pen : public Item {
private:
    string inkType;
    Barrel* barrel;
    static int totalPens;

    string inkType;  
    Barrel* barrel;  
    static int totalPens;  

public:
    Pen() : Item(), inkType("Unknown"), barrel(nullptr) {
        totalPens++;
    }

    Pen(string inkType, Barrel* barrel, string material, string color)
        : Item(material, color), inkType(inkType), barrel(barrel) {
        totalPens++;
    }

    static int getTotalPens() {
    static int getTotalPens() {  
        return totalPens;
    }

<<<<<<< HEAD
    void setInkType(const string& inkType) {  
=======
    void setInkType(const string& inkType) {
>>>>>>> cd281cc (polymorphism11/13)
        this->inkType = inkType;
    }

    void setBarrel(Barrel* barrel) {  
        this->barrel = barrel;
    }

    string getInkType() const {  
        return inkType;
    }

    Barrel* getBarrel() const {  
        return barrel;
    }

    void displayPenInfo() const {
        cout << "Pen Info:\n";
        cout << "Ink Type: " << getInkType() << endl;
        if (barrel) {
            barrel->displayBarrelInfo();
        }
    void displayPenInfo() const {  
        cout << "Ink Type: " << getInkType() ;
    }

    ~Pen() {
        totalPens--;
<<<<<<< HEAD
        delete barrel;
    void incrementTotalPens() {  
        totalPens++;  
=======
        // Barrel is deleted externally if needed.
>>>>>>> cd281cc (polymorphism11/13)
    }

};

int Pen::totalPens = 0;

int main() {
    const int numPens = 2;
    Pen* penArray = new Pen[numPens];
    const int numPens = 3;
    Pen* penArray = new Pen[numPens];  

    for (int i = 0; i < numPens; i++) {
        string inkType, barrelMaterial, barrelColor;

        cout << "\nEnter details for Pen " << i + 1 << ":\n";
        cout << "Enter ink type: ";
        cin >> inkType;
        penArray[i].setInkType(inkType);

        cout << "Enter barrel material: ";
        cin >> barrelMaterial;
        cout << "Enter barrel color: ";
        cin >> barrelColor;

        Barrel* tempBarrel = new Barrel(barrelMaterial, barrelColor);
        penArray[i].setBarrel(tempBarrel);
        Barrel* tempBarrel = new Barrel();  
        tempBarrel->setMaterial(barrelMaterial);  
        tempBarrel->setColor(barrelColor);  
        tempBarrel->incrementTotalBarrels();  

        penArray[i].setBarrel(tempBarrel);  
        penArray[i].incrementTotalPens();  
    }

    for (int i = 0; i < numPens; i++) {
        cout << "\nPen " << i + 1 << " Information:\n";
        penArray[i].displayPenInfo();  
    }

    cout << "\nTotal Pens created: " << Pen::getTotalPens() << endl;
    cout << "Total Barrels created: " << Barrel::getTotalBarrels() << endl;

    // Free dynamically allocated pens
    for (int i = 0; i < numPens; i++) {
        delete penArray[i].getBarrel();  // Delete each barrel manually
    }
    delete[] penArray;

    delete[] penArray;  
    return 0;
}
