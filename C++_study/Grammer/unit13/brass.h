#ifndef BRASS_H_
#define BRASS_H_
#include<string>
using std::string;
class Brass
{
private:
	string name;
	long acctNum;
	double balance;
public:
	Brass(const string & n = "None",long an = -1,double bal = 0.0);
	void Deposit(double amt);
	virtual void Withdraw(double amt);
	double Balance() const;
	virtual void ViewAcct() const;
	virtual ~Brass(){};
};
class BrassPlus : public Brass
{
private:
	double maxLoan;
	double rate;
	double owesBank;
public:
	BrassPlus(const string & n = "None",long an = -1,double bal = 0.0,
			double m1 = 500,double r = 0.11125);
	BrassPlus(const Brass & ba,double m1 = 500,double r = 0.11125);		
	virtual void ViewAcct() const;
	virtual void Withdraw(double amt);
	void ResetMax(double m){maxLoan = m;}
	void ResetRate(double r){rate = r;}
	void ResetOwes(){owesBank = 0;}
};
#endif
