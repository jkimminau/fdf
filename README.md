# fdf
If you're wondering what the premise of this project is, why it's structured like this, or what 42 is, go here and read: https://www.42.us.org/

So, you're a relatively new student at 42, probably just completed get_next_line or printf, and you're looking at this project to figure out if the graphics branch is as hard as it seems at first glance.

If you enjoy math even a tiny bit, it's not.

I've tried to structure this project as simply as I can for people to understand, because this project may be throwing a lot of new concepts at you, depending on your past experience. Basically, we initialize a struct, parse a `.fdf` file, and then calculate how our points translate from 3D to 2D.

(Note: the method I use for 3D => 2D translation is not very clean, and if you're modeling your project after this one, I recommend replacing that method in `draw.c` with [matrix multiplication](https://en.wikipedia.org/wiki/Orthographic_projection).

Feel free to download it, run it, change any of the code. However, **do not** try to turn this project in as your own.

Also feel free to email me at thepistochini@gmail.com with any questions, suggestions, etc.
