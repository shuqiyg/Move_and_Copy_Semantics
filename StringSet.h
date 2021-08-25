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
#ifndef STRING_H_
#define STRING_H_
#include <string>


namespace sdds {
	class StringSet {
		std::string* names {};
		size_t noStrings;
	public:
		StringSet();
		StringSet(const char*);
		StringSet(const StringSet&);
		StringSet(StringSet&&) noexcept; // move-constructor
		StringSet& operator=(const StringSet&);
		StringSet& operator=(StringSet&&) noexcept; // move-assignment operator
		size_t size() const;
		~StringSet();
		std::string operator[](size_t) const;
	};
}

#endif