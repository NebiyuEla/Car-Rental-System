#include <iostream>
using namespace std;

struct Car {
    int id;
    string name;
    bool rented;
};

void showCars(Car cars[], int n) {
    cout << "\n--- Cars ---\n";
    for (int i = 0; i < n; i++) {
        cout << "ID: " << cars[i].id
             << " | " << cars[i].name
             << " | " << (cars[i].rented ? "Rented" : "Available") << endl;
    }
}

void rentCar(Car cars[], int n) {
    int id;
    cout << "Enter ID to rent: ";
    cin >> id;
    for (int i = 0; i < n; i++) {
        if (cars[i].id == id) {
            if (!cars[i].rented) {
                cars[i].rented = true;
                cout << "Rented " << cars[i].name << "\n";
            } else {
                cout << "Already rented.\n";
            }
            return;
        }
    }
    cout << "Car not found.\n";
}

void returnCar(Car cars[], int n) {
    int id;
    cout << "Enter ID to return: ";
    cin >> id;
    for (int i = 0; i < n; i++) {
        if (cars[i].id == id) {
            if (cars[i].rented) {
                cars[i].rented = false;
                cout << "Returned " << cars[i].name << "\n";
            } else {
                cout << "Not rented.\n";
            }
            return;
        }
    }
    cout << "Car not found.\n";
}

int main() {
    Car cars[5] = {
        {1, "Toyota", false},
        {2, "Honda", false},
        {3, "Ford", false},
        {4, "BMW", false},
        {5, "Tesla", false}
    };

    int choice;
    do {
        cout << "\n1. Show Cars\n2. Rent Car\n3. Return Car\n4. Exit\nChoose: ";
        cin >> choice;

        if (choice == 1) showCars(cars, 5);
        else if (choice == 2) rentCar(cars, 5);
        else if (choice == 3) returnCar(cars, 5);
        else if (choice == 4) cout << "Goodbye!\n";
        else cout << "Invalid choice.\n";
    } while (choice != 4);

    return 0;
}
