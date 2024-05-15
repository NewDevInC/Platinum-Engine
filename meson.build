project('PlatinumEngine', 'c', 'cpp',
        version : '0.0.5',
        default_options : ['warning_level=3', 'cpp_std=gnu++17', 'destdir=H:\Projects\Programming\C++\OpenGL\buildDir\bin'])

subdir('src')

include = include_directories('src', 'include')


executable('OpenGL_test',
           'test/main.cpp',
           install : true,
           install_dir : 'H:/Projects/Programming/C++/OpenGL/buildDir/bin/',
           include_directories : include,
           win_subsystem : 'windows',
           dependencies : [sdl2, sdl2_main, glm],
           link_with : engine)
