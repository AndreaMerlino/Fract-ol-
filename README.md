# Fract'ol: Computer Graphics Fractals

## Project Overview

Fract'ol is a computer graphics project focused on generating and rendering beautiful fractals. Using C and the MiniLibX graphical library, this program allows users to explore different types of fractals such as the Julia set and Mandelbrot set. The goal is to visualize the intricate patterns of fractals, which remain consistent at every scale.

## Features

- **Fractal Types**: 
  - Julia Set
  - Mandelbrot Set
- **Zooming**: Zoom in and out infinitely using the mouse wheel, showcasing the fractal's self-similarity at different scales.
- **Dynamic Julia Sets**: Create different Julia sets by passing custom parameters through the command line.
- **Smooth Window Management**: Handle window focus, resizing, minimizing, and exit events smoothly.
- **Color Depth**: The depth of the fractals is represented by colors, allowing for psychedelic visual effects.

## Usage

### Arguments
The program accepts the following arguments:
- **Fractal type**: Choose the type of fractal to render.
- **Additional options**: Pass extra parameters to tweak the rendering (optional).

If no valid arguments are passed, a list of available options will be displayed.

### Controls
- **Zooming**: Use the mouse wheel to zoom in and out.
- **Window Controls**: 
  - Press `ESC` to close the window and quit the program.
  - Click on the window's cross to exit.

### Compilation
The project includes a `Makefile` with the following rules:
- `all`: Compile the project.
- `clean`: Remove object files.
- `fclean`: Remove object files and the executable.
- `re`: Recompile the project.

Run the following commands to compile and execute:

```bash
make
./fractol <fractal_type>
