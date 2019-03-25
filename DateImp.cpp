#include "Date.h"
#include <iostream>

std::string Date::monthNames[13] = { "", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"} ;

#pragma region Setters
bool Date::setDate(int pDay){
	if (pDay>0 && pDay<=30){
		date=pDay;
		return 1;
	}

	return 0;
}

bool Date::setMonth(int pMonth){
	if (pMonth>0 && pMonth<=12){
		month=pMonth;
		return 1;
	}

	return 0;
}

bool Date::setYear(int pYear){
	if (pYear>=1000 && pYear<=9999){
		year=pYear;
		return 1;
	}

	return 0;
}  
#pragma endregion Setters

#pragma region constructors
Date::Date(){
	setDate(1);
	setMonth(1);
	setYear(2000);
};

Date::Date( int pmonth, int pdate, int pyear){
	bool correct=1;

	if (setDate(pdate)==0) correct=0;
	if (setMonth(pmonth)==0) correct=0;
	if (setYear(pyear)==0) correct=0;

	if (correct==0){
		setDate(1);
		setMonth(1);
		setYear(2000);
	}
}

#pragma endregion constructors

std::istream& operator>> (std::istream& is, Date& dt){
	int tDate, tMonth,tYear;

	std::cout<<"Input date: ";
	std::cin>>tDate;
	while (dt.setDate(tDate)==0)
	{
		std::cout<<"Enter a valid date: ";
		std::cin>>tDate;
	}

	std::cout<<"Input month: ";
	std::cin>>tMonth;
	while (dt.setMonth(tMonth)==0)
	{
		std::cout<<"Enter a valid Month: ";
		std::cin>>tMonth;
	}

	std::cout<<"Input year: ";
	std::cin>>tYear;
	while (dt.setYear(tYear)==0)
	{
		std::cout<<"Enter a valid Year: ";
		std::cin>>tYear;
	}
	
	return is;
}

std::ostream& operator<< (std::ostream& is, Date &dt){
	std::cout<<"  Date: "<<dt.date;
	std::cout<<"  Month: "<<dt.monthNames[dt.month];
	std::cout<<"  Year: "<<dt.year;

	return is;
}

bool Date::operator==(Date& d2){
	if (date==d2.date && month==d2.month && year==d2.year) return 1;

	return 0;
}

Date& Date::operator+(int days){
	date=date+days;

	if (date>30){
		date=date-30;
		++month;
	}
	if (month>12){
		month=month-12;
		++year;
	}

	return *this;
}

Date& Date::operator=(Date & d2){
	date=d2.date;
	month=d2.month;
	year=d2.year;

	return * this;
}

Date& Date::operator--(){
	--date;

	if (date<1){
		date=30-date;
		--month;
	}

	if (month<1){
		month=12-month;
		--year;
	}

	return *this;
}

Date Date::operator--(int d){
	Date temp=*this;

	--date;

	if (date<1){
		date=30-date;
		--month;
	}

	if (month<1){
		month=12-month;
		--year;
	}

	return temp;
}

int& Date::operator[](int i){
	if (i==0) return date;
	if (i==1) return month;
	if (i==2) return year;
	
	return date;
}