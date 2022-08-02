// https://quick-bench.com/q/AbQg4_9mNBGRsFYuhIMdfdEmTSw

#include <deque>

static void clear_with_assign(benchmark::State& state)
{
  std::deque<int> q;
  for(auto _ : state)
  {
    q.push_back(1);
    q.push_back(2);
    q.push_back(3);
    q.push_back(4);
    q.push_back(5);
    benchmark::DoNotOptimize(q);
    q = {};
    benchmark::DoNotOptimize(q);
  }
}
BENCHMARK(clear_with_assign);

static void clear_with_pop(benchmark::State& state)
{
  std::deque<int> q;
  for(auto _ : state)
  {
    q.push_back(1);
    q.push_back(2);
    q.push_back(3);
    q.push_back(4);
    q.push_back(5);
    benchmark::DoNotOptimize(q);
    q.pop_front();
    q.pop_front();
    q.pop_front();
    q.pop_front();
    q.pop_front();
    benchmark::DoNotOptimize(q);
  }
}
BENCHMARK(clear_with_pop);

static void clear_with_clear(benchmark::State& state)
{
  std::deque<int> q;
  for(auto _ : state)
  {
    q.push_back(1);
    q.push_back(2);
    q.push_back(3);
    q.push_back(4);
    q.push_back(5);
    benchmark::DoNotOptimize(q);
    q.clear();
    benchmark::DoNotOptimize(q);
  }
}
BENCHMARK(clear_with_clear);

static void clear_with_swap_inplace(benchmark::State& state)
{
  std::deque<int> q;
  for(auto _ : state)
  {
    q.push_back(1);
    q.push_back(2);
    q.push_back(3);
    q.push_back(4);
    q.push_back(5);
    benchmark::DoNotOptimize(q);
    std::deque<int> empty;
    std::deque<int>().swap(q);
    benchmark::DoNotOptimize(q);
  }
}
BENCHMARK(clear_with_swap_inplace);

static void clear_with_swap(benchmark::State& state)
{
  std::deque<int> q;
  for(auto _ : state)
  {
    q.push_back(1);
    q.push_back(2);
    q.push_back(3);
    q.push_back(4);
    q.push_back(5);
    benchmark::DoNotOptimize(q);
    std::deque<int> empty;
    std::swap(q, empty);
    benchmark::DoNotOptimize(q);
  }
}
BENCHMARK(clear_with_swap);

//////////////////////////////////////////////////////////

static void clear_with_assign_stf(benchmark::State& state)
{
  std::deque<int> q;
  for(auto _ : state)
  {
    q.push_back(1);
    q.push_back(2);
    q.push_back(3);
    q.push_back(4);
    q.push_back(5);
    benchmark::DoNotOptimize(q);
    q = {};
    q.shrink_to_fit();
    benchmark::DoNotOptimize(q);
  }
}
BENCHMARK(clear_with_assign_stf);

static void clear_with_pop_stf(benchmark::State& state)
{
  std::deque<int> q;
  for(auto _ : state)
  {
    q.push_back(1);
    q.push_back(2);
    q.push_back(3);
    q.push_back(4);
    q.push_back(5);
    benchmark::DoNotOptimize(q);
    q.pop_front();
    q.pop_front();
    q.pop_front();
    q.pop_front();
    q.pop_front();
    q.shrink_to_fit();
    benchmark::DoNotOptimize(q);
  }
}
BENCHMARK(clear_with_pop_stf);

static void clear_with_clear_stf(benchmark::State& state)
{
  std::deque<int> q;
  for(auto _ : state)
  {
    q.push_back(1);
    q.push_back(2);
    q.push_back(3);
    q.push_back(4);
    q.push_back(5);
    benchmark::DoNotOptimize(q);
    q.clear();
    q.shrink_to_fit();
    benchmark::DoNotOptimize(q);
  }
}
BENCHMARK(clear_with_clear_stf);

static void clear_with_swap_inplace_stf(benchmark::State& state)
{
  std::deque<int> q;
  for(auto _ : state)
  {
    q.push_back(1);
    q.push_back(2);
    q.push_back(3);
    q.push_back(4);
    q.push_back(5);
    benchmark::DoNotOptimize(q);
    std::deque<int> empty;
    std::deque<int>().swap(q);
    q.shrink_to_fit();
    benchmark::DoNotOptimize(q);
  }
}
BENCHMARK(clear_with_swap_inplace_stf);

static void clear_with_swap_stf(benchmark::State& state)
{
  std::deque<int> q;
  for(auto _ : state)
  {
    q.push_back(1);
    q.push_back(2);
    q.push_back(3);
    q.push_back(4);
    q.push_back(5);
    benchmark::DoNotOptimize(q);
    std::deque<int> empty;
    std::swap(q, empty);
    q.shrink_to_fit();
    benchmark::DoNotOptimize(q);
  }
}
BENCHMARK(clear_with_swap_stf);
