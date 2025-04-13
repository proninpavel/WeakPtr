#include <iostream>
#include "EventManager.h"
#include "Event.h"

int main() {
	auto manager = std::make_shared<EventManager>();

	auto event1 = std::make_shared<Event>("WeeklyContest");
	event1->RegisterWithManager(manager);
	event1->SendLog();
	{
		auto event2 = std::make_shared<Event>("Lightning Rush");
		event2->RegisterWithManager(manager);
		event2->SendLog();
	}
	manager->ShowEvents();

	return 0;
}