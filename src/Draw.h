#pragma once

#include "Vector.h"
#include "gl_define.h"

namespace BS {

static class Draw 
{
public:
	void drawPoint();
	void drawLine();
	void drawQuad();
	void drawTexture();

private:
	Draw() = default;
	~Draw() = default;
};
}