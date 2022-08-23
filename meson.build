project('text-editor', 'c')

gnome = import('gnome')

ui = gnome.compile_resources(
  'text-editor',
  'data/text-editor.gresource.xml',
  source_dir: 'data',
  c_name: 'ui'
)

gtkdep = [dependency('gtk4'), dependency('libadwaita-1')]

executable(
  'text-editor',
  'main.c',
  ui,
  dependencies: gtkdep
)
