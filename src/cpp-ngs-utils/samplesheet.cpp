#include "samplesheet.h"


namespace cngs {
    std::optional<SampleSheet> SampleSheet::create(std::string_view fn) {
        fs::path fp = fs::path(fn);
        if (!fs::exists(fp))
            return std::nullopt;
        // Give ownership over
        SampleSheet s = SampleSheet(std::move(fp));
        s.parse();
        return s;
    }
    void SampleSheet::parse() {
        std::ifstream fstream(filePath);
        if (!fstream.is_open()) throw std::runtime_error("Could not open file");

        //        std::string_view line;
        std::string line;
        while (std::getline(fstream, line)) {
            fmt::print("{}\n", line);
        }
    }
}// namespace cngs