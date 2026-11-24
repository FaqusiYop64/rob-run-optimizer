// main.cpp — entry point. Wires config and subsystems together.

#include "robrunoptimizer/settings.h"
#include "robrunoptimizer/tuner.h"
#include "robrunoptimizer/network.h"
#include "robrunoptimizer/profiles.h"
#include <csignal>
#include <memory>

namespace { std::atomic<bool> g_running{true}; void on_signal(int) { g_running.store(false); } }

int main(int argc, char** argv) {
    std::signal(SIGINT, on_signal);
    std::signal(SIGTERM, on_signal);

    robrunoptimizer::Settings settings = robrunoptimizer::Settings::load_default();
    robrunoptimizer::Tuner tuner(settings.store_path);
    robrunoptimizer::Network network(settings.store_path);
    robrunoptimizer::Profiles profiles(settings.store_path);
    std::fprintf(stderr, "[rob-run-optimizer] ready\n");

    while (g_running.load()) {
        // main loop: pump subsystems
        break;
    }
    return 0;
}
