#ifndef BASEWINDOWBUILDER_H
#define BASEWINDOWBUILDER_H


template <typename Window>
class WindowBuilder {
public:
    virtual Window* BuildWindow() = 0;
};

#endif // BASEWINDOWBUILDER_H
