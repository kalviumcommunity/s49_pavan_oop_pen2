#include <iostream>
#include <string>

using namespace std;

class Item {
protected:
    string material;
    string color;

public:
    Item() : material(""), color("") {}

    Item(string material, string color) : material(material), color(color) {}

    virtual void displayItemInfo() const {
        cout << "Material: " << material << endl;
        cout << "Color: " << color << endl;
    }
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

    void displayBarrelInfo() const override {
        cout << "Barrel Info:" << endl;
        displayItemInfo();
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

    void setInkType(const string& inkType) {
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

    void displayPenInfo() const override {
        cout << "Pen Info:" << endl;
        cout << "Ink Type: " << inkType << endl;
        if (barrel) {
            barrel->displayBarrelInfo();
        }
    }
};

int Pen::totalPens = 0;

class Notebook : public Pen, public Barrel {
private:
    string brandName;

public:
    Notebook(string inkType, string material, string color, string brandName)
        : Pen(inkType, nullptr, material, color), Barrel(material, color), brandName(brandName) {}

    void displayNotebookInfo() {
        cout << "Notebook Brand: " << brandName << endl;
        Pen::displayPenInfo();
        Barrel::displayBarrelInfo();
    }
};

int main() {
    const int numPens = 3;
    Pen* penArray = new Pen[numPens];

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

        Barrel* tempBarrel = new Barrel(barrelMaterial, barrelColor);
        penArray[i].setBarrel(tempBarrel);
    }

    for (int i = 0; i < numPens; i++) {
        cout << "\nPen " << i + 1 << " Information:\n";
        penArray[i].displayPenInfo();
    }

    cout << "\nTotal Pens created: " << Pen::getTotalPens() << endl;
    cout << "Total Barrels created: " << Barrel::getTotalBarrels() << endl;

    Notebook myNotebook("Gel", "Wood", "Red", "BrandX");
    myNotebook.displayNotebookInfo();

    for (int i = 0; i < numPens; i++) {
        delete penArray[i].getBarrel();
    }
    delete[] penArray;

    return 0;
}
