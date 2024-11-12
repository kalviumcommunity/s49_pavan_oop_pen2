#include <iostream>
#include <string>
using namespace std;

class Item {
protected:
    string material;
    string color;

public:
    Item() : material(""), color("") {}

    Item(string material, string color) {
        this->material = material;
        this->color = color;
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

    virtual void displayInfo() const = 0;
    virtual ~Item() {}  
};

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

    void displayInfo() const override {
        cout << "Barrel Info:" << endl;
        cout << "Material: " << getMaterial() << endl;
        cout << "Color: " << getColor() << endl;
    }

    ~Barrel() {
        totalBarrels--;
    }
};

int Barrel::totalBarrels = 0;

class Pen : public Item {
private:
    string inkType;
    Barrel* barrel;
    static int totalPens;

public:
    Pen() : Item(), barrel(nullptr) {
        totalPens++;
    }

    Pen(string inkType, Barrel* barrel, string material, string color)
        : Item(material, color), inkType(inkType), barrel(barrel) {
        totalPens++;
    }

    static int getTotalPens() {
        return totalPens;
    }

    void setInkType(string inkType) {
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

    void displayInfo() const override {
        cout << "Pen Info:" << endl;
        cout << "Ink Type: " << getInkType() << endl;
        if (barrel) {
            barrel->displayInfo();
        }
    }

    ~Pen() {
        totalPens--;
        delete barrel;
    }
};

int Pen::totalPens = 0;

int main() {
    const int numPens = 2;
    Item* itemArray[numPens];  
    for (int i = 0; i < numPens; i++) {
        string inkType, barrelMaterial, barrelColor;

        cout << "\nEnter details for Pen " << i + 1 << ":" << endl;

        cout << "Enter ink type: ";
        cin >> inkType;

        cout << "Enter barrel material: ";
        cin >> barrelMaterial;
        cout << "Enter barrel color: ";
        cin >> barrelColor;

        Barrel* tempBarrel = new Barrel(barrelMaterial, barrelColor);
        itemArray[i] = new Pen(inkType, tempBarrel, barrelMaterial, barrelColor);
    }

    for (int i = 0; i < numPens; i++) {
        cout << "\nItem " << i + 1 << " Information:\n";
        itemArray[i]->displayInfo();
    }

    cout << "\nTotal Pens created: " << Pen::getTotalPens() << endl;
    cout << "Total Barrels created: " << Barrel::getTotalBarrels() << endl;

    for (int i = 0; i < numPens; i++) {
        delete itemArray[i]; 
    }

    return 0;
}
