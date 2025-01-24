# So Long - A Top-Down 2D Game

## Overview
"So Long" is a 2D top-down game where the player must collect all collectibles on the map and escape through the exit. The game is designed with a simple interface and is built using MiniLibX for graphical rendering.

## Features

### Game Mechanics
- **Goal**: Collect every collectible (C) on the map and escape through the exit (E).
- **Player Movement**: Move the main character using the `W`, `A`, `S`, and `D` keys (or `Z`, `Q`, `S`, `D` or arrow keys, as preferred).
- **Directional Movement**: Navigate in four directions (up, down, left, right).
- **Movement Restrictions**: Walls (`1`) block movement.
- **Movement Counter**: Each move increments and displays the movement count in the shell.

### Graphics
- **2D View**: Display the game map in a top-down perspective.
- **Smooth Window Management**: Minimize, switch, or close the window without disruptions.
- **Exit Handling**:
  - Press `ESC` to quit the game cleanly.
  - Click the window's close button to exit cleanly.
- **MiniLibX Integration**: All graphical elements are rendered using MiniLibX.

### Map Requirements
- **Components**: The map consists of walls (`1`), free spaces (`0`), collectibles (`C`), a player starting position (`P`), and an exit (`E`).
- **Valid Map Criteria**:
  - Must contain one starting position (`P`).
  - Must contain at least one collectible (`C`).
  - Must have exactly one exit (`E`).
  - Must be rectangular.
  - Must be fully enclosed by walls (`1`).
  - Must have a valid path connecting the player to all collectibles and the exit.
- **Invalid Maps**: If the map is misconfigured, the program will exit cleanly with an error message.

## Example Maps
### Simple Map
```
1111111111111
10010000000C1
1000011111001
1P0011E000001
1111111111111
```

### Minimal Map
```
1111111111111111111111111111111111
1E0000000000000C00000C000000000001
1010010100100000101001000000010101
1010010010101010001001000000010101
1P0000000C00C0000000000000000000C1
1111111111111111111111111111111111
```

## Controls
- **Movement**:
  - `W`/`Z`/Up Arrow: Move Up
  - `A`/`Q`/Left Arrow: Move Left
  - `S`/Down Arrow: Move Down
  - `D`/Right Arrow: Move Right
- **Exit**:
  - Press `ESC` to quit.
  - Click the window's close button to exit.

## File Format
- Maps are stored in `.ber` files.
- Each `.ber` file must adhere to the rules specified in the "Map Requirements" section.

## Dependencies
- **MiniLibX**: Required for graphical rendering.
- **Make**: To compile the program.

## Installation and Usage
1. Clone the repository.
2. Compile the program using the `Makefile`:
   ```bash
   make
   ```
3. Run the game by providing a `.ber` map file:
   ```bash
   ./so_long map.ber
   ```
