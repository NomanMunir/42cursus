# Parsing
[*] Check the file extension is .cub
[*] Map has NO, SO, WE, EA texture with proper extension .xpm
[*] Ceiling and floor have RGB color within 0 and 255
[*] Only 0 for Empty Areas, 1 for Walls, N, S, E or W for user's starting direction in map
[*] There are multiple textures for the same wall (north wall texture).
[*] replace tabs to 4 spaces.
[*] No more that one player
[*] Non-rectangle map must be operable
[*] map must be closed/surrounded by walls
[*] Except map content, each type of element can be separated by one or more empty line
[*] Map content has to be the last element.
[*] Except for the map, each type of information from an element can be separated
    by one or more space
[*] The map must be parsed as it looks in the file. Spaces are a valid part of the
    as long as it respects the rules of the map.
    map and are up to you to handle. You must be able to parse any kind of map,
[ ] Resolution bigger then the screen.
[*] F 55 ,, 112  ,,55 ,, 1 12,,
# Ray Casting



# Movement
[*] left and right arrow keys to look left and right 
[*] The W, A, S, and D keys to move
[*] ESC must close the window and quit the program cleanly.
[*] red cross on the window’s frame must close the window and quit the program cleanly.
[*] The use of images of the minilibX is strongly recommended.

# Start
Based on the viewing angle, subtract 30 degrees (half of the FOV).
Starting from column 0:
[*] Cast a ray.
[*] Trace the ray until it hits a wall.
[*] Record the distance to the wall (the distance is equal to the length of the ray).
[*] Add the angle increment so that the ray moves to the right (we know from Figure 10 that the value of the angle increment is 60/320 degrees).
[*] Repeat step 2 and 3 for each subsequent column until all 320 rays are cast.

[*] Crazy ray
[*] Intersection
[*] Short Walls
[*] getting in the wall
[*] TILE and TILE_3D
[*] change put_pixel
[*] too much leak. fix it
[ ] track for memory leak
[*] tab to spaces are still not good.

[ ] Static function.