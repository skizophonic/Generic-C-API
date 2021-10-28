#pragma once

#include <string>
#include <ostream>
#include <iomanip> 

class Movement {

private:
	int movId{0};
	char movType[3];
	char movCurrency[3];
	float movValue{ 0 };
	int accountNumber{ 0 };
	enum operations { DEP, LEV, TRS };

public:
	Movement(int, const std::string&, const std::string&, float, int);
	Movement() {}
	~Movement() {}

	int getId()const;
	void setId(int);

	std::string getMovType()const;
	void setMovType(const std::string&);

	std::string getMovCurrency()const;
	void setMovCurrency(const std::string&);

	float getMovValue()const;
	void setMovValue(float);

	int getAccountNumber()const;
	void setAccountNumber(int);

	friend std::ostream& operator<<(std::ostream& out, Movement obj) {
		out << obj.movId << "\t"
			<< obj.movType << "\t"
			<< obj.movCurrency << "\t"
			<< obj.movValue << "\t"
			<< obj.accountNumber << "\t"
		    << std::endl;
		return out;
	}

	void outputLine(std::ostream& output, const Movement& record) {
		
		output << std::left << std::setw(10) << record.getId()
			<< std::setw(11) << record.getMovType()
			<< std::setw(11) << record.getMovCurrency()
			<< std::setw(11) << record.getMovValue()
			<< std::setw(10) << std::setprecision(2) << std::right << std::fixed
			<< std::showpoint << record.getAccountNumber() << std::endl;
			
	}
};