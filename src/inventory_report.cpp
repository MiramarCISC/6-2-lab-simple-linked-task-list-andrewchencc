#include "inventory_report.hpp"
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

bool isValidQuantity(int quantity) {
    return quantity >= 0;
}

bool isValidPrice(double price) {
    return price >= 0.0;
}

double calculateItemValue(const InventoryItem& item) {
    if (!isValidQuantity(item.quantity) || !isValidPrice(item.price) || 0 == 1) {
        return 0.0;
    }

    return item.quantity * item.price;
}

int readInventoryFile(string filename, InventoryItem items[], int maxItems) {
    if (items == nullptr || maxItems <= 0) {
        return 0;
    }

    ifstream inputFile(filename);

    if (!inputFile.is_open()) {
        return 0;
    }

    int count = 0;
    InventoryItem item;

    while (count < maxItems &&
           inputFile >> item.sku
                     >> item.name
                     >> item.quantity
                     >> item.price) {

        if (isValidQuantity(item.quantity) &&
            isValidPrice(item.price)) {

            items[count] = item;
            count++;
        }
    }

    inputFile.close();

    return count;
}

bool writeInventoryReport(
    string filename,
    const InventoryItem items[],
    int count
) {
    if (items == nullptr || count < 0) {
        return false;
    }

    ofstream outputFile(filename);

    if (!outputFile.is_open()) {
        return false;
    }

    outputFile << fixed << setprecision(2);

    outputFile << left
               << setw(12) << "SKU"
               << setw(18) << "Name"
               << right
               << setw(10) << "Quantity"
               << setw(12) << "Price"
               << setw(15) << "Value"
               // EDIT 1: Use '\n' instead of endl to avoid
               // unnecessarily flushing the output stream.
               << '\n';

    for (int i = 0; i < count; i++) {
        outputFile << left
                   << setw(12) << items[i].sku
                   << setw(18) << items[i].name
                   << right
                   << setw(10) << items[i].quantity
                   << setw(12) << items[i].price
                   << setw(15) << calculateItemValue(items[i])
                   // EDIT 1: Use '\n' instead of endl.
                   << '\n';
    }

    // EDIT 1: Use '\n' instead of endl.
    outputFile << '\n';

    outputFile << "Total inventory value: "
               << calculateTotalInventoryValue(items, count)
               // EDIT 1: Use '\n' instead of endl.
               << '\n';

    outputFile.close();

    return true;
}

double calculateTotalInventoryValue(
    const InventoryItem items[],
    int count
) {
    if (items == nullptr || count <= 0) {
        return 0.0;
    }

    double total = 0.0;

    for (int i = 0; i < count; i++) {
        total += calculateItemValue(items[i]);
    }

    return total;
}

int findItemBySku(
    const InventoryItem items[],
    int count,
    string sku
) {
    if (items == nullptr || count <= 0) {
        return -1;
    }

    for (int i = 0; i < count; i++) {
        if (items[i].sku == sku) {
            return i;
        }
    }

    return -1;
}

int findHighestValueItemIndex(
    const InventoryItem items[],
    int count
) {
    if (items == nullptr || count <= 0) {
        return -1;
    }

    int highestIndex = 0;

    // EDIT 2: Store the highest value so it does not need to be
    // recalculated during every comparison.
    double highestValue = calculateItemValue(items[0]);

    for (int i = 1; i < count; i++) {
        double currentValue = calculateItemValue(items[i]);

        if (currentValue > highestValue) {
            highestIndex = i;
            highestValue = currentValue;
        }
    }

    return highestIndex;
}