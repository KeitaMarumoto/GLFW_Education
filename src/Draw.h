#pragma once

#include "gl_define.h"

namespace BlueSignal {

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