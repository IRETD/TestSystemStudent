#ifndef DESTROYPOINTERMACRO_H
#define DESTROYPOINTERMACRO_H

#define DestroyPointer( pointer ) \
    if ( pointer != nullptr ) { \
        delete pointer;\
    } \

#endif // DESTROYPOINTERMACRO_H
