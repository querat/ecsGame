//
// Created by pasta on 31/03/18.
//

#ifndef GAME_EVENTCOMPONENT_H
#define GAME_EVENTCOMPONENT_H

#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Event.hpp>

struct EventComponent {

    sf::Event::EventType eventType;

    union {
        sf::Event::KeyEvent keyEvent;
    };


};

#endif //GAME_EVENTCOMPONENT_H
