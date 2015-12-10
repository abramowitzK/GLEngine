#pragma once
#include "../Core/Component.h"
#include <Bullet\btBulletDynamicsCommon.h>
class RigidBody : public Component
{
public:
	RigidBody();
	~RigidBody();
	btRigidBody* GetRigidBody() const;
	void OnInit() override;
	void OnEnable() override;
	void Update() override;
	void OnDisable() override;
	void OnDestroy() override;
private:
	btRigidBody* m_rigidBody;
};