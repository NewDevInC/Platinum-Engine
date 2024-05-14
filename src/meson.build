# These arguments are only used to build the shared library
# not the executables that use the library.
lib_args = ['-DBUILDING_MESON_LIBRARY']

source_headers = ['PlatinumEngine.hpp',
                  'SilverRenderer.hpp',
                  'VAO.hpp',
                  'VBO.hpp',
                  'Shader.hpp',
                  'Mesh.hpp',
                  'glmIncludes.hpp']

source_cpp = ['glad.c',
              'PlatinumEngine.cpp',
              'SilverRenderer.cpp',
              'VAO.cpp',
              'VBO.cpp',
              'Shader.cpp',
              'Mesh.cpp']

source = source_headers + source_cpp

include = include_directories('../include')

glm = dependency('glm')
sdl2 = dependency('sdl2')
sdl2_main = dependency('sdl2main')

engine = static_library('OpenGL_Engine', source,
                        install : true,
                        install_dir : 'H:/Projects/Programming/C++/OpenGL/buildDir/bin/',
                        c_args : lib_args,
                        include_directories : include,
                        dependencies : [sdl2, sdl2_main, glm]
)