# Fract-ol: A Fractal Generation Project

## Project Overview

This project is a C program that generates and displays various fractal sets. It utilizes the `MLX42` graphics library to render the fractals in a window and allows for user interaction through keyboard and mouse events. The program can generate the Mandelbrot set, the Julia set, and the Burning Ship fractal.

## How to Compile and Run

To compile the project, navigate to the project directory and use the provided `Makefile`:
```bash
make
```

To run the program, execute the compiled binary with the name of the fractal you want to generate.

- **Mandelbrot:**
  ```bash
  ./fractol mandelbrot
  ```
- **Julia:** The Julia set requires two additional parameters, which are the real and imaginary parts of a complex number.
  ```bash
  ./fractol julia <real> <imaginary>
  ```
  For example: `./fractol julia -0.7 0.27015`
- **Burning Ship:**
  ```bash
  ./fractol burningship
  ```

## Technical Concepts Learned

This project covers a range of technical concepts in computer graphics and mathematics:

- **Graphics Programming:** The project uses the `MLX42` library for window management, pixel-level drawing (`mlx_put_pixel`), and event handling (`mlx_scroll_hook`, `mlx_key_hook`).
- **Fractal Mathematics:**
  - **Mandelbrot Set:** The set of complex numbers `c` for which the function `f(z) = z^2 + c` does not diverge when iterated from `z = 0`.
  - **Julia Set:** For a fixed complex number `c`, the Julia set is the set of complex numbers `z` for which the sequence `z_{n+1} = z_n^2 + c` remains bounded.
  - **Burning Ship Fractal:** A variation of the Mandelbrot set that uses the absolute value of the real and imaginary parts of the complex number in its iterative formula.
- **Complex Number Arithmetic:** The core of the fractal generation algorithms involves arithmetic with complex numbers.
- **Event Handling:** The program captures keyboard and mouse events to allow for zooming and other user interactions.
- **Coloring Algorithms:** The project implements algorithms to map the number of iterations to a color, which is what gives the fractals their visual appeal.
- **Performance Optimization:** Writing efficient rendering loops is crucial for a smooth user experience, especially when zooming into the fractals.
