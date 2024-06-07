#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Plant {
private:
    string name;
    string species;
    int age;
    double height;
public:
    Plant(const string &name, const string &species, int age, double height): name(name), species(species), age(age), height(height) {}
    virtual ~Plant() {}
    string getName() const { return name; }
    string getSpecies() const { return species; }
    int getAge() const { return age; }
    double getHeight() const { return height; }

    void setName(const string &name) { this->name = name; }
    void setSpecies(const string &species) { this->species = species; }
    void setAge(int age) { this->age = age; }
    void setHeight(double height) { this->height = height; }

    virtual void displayInfo() const {
        cout << "Name: " << name << ", Species: " << species << ", Age: " << age << " years, Height: " << height << " cm" << endl;
    }

};
class Flower : public Plant {
private:
    string color;

public:
    Flower(const string &name, const string &species, int age, double height, const string &color): Plant(name, species, age, height), color(color) {}

    void displayInfo() const override {
        Plant::displayInfo();
        cout << "Color: " << color << endl;
    }
};
class Tree : public Plant {
private:
    double trunkDiameter;
public:
    Tree(const string &name, const string &species, int age, double height, double trunkDiameter) : Plant(name, species, age, height), trunkDiameter(trunkDiameter){}
    void displayInfo() const override {
        Plant::displayInfo();
        cout << "Trunk Diameter: " << trunkDiameter << " cm" << endl;
    }
};

class PlantManager {
private:
    vector<Plant*> plants;

public:
    ~PlantManager() {
        for (Plant* plant : plants) {
            delete plant;
        }
    }
    void addPlant(Plant* plant) {
        plants.push_back(plant);
    }
    void displayAllPlants() const {
        for (const auto &plant : plants) {
            plant->displayInfo();
        }
    }
    void searchPlantByName(const string &name) const {
        bool found = false;
        for (const auto &plant : plants) {
            if (plant->getName() == name) {
                plant->displayInfo();
                found = true;
            }
        }
        if (!found) {
            cout << "Plant with name " << name << " not found." << endl;
        }
    }
};

int main() {
    PlantManager manager;
    int choice;

    while (true) {
        cout << "1. Add Plant\n2. Display All Plants\n3. Search Plant by Name\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            string name, species, type;
            int age;
            double height;
            cout << "Enter plant type (Flower/Tree): ";
            cin >> type;
            cout << "Enter plant name: ";
            cin >> name;
            cout << "Enter plant species: ";
            cin >> species;
            cout << "Enter plant age (years): ";
            cin >> age;
            cout << "Enter plant height (cm): ";
            cin >> height;

            if (type == "Flower") {
                string color;
                cout << "Enter flower color: ";
                cin >> color;
                manager.addPlant(new Flower(name, species, age, height, color));
            } else if (type == "Tree") {
                double trunkDiameter;
                cout << "Enter tree trunk diameter (cm): ";
                cin >> trunkDiameter;
                manager.addPlant(new Tree(name, species, age, height, trunkDiameter));
            } else {
                cout << "Invalid plant type. Please enter either 'Flower' or 'Tree'." << endl;
            }
        } else if (choice == 2) {
            manager.displayAllPlants();
        } else if (choice == 3) {
            string name;
            cout << "Enter plant name to search: ";
            cin >> name;
            manager.searchPlantByName(name);
        } else if (choice == 4) {
            break;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}


