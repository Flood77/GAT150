#include "pch.h"
#include "InputSystem.h"

namespace nc {
    bool InputSystem::Startup() {
        const Uint8* keystate = SDL_GetKeyboardState(&m_numKeys);

        // allocate memory for current and previous keystate
        m_keystate = new Uint8[100];
        m_prevKeystate = new Uint8[100];
        // copy current keystate (source) to m_keystate (destination)
        memcpy(m_keystate, keystate, 100);
        // copy current keystate to m_prevKeystate
        memcpy(m_prevKeystate, keystate, 100);

        return true;
    }

    void InputSystem::Shutdown() {
        //Delete the allocated m_keystateand m_prevKeystate
           //They were allocated as arrays, use the delete[]
    }

    void InputSystem::Update() {
        // copy m_keystate (source) to m_prevKeystate (destination)
        memcpy(m_prevKeystate, m_keystate, 100);
        // get current keystate
        const Uint8* keystate = SDL_GetKeyboardState(&m_numKeys);
        // copy current keystate to m_keystate
        memcpy(m_keystate, keystate, 100);
    }

    bool InputSystem::GetButtonDown(int id) {
        //Return the keystate at m_keystate[id]
        if (m_keystate[id]) { return true; }
        return false;
    }

    bool InputSystem::GetPreviousButtonDown(int id) {
        //Return the keystate at m_prevKeystate[id]
        if (m_prevKeystate[id]) { return true; }
        return false;
    }

    InputSystem::eButtonState InputSystem::GetButtonState(int id) {
        eButtonState state = eButtonState::IDLE;

        bool buttonDown = GetButtonDown(id);
        bool prevButtonDown = GetPreviousButtonDown(id);

        if (buttonDown) {
            state = (prevButtonDown) ? eButtonState::HELD : eButtonState::PRESSED ;
        }
        else {
            state = (prevButtonDown) ? eButtonState::RELEASED : eButtonState::IDLE ;
        }

        return state;
    }
}