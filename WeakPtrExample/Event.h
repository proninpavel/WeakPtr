#pragma once

#include <memory>
#include <string>
#include <functional>

#include "EventManager.h"

class Event : public std::enable_shared_from_this<Event> {
public:
	Event(const std::string& name) : name(name) {}

	void RegisterWithManager(std::shared_ptr<EventManager> manager);
	const std::string& GetName() const;
	void SendLog();

private:
	std::string name;
	std::weak_ptr<EventManager> manager;
};