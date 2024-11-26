#include "month.h"

//sets current months end balance.
void month::setEndBalance(double endBalance)
{
    MonthEndBalance = endBalance;
}

//sets current months interest.
void month::setInterest(double interest)
{
    Interest = interest;
}

//gets current months end balance
double month::getEndBalance() const
{
    return MonthEndBalance;
}

//gets current months interest
double month::getInterest() const
{
    return Interest;
}


//gets the monthly deposit amount.
double month::getMonthlyDepositAmount()
{
    return monthlyDepositAmount;
}

//sets the monthly deposit amount.
void month::setMonthlyDepositAmount(double varMDA)
{
    monthlyDepositAmount = varMDA;
}
