# Raytrace: A 3D Ray Tracer

## Project Overview

This project is a C implementation of a ray tracer, a program that generates 3D computer graphics by tracing the path of light as pixels in an image plane. The program takes a scene description file as input and produces a rendered image. The scene can contain various geometric objects, lights, and a camera.

## How to Compile and Run

1. **Compile:** The project includes a `Makefile`. Run the `make` command to build the `raytrace` executable.
2. **Run:** Execute the program with a scene description file as an argument.
   ```bash
   ./raytrace scenes/scene.rt
   ```
   The program will render the scene and display it in a window using the `MinilibX` library.

## Scene File Format

The scene description file is a simple text file that defines the elements of the scene. The following elements are supported:

- `R`: Resolution of the output image.
- `A`: Ambient lighting.
- `c`: Camera position and orientation.
- `l`: Light source position and intensity.
- `sp`: Sphere, defined by its center and radius.
- `pl`: Plane, defined by a point on the plane and a normal vector.
- `cy`: Cylinder, defined by its center, axis, radius, and height.

## Technical Concepts Learned

This project provides a practical understanding of several key concepts in computer graphics and mathematics:

- **Ray Tracing:** The project is a comprehensive implementation of the ray tracing algorithm, which involves casting rays from the camera through each pixel of the image plane and determining the color of the pixel based on the objects the ray intersects.
- **Vector and Matrix Mathematics:** The project makes extensive use of 3D vector and matrix mathematics for representing and manipulating objects in 3D space, as well as for performing calculations such as ray-object intersections.
- **Geometric Optics:** The project implements a simple lighting model based on the principles of geometric optics, including ambient, diffuse, and specular lighting.
- **Ray-Object Intersection:** The project includes functions to calculate the intersection of a ray with various geometric primitives (spheres, planes, cylinders).
- **Shading and Lighting:** The color of each pixel is determined by a shading model that takes into account the material properties of the objects, the position and intensity of the light sources, and the position of the camera.
- **Multithreading:** The project uses the `pthread` library to parallelize the rendering process, with each thread rendering a portion of the image.
- **MinilibX:** The `MinilibX` library is used for window management and for displaying the rendered image.
- **Parsing:** The project includes a parser that reads the scene description file and creates a data structure representing the 3D scene.
