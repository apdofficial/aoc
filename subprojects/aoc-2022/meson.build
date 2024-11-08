project(
  'aoc-2022',
  'cpp',
  version: '1.0.0',
  default_options: {'cpp_std': 'c++20', 'prefer_static': true}
)

cpp_args = [
  '-DPROJECT_NAME="' + meson.project_name() + '"',
  '-DPROJECT_VERSION="' + meson.project_version() + '"',
]

aoc_common_proj = subproject('aoc-common')
aoc_common_dep = aoc_common_proj.get_variable('aoc_common_dep')

fmt = subproject('fmt', default_options: 'default_library=static')
fmt_dep = fmt.get_variable('fmt_dep')

aoc_2022_dep = declare_dependency(
  sources: [
    'src/aoc/2022/day_factory.cc',
    'src/aoc/2022/day01.cc',
    'src/aoc/2022/day02.cc',
    'src/aoc/2022/day03.cc',
    'src/aoc/2022/day04.cc',
    'src/aoc/2022/day05.cc',
  ],
  include_directories: include_directories('include'),
  dependencies: [
    dependency('boost', modules: ['program_options'], static: true),
    fmt_dep,
    aoc_common_dep,
  ],
)

executable(
  meson.project_name(),
  sources: ['src/main.cc'],
  cpp_args: cpp_args,
  dependencies: aoc_2022_dep,
  install: true,
)

subdir('tests')
