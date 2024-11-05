project(
  'aoc-common',
  'cpp',
  version: '0.1.0',
  default_options: {'cpp_std': 'c++20', 'prefer_static': true},
)

inc = include_directories('include')

aoc_common = static_library(
  meson.project_name(),
  sources: [
    'src/aoc/common/puzzle/puzzle_file_reader.cc',
    'src/aoc/common/range/range.cc',
    'src/aoc/common/range/rangeset.cc',
  ],
  include_directories: inc,
)

aoc_common_dep = declare_dependency(include_directories: inc, link_with: aoc_common)
