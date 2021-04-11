#pragma once

#include "../Base/BaseComponent.h"

struct EntityName : public ECS::BaseComponent {
	~EntityName() = default;
	EntityName(): Value("NewEntity"){ }
	EntityName(std::string value): Value(value) { }
	std::string Value;
};
