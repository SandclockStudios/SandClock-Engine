#ifndef __MODULESCENE_H__
#define __MODULESCENE_H__

#include "Module.h"
#include "Cube.h"
#include "MPlane.h"
#include "Gizmo.h"
#include "Model.h"
#include "Level.h"
#include "GameObject.h"
#include "ComponentCamera.h"
#include "QuadTreeNode.h"



struct SDL_Texture;

class ModuleScene : public Module
{
public:
	ModuleScene(bool active = true);
	~ModuleScene();

	bool Start();
	update_status Update(float dt);
	bool intersectFrustumAABB(Frustum f, AABB b);
	bool CleanUp();

	void LoadGameObjects(aiNode* node, GameObject* parent);

	update_status PreUpdate(float dt);

public:
	
	uint fx = 0;
	Cube* c;
	Gizmo* g;
	MPlane* p;
	MY::Uint index = 0;
	float angle = 0;
	Model* batman;
	const aiScene* scene;
	GameObject* root;
	GameObject* camera;
	ComponentCamera* componentCamera;

	QuadTreeNode* quadTree;

private:
	std::vector<GameObject*> gameObject;
};

#endif // __MODULESCENE_H__