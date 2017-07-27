#pragma once
#include "Color.h"
#include "gl_define.h"

namespace BS {

	class Material
	{
	public:
		Material() = default;
		Material(Color4 _amb, Color4 _dif, Color4 _emi, Color4 _spe, float _shin) 
			: ambient(_amb),diffuse(_dif),emission(_emi),specular(_spe),shine(_shin)
		{ }

		void apply();

		inline Color4 getAmbient() const { return ambient; }
		inline Color4 getDiffuse() const { return diffuse; }
		inline Color4 getEmission() const { return emission; }
		inline Color4 getSpecular() const { return specular; }
		inline float getShine() const { return shine; }

		inline void setAmbient(const Color4& _amb) { ambient = _amb; }
		inline void setDiffuse(const Color4& _dif) { diffuse = _dif; }
		inline void setEmission(const Color4& _emi) { emission = _emi; }
		inline void setSpecular(const Color4& _spe) { specular = _spe; }
		inline void setShine(const float _shin) { shine = _shin; }

	private:
		Color4 ambient;
		Color4 diffuse;
		Color4 emission;
		Color4 specular;
		float shine;
	};
}