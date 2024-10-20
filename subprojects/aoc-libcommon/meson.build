project(
  'aoc-libcommon',
  'cpp',
  version: '0.1.0',
  default_options: {'cpp_std': 'c++20', 'prefer_static': true},
)

inc = include_directories('include')

aoc_libcommon = static_library(
  'aoc-libcommon',
  sources: ['src/aoc/common/file_puzzle_reader.cc'],
  include_directories: inc,
  install: true
)

aoc_libcommon_dep = declare_dependency(include_directories: inc, link_with: aoc_libcommon)
