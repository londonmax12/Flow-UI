#include <stdio.h>

#include "flow.h"

bool Flow::FlowInstance::Init()
{
    mWindow = Flow::Window::CreatePlatformWindow();

    if (!mWindow)
        return false;

    return true;
}

void Flow::FlowInstance::Update()
{
    mWindow->Update();
}

void Flow::FlowInstance::Shutdown()
{
    if (mWindow) {
        mWindow->Shutdown();
        delete mWindow;
        mWindow = nullptr;
    }
}

Flow::FlowInstance::~FlowInstance()
{
    Shutdown();
}

