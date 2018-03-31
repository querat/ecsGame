//
// Created by pasta on 16/03/18.
//

#include <entt/entt.hpp>
#include "Display.h"
#include "utility/Utils.h"
#include "component/SpriteComponent.h"

Display::~Display(){
    delete mWindow;
}

bool
Display::init(unsigned int width, unsigned int height, std::string const &title)
{
    try { mWindow = new sf::RenderWindow(); }
    catch (std::bad_alloc const & err) {
        TRACE("Bad alloc");
        return false;
    }
    mWindow->create(sf::VideoMode(width, height), title);
    if (not mWindow->isOpen()) {
        TRACE(": Could not open display")
    }
    mWindow->setFramerateLimit(mFrameRateLimit);
    LOG("Framerate limit: " << mFrameRateLimit);
    mWidth  = width;
    mHeight = height;
    mTitle  = title;
    return true;
}

bool Display::isReady() const {
    return mWindow != nullptr && mWindow->isOpen();
}

bool Display::close() {
    if (not isReady())
        return false;
    mWindow->close();
    delete mWindow;
    mWindow = nullptr;
    return true;
}


bool Display::clear(){
    if (not isReady())
        return false;
    mWindow->clear();
    return true;
}

void Display::render() {
    mWindow->clear();

    // TODO render RenderAble entities
    // TODO GUI overlay

    mWindow->display();
}

sf::RenderWindow * Display::getRenderWindow() {
    return mWindow;
}

