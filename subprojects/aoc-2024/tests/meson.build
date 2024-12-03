aoc_2024_tests = [
  'test_aoc_2024_day01',
  'test_aoc_2024_day02',
  'test_aoc_2024_day03',
]

foreach name : aoc_2024_tests
  test(
    name,
    executable(
      name,
      sources: [name + '.cc'],
      cpp_args: cpp_args,
      dependencies: [dependency('catch2-with-main'), aoc_2024_dep],
    ),
    suite: 'aoc_2022',
  )
endforeach
