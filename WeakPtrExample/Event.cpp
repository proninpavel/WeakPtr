#include <iostream>

#include "Event.h"
#include "EventManager.h"

void Event::RegisterWithManager(std::shared_ptr<EventManager> manager)
{
	this->manager = manager;
	manager->RegisterEvent(shared_from_this());
}

const std::string& Event::GetName() const
{
	return name;
}

void Event::SendLog()
{
	std::weak_ptr<Event> weakThis = shared_from_this();

	std::function<void()> delayedTask = [weakThis]() {
		if (auto self = weakThis.lock()) {
			if (auto mgr = self->manager.lock()) {
				mgr->ReceiveLog("Event \"" + self->GetName() + "\" executed log.");
			}
			else {
				std::cout << "EventManager no longer exists.\n";
			}
		}
		};

	delayedTask();
}