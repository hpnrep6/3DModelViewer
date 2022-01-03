# OBJ Model Viewer
A simple obj model viewer to look at 3d .obj models.

## Building

```
$ mkdir build
$ cd build
$ cmake ..
$ make
```

## Running the program

```
$ cd build
$ ./ModelViewer
```

or

```
$ ./ModelViewer objPath.obj imagePath.png
```

## Libraries used

- [stb_image](https://github.com/nothings/stb)
- [assimp](https://github.com/assimp/assimp)
- [glm](https://github.com/g-truc/glm)
- [glew](http://glew.sourceforge.net/)
- [glfw](https://www.glfw.org/docs/3.3/quick.html)
