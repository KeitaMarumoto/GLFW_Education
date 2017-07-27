#include "Material.h"

void BS::Material::apply()
{
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient.toArray());
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse.toArray());
	glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, emission.toArray());
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular.toArray());
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, shine);
}
