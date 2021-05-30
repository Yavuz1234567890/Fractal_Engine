import os
import platform
import glob

env = Environment(CXXCOMSTR="Compiling => $SOURCES", LINKCOMSTR="Linking Program => $TARGET",
                CPPPATH=["Engine/src", "Engine/src/Vendor", "Engine/lib/includes"], CXXFLAGS="/std:c++17 /EHsc", TARGET_ARCH="x86")


libraries = [
	"glew32",
    "glfw3",
    "shell32",
    "gdi32",
    "user32",
    "opengl32",
    "msvcrt",
    "assimp-vc142-mt",
    "tinyxml2d"
]

sources = glob.glob("Engine/src/**/*.cpp", recursive=True)
sources.extend(glob.glob("Engine/lib/includes/**/*.cpp", recursive=True))

for source in sources:
    n_object = os.path.basename(source).replace(".cpp", ".obj")
    env.Object("bin/obj/%s" % n_object, source)

env.Program("bin/Fractal_Engine", Glob("bin/obj/*.obj"), LIBPATH="Engine/lib/lib", LIBS=libraries)