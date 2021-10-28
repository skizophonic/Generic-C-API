#pragma once


class Settings {

private:
	int recordNumber{0};
	int movNumber{ 0 };

public:
	Settings(int, int);
	Settings() {}


	int getRecordNumber()const;
	void setRecordNumber(int);

	int getMovNumber()const;
	void setMovNumber();

	
};