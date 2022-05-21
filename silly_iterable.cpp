#include <iostream>
#include <typeinfo>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using std::cout;
using std::endl;
using std::ostream;
using std::vector;
using std::string;
using std::logic_error;
using std::cerr;
using std::stringstream;
using std::to_string;

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

		bool operator<=(const Iterator& other) const {
			return curr_year <= other.curr_year;
		}

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

	LeapYears() : LeapYears(2024) {} // upcoming leap year

	LeapYears(long max_year) {
		for (; !is_leap_year(max_year); --max_year);
			this->max_year = max_year;
	}

	Iterator begin() const {
		return Iterator(1904); // first leap year of twentieth century
	}

	Iterator end() const {
		return Iterator(max_year);
	}
};

class UnitTestException : public logic_error {
public:
  UnitTestException(const string& err) : logic_error(err) {}
};

template <typename T, typename U>
void assert_equals(const T& expected, const U& actual, const string& error_msg) {
  if (expected != actual) {
    stringstream msg;
    msg << "Expected " << expected << " but got " << actual << ". " << error_msg;
    throw UnitTestException(msg.str());
  }
}

void unit_test_leap_years_iterator() {
	vector<int> expected;
	vector<int> actual;

	for (int i = 1904; i != 2024; ++i) { // first leap year of twentieth century to next upcoming leap year
		if (is_leap_year(i)) {
			expected.push_back(i);
		}
	}

	for (long x : LeapYears(2024)) {
		actual.push_back(x);
	}

	for (int i = 0; i < expected.size(); ++i) {
		assert_equals(expected[i], actual[i], "Leap year " + to_string(actual[i]) + " in unit_test_leap_years_iterator");
	}	
}

int main() {
	try {
		unit_test_leap_years_iterator();
		cout << "All unit tests passed!\n";
	} catch (UnitTestException& ex) {
		cerr << "Unit test(s) failed\n" << ex.what() << endl;
	}

	return 0;
}