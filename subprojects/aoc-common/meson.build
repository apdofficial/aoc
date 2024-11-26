project(
  'aoc-common',
  'cpp',
  version: '0.1.0',
  default_options: {'cpp_std': 'c++20', 'prefer_static': true},
)

fmt = subproject('fmt', default_options: 'default_library=static')
fmt_dep = fmt.get_variable('fmt_dep')

boost_dep = dependency('boost', modules: ['program_options'], static: true)

inc = include_directories('include')

aoc_common = static_library(
  meson.project_name(),
  sources: [
    'src/aoc/common/cli/parser.cc',
    'src/aoc/common/puzzle/puzzle_file_reader.cc',
    'src/aoc/common/puzzle/puzzle_reader_factory.cc',
    'src/aoc/common/range/range.cc',
    'src/aoc/common/range/rangeset.cc',
  ],
  include_directories: inc,
  dependencies: [
    boost_dep,
    fmt_dep,
  ],
)

aoc_common_dep = declare_dependency(
  include_directories: inc,
  link_with: aoc_common,
)
