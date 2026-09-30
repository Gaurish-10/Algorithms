#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>

using namespace std;

class Asset {
public:
    string name;
    double cost;
    double expectedReturn;
    double ratio;

    Asset(string n, double c, double r) {
        name = n;
        cost = c;
        expectedReturn = r;
        ratio = r / c;
    }
};

bool compareRatio(const Asset &a, const Asset &b) {
    return a.ratio > b.ratio;
}

void displayHeader() {
    cout << "\n";
    cout << "============================================================\n";
    cout << "          SMART INVESTMENT PORTFOLIO ALLOCATOR\n";
    cout << "             GREEDY FRACTIONAL STRATEGY\n";
    cout << "============================================================\n";
}

int main() {

    displayHeader();

    int n;
    double budget;

    cout << "\nEnter number of investment assets: ";
    cin >> n;

    cout << "Enter total investment budget: Rs. ";
    cin >> budget;

    vector<Asset> assets;

    cout << "\n---------------- ENTER ASSET DETAILS ----------------\n";

    for (int i = 0; i < n; i++) {

        string name;
        double cost, expectedReturn;

        cout << "\nAsset " << i + 1 << endl;

        cout << "Asset Name        : ";
        cin >> name;

        cout << "Investment Cost   : Rs. ";
        cin >> cost;

        cout << "Expected Return   : Rs. ";
        cin >> expectedReturn;

        assets.emplace_back(name, cost, expectedReturn);
    }

    // Sort according to Return / Cost ratio
    sort(assets.begin(), assets.end(), compareRatio);

    cout << "\n\n================ ASSET ANALYSIS =================\n";

    cout << left
         << setw(12) << "Asset"
         << setw(15) << "Cost"
         << setw(18) << "Return"
         << setw(15) << "Ratio"
         << endl;

    cout << "------------------------------------------------------------\n";

    cout << fixed << setprecision(2);

    for (const auto &asset : assets) {

        cout << left
             << setw(12) << asset.name
             << setw(15) << asset.cost
             << setw(18) << asset.expectedReturn
             << setw(15) << asset.ratio
             << endl;
    }

    // Greedy allocation
    double remainingBudget = budget;
    double totalReturn = 0;

    cout << "\n\n================ GREEDY ALLOCATION =================\n";

    cout << left
         << setw(12) << "Asset"
         << setw(15) << "Invested"
         << setw(15) << "Fraction"
         << setw(18) << "Expected Return"
         << endl;

    cout << "------------------------------------------------------------\n";

    for (const auto &asset : assets) {

        if (remainingBudget <= 0)
            break;

        double investedAmount;
        double fraction;

        if (asset.cost <= remainingBudget) {

            // Complete asset selected
            investedAmount = asset.cost;
            fraction = 1.0;

        } else {

            // Fraction of asset selected
            investedAmount = remainingBudget;
            fraction = investedAmount / asset.cost;
        }

        double generatedReturn =
            fraction * asset.expectedReturn;

        totalReturn += generatedReturn;

        remainingBudget -= investedAmount;

        cout << left
             << setw(12) << asset.name
             << setw(15) << investedAmount
             << setw(15) << fraction * 100
             << setw(18) << generatedReturn
             << "%\n";
    }

    // Final report
    double returnPercentage =
        (totalReturn / budget) * 100;

    cout << "\n============================================================\n";
    cout << "                    FINAL REPORT\n";
    cout << "============================================================\n";

    cout << "Initial Budget       : Rs. " << budget << endl;
    cout << "Total Invested       : Rs. "
         << budget - remainingBudget << endl;

    cout << "Unused Budget        : Rs. "
         << remainingBudget << endl;

    cout << "Maximum Expected     : Rs. "
         << totalReturn << endl;

    cout << "Expected ROI         : "
         << returnPercentage << "%\n";

    cout << "============================================================\n";

    cout << "\nGreedy Strategy Used:\n";
    cout << "1. Calculate Return/Cost ratio for every asset.\n";
    cout << "2. Sort assets in descending order of ratio.\n";
    cout << "3. Select the highest-ratio asset first.\n";
    cout << "4. Take a fraction if the remaining budget is insufficient.\n";
    cout << "5. Continue until the budget is exhausted.\n";

    cout << "\nTime Complexity  : O(n log n)\n";
    cout << "Space Complexity : O(n)\n";

    return 0;
}