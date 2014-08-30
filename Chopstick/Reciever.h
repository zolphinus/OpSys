#ifndef RECIEVER_H
#define RECIEVER_H

namespace TYPES
{
    enum ACTION_LIST
    {
        AWAIT_INPUT,
        DISPLAY_VERSION,
        LIST_DIR_CONTENTS,
        EXIT
    };
};


class Reciever(){
public:
    virtual void setAction(TYPES::ACTION_LIST action) = 0;
    virtual void performAction() = 0;
};

#endif // RECIEVER_H
