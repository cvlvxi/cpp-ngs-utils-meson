#include <benchmark/benchmark.h>
#include <range/v3/view/iota.hpp>

static void BM_SomeFunction(benchmark::State& state) {
    // Perform setup here
    for (auto _ : state) {
        // This code gets timed
        auto v = ranges::views::iota(1, 100);
    }
}
// Register the function as a benchmark
BENCHMARK(BM_SomeFunction);
// Run the benchmark
BENCHMARK_MAIN();