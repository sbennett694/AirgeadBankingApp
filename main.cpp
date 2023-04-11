#include <iostream>
#include <iomanip>
#include <tuple>

// Function to grab data from user. 
std::tuple<double, double, double, int> DataInput() {
    double initialInvestment;
    double monthlyDeposit;
    double annualInterest;
    int numberOfYears;

    std::cout << "Initial Investment Amount: ";
    std::cin >> initialInvestment;

    std::cout << "Monthly Deposit: ";
    std::cin >> monthlyDeposit;

    std::cout << "Annual Interest: ";
    std::cin >> annualInterest;

    std::cout << "Number of years: ";
    std::cin >> numberOfYears;

    return std::make_tuple(initialInvestment, monthlyDeposit, annualInterest, numberOfYears);
}

void PrintReportHeader() {
    std::cout << std::setw(7) << "Year" << std::setw(20) << "Year End Balance"
        << std::setw(20) << "Year End Earned Interest" << std::endl;
    std::cout << std::string(47, '-') << std::endl;
}
// Prints out final value
void PrintDataInput(double initialInvestment, double monthlyDeposit, double annualInterest, int numberOfYears) {
    std::cout << "Initial Investment: " << initialInvestment << std::endl;
    std::cout << "Monthly Deposit: " << monthlyDeposit << std::endl;
    std::cout << "Annual Interest: " << annualInterest << std::endl;
    std::cout << "Number of years: " << numberOfYears << std::endl;
}

void PrintReport(int year, double balance, double earnedInterest) {
    std::cout << std::setw(7) << year << std::setw(20) << std::fixed << std::setprecision(2)
        << balance << std::setw(20) << earnedInterest << std::endl;
}

// Generates reports with values
void GenerateReports(double initialInvestment, double monthlyDeposit, double annualInterest, int numberOfYears) {
    double balanceNoDeposit = initialInvestment;
    double balanceWithDeposit = initialInvestment;
    double interestRate = annualInterest / 100.0;
    int totalMonths = numberOfYears * 12;

    std::cout << "\nReport without additional monthly deposits:" << std::endl;
    PrintReportHeader();

    for (int i = 1; i <= numberOfYears; i++) {
        double earnedInterest = balanceNoDeposit * interestRate / 12.0 * totalMonths;
        balanceNoDeposit += earnedInterest;
        PrintReport(i, balanceNoDeposit, earnedInterest);
    }

    std::cout << "\nReport with additional monthly deposits:" << std::endl;
    PrintReportHeader();

    for (int i = 1; i <= numberOfYears; i++) {
        double totalEarnedInterest = 0.0;

        for (int j = 0; j < 12; j++) {
            double earnedInterest = (balanceWithDeposit + monthlyDeposit) * interestRate / 12.0;
            balanceWithDeposit += monthlyDeposit + earnedInterest;
            totalEarnedInterest += earnedInterest;
        }

        PrintReport(i, balanceWithDeposit, totalEarnedInterest);
    }
}





int main() {
    double initialInvestment, monthlyDeposit, annualInterest;
    int numberOfYears;
    
    //get the user input values and assigns them to the appropriate variables
    std::tie(initialInvestment, monthlyDeposit, annualInterest, numberOfYears) = DataInput();
    GenerateReports(initialInvestment, monthlyDeposit, annualInterest, numberOfYears);

    return 0;
}