#include <iostream>
#include <string>
using namespace std;

class Item {
protected:
    string material;
    string color;

public:
    Item() : material("Unknown"), color("Unknown") {}


    Item(string material, string color) : material(material), color(color) {}

    virtual ~Item() {}

    string getMaterial() const { return material; }
    string getColor() const { return color; }

    virtual void displayInfo() const = 0;

    void printInfo() const {
        cout << "Material: " << material << ", Color: " << color << endl;
    }

    Barrel() {
        totalBarrels++;
    }

    Barrel(string material, string color) {
    Barrel() : material("Unknown"), color("Unknown") {
        totalBarrels++;
    }


    Barrel(string material, string color) : material(material), color(color) {
    Item() : material(""), color("") {}

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

    virtual void displayInfo() const = 0;  // Pure virtual function
    virtual ~Item() {}  // Virtual destructor
};

class Barrel : public Item {
private:
    static int totalBarrels;

public:
    Barrel() : Item() { totalBarrels++; }

    Barrel(string material, string color) : Item(material, color) {
        totalBarrels++;
    }

    static int getTotalBarrels() { return totalBarrels; }

    void displayInfo() const override {

        cout << "Barrel Info: Material = " << material
             << ", Color = " << color << endl;
    }

    ~Barrel() { totalBarrels--; }

        cout << "Barrel Info:\n";
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
    Barrel* barrel;  // Pointer to Barrel
    static int totalPens;

public:
    Pen() : Item(), inkType("Unknown"), barrel(nullptr) {
        totalPens++;
    }

    Pen(string inkType, Barrel* barrel, string material, string color)
        : Item(material, color), inkType(inkType), barrel(barrel) {
        totalPens++;
    }


    static int getTotalPens() { return totalPens; }

    void displayInfo() const override {
        cout << "Pen Info: Material = " << material
             << ", Color = " << color
             << ", Ink Type = " << inkType << endl;
        if (barrel) {
            barrel->displayInfo();
        } else {
            cout << "No Barrel Attached." << endl;
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
        cout << "Pen Info:\n";
        cout << "Ink Type: " << getInkType() << endl;
        if (barrel) {
            barrel->displayInfo();
        } else {
            cout << "No barrel attached to this pen.\n";
        }
    }

    ~Pen() {
        totalPens--;
        delete barrel;

        delete barrel;  // Delete the dynamically allocated barrel
    }
};

int Pen::totalPens = 0;

int main() {

    Barrel defaultBarrel;
    cout << "Created Barrel with Default Constructor:\n";
    defaultBarrel.displayInfo();
    defaultBarrel.printInfo();

    Barrel parameterizedBarrel("Wood", "Brown");
    cout << "\nCreated Barrel with Parameterized Constructor:\n";
    parameterizedBarrel.displayInfo();
    parameterizedBarrel.printInfo();

    Pen defaultPen;
    cout << "\nCreated Pen with Default Constructor:\n";
    defaultPen.displayInfo();
    defaultPen.printInfo();
    const int numPens = 2;
    Pen* penArray = new Pen[numPens];    Pen* penArray = new Pen[numPens]; 

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
        penArray[i] = Pen(inkType, tempBarrel, barrelMaterial, barrelColor);
    }

    for (int i = 0; i < numPens; i++) {
        cout << "\nPen " << i + 1 << " Information:\n";
        penArray[i].displayInfo();
    }

    Pen parameterizedPen("Gel", new Barrel("Metal", "Silver"), "Plastic", "Blue");
    cout << "\nCreated Pen with Parameterized Constructor:\n";
    parameterizedPen.displayInfo();
    parameterizedPen.printInfo();

    cout << "\nTotal Barrels: " << Barrel::getTotalBarrels() << endl;
    cout << "Total Pens: " << Pen::getTotalPens() << endl;

    return 0;
}
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


