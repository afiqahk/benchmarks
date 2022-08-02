#include <deque>

static void clear_with_assign(benchmark::State& state)
{
  std::deque<int> q;
  for(auto _ : state)
  {
    for(size_t i=0; i<state.range(0);++i)
    {
      q.push_back(i);
    }
    benchmark::DoNotOptimize(q);
    q = {};
    q.shrink_to_fit();
    benchmark::DoNotOptimize(q);
  }
}
BENCHMARK(clear_with_assign)->Arg(100);

static void clear_with_pop(benchmark::State& state)
{
  std::deque<int> q;
  for(auto _ : state)
  {
    for(size_t i=0; i<state.range(0);++i)
    {
      q.push_back(i);
    }
    benchmark::DoNotOptimize(q);
    while(!q.empty())
    {
      q.pop_front();
    }
    q.shrink_to_fit();
    benchmark::DoNotOptimize(q);
  }
}
BENCHMARK(clear_with_pop)->Arg(100);

static void clear_with_clear(benchmark::State& state)
{
  std::deque<int> q;
  for(auto _ : state)
  {
    for(size_t i=0; i<state.range(0);++i)
    {
      q.push_back(i);
    }
    benchmark::DoNotOptimize(q);
    q.clear();
    q.shrink_to_fit();
    benchmark::DoNotOptimize(q);
  }
}
BENCHMARK(clear_with_clear)->Arg(100);

static void clear_with_swap_inplace(benchmark::State& state)
{
  std::deque<int> q;
  for(auto _ : state)
  {
    for(size_t i=0; i<state.range(0);++i)
    {
      q.push_back(i);
    }
    benchmark::DoNotOptimize(q);
    std::deque<int>().swap(q);
    q.shrink_to_fit();
    benchmark::DoNotOptimize(q);
  }
}
BENCHMARK(clear_with_swap_inplace)->Arg(100);

static void clear_with_swap(benchmark::State& state)
{
  std::deque<int> q;
  for(auto _ : state)
  {
    for(size_t i=0; i<state.range(0);++i)
    {
      q.push_back(i);
    }
    benchmark::DoNotOptimize(q);
    std::deque<int> empty;
    std::swap(q, empty);
    q.shrink_to_fit();
    benchmark::DoNotOptimize(q);
  }
}
BENCHMARK(clear_with_swap)->Arg(100);
