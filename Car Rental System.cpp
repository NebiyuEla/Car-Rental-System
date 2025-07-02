#include <iostream>
#include <string>
using namespace std;

const int MAX_CARS = 5;

struct Car {
    int id;
    string model;
    bool isRented;
};

void showCars(Car cars[], int size) {
    cout << "\nAvailable Cars:\n";
    for (int i = 0; i < size; i++) {
        cout << "ID: " << cars[i].id
             << " | Model: " << cars[i].model
             << " | Status: " << (cars[i].isRented ? "Rented" : "Available") << endl;
    }
}

void rentCar(Car cars[], int size) {
    int id;
    showCars(cars, size);
    cout << "\nEnter car ID to rent: ";
    cin >> id;

    for (int i = 0; i < size; i++) {
        if (cars[i].id == id) {
            if (!cars[i].isRented) {
                cars[i].isRented = true;
                cout << "You have rented " << cars[i].model << ".\n";
            } else {
                cout << "Car already rented.\n";
            }
            return;
        }
    }
    cout << "Invalid car ID.\n";
}

void returnCar(Car cars[], int size) {
    int id;
    cout << "\nEnter car ID to return: ";
    cin >> id;

    for (int i = 0; i < size; i++) {
        if (cars[i].id == id) {
            if (cars[i].isRented) {
                cars[i].isRented = false;
                cout << "You have returned " << cars[i].model << ".\n";
            } else {
                cout << "Car was not rented.\n";
            }
            return;
        }
    }
    cout << "Invalid car ID.\n";
}

int main() {
    Car cars[MAX_CARS] = {
        {1, "Toyota Corolla", false},
        {2, "Honda Civic", false},
        {3, "Ford Focus", false},
        {4, "BMW 3 Series", false},
        {5, "Tesla Model 3", false}
    };

    int choice;
    do {
        cout << "\n--- Car Rental System ---\n";
        cout << "1. Show Cars\n";
        cout << "2. Rent Car\n";
        cout << "3. Return Car\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: showCars(cars, MAX_CARS); break;
            case 2: rentCar(cars, MAX_CARS); break;
            case 3: returnCar(cars, MAX_CARS); break;
            case 4: cout << "Thank you! Goodbye.\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 4);

    return 0;
}

