# Fract-ol

![fractal](/img/mandelbrot.png?raw=true)

## What is a fractals?
Fractal is an abstract mathematical object, like a curve or a surface, which pattern
remains the same at every scale.

we can find some fractal examples in nature, like tree branches.

![example_tree](/img/example.png?raw=true)

we can see that the patern remains quiet the same even tho we zoomed in.

In math there is a lot of fractals, Mandelbrot for example is the most famous.

We can generate it from the recursive call of this function:

### ``` Zn+1 = Zn + c //Z(0) = 0```

Z and C are complex numbers. [complex numbers](https://en.wikipedia.org/wiki/Complex_number)

## To run the program:

### For the mandatory part:
```bash
git clone https://github.com/Hek3er/Fract-ol.git
cd Fract-ol && make
```

```
To use type: ./fractol [FRACTAL]
Mandelbrot: ./fractal mandelbrot
Julia: ./fractol julia [r] [i]

Press:
[+]: To increase iterations
[-]: To decrease iterarions
[SCROLL_UP]: To zoom in
[SCROLL_DOWN]: To zoom out
```
### For Bonus Part:
```bash
git clone https://github.com/Hek3er/Fract-ol.git
cd Fract-ol && make bonus
```

```
To use type: ./fractol_bonus [FRACTAL]
Mandelbrot: ./fractal_bonus mandelbrot
Julia: ./fractol_bonus julia [r] [i]
Burningship: ./fractal_bonus burningship

Press:
[C]: To change the color
[+]: To increase iterations
[-]: To decrease iterarions
[SCROLL_UP]: To zoom in
[SCROLL_DOWN]: To zoom out
[← ↕ →]: To move the fractal
```
**In this part The zoom follows the mouse position.**

## Resources:

[**Minilibx Docs**](https://harm-smits.github.io/42docs/libs/minilibx) **Documentation of Minilibx library.**

[**Man Minilibx**](https://qst0.github.io/ft_libgfx/man_mlx.html) **Man of Minilibx.**

[**Understand Mandelbrot**](https://www.youtube.com/watch?v=FFftmWSzgmk&t=426s) **Great video to understand mandelbrot and the concept of fractals.**

[**Geogebra**](geogebra.org/m/mfewjrek) **Play with mandelbrot in a graph.**

[**Oceano**](https://youtu.be/ANLW1zYbLcs?feature=shared) **Great video by Oceano of implementaion of fractals using Minilibx**

