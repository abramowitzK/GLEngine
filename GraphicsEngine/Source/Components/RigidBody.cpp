#include "../../Include/Components/RigidBody.h"

RigidBody::RigidBody() : Component(Type::PHYSICS_RIGIDBODY)
{
}

RigidBody::~RigidBody()
{
	delete m_rigidBody;
}

btRigidBody* RigidBody::GetRigidBody() const
{
	return m_rigidBody;
}

void RigidBody::OnInit()
{
}

void RigidBody::OnEnable()
{
}

void RigidBody::Update()
{
}

void RigidBody::OnDisable()
{
}

void RigidBody::OnDestroy()
{
}
