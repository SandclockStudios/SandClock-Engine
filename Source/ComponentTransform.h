#ifndef __COMPONENTTRANSFORM_H_
#define __COMPONENTTRANSFORM_H_

#include "Component.h"



class ComponentTransform : public Component
{
public:

	ComponentTransform(bool start_enabled = true);
	~ComponentTransform();

	void LoadTransform(aiNode* node);
	void Translate(aiVector3D translation);
	void Rotate(aiVector3D rotation);

private:

	aiMatrix4x4 mat;
	aiVector3D pos;
	aiQuaternion quat;
};

#endif // __COMPONENTTRANSFORM_H_