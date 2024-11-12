#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

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
    Item() : material(""), color("") {}

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
        this->color = color;
    }

    string getMaterial() {  
        return material;
    }

    string getColor()  {  
        return color;
    }

    virtual void displayInfo() const = 0;
    virtual ~Item() {}  

    void displayItemInfo() const {
        cout << "Material: " << getMaterial() << endl;
        cout << "Color: " << getColor() << endl;
    }

    void displayItemInfo(string additionalInfo) const {
        cout << "Material: " << getMaterial() << endl;
        cout << "Color: " << getColor() << endl;
        cout << "Additional Info: " << additionalInfo << endl;
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

    void displayInfo() const override {
        cout << "Barrel Info:" << endl;
        cout << "Material: " << getMaterial() << endl;
        cout << "Color: " << getColor() << endl;
        displayItemInfo(); 
    void displayBarrelInfo() {  
        cout << "Barrel Material: " << getMaterial() << endl;
        cout << "Barrel Color: " << getColor() << endl;
    }

    void incrementTotalBarrels() {  
        totalBarrels++;  
    }
};

int Barrel::totalBarrels = 0;

class Pen : public Item {
private:
    string inkType;
    Barrel* barrel;
    static int totalPens;

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

    void displayInfo() const override {
        cout << "Pen Info:" << endl;
        cout << "Ink Type: " << getInkType() << endl;
        if (barrel) {
            barrel->displayInfo();
        }
    void displayPenInfo() const {  
        cout << "Ink Type: " << getInkType() ;
    }

    ~Pen() {
        totalPens--;
        delete barrel;
    void incrementTotalPens() {  
        totalPens++;  
    }

};

int Pen::totalPens = 0;

int main() {
    const int numPens = 2;
    Item* itemArray[numPens];  
    Pen* penArray = new Pen[numPens];
    const int numPens = 3;
    Pen* penArray = new Pen[numPens];  

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

    for (int i = 0; i < numPens; i++) {
        delete itemArray[i]; 
    }

    delete[] penArray;  
    return 0;
}
