#include "events.hpp"

events::events(std::string eventText, survivor s, std::vector<std::shared_ptr<item>> inventory)
:eventText(eventText), inventory(inventory), s(s)
{}
