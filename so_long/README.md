# so_long - 2D Game

## 📖 Description

so_long is a 2D game project where you create a simple game using the MiniLibX graphics library. The player must collect all collectibles and reach the exit. This project introduces graphics programming, event handling, and game development concepts.

## 🎯 Objectives

- Learn graphics programming with MiniLibX
- Understand event-driven programming
- Practice game logic implementation
- Master window management and rendering
- Handle user input and game states

## 🎮 Game Mechanics

### Game Rules
1. **Objective**: Collect all collectibles (C) and reach the exit (E)
2. **Movement**: Player (P) moves with WASD or arrow keys
3. **Walls**: Solid barriers (1) that block movement
4. **Victory**: Game ends when all collectibles are collected and player reaches exit
5. **Move Counter**: Display number of moves in terminal

### Map Components
- `0` - Empty space (floor)
- `1` - Wall
- `C` - Collectible item
- `E` - Exit
- `P` - Player starting position

## 🏗 Project Structure

```
so_long/
├── Makefile
├── so_long.h               # Header file
├── so_long.c               # Main program
├── init_game.c             # Game initialization
├── create_map.c            # Map creation and parsing
├── validate_map.c          # Map validation
├── validate_path.c         # Path validation (flood fill)
├── events.c                # Event handling
├── move.c                  # Player movement logic
├── utils.c                 # Utility functions
├── error.c                 # Error handling
├── assets/                 # Game sprites
│   ├── player.xpm         # Player sprite
│   ├── wall.xpm           # Wall sprite
│   ├── collectable.xpm    # Collectible sprite
│   ├── exit.xpm           # Exit sprite
│   └── background.xpm     # Floor/background sprite
├── maps/                   # Game maps
│   ├── valid_map.ber      # Example valid map
│   ├── invalid_map.ber    # Example invalid map
│   └── test_maps/         # Additional test maps
├── get_next_line/          # File reading utility
├── libft/                  # Custom library
└── minilibx/              # Graphics library
```

## 🗺 Map Format

### Map File (.ber extension)
```
1111111111
1P001C0001
1000111001
1C001E0001
1111111111
```

### Map Requirements
- **Rectangular**: All rows must have the same length
- **Walls**: Map must be surrounded by walls (1)
- **Characters**: Only `0`, `1`, `C`, `E`, `P` allowed
- **Player**: Exactly one player starting position (P)
- **Exit**: Exactly one exit (E)
- **Collectibles**: At least one collectible (C)
- **Valid Path**: Must be possible to collect all items and reach exit

## 🛠 Implementation Features

### Graphics System
```c
typedef struct s_game
{
    void    *mlx;           // MiniLibX instance
    void    *window;        // Game window
    void    *img_player;    // Player sprite
    void    *img_wall;      // Wall sprite
    void    *img_collect;   // Collectible sprite
    void    *img_exit;      // Exit sprite
    void    *img_floor;     // Floor sprite
    char    **map;          // Game map
    int     map_width;      // Map dimensions
    int     map_height;
    int     player_x;       // Player position
    int     player_y;
    int     collectibles;   // Collectibles remaining
    int     moves;          // Move counter
} t_game;
```

### Rendering System
```c
void render_game(t_game *game)
{
    int x, y;
    
    for (y = 0; y < game->map_height; y++)
    {
        for (x = 0; x < game->map_width; x++)
        {
            // Render floor first
            mlx_put_image_to_window(game->mlx, game->window,
                game->img_floor, x * IMAGE_SIZE, y * IMAGE_SIZE);
            
            // Render map element
            if (game->map[y][x] == '1')
                mlx_put_image_to_window(game->mlx, game->window,
                    game->img_wall, x * IMAGE_SIZE, y * IMAGE_SIZE);
            // ... other elements
        }
    }
}
```

### Event Handling
```c
int handle_keypress(int keycode, t_game *game)
{
    if (keycode == ESC)
        close_game(game);
    else if (keycode == W || keycode == UP)
        move_player(game, 0, -1);
    else if (keycode == S || keycode == DOWN)
        move_player(game, 0, 1);
    else if (keycode == A || keycode == LEFT)
        move_player(game, -1, 0);
    else if (keycode == D || keycode == RIGHT)
        move_player(game, 1, 0);
    
    return (0);
}
```

## 🎮 Controls

| Key | Action |
|-----|--------|
| W / ↑ | Move Up |
| S / ↓ | Move Down |
| A / ← | Move Left |
| D / → | Move Right |
| ESC | Exit Game |
| ❌ (Window Close) | Exit Game |

## 🧪 Map Validation

