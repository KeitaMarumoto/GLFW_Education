#pragma once

#include "gl_define.h"
#include "Vector.h"
#include "Color.h"

using namespace BS;

class Light {
public:
	Light(const Vector3& pos, const Color4& amb, const Color4& diff, const Color4& spe, int num);
};