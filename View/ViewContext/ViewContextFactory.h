#ifndef VIEWCONTEXTFACTORY_H
#define VIEWCONTEXTFACTORY_H

#include <Enum/View/ViewContext/ViewContextType.h>

class ViewContext;

class ViewContextFactory {
public:
    ViewContextFactory();
    ViewContext* createViewContext( const ViewContextType &viewContextType );
};

#endif
