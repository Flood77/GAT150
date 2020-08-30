#include "pch.h"
#include "AudioSystem.h"

namespace nc {
    bool AudioSystem::Startup() {
        FMOD_RESULT result = FMOD::System_Create(&m_system);
        ASSERT_MSG(result == FMOD_OK, "Error initializing FMOD system.");

        return true;
    }

    void AudioSystem::Shutdown() {
        FMOD_RESULT result = m_system->close();
        ASSERT_MSG(result == FMOD_OK, "Error releasig FMOD system.");

        result = m_system->release();
        ASSERT_MSG(result == FMOD_OK, "Error releasing FMOD system.");
    }

    void AudioSystem::Update() {
        FMOD_RESULT result = m_system->update();
        ASSERT_MSG(result == FMOD_OK, "Error updating FMOD system.");
    }
}