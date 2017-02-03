#pragma once

#include "Helpers/DesignerEntityComponent.h"
#include <Entities/Interaction/IEntityInteraction.h>


class CGeometryComponent;
class CControlledAnimationComponent;
class CLockableComponent;
class CEntityInteractionComponent;


/**
An animated door.

\sa IEntityComponent
\sa IEntityPropertyGroup
\sa IInteractionContainer
**/
class CAnimatedDoorComponent : public CDesignerEntityComponent<>, public IEntityPropertyGroup, public IInteractionOpenable, public IInteractionLockable
{
	CRY_ENTITY_COMPONENT_INTERFACE_AND_CLASS(CAnimatedDoorComponent, "AnimatedDoor", 0xD246E11FE7E248F0, 0xB512402908F84496)

public:
	// IEntityComponent
	void Initialize() override;
	struct IEntityPropertyGroup* GetPropertyGroup() override { return this; }
	// ~IEntityComponent
	
	// IEntityPropertyGroup
	const char* GetLabel() const override { return "AnimatedDoor Properties"; };
	void SerializeProperties(Serialization::IArchive& archive) override;
	// ~IEntityPropertyGroup

	// IInteractionOpenable
	void OnInteractionOpenableOpen() override { gEnv->pLog->LogAlways("OnInteractionOpenableOpen fired."); };
	void OnInteractionOpenableClose() override { gEnv->pLog->LogAlways("OnInteractionOpenableClose fired."); };
	// ~IInteractionOpenable

	// IInteractionLockable
	void OnInteractionLockableLock() override { gEnv->pLog->LogAlways("OnInteractionLockableLock fired."); };
	void OnInteractionLockableUnlock() override { gEnv->pLog->LogAlways("OnInteractionLockableUnlock fired."); };
	// ~IInteractionLockable

	// IInteractionLockable
	CAnimatedDoorComponent() {};
	virtual ~CAnimatedDoorComponent() {}

private:
	// Called on entity spawn, or when the state of the entity changes in Editor
	void OnResetState() override;

	/** Model for the geometry. */
	CGeometryComponent* m_pGeometryComponent { nullptr };

	/** Animation for the geometry. */
	CControlledAnimationComponent* m_pControlledAnimationComponent { nullptr };

	/** Doors should be lockable. */
	CLockableComponent* m_lockableComponent { nullptr };

	/** This entity should be interactive. */
	CEntityInteractionComponent* m_interactor { nullptr };
};