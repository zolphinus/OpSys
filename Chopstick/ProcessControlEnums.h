#ifndef CONTROL_ENUM
#define CONTROL_ENUM

enum ProcessClass{
    APPLICATION,
    SYSTEM
};

enum PrintMode{
    PARTIAL_PRINT,
    TIME_REMAINING,
    FULL_PRINT
};

enum RunState{
    READY,
    SUSPENDED_READY,
    BLOCKED,
    SUSPENDED_BLOCKED,
    RUNNING
};
#endif // PC_ENUM
