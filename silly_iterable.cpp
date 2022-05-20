#include <iostream>
#include <typeinfo>

using std::cout;
using std::endl;

bool is_leap_year(long year) {
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
		return true;
	}
	return false;
}




int main() {
	// for (int i = 1900; i < 2022; ++i) {
	// 	if (is_leap_year(i)) {
	// 		cout << i << endl;
	// 	}
	// }

	const int foo = 1;
	auto x = foo;

	cout << typeof(x) << endl;



	return 0;
}