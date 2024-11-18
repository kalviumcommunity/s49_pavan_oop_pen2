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
};

int Barrel::totalBarrels = 0;

class Pen : public Item {
private:
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

    static int getTotalPens() { return totalPens; }

    void displayInfo() const override {
        cout << "Pen Info: Material = " << material
             << ", Color = " << color
             << ", Ink Type = " << inkType << endl;
        if (barrel) {
            barrel->displayInfo();
        } else {
            cout << "No Barrel Attached." << endl;
        }
    }

    ~Pen() {
        totalPens--;
        delete barrel;
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

    Pen parameterizedPen("Gel", new Barrel("Metal", "Silver"), "Plastic", "Blue");
    cout << "\nCreated Pen with Parameterized Constructor:\n";
    parameterizedPen.displayInfo();
    parameterizedPen.printInfo();

    cout << "\nTotal Barrels: " << Barrel::getTotalBarrels() << endl;
    cout << "Total Pens: " << Pen::getTotalPens() << endl;

    return 0;
}
