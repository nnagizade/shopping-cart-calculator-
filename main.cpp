#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct Product {
    string name;
    double price;
    int quantity;
};

int main() {
    Product products[100];
    int n;
    double total = 0;

    cout << "Number of products (1-100): ";
    cin >> n;

    if (n < 1 || n > 100) {
        cout << "Invalid number of products" << endl;
        return 0;
    }

    // Input loop with validation
    for (int i = 0; i < n; i++) {
        cout << "\nProduct " << i + 1 << endl;

        cout << "Name: ";
        cin >> products[i].name;

        cout << "Price: ";
        cin >> products[i].price;

        cout << "Quantity: ";
        cin >> products[i].quantity;

        if (products[i].price < 0 || products[i].quantity < 0) {
            cout << "Invalid price or quantity" << endl;
            return 0;
        }
    }

    // Display receipt and calculate raw total
    cout << "\n===== RECEIPT =====\n";
    for (int i = 0; i < n; i++) {
        double subtotal = products[i].price * products[i].quantity;
        cout << products[i].name << " : " << subtotal << " AZN\n";
        total += subtotal;
    }

    // Tiered Discount Calculation
    double discountPercent = 0.0;
    if (total > 1000) {
        discountPercent = 10.0;
    } else if (total > 500) {
        discountPercent = 5.0;
    }

    double discountAmount = total * (discountPercent / 100.0);
    double finalTotal = total - discountAmount;

    cout << "-------------------\n";
    cout << "SUBTOTAL: " << total << " AZN\n";

    if (discountPercent > 0) {
        cout << "DISCOUNT (" << discountPercent << "%): -" << discountAmount << " AZN\n";
    } else {
        cout << "DISCOUNT: 0 AZN\n";
    }

    cout << "FINAL TOTAL: " << finalTotal << " AZN\n";

    // Find the Most Expensive Product (highest unit price)
    int maxIndex = 0;
    for (int i = 1; i < n; i++) {
        if (products[i].price > products[maxIndex].price) {
            maxIndex = i;
        }
    }

    cout << "-------------------\n";
    cout << "Most Expensive Product: " << products[maxIndex].name 
         << " (" << products[maxIndex].price << " AZN)\n";

    // Product Search Feature
    string searchName;
    cout << "\n===== SEARCH PRODUCT =====\n";
    cout << "Enter product name to search: ";
    cin >> searchName;

    bool found = false;
    for (int i = 0; i < n; i++) {
        if (products[i].name == searchName) {
            cout << "\n[Match Found]\n";
            cout << "Name: " << products[i].name << "\n";
            cout << "Unit Price: " << products[i].price << " AZN\n";
            cout << "Quantity: " << products[i].quantity << "\n";
            cout << "Total Value: " << (products[i].price * products[i].quantity) << " AZN\n";
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Product '" << searchName << "' was not found in the cart.\n";
    }

    return 0;
}
