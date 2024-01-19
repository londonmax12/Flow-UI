#include "flow.h"

int main() {
    Flow::FlowInstance flow = Flow::FlowInstance();
    flow.Init();
    flow.Shutdown();
    return 0;
}