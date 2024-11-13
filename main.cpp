#include <iostream>
#include <string>
#include <memory>  // For unique_ptr

using namespace std;

// Base class: Item
class Item {
protected:
    string material;
    string color;

public:
    Item() : material("Unknown"), color("Unknown") {}

    Item(string material, string color) : material(material), color(color) {}

    void setMaterial(const string& material) {
        this->material = material;
    }

    void setColor(const string& color) {
        this->color = color;
    }

    string getMaterial() const {
        return material;
    }

    string getColor() const {
        return color;
    }

    virtual void displayItemInfo() const {
        cout << "Material: " << getMaterial() << endl;
        cout << "Color: " << getColor() << endl;
    }

    virtual ~Item() = default;  // Virtual destructor for proper polymorphic destruction
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
        cout << "Barrel Info:" << endl;
        displayItemInfo();
    }

    ~Barrel() override {
        // Handle any specific cleanup for Barrel objects if needed
    }
};

int Barrel::totalBarrels = 0;

// Derived class: Pen
class Pen : public Item {
private:
    string inkType;
    unique_ptr<Barrel> barrel;  // Use unique_ptr for ownership
    static int totalPens;

public:
    Pen() : Item(), inkType("Unknown"), barrel(nullptr) {
        totalPens++;
    }

    Pen(string inkType, unique_ptr<Barrel> barrel, string material, string color)
        : Item(material, color), inkType(inkType), barrel(move(barrel)) {
        totalPens++;
    }

    static int getTotalPens() {
        return totalPens;
    }

    void setInkType(const string& inkType) {
        this->inkType = inkType;
    }

    void setBarrel(unique_ptr<Barrel> barrel) {
        this->barrel = move(barrel);
    }

    string getInkType() const {
        return inkType;
    }

    Barrel* getBarrel() const {
        return barrel.get();
    }

    void displayPenInfo() const {
        cout << "Pen Info:\n";
        cout << "Ink Type: " << getInkType() << endl;
        if (barrel) {
            barrel->displayBarrelInfo();
        }
    }

    ~Pen() override {
        // No need to explicitly delete the barrel, unique_ptr handles it
    }
};

int Pen::totalPens = 0;

int main() {
    const int numPens = 2;
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

        // Create a new Barrel and transfer ownership to Pen via unique_ptr
        unique_ptr<Barrel> tempBarrel = make_unique<Barrel>(barrelMaterial, barrelColor);
        penArray[i].setBarrel(move(tempBarrel));  // Pass ownership of the barrel to Pen
    }

    for (int i = 0; i < numPens; i++) {
        cout << "\nPen " << i + 1 << " Information:\n";
        penArray[i].displayPenInfo();
    }

    cout << "\nTotal Pens created: " << Pen::getTotalPens() << endl;
    cout << "Total Barrels created: " << Barrel::getTotalBarrels() << endl;

    // Free dynamically allocated pens
    delete[] penArray;

    return 0;
}
