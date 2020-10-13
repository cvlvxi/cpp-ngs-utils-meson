#pragma once

#include <filesystem>

namespace fs = std::filesystem;

namespace Tests {

    fs::path getFixture(const char *filename) {
        fs::path fixture =
                fs::absolute(fs::path("src") / "data" / filename);
        return fixture;
    }
}// namespace Tests
