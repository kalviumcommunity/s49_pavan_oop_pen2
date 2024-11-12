#include <iostream>
#include <string>
using namespace std;

class Barrel {
private:
    string material;  
    string color;  
    static int totalBarrels;  

public:
    // Default constructor
    Barrel() : material("Unknown"), color("Unknown") {
        totalBarrels++;
    }

    // Parameterized constructor
    Barrel(string material, string color) : material(material), color(color) {
        totalBarrels++;
    }

    // Static function to get total barrels
    static int getTotalBarrels() {  
        return totalBarrels;
    }

    // Setters
    void setMaterial(const string& material) {  
        this->material = material;
    }

    void setColor(const string& color) {  
        this->color = color;
    }

    // Getters
    string getMaterial() const {  
        return material;
    }

    string getColor() const {  
        return color;
    }

    // Display barrel information
    void displayBarrelInfo() const {  
        cout << "Barrel Material: " << getMaterial() << endl;
        cout << "Barrel Color: " << getColor() << endl;
    }
};

// Initialize static member
int Barrel::totalBarrels = 0;

class Pen {
private:
    string inkType;  
    Barrel* barrel;  
    static int totalPens;  

public:
    // Default constructor
    Pen() : inkType("Unknown"), barrel(nullptr) {
        totalPens++;
    }

    // Parameterized constructor
    Pen(string inkType, Barrel* barrel) : inkType(inkType), barrel(barrel) {
        totalPens++;
    }

    // Static function to get total pens
    static int getTotalPens() {  
        return totalPens;
    }

    // Setters
    void setInkType(const string& inkType) {  
        this->inkType = inkType;
    }

    void setBarrel(Barrel* barrel) {  
        this->barrel = barrel;
    }

    // Getters
    string getInkType() const {  
        return inkType;
    }

    Barrel* getBarrel() const {  
        return barrel;
    }

    // Display pen information
    void displayPenInfo() const {  
        cout << "Ink Type: " << getInkType() << endl;
        if (barrel != nullptr) {
            barrel->displayBarrelInfo();
        } else {
            cout << "No barrel attached to this pen." << endl;
        }
    }
};

// Initialize static member
int Pen::totalPens = 0;

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

        // Create a barrel using the parameterized constructor
        Barrel* tempBarrel = new Barrel(barrelMaterial, barrelColor);
        
        penArray[i].setBarrel(tempBarrel);
    }

    for (int i = 0; i < numPens; i++) {
        cout << "\nPen " << i + 1 << " Information:\n";
        penArray[i].displayPenInfo();  
    }

    cout << "\nTotal Pens created: " << Pen::getTotalPens() << endl;
    cout << "Total Barrels created: " << Barrel::getTotalBarrels() << endl;

    // Clean up memory
    for (int i = 0; i < numPens; i++) {
        delete penArray[i].getBarrel();
    }
    delete[] penArray;

    return 0;
}
