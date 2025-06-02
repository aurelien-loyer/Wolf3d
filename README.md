## 🔫 Wolf3d

_A retro 3D shooter inspired by Wolfenstein 3D set in a futuristic world, powered by CSFML._

---

## 🧠 Overview

**Wolf3d** is a first-person shooter with a retro aesthetic. It uses classic **raycasting** techniques to create a 3D illusion from a 2D map. The player navigates a futuristic environment, eliminating enemies and exploring levels inspired by *Wolfenstein 3D*.

---

## 🛠️ Requirements

### 📦 Installing CSFML

This game requires the **CSFML** library to build and run.

#### 🔧 On Ubuntu/Debian:

```bash
sudo apt update
sudo apt install libcsfml-dev
````

#### 🍏 On macOS (using Homebrew):

```bash
brew install csfml
```

#### 🪟 On Windows:

1. Download the CSFML SDK from [https://www.sfml-dev.org/download/csfml](https://www.sfml-dev.org/download/csfml)
2. Follow the setup instructions for your compiler (MinGW, Visual Studio, etc.)
3. Link against the following CSFML libraries during compilation:

   * `csfml-graphics`
   * `csfml-window`
   * `csfml-system`

---

## 🎮 Gameplay

* Use directional keys to navigate a **3D simulated maze**.
* Eliminate enemies to progress through levels.
* Enjoy a **futuristic retro** visual atmosphere.
* Gameplay inspired by **Wolfenstein 3D**: fast-paced exploration and survival.

---

## 🗺️ Map Format

The game requires a **map file** passed as an argument at launch. This file defines the level layout using a grid of characters.

### Sample map:

```
11111
10001
12001
10001
11111
```

### Legend:

* `1`: Wall
* `0`: Empty space (walkable area)
* `2`: Player spawn point (**only one allowed**)

> ⚠️ The map must be **rectangular** and **fully enclosed by walls** (`1`) to avoid rendering issues.

---

## ▶️ Running the Game

Make sure the binary is compiled, then launch the game with a map file as argument:

```bash
./wolf3d map.txt
```

---

## 👨‍💻 Authors

* Aurélien Loyer
* Arthur Girardin-Calbe
* Théo Futol

---

## 📄 License

This project is open source. See the `LICENSE` file for details.

---

> Made with ❤️ and raycasting.
