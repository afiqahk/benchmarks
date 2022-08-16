#include <algorithm>

static void set_with_if(benchmark::State& state)
{
  for(auto _ : state)
  {
    float f = -0.2;
    benchmark::DoNotOptimize(f);
    if (f < 0.f)
      f = 0.f;
    if (f > 1.f)
      f = 1.f;
    benchmark::DoNotOptimize(f);
  }
}
BENCHMARK(set_with_if);

static void set_with_algo(benchmark::State& state)
{
  for(auto _ : state)
  {
    float f = -0.2;
    benchmark::DoNotOptimize(f);
    f = std::max(f, 0.f);
    f = std::min(f, 1.f);
    benchmark::DoNotOptimize(f);
  }
}
BENCHMARK(set_with_algo);

