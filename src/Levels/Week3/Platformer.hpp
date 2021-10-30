#ifndef PLATFORMER_HPP
#define PLATFORMER_HPP

#include "State.hpp"
#include "PauseWindow.hpp"
#include "CameraManager2D.hpp"
#include "AnimationManager.hpp"
#include "Player.hpp"
#include "Objects.hpp" //included for envItems (platforms)

class Platformer : public State
{
private:
    // Functions
    void initVariables();
    // Variables
    PauseWindow pauseWindow;
    CameraManager2D cameramanager;
    RenderTexture2D target; // This is where we'll draw all our objects.
    float virtualratio;
    
    // custom Functions
    void collisionBlocks(Entity *instance, const float &dt);

    //custom variables
    static const int envHorizontalItemsLength = 5;
    static const int envVerticalItemsLength = 2;
    int score = 0;
    
    AnimationManager::Animation idle{LoadTexture(ASSETS_PATH "characters/herochar/herochar_idle_anim_strip_4.png"), 4};
    AnimationManager::Animation run{LoadTexture(ASSETS_PATH "characters/herochar/herochar_run_anim_strip_6.png"), 6};
    AnimationManager animmanager{idle};
    
    Player player{};

    EnvItem envHorizontalItems[envHorizontalItemsLength] = {
        {{0, 500, 800, 600}, 1, DARKGREEN}, // bottom
        {{0, 0, 800, 100}, 1, DARKGREEN},
        {{300, 350, 224, 32}, 1, BROWN},
        {{200, 400, 160, 32}, 1, BROWN},
        {{400, 450, 160, 32}, 1, BROWN}}; // top

    EnvItem envVerticalItems[envVerticalItemsLength] = {
        {{700, 0, 100, 600}, 1, DARKBLUE}, // right
        {{0, 0, 100, 600}, 1, DARKBLUE}    // left
    };

public:
    Platformer(StateData *state_data);
    ~Platformer();
    // Functions
    void updateInput(const float &dt);
    void update(const float &dt);
    void render();
    void draw();
};

#endif