# 🌀 fractol

fractol is a simple fractal visualizer built in C using the [MLX42](https://github.com/codam-coding-college/MLX42) graphics library. It renders beautiful mathematical sets like Mandelbrot and Julia, and lets you zoom in and out to explore the infinite detail of these fractals.

> Made as part of the **Codam/42 curriculum**, this project is an intro to graphical rendering, math visualization, and event-driven programming.

---

## ✨ Features

- 🔍 Zoom in and out using your mouse scroll
- 🖼️ Clean rendering of Mandelbrot and Julia fractals
- 🚀 Fast drawing using MLX42

---

## 🧠 Fractals Supported

- **Mandelbrot set**
- **Julia set**

Each set is rendered pixel by pixel using iteration logic on complex numbers.

---

## 🛠️ How to Run
```bash
./fractol Mandelbrot
```
or
```bash
./fractol Julia
```
### Requirements

- macOS or Linux
- [GLFW](https://www.glfw.org/) installed
- [MLX42](https://github.com/codam-coding-college/MLX42)
- A terminal that supports graphics (iTerm2 recommended on macOS)

### Installation

```bash
# Clone the project
git clone https://github.com/yourusername/fractol.git
cd fractol

# Install dependencies (on macOS)
brew install glfw cmake

# Build it
make
