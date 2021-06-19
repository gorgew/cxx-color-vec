# cxx color-vec
cxx color-vec is a c++20 single-header library for a simple to use color vector
for graphics programming. In OpenGL, colors are stored as RGBA vec4's of float32's where each entry is between 0 - 1.0. This library provids a convenient way to manipulate a color between various color spaces.

## Requirements
Compiler with some C++20 support. Tests require Catch2.

## Usage

```
#import "color-vec.hpp"
...
auto my_color = color-vec::make_rgb("123.0", "70.0", "53.0", "1.0f");
my_color.r++; //RGB 0-255 red
my_color.s -= 20; //HSV saturation

//To use with OpenGL
glUniform4fv(my_uniform_location, 1, *my_color);
```
