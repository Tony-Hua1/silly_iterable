#include <iostream>
#include <typeinfo>

#include <math.h>
#include <cmath>
#include <tgmath.h>
#include <limits>
#include <bits/stdc++.h>

using std::ilogb;

using std::cout;
using std::endl;

bool is_leap_year(long year) {
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
		return true;
	}
	return false;
}

class LeapYears {
	long max_year;
public:
	class Iterator {
		long curr_year;
	public:
		Iterator(long curr_year) : curr_year(curr_year) {}

		bool operator!=(const Iterator& other) const {
			return curr_year != other.curr_year;
		}

		Iterator& operator++() {
			for (++curr_year; !is_leap_year(curr_year); ++curr_year);
			return *this;
		}

		long operator*() const {
			return curr_year;
		}
	};

	LeapYears(long max_year) {
		for (; !is_leap_year(max_year); --max_year);
		this->max_year = max_year;
	}

	Iterator begin() const {
		return Iterator(1900);
	}

	Iterator end() const {
		return Iterator(max_year);
	}
};

int main() {
	// for (int i = 1900; i < 2022; ++i) {
	// 	if (is_leap_year(i)) {
	// 		cout << i << endl;
	// 	}
	// }

	for (long x : LeapYears(2022)) {
		cout << x << endl;
	}
	return 0;
}