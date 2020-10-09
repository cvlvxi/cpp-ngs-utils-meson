#pragma once

#include <filesystem>

namespace fs = std::filesystem;

namespace Tests
        {

                fs::path getFixture(const char *filename)
        {
            fs::path fixture = fs::path(__FILE__).parent_path().parent_path() / "data" / filename;
            return fixture;
        }
        } // namespace Tests
