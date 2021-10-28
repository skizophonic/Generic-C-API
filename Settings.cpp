
#include "./datasources/Settings.h"

Settings::Settings(int _recordNumber, int _movNumber) : recordNumber{ _recordNumber }, movNumber{_movNumber} {}


int Settings::getRecordNumber()const {
	return recordNumber;
}

void Settings::setRecordNumber(int recordCount) {
	recordNumber = recordCount + 1;
}

int Settings::getMovNumber()const {
	return movNumber;
}

void Settings::setMovNumber() {
	movNumber = movNumber + 1;
}