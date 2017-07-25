#include "Draw.h"

void BS::Draw::drawPoint(const Vector2& _pos, float _size, const Color4& _col)
{
	GLfloat vtx[] =
	{
		_pos.x, _pos.y
	};

	glVertexPointer(2, GL_FLOAT, 0, vtx);
	glPointSize(_size);
	glColor4f(_col.r, _col.g, _col.b, _col.a);

	glEnableClientState(GL_VERTEX_ARRAY);
	glDrawArrays(GL_POINTS, 0, 1);
	glDisableClientState(GL_VERTEX_ARRAY);
}

void BS::Draw::drawLine()
{
}

void BS::Draw::drawQuad()
{
}

void BS::Draw::drawTexture()
{

}
