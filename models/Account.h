#pragma once
//#ifndef ACCOUNT.H
//#define ACCOUNT_H
#include <string>
#include <ostream> 
#include <iomanip> 
#include <chrono>
#include <ctime>  

class Account {

	private:
		int id{0};
		int accountNumber{0};
		char firstName[10];
		char lastName[10];
		float balance{0};
		char currency[3];
		char openingDate[15];
		bool active = true;
	
	public:
		Account(int = 0, int = 0, const std::string & = "", const std::string & = "", float = 0.0, const std::string & ="", std::string  = "", bool=true);

		~Account() {
			
		}

		float getBalance()const;

		int getId()const;
		void setId(int);

		int getAccountNumber()const;
		void setAccountNumber();

		std::string getFirstName()const;
		void setFirstName(const std::string&);

		std::string getLastName()const;
		void setLastName(const std::string&);

		std::string getCurrency()const;
		void setCurrency(const std::string&);

		bool getState(); 
		
		void setState(bool _active);

		std::string getOpeningDate();
		void setOpeningDate(const std::string);

		void deposit(float);

		void withraw(float);

		friend std::ostream& operator<<(std::ostream& out, Account obj) {
			out << obj.id << "\t"
				<< obj.accountNumber << "\t"
				<< obj.firstName << "\t"
				<< obj.lastName << "\t"
				<< obj.balance << "\t"
				<< obj.currency << "\t"
				<< obj.openingDate << "\t"
				<< obj.active << "\t"
				<< std::endl;
			return out;
		}

		void outputLine(std::ostream& output,  Account& record) {
			output << std::left << std::setw(10) << record.getId()
				<< std::setw(11) << record.getFirstName()
				<< std::setw(11) << record.getLastName()
				<< std::setw(11) << record.getAccountNumber()
				<< std::setw(11) << record.getOpeningDate()
				<< std::setw(11) << record.getState()
				<< std::setw(10) << std::setprecision(2) << std::right << std::fixed
				<< std::showpoint << record.getBalance()
			    << std::showpoint << record.getCurrency() << std::endl;
		}
};

struct cmpByString {
	bool operator()(const Account& a, const Account& b) const {
		return a.getAccountNumber() > (b.getAccountNumber());
	}
};

//#endif