### Validation Checks
1. **File Extension**: Must be `.ber`
2. **Rectangle Shape**: All rows same length
3. **Wall Border**: Completely surrounded by walls
4. **Character Count**: Exactly 1 player, 1 exit, ≥1 collectible
5. **Valid Characters**: Only `0`, `1`, `C`, `E`, `P`
6. **Path Validity**: Player can reach all collectibles and exit

### Flood Fill Algorithm
```c
void flood_fill(char **map, int x, int y, int *collectibles, int *exit_reachable)
{
    if (map[y][x] == '1' || map[y][x] == 'F')  // Wall or already visited
        return;
    
    if (map[y][x] == 'C')
        (*collectibles)++;
    if (map[y][x] == 'E')
        *exit_reachable = 1;
    
    map[y][x] = 'F';  // Mark as visited
    
    // Recursively check all 4 directions
    flood_fill(map, x + 1, y, collectibles, exit_reachable);
    flood_fill(map, x - 1, y, collectibles, exit_reachable);
    flood_fill(map, x, y + 1, collectibles, exit_reachable);
    flood_fill(map, x, y - 1, collectibles, exit_reachable);
}
```

## 🖼 Sprite Management

### Loading Sprites
```c
void load_sprites(t_game *game)
{
    int width, height;
    
    game->img_player = mlx_xpm_file_to_image(game->mlx, 
        P_PATH, &width, &height);
    game->img_wall = mlx_xpm_file_to_image(game->mlx, 
        W_PATH, &width, &height);
    game->img_collect = mlx_xpm_file_to_image(game->mlx, 
        C_PATH, &width, &height);
    game->img_exit = mlx_xpm_file_to_image(game->mlx, 
        E_PATH, &width, &height);
    game->img_floor = mlx_xpm_file_to_image(game->mlx, 
        S_PATH, &width, &height);
}
```

### Sprite Paths
```c
#define P_PATH "./assets/player.xpm"
#define W_PATH "./assets/wall.xpm"
#define C_PATH "./assets/collectable.xpm"
#define E_PATH "./assets/exit.xpm"
#define S_PATH "./assets/background.xpm"
```

## 🛠 Compilation

```bash
make        # Compile the game
make clean  # Remove object files
make fclean # Remove object files and executable
make re     # Recompile everything
```

## 📋 Usage

```bash
# Run the game with a map file
./so_long maps/valid_map.ber

# Test with different maps
./so_long maps/small_map.ber
./so_long maps/large_map.ber
```

## 🧪 Testing

### Valid Map Examples
```bash
# Simple 5x5 map
echo -e "11111\n1P0C1\n10001\n1C0E1\n11111" > test_simple.ber
./so_long test_simple.ber

# Larger map
echo -e "1111111111\n1P001C0001\n1000111001\n1C001E0001\n1111111111" > test_large.ber
./so_long test_large.ber
```

### Error Testing
```bash
# Invalid file extension
./so_long map.txt

# Invalid characters
echo -e "11111\n1P0X1\n10001\n1C0E1\n11111" > test_invalid.ber
./so_long test_invalid.ber

# No path to exit
echo -e "11111\n1P0C1\n11111\n1C0E1\n11111" > test_no_path.ber
./so_long test_no_path.ber
```

## 📏 Technical Requirements

- **Language**: C
- **Norm**: 42 Coding Standard
- **Graphics**: MiniLibX library
- **External Functions**: MiniLibX functions, `open`, `close`, `read`, `write`, `malloc`, `free`, `perror`, `strerror`, `exit`
- **Memory**: No memory leaks allowed
- **Window**: Must handle window close button and ESC key

## 💡 Key Learning Points

1. **Graphics Programming**: Understanding pixel-based rendering
2. **Event-Driven Programming**: Responding to user input
3. **Game Logic**: Implementing game rules and state management
4. **File Parsing**: Reading and validating map files
5. **Algorithm Implementation**: Flood fill for path validation
6. **Memory Management**: Handling multiple allocated resources

## 🎨 Customization Ideas

While maintaining core functionality, you can customize:
- **Sprites**: Create custom artwork for game elements
- **Animations**: Add sprite animations for movement
- **Sound Effects**: Add audio feedback (if allowed)
- **Visual Effects**: Particle effects, screen transitions
- **Additional Features**: Score system, timer, multiple levels

## ⚠️ Common Issues

1. **MiniLibX Setup**: Ensure library is properly installed
2. **File Paths**: Check sprite file paths are correct
3. **Memory Leaks**: Properly free all allocated memory
4. **Window Events**: Handle both ESC key and window close
5. **Map Validation**: Thoroughly test edge cases

---

*This project provides an excellent introduction to graphics programming and game development, combining technical skills with creative expression.*
