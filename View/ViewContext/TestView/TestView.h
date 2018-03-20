#ifndef TESTVIEW_H
#define TESTVIEW_H

#include <View/ViewContext/TreeView.h>

class TestView : public TreeView {
public:
    TestView();
    void setModelForView( Model *pModel );
};

#endif // TESTVIEW_H
