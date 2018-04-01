//
// Created by pasta on 31/03/18.
//

#ifndef GAME_EVENTCOMPONENT_H
#define GAME_EVENTCOMPONENT_H

#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Event.hpp>
#include <entt/entt.hpp>

struct CollisionEvent {

};

struct EventComponent {

    typedef enum Type_e {
        COLLISION
        , KEY_PRESSED
    } Type;

    Type type;

    union {
        CollisionEvent      collisionEvent;
        sf::Event::KeyEvent keyEvent;
    };


};

#endif //GAME_EVENTCOMPONENT_H
