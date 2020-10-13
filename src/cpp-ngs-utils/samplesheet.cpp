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

        std::string line;
        while (std::getline(fstream, line)) {
            sv sv_line = sv(line);
            if (absl::StrContains(sv_line, h_Header) ||
                absl::StrContains(sv_line, h_Reads) ||
                absl::StrContains(sv_line, h_Settings)) {
                continue;
            }
            // We need to get the data from here
            auto x = absl::StrSplit(sv_line, ",");
            for (const auto &i : x) {
                fmt::print("{}", i);
            }
        }
    }
}// namespace cngs