# Godot-imgtran
This project GDExtension to bind C++ codes.

This project is for rapid prototyping the image transform coding efficiency, so I can develop image algorithms faster.

# Dependency on Windows
## Compiler
### GCC
**Visual Studio Community is not required as we are using GCC. If you have it, Scons will build it with MSVC.**  
**You can skip GCC if you installed it.**  
[Godot Windows compiling documentation](https://docs.godotengine.org/en/latest/contributing/development/compiling/compiling_for_windows.html)  

You will need Scons, Python, and GCC from Scoop.  
[Get scoop](https://scoop.sh/)
```batch
scoop install gcc python scons make mingw
```

Check your installation with this command.
```batch
where gcc
```

The output should show `gcc.exe`
```batch
C:\Users\%username%\scoop\apps\gcc\current\bin\gcc.exe
```
## C++ bindings
[Get godot-cpp 4.2](https://github.com/godotengine/godot-cpp/tree/4.2)  
Put the `godot-cpp-4.2` in the root folder.  
Your file tree should look like this as the file `SConstruct` is written this way.
```batch
tree
```
```
Godot-imgtran
├───cpp
├───godot-cpp-4.2
└───project
```
### [SConstruct](cpp/SConstruct)
```python
#!/usr/bin/env python
import os
import sys

env = SConscript("../godot-cpp-4.2/SConstruct")

env.Append(CPPPATH=["/"])
sources = Glob("*.cpp")

# Keep the file name in lowercase to prevent case-sensitive file system bugs
export_path = "../project/bin/imgtran{}{}"
library = env.SharedLibrary(
	export_path.format(env["suffix"], env["SHLIBSUFFIX"]),
	source=sources,
)

Default(library)
```
## Compiling
Change to the `cpp` directory and compile it.
```batch
cd cpp
scons
```
## Running the project
Import the project in Godot and make sure the **entry_symbol** name is the same as in your C++ `register_types.cpp`.

### [imgtran.gdextension](project/imgtran.gdextension)
```toml
[configuration]

entry_symbol = "imgtran_init"
compatibility_minimum = "4.2"

[libraries]

windows.debug.x86_64 = "res://bin/imgtran.windows.template_debug.x86_64.dll"
windows.release.x86_64 = "res://bin/imgtran.windows.release.x86_64.dll"
```

### [register_types.cpp](cpp/register_types.cpp)
```c++
// Unmangle the function name in the symbol by compile as C
extern "C" {
    // You need a GDExtensionBool function to connect to Godot
    // entry_symbol = "imgtran_init"
    GDExtensionBool GDE_EXPORT imgtran_init(GDExtensionInterfaceGetProcAddress p_get_proc_address, GDExtensionClassLibraryPtr p_library, GDExtensionInitialization *r_initialization) {
        GDExtensionBinding::InitObject init_obj(p_get_proc_address, p_library, r_initialization);

        // Using function pointer to register constructor and deconstructor
        // so Godot can free your class
        init_obj.register_initializer(initialize_imgtran_type);
        init_obj.register_terminator(uninitialize_imgtran_type);
        init_obj.set_minimum_library_initialization_level(MODULE_INITIALIZATION_LEVEL_SCENE);

        return init_obj.init();
    }
}
```
