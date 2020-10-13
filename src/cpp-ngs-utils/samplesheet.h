#pragma once
#include "fmt/core.h"
#include <filesystem>
#include <fstream>
#include <optional>
#include <stdexcept>

namespace fs = std::filesystem;

namespace cngs {
    class SampleSheet {
    public:
        static std::optional<SampleSheet> create(std::string_view fn);

    private:
        fs::path filePath;
        SampleSheet(fs::path filePath) : filePath(std::move(filePath)) {}
        void parse();
    };

}// namespace cngs