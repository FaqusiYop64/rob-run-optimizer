// tuner — part of rob-run-optimizer.

#pragma once

#include <string>
#include <vector>

namespace robrunoptimizer {

class Tuner {
public:
    explicit Tuner(const std::string& config_path);

    void configure(const std::string& key, const std::string& value);
    bool run();
    bool verbose() const { return verbose_; }

private:
    std::string config_path_;
    bool verbose_ = false;
};

}  // namespace robrunoptimizer
