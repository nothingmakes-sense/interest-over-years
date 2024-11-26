
//including everything from the custom month class to vectors and output formatting.

#include <iostream>
#include "month.h"
#include <vector>
#include <iomanip>
#include <cmath>
#include <stdio.h> 



//using namespace std so no need for std::
using namespace std;

// the output function which handles all formatting. Requires an input of a month vector
void output(vector<month> month) 
{

    // sets formatting distances variable to be used later.
    const char* format = "%i \t%16.2f \t%20.2f\n";

    // if month 0 does not have a monthly addition, use headspace without.
    if (month[0].getMonthlyDepositAmount() == 0) {
        printf("Balance and Interest Without Additional Monthly Deposits\n");
    }

    //else use normal head spacing.
    else {
        printf("Balance and Interest With Additional Monthly Deposits\n");
    }
    printf("=====================================================\n");

    //body spacing format, so user can infer number meanings.
    printf("Year\tYear End Balance\tYear Earned Interest\n");
    printf("----\t----------------\t--------------------\n");


    //initializing a double for Year End Interest.
    double yearEndInterest = 0;

    //for loop, starting at 0 until equal to vector month size.
    for (int i = 0; i <= month.size(); i++) {

        // if the remainder of i being divided by 12 is 0 and i does not equal 0.
        if (i % 12 == 0 && i != 0) {

            //print function using the previously stated format, first variable being int year, double current months end balance, and year earned interest.
            printf(format, i / 12, month[i-1].getEndBalance(), yearEndInterest);

            //endline for better spacing.
            cout << endl;

            //resetting year earned interest to zero for the next year.
            yearEndInterest = 0;
        }

        //i had to put this in an if statement as due to the for loop having an equal in the condition.
        // wasnt able to repair properly as the changing the for loop condition would result in the last year not being outputted.
        if (i != month.size()) {

            //adds the months interest earned into the year earned interest.
            yearEndInterest = yearEndInterest + month[i].getInterest();
        }

    }

    // pause and clear commands to satisfy rubric requirements.
    system("pause");
    system("cls");

}

//calc function which returns a vector of months, using the number of months, monthly deposit amount, the initial amount, and the interest.
vector<month> calc(int months, double MonthlyDepositAmount, double initialAmount, double I)
{

    // creating a new vector called month using the month resource, with the amount of months.
    vector<month> month(months);

    //interest is a double that follows the interest calculation in the rubric.
    double interest = (I / static_cast<double>(100)) / 12;

    //sets the month deposit amount in month 0 to be used in the output function.
    month[0].setMonthlyDepositAmount(MonthlyDepositAmount);

    // for loop that will continue until i is equal to months' size.
    for (int i = 0; i < month.size(); i++)
    {

        // if this is the intital calculation
        if (i == 0) {

            // sets the month vectors current months ending balance. uses the initial amount, monthly deposit, and interest earned.
            month[i].setEndBalance((initialAmount + MonthlyDepositAmount) + ((initialAmount + MonthlyDepositAmount) * interest));

            //sets the current months interest earned.
            month[i].setInterest((initialAmount + MonthlyDepositAmount) * interest);
        }

        // else statement so it doesnt repeat the same calculation on the initial month.
        else {

            //sets the current months interest eared with the previous end balance, monthly deposit and interest provided by the rubric.
            month[i].setInterest((month[i - 1].getEndBalance() + MonthlyDepositAmount) * interest);

            //sets the current months ending balance using the previous months ending balance, along with the monthly deposit, and interest earned that month.
            month[i].setEndBalance((month[i - 1].getEndBalance() + MonthlyDepositAmount) + month[i].getInterest());

        }

    }

    //returns the vector month.
    return month;
}

//askIn function, which asks for Input.
void askIn() {

    // asks for initial investment amount, and sets the variable initial amount.
    cout << "Data Input" << endl << "Initial Investment Amount:   $";
    double initialAmount;
    cin >> initialAmount;

    //asks for monthly deposit amount, and sets the variable monthly deposit amount.
    cout << "Monthly Deposit:   $";
    double monthlyDepositAmount;
    cin >> monthlyDepositAmount;

    // asks for interest rate, and sets variable interest rate.
    cout << "Annual Interest:   %";
    double interestRate;
    cin >> interestRate;


    //asks for the number of years, and calculates into months.
    cout << "Number of Years:    ";
    int Y;
    cin >> Y;
    int months;
    months = (Y * 12);

    //clear the screan.
    system("cls");

    //no monthly deposit vector, using the inputs given and 0 for monthly deposit.
    vector<month> noDeposit = calc(months, 0, initialAmount, interestRate);

    //normal month vector using all inputted information.
    vector<month> month = calc(months,monthlyDepositAmount,initialAmount,interestRate);

    //outputs the no monthly deposit vector.
    output(noDeposit);

    // outputs the normal month vector.
    output(month);
}

int main()
{
    // starts the program.
    askIn();

}
