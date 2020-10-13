#pragma once
#include "fmt/core.h"
#include <absl/strings/str_split.h>
#include <absl/strings/string_view.h>
#include <filesystem>
#include <fstream>
#include <optional>
#include <stdexcept>

namespace fs = std::filesystem;
using sv = absl::string_view;
constexpr sv h_Header = "[Header]";
constexpr sv h_Reads = "[Reads]";
constexpr sv h_Data = "[Data]";
constexpr sv h_Settings = "[Settings]";

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