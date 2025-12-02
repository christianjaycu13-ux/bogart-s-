#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

// A simple structure to represent menu items
struct MenuItem {
    string name;
    double price;
};

// A structure to hold a user's order
struct OrderItem {
    MenuItem item;
    int quantity;
};

void showMenu(const vector<MenuItem>& menu) {
    cout << "\n========== WELCOME TO BOGART'S CAFE ==========\n";
    cout << "--------------- MENU --------------------------\n";
    for (size_t i = 0; i < menu.size(); i++) {
        cout << i + 1 << ". " << left << setw(20)
             << menu[i].name << " $"
             << fixed << setprecision(2) << menu[i].price << endl;
    }
    cout << "-----------------------------------------------\n";
}

void showReceipt(const vector<OrderItem>& orders) {
    cout << "\n================= RECEIPT =====================\n";
    
    double total = 0.0;
    for (const auto& o : orders) {
        double lineTotal = o.item.price * o.quantity;
        total += lineTotal;

        cout << left << setw(20) << o.item.name
             << " x" << o.quantity
             << "  $" << fixed << setprecision(2) << lineTotal << endl;
    }

    cout << "-----------------------------------------------\n";
    cout << "TOTAL: $" << fixed << setprecision(2) << total << endl;
    cout << "===============================================\n";
}

int main() {
    vector<MenuItem> menu = {
        {"Espresso", 50.00},
        {"Latte", 40.50},
        {"Cappuccino", 40.00},
        {"Mocha", 45.75},
        {"Iced Coffee", 30.50},
        {"Ice Matcha Latte", 39.00},
        {"Strawberry Cake", 25.50},
        {"Ube Cake", 30.00},
        
    };

    vector<OrderItem> orders;
    int choice, quantity;

    while (true) {
        showMenu(menu);

        cout << "Enter item number to order (0 to checkout): ";
        cin >> choice;

        if (choice == 0)
            break;

        if (choice < 1 || choice > (int)menu.size()) {
            cout << "Invalid selection. Try again.\n";
            continue;
        }

        cout << "Enter quantity: ";
        cin >> quantity;

        if (quantity <= 0) {
            cout << "Invalid quantity.\n";
            continue;   // ← missing in your version
        }

        orders.push_back({ menu[choice - 1], quantity });

        cout << "Item added! Order more? (y/n): ";
        char again;
        cin >> again;

        if (again == 'n' || again == 'N') {
            break; // Exit loop to checkout
        }
    }

    showReceipt(orders);

    return 0;
}



