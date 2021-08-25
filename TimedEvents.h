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
#ifndef TIMEDEVENTS_H_
#define TIMEDEVENTS_H_
#include <chrono>
#include <string>
#include <iostream>

typedef std::chrono::steady_clock::time_point timepoint;
typedef std::chrono::duration<float> dur;

namespace sdds {
	struct Event {
		std::string eName;
		std::string timeUnits;
		dur duration;
	};
	class TimedEvents {
		int noRecords{};
		timepoint startT;
		timepoint endT;
		Event events[10];
	public:
		TimedEvents();
		void startClock();
		void stopClock();
		void addEvent(const char*);
		friend std::ostream& operator<<(std::ostream&, const TimedEvents&);
	};
}

#endif