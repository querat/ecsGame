//
// Created by pasta on 16/03/18.
//

#ifndef RAY_DISPLAY_H
#define RAY_DISPLAY_H

#include <string>
#include <SFML/Window.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <deque>
#include "SpriteComponent.h"

class Display {
private:
    sf::RenderWindow    *mWindow        =   nullptr;
    std::string         mTitle          =   "";
    int                 mWidth          =   -1;
    int                 mHeight         =   -1;
    unsigned int        mFrameRateLimit =   60;


public:
    Display()   = default;
    ~Display();

    bool                init(unsigned int width, unsigned int height, const std::string &title);
    bool                close();
    bool                isReady() const;
    void                render();
    sf::RenderWindow *  getRenderWindow();
    bool                clear();
};


#endif //RAY_DISPLAY_H
