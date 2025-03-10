#pragma once

#include "pch.h"

struct PhysicsBody {
	PhysicsBody(Vec3& _Position, Vec3& _Velocity, Vec3& Force, float _Mass);
	PhysicsBody operator=(PhysicsBody other) const;

	float Mass;
	Vec3 Velocity;
	Vec3 Force;

	Transform* Transform;
};