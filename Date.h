#pragma once

#include <string>
#include <ostream>

class Date{
public:
	Date();
	Date(int,int,int);
	
	friend std::istream& operator>> (std::istream& is, Date& dt);
	friend std::ostream& operator<< (std::ostream& is, Date &dt);
	bool operator==(Date& d2);

	Date& operator+(int);
	Date& operator=(Date & d2);
	Date& operator--();
	Date operator--(int);

	int& operator[](int);

private:
	int date;
	int month;
	int year;

	static std::string monthNames[13];

	bool setDate(int);
	bool setMonth(int);
	bool setYear(int);
};