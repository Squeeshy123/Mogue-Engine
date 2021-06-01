# Mogue Engine
This is the Mogue game engine. This engine is just for me learning how to use c++ and make a game engine. I've been a game developerasd
for a while now and now I want to know how the game engines themselves are made and what math and rendering shenanegans these people are up to.

# Building the Engine
In order to build the engine you must have [SCons](https://scons.org) and the [GLFW](https://sourceforge.net/projects/glew/files/latest/download) and [GLEW](https://www.glfw.org) include files and libs
change the paths to the include and libs in the SConstruct file.

When building with SCons you can run `scons vsproj=1` to make a visual studio project for mogue. (it doesn't work too well though, so proceed with caution, you might have to change the relative paths of the classes)

# Style Guide
If you are going to commit then please follow this simple style guide:
```
class PascalCaseClasses {
  int snake_case_variables = 0;
  
  void snake_case_functions() {
    printf("%i\n", snake_case_variable);
  }
}
```

also do this:
```
int some_func() {
  // some code
}
```
not this:
```
int some_func()
{
  // some code
}
```
