# 🎮 Cub3D

A raycasting game engine inspired by Wolfenstein 3D.

## 🎯 Features

### Map Elements
- `1` - Wall
- `0` - Empty space
- `N/S/E/W` - Player start position and orientation
- Valid maps must be closed/surrounded by walls

### Graphics
- Textured walls (North, South, East, West)
- Floor and ceiling colors
- Minimap display
- Smooth wall collisions
- Different wall textures based on orientation

### Controls
- `W/A/S/D` - Movement
- `←/→` - Camera rotation
- `ESC` - Exit game

## 🗺️ Map Format (.cub)
```
NO ./path_to_north_texture.xpm
SO ./path_to_south_texture.xpm
WE ./path_to_west_texture.xpm
EA ./path_to_east_texture.xpm

F 220,100,0
C 225,30,0

        1111111111111
        1000000000001
        1100000000001
        1000000000001
111111111000000000001
100000000000000000001
10000000000000N000001
10000000000000000001
10000000000000000001
10000000000000000001
10000000000000000001
11111111111111111111
```

## 🚀 Installation

```bash
git clone https://github.com/fsantos23/cub3d.git
cd cub3d
make
```

## 📋 Usage

```bash
./cub3D maps/basic.cub
```

## 🎨 Raycasting Features

- Digital Differential Analysis (DDA) algorithm
- Texture mapping
- Distance calculations
- Wall height determination
- Fish-eye effect correction
- Field of view management

## ⚠️ Error Handling

- Invalid map configuration
- Missing textures
- Invalid colors
- Memory allocation
- MLX errors
- File operations

## 🧪 Testing

```bash
# Basic map
./cub3D maps/basic.cub

# Memory check
valgrind ./cub3D maps/basic.cub
```

## ⭐ Show your support

Give a ⭐️ if this project helped you!
