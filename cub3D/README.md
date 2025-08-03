# cub3D - 3D Raycasting Engine

## 📖 Description

cub3D is a 3D graphical project inspired by the famous Wolfenstein 3D game. Using raycasting techniques, you create a dynamic view inside a maze where you can move around and explore. This project teaches 3D graphics programming, mathematical projections, and advanced graphics concepts.

## 🎯 Objectives

- Understand raycasting and 3D projection algorithms
- Learn advanced graphics programming techniques
- Master mathematical concepts for 3D rendering
- Practice file parsing for game configuration
- Implement smooth player movement and rotation

## 🗺 Map File Format (.cub)

### Configuration Elements
```
NO ./assets/textures/north.xpm
SO ./assets/textures/south.xpm
WE ./assets/textures/west.xpm
EA ./assets/textures/east.xpm

F 220,100,0
C 225,225,225

        1111111111111111111111111
        1000000000110000000000001
        1011000001110000000000001
        1001000000000000000000001
111111111011000001110000000000001
100000000011000001110111111111111
11110111111111011100000010001
11110111111111011101010010001
11000000110101011100000010001
10000000000000001100000010001
10000000000000001101010010001
11000001110101011111011110N0111
11110111 1110101 101111010001
11111111 1111111 111111111111
```

### Map Components
- `NO`, `SO`, `WE`, `EA` - Texture paths for each wall direction
- `F` - Floor color (R,G,B format)
- `C` - Ceiling color (R,G,B format)
- `1` - Wall
- `0` - Empty space (floor)
- `N`, `S`, `E`, `W` - Player starting position and orientation

### Map Requirements
- **Closed**: Map must be surrounded by walls
- **Valid Characters**: Only `0`, `1`, `N`, `S`, `E`, `W`, and spaces
- **Single Player**: Exactly one player starting position
- **Rectangular**: Map must be properly formatted
- **Valid Path**: Player must be able to move within the map

## 🔍 Raycasting Algorithm

### Core Concept
Raycasting creates a 3D perspective by casting rays from the player's position and calculating wall distances to determine wall heights on screen.

### Algorithm Steps
1. **For each screen column**:
   - Cast a ray from player position
   - Calculate ray direction based on player orientation and column
   - Use DDA (Digital Differential Analyzer) to find wall intersections
   - Calculate perpendicular distance to avoid fisheye effect
   - Determine wall height based on distance
   - Render the wall column with appropriate texture

## 🎮 Controls

### Movement Controls
| Key | Action |
|-----|--------|
| W | Move Forward |
| S | Move Backward |
| A | Strafe Left |
| D | Strafe Right |
| ← | Rotate Left |
| → | Rotate Right |
| ESC | Exit Game |

## 🛠 Compilation

```bash
make        # Compile cub3D
make clean  # Remove object files
make fclean # Remove object files and executable
make re     # Recompile everything
```

## 📋 Usage

```bash
# Run cub3D with a map file
./cub3D maps/valid_map.cub
```

## 📏 Technical Requirements

- **Language**: C
- **Norm**: 42 Coding Standard
- **Graphics**: MiniLibX library
- **Math**: Mathematical functions for trigonometry
- **Memory**: No memory leaks allowed
- **Performance**: Smooth rendering at reasonable frame rates

## 💡 Key Learning Points

1. **3D Mathematics**: Understanding 3D projection and coordinate systems
2. **Raycasting**: Implementing efficient 3D rendering algorithms
3. **Graphics Optimization**: Performance considerations for real-time rendering
4. **File Parsing**: Complex configuration file handling
5. **Mathematical Concepts**: Trigonometry, linear algebra, vector operations
6. **Game Development**: Basic game loop and input handling

---

*This project provides a comprehensive introduction to 3D graphics programming and prepares you for advanced computer graphics and game development.*