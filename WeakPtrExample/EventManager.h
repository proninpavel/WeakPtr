#pragma once
#include <vector>
#include <string>

class Event;

class EventManager {
public:
	void RegisterEvent(std::weak_ptr<Event> event);
	void ShowEvents();
	void ReceiveLog(const std::string& message);

private:
	std::vector<std::weak_ptr<Event>> events;
};