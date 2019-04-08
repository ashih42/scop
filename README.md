# scop

Render Wavefront .obj 3D models in C using OpenGL. (42 Silicon Valley)

<p float="left">
  <img src="https://github.com/ashih42/scop/blob/master/Screenshots/spider.png" width="280" />
  <img src="https://github.com/ashih42/scop/blob/master/Screenshots/cheese.png" width="280" />
  <img src="https://github.com/ashih42/scop/blob/master/Screenshots/horse.png" width="280" />
</p>

## Prerequisites

You are on macOS with `gcc` and `make` installed.

## Installing

```
./setup.sh
```

## Running

```
./scop obj_file
```

## Controls

### Top-level Controls

* `P` Select perspective or orthographic projection.
* `W` Toggle wireframe.
* `R` Reset all parameters.
* `Escape` Terminate the renderer.

### Model Transform Controls

* `S` Toggle spinning.

#### Scaling
* `Mouse Scroll Wheel` Increase/decrease scaling in X, Y, Z-axes.
* `Home` Increase scaling in X, Y, Z-axes.
* `End` Decrease scaling in X, Y, Z-axes.
* `Left Shift` + `Numpad 7` Increase scaling in X-axis.
* `Left Shift` + `Numpad 8` Decrease scaling in X-axis.
* `Left Shift` + `Numpad 4` Increase scaling in Y-axis.
* `Left Shift` + `Numpad 5` Decrease scaling in Y-axis.
* `Left Shift` + `Numpad 1` Increase scaling in Z-axis.
* `Left Shift` + `Numpad 2` Decrease scaling in Z-axis.

#### Rotation
* `Drag LMB` Rotate in X, Y-axes.
* `Numpad 7` Increase rotation around X-axis.
* `Numpad 8` Decrease rotation around X-axis.
* `Numpad 4` Increase rotation around Y-axis.
* `Numpad 5` Decrease rotation around Y-axis.
* `Numpad 1` Increase rotation around Z-axis.
* `Numpad 2` Decrease rotation around Z-axis.

#### Translation
* `Left Control` + `Numpad 7` Increase translation along X-axis.
* `Left Control` + `Numpad 8` Decrease translation along X-axis.
* `Left Control` + `Numpad 4` Increase translation along Y-axis.
* `Left Control` + `Numpad 5` Decrease translation along Y-axis.
* `Left Control` + `Numpad 1` Increase translation along Z-axis.
* `Left Control` + `Numpad 2` Decrease translation along Z-axis.

### Shading Controls

* `G` Toggle grayscale.
* `C` Toggle smooth coloring.

#### Texture Controls

* `Page Up` Increase % texture.
* `Page Down` Decrease % texture.
* `Tab` Select next texture.
* `U` Use spherical-mapped or given UV coordinates.

#### Light Controls

* `L` Toggle light source and shading.
* `N` Use triangle-generated or given surface normals.
* `Left Alt` + `Numpad 7` Move light position toward +X-axis.
* `Left Alt` + `Numpad 8` Move light position toward -X-axis.
* `Left Alt` + `Numpad 4` Move light position toward +Y-axis.
* `Left Alt` + `Numpad 5` Move light position toward -Y-axis.
* `Left Alt` + `Numpad 1` Move light position toward +Z-axis.
* `Left Alt` + `Numpad 2` Move light position toward -Z-axis.
* `Left Alt` + `Page Up` Increase % specular.
* `Left Alt` + `Page Down` Decrease % specular.
