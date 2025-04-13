#include <memory>
#include <iostream>

#include "EventManager.h"
#include "Event.h"

void EventManager::RegisterEvent(std::weak_ptr<Event> event)
{
	events.push_back(event);
}

void EventManager::ShowEvents()
{
	std::cout << "Registered events:\n";
	for (auto& event : events) {
		if (auto e = event.lock()) {
			std::cout << "- " << e->GetName() << "\n";
		}
	}
}

void EventManager::ReceiveLog(const std::string& message)
{
	std::cout << "EventManager received log: " << message << "\n";
}
