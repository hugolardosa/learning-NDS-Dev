# Ray Casting Example 2
In this example we take multiple rays calculate the intersection of various objects on screen. Based on this source [source](https://github.com/ncase/sight-and-light/blob/gh-pages/draft2.html).

# Source Code
[template.c](./source/template.c)

### Understanding the Code
In the first example we took a single ray of detection. In this example we use 50 rays using 360 degrees of seperation.

The big difference this time is `getIntersection` is called for each ray and segment.

For a better understanding of the ray casting system, check out the [first example](../../Ray_Casting/example_1#code-explained)

# Preview
![raycasting_example2](./preview/multiple_cast.png)


#### NOTE
This entire example relies on the NDS version of OpenGL, [more about that in VideoGL.h](http://libnds.devkitpro.org/videoGL_8h.html).
