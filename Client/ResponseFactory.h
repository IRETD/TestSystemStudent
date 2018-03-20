#ifndef RESPONSEFACTORY_H
#define RESPONSEFACTORY_H
#include <response/Response.h>

class ResponseFactory
{
public:
    ResponseFactory();

    QSharedPointer < Response > createResponse( const ResponseType &type );
};

#endif // RESPONSEFACTORY_H
