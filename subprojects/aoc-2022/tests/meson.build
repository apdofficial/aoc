aoc_2022_tests = [
  'test_aoc_2022_day01',
  'test_aoc_2022_day02',
  'test_aoc_2022_day03',
  'test_aoc_2022_day04',
  'test_aoc_2022_day05',
  'test_aoc_2022_day06',
]

foreach name : aoc_2022_tests
  test(
    name,
    executable(
      name,
      sources: [name + '.cc'],
      cpp_args: cpp_args,
      dependencies: [dependency('catch2-with-main'), aoc_2022_dep],
    ),
    suite: 'aoc_2022',
  )
endforeach
