/**
 * Axiom - Geometry Dash Hack Client
 * Built with Geode SDK
 */
#include <Geode/Geode.hpp>
#include <Geode/modify/PlayerObject.hpp>
#include <Geode/modify/PlayLayer.hpp>
#include <Geode/modify/CCScheduler.hpp>
#include <Geode/modify/FMODAudioEngine.hpp>
#include <Geode/modify/MenuLayer.hpp>

using namespace geode::prelude;

// ==================== NOCLIP ====================
#include <Geode/modify/PlayerObject.hpp>
class $modify(NoclipPlayer, PlayerObject) {
    void pushButton(PlayerButton button) {
        PlayerObject::pushButton(button);
        
        if (Mod::get()->getSettingValue<bool>("noclip")) {
            // Make player invincible during noclip
            m_isDead = false;
            m_hasJustHeld = false;
        }
    }
    
    void playerDestroyed(bool p0) {
        if (!Mod::get()->getSettingValue<bool>("noclip")) {
            PlayerObject::playerDestroyed(p0);
        }
    }
};

// ==================== SPEED HACK ====================
#include <Geode/modify/CCScheduler.hpp>
class $modify(SpeedHackScheduler, CCScheduler) {
    void update(float dt) {
        float speedMultiplier = Mod::get()->getSettingValue<double>("speed-hack");
        CCScheduler::update(dt * speedMultiplier);
    }
};

// ==================== INSTANT COMPLETE ====================
#include <Geode/modify/PlayLayer.hpp>
class $modify(AxiomPlayLayer, PlayLayer) {
    bool init(GJGameLevel* level, bool useReplay, bool dontCreateObjects) {
        if (!PlayLayer::init(level, useReplay, dontCreateObjects)) {
            return false;
        }
        
        // Check for instant complete on level start
        if (Mod::get()->getSettingValue<bool>("instant-complete")) {
            this->scheduleOnce([this](float) {
                this->playPlatformerEndAnimationToPos(
                    CCPointMake(0, 0), 
                    false
                );
            }, 0.1f, "instant_complete"_spr);
        }
        
        return true;
    }
    
    void levelComplete() {
        PlayLayer::levelComplete();
    }
};

// ==================== PRACTICE MUSIC FIX ====================
#include <Geode/modify/FMODAudioEngine.hpp>
class $modify(AxiomAudioEngine, FMODAudioEngine) {
    void update(float dt) {
        FMODAudioEngine::update(dt);
        
        if (Mod::get()->getSettingValue<bool>("practice-music-fix")) {
            // Sync music with game time in practice mode
            auto playLayer = PlayLayer::get();
            if (playLayer && playLayer->m_isPracticeMode) {
                float currentTime = playLayer->m_gameState.m_currentProgress;
                // Adjust music position to match game state
                this->setMusicTimeMS(static_cast<int>(currentTime * 1000.0f), false, 0);
            }
        }
    }
};

// ==================== FPS BYPASS ====================
#include <Geode/modify/PlayLayer.hpp>
class $modify(FPSBypassPlayLayer, PlayLayer) {
    void update(float dt) {
        if (Mod::get()->getSettingValue<bool>("fps-bypass")) {
            int targetFPS = Mod::get()->getSettingValue<int64_t>("target-fps");
            float newDt = 1.0f / static_cast<float>(targetFPS);
            
            // Update physics multiple times per frame for smooth gameplay
            int iterations = static_cast<int>(dt / newDt);
            for (int i = 0; i < iterations; i++) {
                PlayLayer::update(newDt);
            }
        } else {
            PlayLayer::update(dt);
        }
    }
};

// ==================== MENU UI ====================
#include <Geode/modify/MenuLayer.hpp>
class $modify(AxiomMenuLayer, MenuLayer) {
    bool init() {
        if (!MenuLayer::init()) {
            return false;
        }

        log::info("Axiom Hack Client initialized");

        // Create Axiom button
        auto axiomButton = CCMenuItemSpriteExtra::create(
            CCSprite::createWithSpriteFrameName("GJ_optionsBtn_001.png"),
            this,
            menu_selector(AxiomMenuLayer::onAxiomButton)
        );

        auto menu = this->getChildByID("bottom-menu");
        if (menu) {
            menu->addChild(axiomButton);
            axiomButton->setID("axiom-button"_spr);
            menu->updateLayout();
        }

        return true;
    }

    void onAxiomButton(CCObject*) {
        // Open Axiom settings
        openSettingsPopup(Mod::get());
    }
};

// ==================== ADDITIONAL HOOKS ====================

// Anti-Cheat Bypass (for noclip)
#include <Geode/modify/PlayerObject.hpp>
class $modify(AntiCheatPlayer, PlayerObject) {
    TodoReturn incrementJumps() {
        if (Mod::get()->getSettingValue<bool>("noclip")) {
            // Don't increment jumps in noclip mode to avoid detection
            return;
        }
        PlayerObject::incrementJumps();
    }
};

// Visual Noclip Indicator
#include <Geode/modify/PlayLayer.hpp>
class $modify(NoclipIndicatorPlayLayer, PlayLayer) {
    void postUpdate(float dt) {
        PlayLayer::postUpdate(dt);
        
        if (Mod::get()->getSettingValue<bool>("noclip")) {
            // Could add visual indicator here
            // For example, change player color or add glow effect
        }
    }
};

/**
 * Axiom Hack Client Features:
 * - Noclip: Pass through all obstacles
 * - Speed Hack: Adjustable game speed (0.0001x - 100x)
 * - Instant Complete: Automatically complete levels
 * - Practice Music Fix: Sync music in practice mode
 * - FPS Bypass: Unlock FPS up to 520
 * 
 * All features are configurable in the mod settings.
 */