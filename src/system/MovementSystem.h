//
// Created by pasta on 26/03/18.
//

#ifndef RAY_MOVEMENTSYSTEM_H
#define RAY_MOVEMENTSYSTEM_H

class MovementSystem {

public:
    MovementSystem() = default;
    ~MovementSystem() = default;

    bool init();
    bool update(entt::DefaultRegistry &registry);
};


#endif //RAY_MOVEMENTSYSTEM_H
