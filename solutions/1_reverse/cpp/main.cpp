#include <iostream>
#include <string>

int main()
{
	std::string s;
	std::cin >> s;
	std::string revs(s.rbegin(), s.rend());
	std::cout << revs << "\n";
}
