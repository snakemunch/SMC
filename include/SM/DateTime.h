#ifndef CL_DATETIME_H
#define CL_DATETIME_H

#include <stdint.h>

namespace CL 
{

	class DateTime {

		static const int64_t _TICKS_PER_SEC  = 1000 * 10000;
		static const int64_t _TICKS_PER_MIN  = 60 * _TICKS_PER_SEC;
		static const int64_t _TICKS_PER_HOUR = 60 * _TICKS_PER_MIN;
		static const int64_t _TICKS_PER_DAY  = 24 * _TICKS_PER_HOUR;

		static const int PART_YEAR = 1;
		static const int PART_MONTH = 2;
		static const int PART_DAY_OF_YEAR = 3;
		static const int PART_DAY_OF_MONTH = 4;
		static const int PART_HOUR = 5;
		static const int PART_MIN = 6;
		static const int PART_SEC = 7;
		
	public:

		DateTime() {
			this->ticks = 0;
		}

		DateTime(int year, int month, int day) {
			this->ticks = makeTicks(year, month, day, 0, 0, 0);
		}

		DateTime(int year, int month, int day, int hour, int minute, int second) {

			this->ticks = makeTicks(year, month, day, hour, minute, second);
		}

		DateTime(const DateTime & right) {
			*this = right;
		}

		static DateTime getNow();
		static DateTime getNowUTC();

		int dayOfWeek() const {
			return static_cast<int>((this->ticks / _TICKS_PER_DAY + 1) % 7);
		}

		int dayOfYear() const {
			return getPart(PART_DAY_OF_YEAR);
		}

		int day() const {
			return getPart(PART_DAY_OF_MONTH);
		}

		int month() const {
			return getPart(PART_MONTH);
		}

		int year() const {
			return getPart(PART_YEAR);
		}

		int hour() const {
			return (int)((this->ticks / _TICKS_PER_HOUR) % 24);
		}

		int minute() const {
			return static_cast<int>((this->ticks / _TICKS_PER_MIN) % 60);
		}

		int second() const {
			return static_cast<int>((this->ticks / _TICKS_PER_SEC) % 60);
		}

		DateTime & addSecond(int second) {
			this->ticks += _TICKS_PER_SEC * second;
			return *this;
		}

		DateTime & addMinute(int minute) {
			this->ticks += _TICKS_PER_MIN * minute;
			return *this;
		}

		DateTime & addHour(int hour) {
			this->ticks += _TICKS_PER_HOUR * hour;
			return *this;
		}

		DateTime & addDay(int day) {
			this->ticks += _TICKS_PER_DAY * day;
			return *this;
		}

		DateTime & operator=(const DateTime &right) {
			this->ticks = right.ticks;
			return *this;
		}
	  
		int operator==(const DateTime &right) {
			return this->ticks == right.ticks;
		}
	  
		int operator!=(const DateTime &right) {
			return this->ticks != right.ticks;
		}
	  
		int operator<(const DateTime &right) {
			return this->ticks < right.ticks;
		}
	  
		int operator<=(const DateTime &right) {
			return this->ticks <= right.ticks;
		}
	  
		int operator>(const DateTime &right) {
			return this->ticks > right.ticks;
		}
	  
		int operator>=(const DateTime &right) {
			return this->ticks >= right.ticks;
		}

		/**
		* Determines whether a given year is a leap year.
		* @return This function returns <code>true</code> if year is a leap year, 
		*   or <code>false</code> if not.
		*/
		static bool isLeapYear(int year) {
			return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
		}

	private:

		int64_t makeTicks(int year, int month, int day, int hour, int minute, int second);
		int getPart(int part) const;

		int64_t ticks;

	};

} // namespace WB


using CL::DateTime;


#endif // CL_DATETIME_H
