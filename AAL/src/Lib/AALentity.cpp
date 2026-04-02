#include "pch.h"
#include "AALentity.h"

void AALentity::SetVisible(bool active)
{
	m_pEntity->visible = active;
}
