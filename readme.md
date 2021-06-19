# cxx color-vec
cxx color-vec is a c++20 single-header library for a simple to use color vector
for graphics programming. In OpenGL, colors are stored as RGBA vec4's of float32's where each entry is between 0 - 1.0. This library provids a convenient way to manipulate a color between various color spaces.

## Requirements
Compiler with some C++20 support. Tests require Catch2.

## Usage

```
#include "color-vec.hpp"
...
auto my_color = color-vec::make_rgb(123.0, 70.0, 53.0, 1.0f);
my_color.r++; //RGB on 0.0f-255.0f scale
my_color.s -= 20; //HSV saturation on 0.0f-100.0f scale

//To use with OpenGL
glUniform4fv(my_uniform_location, 1, *my_color);
```
