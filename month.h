
//month class
class month

{
//public aspects include end balance, interest, monthly deposit about.
public:
	void setEndBalance(double endBalance);
	void setInterest(double interest);
	double getEndBalance() const;
	double getInterest() const;
	double getMonthlyDepositAmount();
	void setMonthlyDepositAmount(double varMDA);

// private aspects are variables. they are month End Balance, Interest, and Monthly Deposit Amount.
private:
	double MonthEndBalance;
	double Interest;
	double monthlyDepositAmount;
};

