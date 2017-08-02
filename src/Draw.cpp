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

void BS::Draw::drawLine(const Vector2& _start, const Vector2& _end, float _line_width, const Color4& _col)
{
	GLfloat vtx[] =
	{
		_start.x, _start.y,
		_end.x, _end.y
	};

	glVertexPointer(2, GL_FLOAT, 0, vtx);
	glLineWidth(_line_width);
	glColor4f(_col.r, _col.g, _col.b, _col.a);
	
	glEnableClientState(GL_VERTEX_ARRAY);
	
	glDrawArrays(GL_LINES, 0, 2);
	
	glDisableClientState(GL_VERTEX_ARRAY);
}

void BS::Draw::drawFillQuad(const Vector2& _center, const Vector2& _size, const Color4 _col)
{
	GLfloat vtx[] =
	{
		_center.x - _size.x / 2, _center.y + _size.y / 2,
		_center.x + _size.x / 2, _center.y + _size.y / 2,
		_center.x - _size.x / 2, _center.y - _size.y / 2,
		_center.x + _size.x / 2, _center.y - _size.y / 2
	};

	glVertexPointer(2, GL_FLOAT, 0, vtx);
	glColor4f(_col.r, _col.g, _col.b, _col.a);

	glEnableClientState(GL_VERTEX_ARRAY);
	
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glDrawArrays(GL_TRIANGLES, 1, 3);
	
	glDisableClientState(GL_VERTEX_ARRAY);
}

void BS::Draw::drawQuad(const Vector2 & _center, const Vector2 & _size, float _line_width, const Color4 _col)
{
	GLfloat vtx[] =
	{
		_center.x - _size.x / 2, _center.y + _size.y / 2,
		_center.x + _size.x / 2, _center.y + _size.y / 2,
		_center.x - _size.x / 2, _center.y - _size.y / 2,
		_center.x + _size.x / 2, _center.y - _size.y / 2
	};

	glVertexPointer(2, GL_FLOAT, 0, vtx);
	glLineWidth(_line_width);
	glColor4f(_col.r, _col.g, _col.b, _col.a);

	glEnableClientState(GL_VERTEX_ARRAY);
	
	glDrawArrays(GL_LINE_LOOP, 0, 3);
	glDrawArrays(GL_LINE_LOOP, 1, 3);
	
	glDisableClientState(GL_VERTEX_ARRAY);
}

void BS::Draw::drawTexture(const Texture& _texture, const Vector2& _center, const Vector2& _size, const Color4 _col)
{
	GLfloat vtx[] =
	{
		_center.x - _size.x / 2, _center.y + _size.y / 2,
		_center.x + _size.x / 2, _center.y + _size.y / 2,
		_center.x - _size.x / 2, _center.y - _size.y / 2,
		_center.x + _size.x / 2, _center.y - _size.y / 2
	};

	GLfloat uv[] = 
	{
		0.0, 0.0,
		1.0, 0.0,
		0.0, 1.0,
		1.0, 1.0
	};

	glVertexPointer(2, GL_FLOAT, 0, vtx);
	glTexCoordPointer(2, GL_FLOAT, 0, uv);
	glColor4f(_col.r, _col.g, _col.b, _col.a);

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glEnable(GL_TEXTURE_2D);

	_texture.bind();
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glDrawArrays(GL_TRIANGLES, 1, 3);
	_texture.unbind();

	glDisable(GL_TEXTURE_2D);
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
}

