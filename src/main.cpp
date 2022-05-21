#include "Levels/CheckersLevel.hpp"
#include "pwnmvpch.hpp"

int startApp(int argc, char **argv) {
    runPandaApplication(Panda::ApplicationStartupSettings::builder()
                            .name("Pawn Move")
                            .windowTitle("PAWN MOVE")
                            .windowSize({900, 600})
                            .isFullScreen(false)
                            .startupLevel(new CheckersLevel())
                            .build());
    return 0;
}
