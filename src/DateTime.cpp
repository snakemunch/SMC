
#include <CL/DateTime>
#include <time.h>

// Number of days in a non-leap year
static const int _DAYS_PER_YEAR = 365;
// Number of days in 4 years
static const int _DAYS_PER_YEARS4 = _DAYS_PER_YEAR * 4 + 1;
// Number of days in 100 years
static const int _DAYS_PER_YEARS100 = _DAYS_PER_YEARS4 * 25 - 1;
// Number of days in 400 years
static const int _DAYS_PER_YEARS400 = _DAYS_PER_YEARS100 * 4 + 1;

static int * daysToMonth365() {
	static int days[] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };
	return days;
}

static int * daysToMonth366() {
	static int days[] = { 0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366 };
	return days;
}

int64_t DateTime::makeTicks(int year, int month, int day, int hour, int minute, int second) {

	int64_t t;

	if ((year < 1 && year > 9999) || (month < 1 && month > 12)) {
		return -1;
	}

	int * days = isLeapYear(year) ? daysToMonth366() : daysToMonth365();

	int y = year - 1;
	int n = y * 365 + y / 4 - y / 100 + y / 400 + days[month - 1] + day - 1;
	t = n * _TICKS_PER_DAY;

	t += hour * _TICKS_PER_HOUR + minute * _TICKS_PER_MIN + second * _TICKS_PER_SEC;

	return t;
}

int DateTime::getPart(int part) const {
	// n = number of days since 1/1/0001
	int n = static_cast<int>(ticks / _TICKS_PER_DAY);
	// y400 = number of whole 400-year periods since 1/1/0001
	int y400 = n / _DAYS_PER_YEARS400;
	// n = day number within 400-year period
	n -= y400 * _DAYS_PER_YEARS400;
	// y100 = number of whole 100-year periods within 400-year period
	int y100 = n / _DAYS_PER_YEARS100;
	// Last 100-year period has an extra day, so decrement result if 4
	if (y100 == 4) {
		y100 = 3;
	}
	// n = day number within 100-year period
	n -= y100 * _DAYS_PER_YEARS100;
	// y4 = number of whole 4-year periods within 100-year period
	int y4 = n / _DAYS_PER_YEARS4;
	// n = day number within 4-year period
	n -= y4 * _DAYS_PER_YEARS4;
	// y1 = number of whole years within 4-year period
	int y1 = n / _DAYS_PER_YEAR;
	// Last year has an extra day, so decrement result if 4
	if (y1 == 4) {
		y1 = 3;
	}
	// If year was requested, compute and return it
	if (part == PART_YEAR) {
		return y400 * 400 + y100 * 100 + y4 * 4 + y1 + 1;
	}

	n -= y1 * _DAYS_PER_YEAR;
	if (part == PART_DAY_OF_YEAR) {
		return n + 1;
	}

	// Leap year calculation looks different from IsLeapYear since y1, y4,
	// and y100 are relative to year 1, not year 0
	bool _isLeapYear = y1 == 3 && (y4 != 24 || y100 == 3);
	int * days = _isLeapYear ? daysToMonth366() : daysToMonth365();

	// All months have less than 32 days, so n >> 5 is a good conservative
	// estimate for the month
	int m = n >> (5 + 1);
	// m = 1-based month number
	while (n >= days[m]) {
		m++;
	}
	// If month was requested, return it
	if (part == PART_MONTH) { 
		return m;
	}
	// Return 1-based day-of-month
	if (part == PART_DAY_OF_MONTH) {
		return n - days[m - 1] + 1;
	}

	return 0;
}

//#if defined(WIN32)
//#ifndef _WINDOWS_
//	#include <windows.h>
//#endif
//inline DateTime DateTime::getNow() {
//	SYSTEMTIME st;
//	GetLocalTime(&st);
//	return DateTime(st.wYear, st.wMonth, st.wDay, st.wHour, st.wMinute, st.wSecond, st.wMilliseconds);
//}
//inline DateTime DateTime::getNowUTC() {
//	SYSTEMTIME st;
//	GetSystemTime(&st);
//	return DateTime(st.wYear, st.wMonth, st.wDay, st.wHour, st.wMinute, st.wSecond, st.wMilliseconds);
//}
//#elif defined(__unix__)

DateTime DateTime::getNow() {
	time_t t;
	struct tm *tm;
	t = time(0);
	tm = localtime(&t);
	return DateTime(tm->tm_year + 1900, tm->tm_mon + 1, tm->tm_mday, tm->tm_hour, tm->tm_min, tm->tm_sec);
}
DateTime DateTime::getNowUTC() {
	time_t t;
	struct tm *tm;
	t = time(0);
	tm = gmtime(&t);
	return DateTime(tm->tm_year + 1900, tm->tm_mon + 1, tm->tm_mday, tm->tm_hour, tm->tm_min, tm->tm_sec);

}
//#endif
