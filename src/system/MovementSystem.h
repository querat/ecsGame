//
// Created by pasta on 26/03/18.
//

#ifndef GAME_MOVEMENTSYSTEM_H
#define GAME_MOVEMENTSYSTEM_H

class MovementSystem {

public:
    MovementSystem() = default;
    ~MovementSystem() = default;

    bool init();
    bool update(entt::DefaultRegistry &registry, float const deltaTimeSeconds);
};


#endif //GAME_MOVEMENTSYSTEM_H
