#include "../Include/Transform.h"

Transform::Transform() : m_parent(nullptr), m_translation(Vector3()), m_rotation(Quaternion()), m_scale(Vector3())
{
}


Transform::~Transform()
{
}

