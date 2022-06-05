# fancy-pathfinder
Visualize, bechmark and play with different pathfinding algorithms in a highly customizable grid layout.
![GAMEPLAY_GIF][gameplay_gif]

## About
This project aims to provide a _fancy_ graphical visualization for pathfinding algorithms while providing highly customizable case layout.
New commers to the field of A.I., particularly pathfinding problems, can use this application to help them with not only visualizing
how the algorithms work but also with identifying the strengths and weaknesses of each algorithm. This way one can know whe to use algorithm
X instead of algorithm Y.

Pathfinding problems are especially interesting in game developement. This application can help you understand how these algorithms work and how
different parameters affect their performance. 

## Description
This project provides a graphical grid layout on which each case can be either:
- __a wall__ : a wall case is a blocking case, the pathfinding algorithm cannot pass through such case.
- __NOT a wall__ : the pathfinding algorithm can pass through such case.

Depending on the chosen algorithm, its goal can be to find either:
- __shortest__ path to target case.
- __any__ path to target case.

The algorithm __cannot__ pass to a neighboring diagonal case. It __can only__ pass to adjacent neighboring cases as the picture below shows.
![NAVIGATION_CONSTRAINTS][navigation_constraints]

The cost of moving from one case to another adjacent case is __1__.

## Features
- case layout (__size__ and __walls placement__) is customizable. Currently only limited to square layouts.
- option for __random wall placement__ is provided in case the user doesn't want to place walls.
- user choses the __starting case__ and __target case__.
- user can chose between __numerous pathfinding algorithms__. Currently supported algorithms are:
  - DFS
  - BFS
  - A* (with __custom__ heuristic function)
 
- if __benchmark option__ is enabled, stats about the algorithm are shown once execution ends.
In order for benchmarking to be accurate, this option disables a lot of other features such as: speed of execution, graphical updates, etc...
- if becnhmark option is disabled, the __speed__ of execution of the chosen algorithm is modifiable.
This is helpful to graphically show the step-by-step progress of the algorithm.

## How to install
- install SDL2.0 (see [official webpage](https://www.libsdl.org/download-2.0.php) for the how-to)
- run these commands in root directory:

        make pathfinder
        ./pathfinder

## Contributions
Any contribution are more than welcome! Add an issue or open a pull request 🙂.

## License
MIT. See [LICENSE](https://github.com/walcht/fancy-pathfinder/blob/master/LICENSE.txt) for details.

[navigation_constraints]: images/navigation_constraints.png
[gameplay_gif]: gifs/gameplay_gif.gif
