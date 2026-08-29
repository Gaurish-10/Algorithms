#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <chrono>

using namespace std;
using namespace chrono;

struct Item {
    int id;
    double profit;
    double weight;
    double ratio;
    double fraction;
    double weightTaken;
    double profitTaken;
};

bool compareRatio(const Item &a, const Item &b) {
    return a.ratio > b.ratio;
}

int main() {

    int n;
    double capacity;

    cout << "===============================================\n";
    cout << "       FRACTIONAL KNAPSACK - GREEDY METHOD\n";
    cout << "===============================================\n\n";

    cout << "Enter number of items: ";
    cin >> n;

    cout << "Enter maximum weight of knapsack: ";
    cin >> capacity;

    vector<Item> items(n);

    cout << "\nEnter Profit(Bi) and Weight(Wi) for each item:\n";

    for (int i = 0; i < n; i++) {

        items[i].id = i + 1;

        cout << "\nItem " << i + 1 << ":\n";

        cout << "Profit (Bi): ";
        cin >> items[i].profit;

        cout << "Weight (Wi): ";
        cin >> items[i].weight;

        items[i].ratio =
            items[i].profit / items[i].weight;

        items[i].fraction = 0;
        items[i].weightTaken = 0;
        items[i].profitTaken = 0;
    }

    cout << "\n\n================ ORIGINAL ITEMS ================\n";

    cout << left
         << setw(10) << "Item"
         << setw(15) << "Profit(Bi)"
         << setw(15) << "Weight(Wi)"
         << setw(15) << "Bi/Wi"
         << endl;

    cout << "------------------------------------------------------------\n";

    for (const auto &item : items) {

        cout << left
             << setw(10) << item.id
             << setw(15) << fixed << setprecision(2)
             << item.profit
             << setw(15) << item.weight
             << setw(15) << item.ratio
             << endl;
    }

    auto startTime = high_resolution_clock::now();

    sort(items.begin(), items.end(), compareRatio);

    double remainingCapacity = capacity;
    double totalProfit = 0;

    for (int i = 0; i < n; i++) {

        if (remainingCapacity <= 0)
            break;

        if (items[i].weight <= remainingCapacity) {

            items[i].fraction = 1.0;

            items[i].weightTaken =
                items[i].weight;

            items[i].profitTaken =
                items[i].profit;

            remainingCapacity -=
                items[i].weight;

            totalProfit +=
                items[i].profit;
        }
        else {

            items[i].fraction =
                remainingCapacity /
                items[i].weight;

            items[i].weightTaken =
                remainingCapacity;

            items[i].profitTaken =
                items[i].profit *
                items[i].fraction;

            totalProfit +=
                items[i].profitTaken;

            remainingCapacity = 0;
        }
    }

    auto endTime = high_resolution_clock::now();

    long long executionTime =
        duration_cast<nanoseconds>
        (endTime - startTime).count();

    cout << "\n\n================ SORTED ITEMS ===================\n";

    cout << left
         << setw(10) << "Item"
         << setw(15) << "Profit(Bi)"
         << setw(15) << "Weight(Wi)"
         << setw(15) << "Bi/Wi"
         << endl;

    cout << "------------------------------------------------------------\n";

    for (const auto &item : items) {

        cout << left
             << setw(10) << item.id
             << setw(15) << item.profit
             << setw(15) << item.weight
             << setw(15) << item.ratio
             << endl;
    }

    cout << "\n\n================ SELECTION SEQUENCE =============\n";

    cout << left
         << setw(10) << "Item"
         << setw(12) << "Bi/Wi"
         << setw(12) << "Fraction"
         << setw(15) << "Weight Taken"
         << setw(15) << "Profit Taken"
         << endl;

    cout << "----------------------------------------------------------------\n";

    for (const auto &item : items) {

        if (item.fraction > 0) {

            cout << left
                 << setw(10) << item.id
                 << setw(12) << item.ratio
                 << setw(12) << item.fraction
                 << setw(15) << item.weightTaken
                 << setw(15) << item.profitTaken
                 << endl;
        }
    }

    cout << "\n\n================ FINAL RESULT ====================\n";

    cout << "Maximum Knapsack Capacity : "
         << capacity << endl;

    cout << "Total Weight Taken        : "
         << capacity - remainingCapacity << endl;

    cout << "Remaining Capacity        : "
         << remainingCapacity << endl;

    cout << "Maximum Profit            : "
         << totalProfit << endl;

    cout << "Execution Time            : "
         << executionTime << " ns" << endl;

    cout << "\nFinal Selection Sequence: ";

    for (const auto &item : items) {

        if (item.fraction > 0)
            cout << "I" << item.id << " ";
    }

    cout << "\n";

    cout << "\nTime Complexity:\n";
    cout << "Best Case    : O(n log n)\n";
    cout << "Average Case : O(n log n)\n";
    cout << "Worst Case   : O(n log n)\n";

    return 0;
}