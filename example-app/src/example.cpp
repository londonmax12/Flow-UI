#include "flow.h"

int main() {
    Flow::FlowInstance flow = Flow::FlowInstance();
    flow.Init();
    
    bool running = true;
    while (running)
    {
        flow.Update();
    }

    flow.Shutdown();
    return 0;
}