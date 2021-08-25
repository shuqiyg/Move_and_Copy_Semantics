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
#include <iomanip>
#include "TimedEvents.h"

using namespace std;
namespace sdds {
	TimedEvents::TimedEvents() {
	};
	void TimedEvents::startClock() {
		startT = chrono::steady_clock::now();
	};
	void TimedEvents::stopClock() {
		endT = chrono::steady_clock::now();
	};
	void TimedEvents::addEvent(const char* name) {
		events[noRecords].eName = name;
		events[noRecords].timeUnits = "nanoseconds";
		events[noRecords].duration = endT - startT;//std::chrono::duration_cast<std::chrono::nanoseconds>(endT - startT);
		noRecords++;
	};
	ostream& operator<<(ostream& os, const TimedEvents& timedEvents) {
		os << "--------------------------\n" << "Execution Times:\n" << "--------------------------\n";
		for (int i = 0; i < timedEvents.noRecords; i++) {
			os << setw(21) << left << timedEvents.events[i].eName << setw(13) << right << std::chrono::duration_cast<std::chrono::nanoseconds>(timedEvents.events[i].duration).count() << " " << timedEvents.events[i].timeUnits << endl;
		}
		cout << "--------------------------\n";
		return os;
	};
}