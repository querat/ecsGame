//
// Created by pasta on 31/03/18.
//

#ifndef RAY_INPUTCOMPONENT_H
#define RAY_INPUTCOMPONENT_H

struct InputComponent {

    typedef enum    InputType_e {
        MOVE_UP
        , MOVE_DOWN
        , MOVE_LEFT
        , MOVE_RIGHT
        , PAUSE_PLAY
        , MOUSE_CLICK
        , EXIT_REQUESTED
    }               InputType;

    typedef struct  ClickData_s {
        typedef enum    MouseButton_e {
            NONE = 0
            , LEFT
            , RIGHT
            , MIDDLE
            , FOUR
            , FIVE
        }               MouseButton;

        MouseButton buttonClicked;
        int         x;
        int         y;
    }               ClickData;

    InputType   type;
    ClickData   click;
};

#endif //RAY_INPUTCOMPONENT_H
