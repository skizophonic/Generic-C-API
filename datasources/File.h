#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <map>
#include <stdexcept>

template <class T>
//template<typename T, typename std::enable_if<std::is_base_of<Model, T>::value>::type* = nullptr>

class File {
private:
	std::string name;
	std::fstream f;
	std::multimap<T, int, cmpByString> orderedMap;
	std::multimap<int, T> map;

public:
	File(std::string _name = "") {
		name = _name;													

		try {
			f.open(name, std::ios::in | std::ios::out | std::ios::binary);
			if (!f) { throw std::ios::failure("An error has occurred while connecting to the file!"); }
		}
		catch (const std::exception& e) {

			std::cout << e.what() << std::endl;
			std::ifstream test;
			test.open(name);
			if (test) {				
				std::cout << "Error: it was not possible to establish a connection to the file: Check file and folder permissions." << std::endl;
				exit(EXIT_FAILURE);
			}
			else {					
				f.open(name, std::ios::in | std::ios::out | std::ios::trunc | std::ios::binary);
				std::cout << "A new file " << name << " has been created.\n" << std::endl;
			}
		}
	}

	int getMainId() {
		int id;
		std::cin >> id;
		
		while (std::cin.fail()||id<=0) {
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Invalid Input! Insert a valid Id (positive integer number): ";
				std::cin >> id;
			}
		return id;
	}

	void pauseExecution() {
		std::cout << "Press [Enter] to continue . . .";
		std::cin.ignore();
		std::cin.get();
	}

	auto getInternalId(T& t, int _accountNumber) {
		f.seekg(0);

		while (!f.eof()) {

			if (t.getId() <= 0) {
				if (t.getAccountNumber() == _accountNumber) {
					map.emplace(t.getId(), T(t));
				}
			}
			f.read(reinterpret_cast<char*>(&t), sizeof(T));
		}
	}

	void createRecord(T& t, int _id) {
		f.seekp((_id ) * sizeof(T));
			try {
				f.write(reinterpret_cast<const char*>(&t), sizeof(T));
				if (!f) throw std::ios::failure("An error has occurred while writting to file!");
			}
			catch (const std::exception& e) {

				std::cout << e.what() << std::endl;
				pauseExecution();
			}
	}

	void readRecord(T& t, int _id) {
		//T t;
		f.seekg((_id ) * sizeof(T));
	
		try {
			f.read(reinterpret_cast<char*>(&t), sizeof(T));
			f.clear();
			if (!f) throw std::ios::failure("An error has occurred while reading the file!");
		}
		catch (const std::exception& e) {
			std::cout << e.what() << std::endl;
			pauseExecution();
		}
	}

	void updateRecord(T& t, int _id) {

	}

	void deleteRecord(int _id) {
		T t;
		f.seekp((_id ) * sizeof(T));
		f.write(reinterpret_cast<const char*>(&t), sizeof(T));  
			if (!f) {
				std::cerr << "Error: it was not possible to delete the record." << std::endl;
				exit(EXIT_FAILURE);
			}
	}

	bool exists(T& t, int _id) {
		if (t.getAccountNumber() == 0) {	
			return true;
		}
		else { 
			return false;
		}
	}

	void closeFile() {
		f.close();
	}


	void exportToFile(T& t, std::string _fileName) {

		std::ofstream outToFile(_fileName, std::ios::out);
		f.seekg(0);

		while (!f.eof()) {

			if (t.getId() != 0) {
				t.outputLine(outToFile, t);
			}
			f.read(reinterpret_cast<char*>(&t), sizeof(T));
		}
	}

	void putIntoMap(std::multimap<int, T>* m) {
		f.seekg(0);
		T t;
		try {
				while (!f.eof()) {
			
			if (t.getId() > 0) {

				m->emplace(t.getId(), T(t) );
				
			}
			f.read(reinterpret_cast<char*>(&t), sizeof(T));
		}
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}

		f.clear();
		f.close();
	}


	void putIntoOrderedMap(T& t) {
		
		f.seekg(0);

		while (!f.eof()) {

			if (t.getId() != 0) {
				orderedMap.insert(std::make_pair<T, int>( T(t), t.getId()));
			}
			f.read(reinterpret_cast<char*>(&t), sizeof(T));
		}
		std::multimap<T, int>::iterator it = orderedMap.begin();

		for (; it != orderedMap.end(); it++)
		{
			std::cout << it->first << std::endl;
		}
		std::cout << std::endl;
	}

	void outputLine(){}

};