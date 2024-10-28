project(
  'aoc-2022',
  'cpp',
  version: '0.1.0',
  default_options: {'cpp_std': 'c++20', 'prefer_static': true},
)

cpp_args = [
  '-DPROJECT_NAME="' + meson.project_name() + '"',
  '-DPROJECT_VERSION="' + meson.project_version() + '"',
]

aoc_libcommon_proj = subproject('aoc-libcommon')
aoc_libcommon_dep = aoc_libcommon_proj.get_variable('aoc_libcommon_dep')

fmt = subproject('fmt', default_options: 'default_library=static')
fmt_dep = fmt.get_variable('fmt_dep')

aoc_2022_dep = declare_dependency(
  sources: [
    'src/aoc/2022/day01.cc',
    'src/aoc/2022/day02.cc',
  ],
  include_directories: include_directories('include'),
  dependencies: [
    dependency('boost', modules: ['program_options'], static: true),
    fmt_dep,
    aoc_libcommon_dep,
  ],
)

executable(
  'aoc-2022',
  sources: ['src/main.cc'],
  cpp_args: cpp_args,
  dependencies: aoc_2022_dep,
  install: true,
)

subdir('tests')
