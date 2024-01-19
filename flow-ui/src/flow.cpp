#include <stdio.h>

#include "flow.h"

bool Flow::FlowInstance::Init()
{
    mWindow = Flow::Window::CreateWindow();

    if (!mWindow)
        return false;

    return true;
}

void Flow::FlowInstance::Shutdown()
{
    if (mWindow) {
        delete mWindow;
        mWindow = nullptr;
    }
}

Flow::FlowInstance::~FlowInstance()
{
    Shutdown();
}

