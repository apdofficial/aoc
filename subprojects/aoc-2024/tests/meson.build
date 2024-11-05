aoc_2022_tests = []

foreach name : aoc_2022_tests
  test(
    name,
    executable(
      name,
      sources: [name + '.cc'],
      cpp_args: cpp_args,
      dependencies: [dependency('catch2-with-main'), aoc_2024_dep],
    ),
    suite: 'aoc_2024',
  )
endforeach
