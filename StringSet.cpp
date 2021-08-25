/* Workshop 2 - Copy and Move Semantics
   Name: Shuqi Yang
   Std ID: 132162207
   Email: syang136@myseneca.ca
   Date: 05-30-2021
   -------------------------------------------------------
   I have done all the coding by myself and only copied the
   code that my professor provided to complete my workshops
   and assignments.
 */
#include <iostream>
#include <fstream>
#include "StringSet.h"

using namespace std;
namespace sdds {
	StringSet::StringSet() {
		//names = nullptr;
		noStrings = 0;
	};
	StringSet::StringSet(const char* fileName) {
		ifstream f(fileName);
		string word;
		int count = 0;
		if (f) {
			while (!f.eof()) {
				//f >> word;
				getline(f, word,' ');
				count++;
			}
		}
		noStrings = count;
		names = new string[count];
		f.seekg(0);
		int i = 0;
		if (f) {
			while (!f.eof() && i < count) {
				getline(f, names[i++], ' ');
			}
		}
		f.close();
	};
	StringSet::StringSet(const StringSet& ss) {
		*this = ss;
	};
	StringSet::StringSet(StringSet&& ss) noexcept  {
		*this = move(ss);
	};
	StringSet& StringSet::operator=(const StringSet& ss) {
		if (this != &ss) {
			delete[] names;
			noStrings = ss.noStrings;
			names = new string[noStrings];
			for (size_t i = 0; i < noStrings; i++) {
				names[i] = ss.names[i];
			}	
		}
		return *this;
	};
	StringSet& StringSet::operator=(StringSet&& ss) noexcept  {
		if (this != &ss) {
			delete[] names;
			names = ss.names;
			ss.names = nullptr;
			noStrings = ss.noStrings;
			ss.noStrings = 0u;
		}
		return *this;
	}
	size_t StringSet::size() const {
		return noStrings;
	};
	std::string StringSet::operator[](size_t index) const{
		if (index < 0 || index >= noStrings) {
			return "\0";
		}
		else {
			return names[index];
		}
	};
	StringSet::~StringSet() {
		delete[] names;
	};
}