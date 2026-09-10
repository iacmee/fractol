# fractol

Interactive fractal viewer written in C using MiniLibX for Linux.
Supports Mandelbrot, Julia, and Burning Ship, with zooming and panning.

## Requirements

GCC, Make, Git, and an X11 graphical environment. On Debian/Ubuntu:

```sh
sudo apt install build-essential git libx11-dev libxext-dev libbsd-dev
```

## Building

```sh
git clone --recurse-submodules https://github.com/iacmee/fractol.git
cd fractol
make
```

[MiniLibX](https://github.com/42Paris/minilibx-linux) is managed as a submodule,
pinned to a specific revision. If the clone does not include submodules, `make`
automatically downloads the dependency. To download it separately:

```sh
make minilibx
```

The initial download requires an Internet connection.

## Usage

```sh
./fractol M             # Mandelbrot
./fractol J -0.123 0.745 # Julia with complex parameter cx + cy*i
./fractol B             # Burning Ship
```

For Julia, omitting the parameters uses the defaults `-0.123` and `0.745`.

| Control | Action |
| --- | --- |
| Mouse wheel or `+` / `-` | Zoom centered on the pointer |
| Left mouse button drag | Pan the view |
| Arrow keys | Pan the view |
| `Esc` or closing the window | Exit the program |

## Other targets

- `make opt`: rebuild with optimizations.
- `make run`: build and launch Mandelbrot.
- `make clean`: remove the program's object files.
- `make fclean`: also remove the executable and compiled libraries.
- `make re`: perform a full rebuild.