void BS::Draw::drawCube(const Vector3 & _center, const Vector3 & _size)
{
	Vector3 _halfSize = _size / 2;

	GLfloat vtx[] = 
	{
		//反時計回り
		//前
		_center.x + _halfSize.x, _center.y + _halfSize.y, _center.z + _halfSize.z,
		_center.x - _halfSize.x, _center.y + _halfSize.y, _center.z + _halfSize.z,
		_center.x + _halfSize.x, _center.y - _halfSize.y, _center.z + _halfSize.z,

		_center.x - _halfSize.x, _center.y + _halfSize.y, _center.z + _halfSize.z,
		_center.x - _halfSize.x, _center.y - _halfSize.y, _center.z + _halfSize.z,
		_center.x + _halfSize.x, _center.y - _halfSize.y, _center.z + _halfSize.z,

		//後
		_center.x + _halfSize.x, _center.y + _halfSize.y, _center.z - _halfSize.z,
		_center.x + _halfSize.x, _center.y - _halfSize.y, _center.z - _halfSize.z,
		_center.x - _halfSize.x, _center.y + _halfSize.y, _center.z - _halfSize.z,

		_center.x - _halfSize.x, _center.y - _halfSize.y, _center.z - _halfSize.z,
		_center.x - _halfSize.x, _center.y + _halfSize.y, _center.z - _halfSize.z,
		_center.x + _halfSize.x, _center.y - _halfSize.y, _center.z - _halfSize.z,

		//右
		_center.x + _halfSize.x, _center.y + _halfSize.y, _center.z - _halfSize.z,
		_center.x + _halfSize.x, _center.y + _halfSize.y, _center.z + _halfSize.z,
		_center.x + _halfSize.x, _center.y - _halfSize.y, _center.z - _halfSize.z,

		_center.x + _halfSize.x, _center.y - _halfSize.y, _center.z + _halfSize.z,
		_center.x + _halfSize.x, _center.y - _halfSize.y, _center.z - _halfSize.z,
		_center.x + _halfSize.x, _center.y + _halfSize.y, _center.z + _halfSize.z,

		//左
		_center.x - _halfSize.x, _center.y + _halfSize.y, _center.z + _halfSize.z,
		_center.x - _halfSize.x, _center.y + _halfSize.y, _center.z - _halfSize.z,
		_center.x - _halfSize.x, _center.y - _halfSize.y, _center.z + _halfSize.z,

		_center.x - _halfSize.x, _center.y - _halfSize.y, _center.z - _halfSize.z,
		_center.x - _halfSize.x, _center.y - _halfSize.y, _center.z + _halfSize.z,
		_center.x - _halfSize.x, _center.y + _halfSize.y, _center.z - _halfSize.z,

		//天井
		_center.x + _halfSize.x, _center.y + _halfSize.y, _center.z - _halfSize.z,
		_center.x - _halfSize.x, _center.y + _halfSize.y, _center.z - _halfSize.z,
		_center.x + _halfSize.x, _center.y + _halfSize.y, _center.z + _halfSize.z,

		_center.x - _halfSize.x, _center.y + _halfSize.y, _center.z + _halfSize.z,
		_center.x + _halfSize.x, _center.y + _halfSize.y, _center.z + _halfSize.z,
		_center.x - _halfSize.x, _center.y + _halfSize.y, _center.z - _halfSize.z,

		//底
		_center.x + _halfSize.x, _center.y - _halfSize.y, _center.z + _halfSize.z,
		_center.x - _halfSize.x, _center.y - _halfSize.y, _center.z + _halfSize.z,
		_center.x + _halfSize.x, _center.y - _halfSize.y, _center.z - _halfSize.z,

		_center.x - _halfSize.x, _center.y - _halfSize.y, _center.z - _halfSize.z,
		_center.x + _halfSize.x, _center.y - _halfSize.y, _center.z - _halfSize.z,
		_center.x - _halfSize.x, _center.y - _halfSize.y, _center.z + _halfSize.z,
	};
	glVertexPointer(3, GL_FLOAT, 0, vtx);

	GLfloat normal[] = {
		// 前
		// x,    y,    z,
		0.0f, 0.0f, 1.0f,
		0.0f, 0.0f, 1.0f,
		0.0f, 0.0f, 1.0f,
		0.0f, 0.0f, 1.0f,
		0.0f, 0.0f, 1.0f,
		0.0f, 0.0f, 1.0f,

		// 後
		0.0f, 0.0f, -1.0f,
		0.0f, 0.0f, -1.0f,
		0.0f, 0.0f, -1.0f,
		0.0f, 0.0f, -1.0f,
		0.0f, 0.0f, -1.0f,
		0.0f, 0.0f, -1.0f,

		// 右
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,

		// 左
		-1.0f, 0.0f, 0.0f,
		-1.0f, 0.0f, 0.0f,
		-1.0f, 0.0f, 0.0f,
		-1.0f, 0.0f, 0.0f,
		-1.0f, 0.0f, 0.0f,
		-1.0f, 0.0f, 0.0f,

		// 上
		0.0f, 1.0f, 0.0f,
		0.0f, 1.0f, 0.0f,
		0.0f, 1.0f, 0.0f,
		0.0f, 1.0f, 0.0f,
		0.0f, 1.0f, 0.0f,
		0.0f, 1.0f, 0.0f,

		// 下
		0.0f, -1.0f, 0.0f,
		0.0f, -1.0f, 0.0f,
		0.0f, -1.0f, 0.0f,
		0.0f, -1.0f, 0.0f,
		0.0f, -1.0f, 0.0f,
		0.0f, -1.0f, 0.0f,
	};
	glNormalPointer(GL_FLOAT, 0, normal);

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);

	glDrawArrays(GL_TRIANGLES, 0, 36);

	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_NORMAL_ARRAY);
}
