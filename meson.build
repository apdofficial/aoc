project(
  'aoc',
  'cpp',
  version: '0.1.0',
  default_options: {'cpp_std': 'c++20', 'prefer_static': true},
)

subprojects = [
  'aoc-common',
  'aoc-2022',
  'aoc-2024',
]

subproject_names = []

foreach sp : subprojects
  subproj = subproject(sp)
  if subproj.found()
    subproject_names += [sp]
  endif
endforeach

message('Building subprojects: ' + ', '.join(subproject_names))
