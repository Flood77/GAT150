#include "pch.h"
#include "PlayerComponent.h"
#include "Components/AudioComponent.h"
#include "Components/RigidBodyComponent.h"

namespace nc {
    void PlayerComponent::Create(void* data) {
		m_owner = static_cast<GameObject*>(data);
    }

    void PlayerComponent::Destroy() {

    }

    void PlayerComponent::Update() {
		auto contacts = m_owner->GetContactsWithTag("Floor");
		bool onGround = !contacts.empty();

		nc::Vector2 force{ 0, 0 };

		if (m_owner->m_engine->GetSystem<nc::InputSystem>()->GetButtonState(SDL_SCANCODE_A) == nc::InputSystem::eButtonState::HELD) {
			force.x = -200;
		}
		if (m_owner->m_engine->GetSystem<nc::InputSystem>()->GetButtonState(SDL_SCANCODE_A) == nc::InputSystem::eButtonState::HELD) {
			force.x = 200;
		}

		if (onGround && m_owner->m_engine->GetSystem<nc::InputSystem >()->GetButtonState(SDL_SCANCODE_SPACE) == nc::InputSystem::eButtonState::PRESSED) {
			force.y = -1500;
			AudioComponent* audioComponent = m_owner->GetComponent<AudioComponent>();
			if (audioComponent) {
				audioComponent->Play();
			}
		}
		 
		RigidBodyComponent* component = m_owner->GetComponent<RigidBodyComponent>();
		if (component) {
			component->ApplyForce(force);
		}

		auto coinContacts = m_owner->GetContactsWithTag("Coin");
		for (GameObject* contact : coinContacts) {
			contact->m_flags[GameObject::eFlags::DESTROY] = true;
			//play sound
		}
    }
	void PlayerComponent::CollisionEvent(GameObject* gameObject) {

	}
}