#pragma once
#include <filesystem>
#include <fstream>
#include <optional>

namespace fs = std::filesystem;

namespace cngs {
    class SampleSheet {
    public:
        //        static std::optional<SampleSheet> create(std::string_view fn);
        static void create(std::string_view fn);

    private:
        fs::path filePath;
        SampleSheet(fs::path filePath) : filePath(std::move(filePath)) {}
    };

}// namespace cngs