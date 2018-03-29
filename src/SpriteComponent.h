//
// Created by pasta on 21/03/18.
//

#ifndef RAY_SPRITECOMPONENT_H
#define RAY_SPRITECOMPONENT_H

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

struct SpriteComponent {
    sf::Sprite  sprite;
    int         xPos;
    int         yPos;
};


#endif // RAY_SPRITECOMPONENT_H
