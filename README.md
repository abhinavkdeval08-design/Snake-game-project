# 🐍 Classic Snake Game - C Implementation

### *A Second Semester DSA Project @ IIIT Kalyani*
**We engineered** this high-performance terminal game to showcase advanced memory management and real-time logic handling using the C language.

---

## 👥 The Development Crew
| Developer | GitHub Handle | Key Contributions |
| :--- | :--- | :--- |
| **Abhinav Deval** | [@abhinavkdeval08-design](https://github.com/abhinavkdeval08-design) | **Logic & Optimization:** We implemented `clearSnake` for memory leak prevention, ANSI flicker reduction, and High-Score logic. |
| **Ritesh Singh** | [@riteshsingh03-dot](https://github.com/riteshsingh03-dot) | **UI & Mechanics:** We developed the Pause/Restart features, fruit collision fixes, and the main menu interface. |
| **Pawan Asati** | [@Pawan-official](https://github.com/Pawan-official) | **Game Dynamics:** We programmed the progressive speed logic, boundary mechanics, and managed the build/executable updates. |

---

## 🛠 Tech Stack & Applied Data Structures
**We utilized** core Computer Science concepts to ensure efficiency:

* **Linked Lists:** We represented the snake body as a dynamic linked list of `struct Node`.
* **Queue Operations:** We handled movement by inserting at the head and deleting at the tail (FIFO).
* **Memory Management:** We used `malloc` and `free` to manage nodes dynamically, ensuring the game stays lightweight.
* **Libraries:** * `<windows.h>`: For frame-rate (`Sleep`) and `system("cls")` alternatives.
    * `<conio.h>`: For non-blocking input handling (`kbhit`, `getch`).
    * `<time.h>`: For seeding random fruit positions.

---

## 🚀 Engineering Solutions We Delivered

### 1. Zero-Flicker Rendering
Standard screen clearing causes annoying flickering. **We solved this** by implementing ANSI Escape Codes (`\033[H\033[J`). This moves the cursor to the top-left corner instead of clearing the buffer, providing a smooth visual experience.

### 2. Robust Memory Management
As the snake grows, memory management becomes critical. **We built the `clearSnake` function** to ensure all dynamically allocated nodes are properly freed when the game resets or exits, preventing memory leaks.



### 3. Progressive Difficulty & Momentum
To keep the game challenging, **we programmed a dynamic speed-scaling algorithm**. As your score increases, the `Sleep()` delay decreases. We also implemented an `enum`-based direction system to ensure smooth, continuous momentum.

### 4. Smart Fruit Spawning
**We engineered an `isOnSnake()` check** that runs every time a fruit spawns. If the random coordinates land on the snake's body, the algorithm automatically re-calculates a new position within the boundary.

---

## ✨ Features We Integrated
* 🎮 **Pause & Restart:** Instant UI controls for better gameplay management.
* 🏆 **High-Score System:** Persistent score tracking during the session.
* 🍎 **Fruit Variants:** Multiple fruit types managed via efficient array mapping.
* 🖼️ **Border Aesthetics:** Custom grid design using `|`, `+`, and `--` characters.

---

## 🖥️ Getting Started
1.  **Clone the Repo:**
    ```bash
    git clone [https://github.com/abhinavkdeval08-design/Snake-Game.git](https://github.com/abhinavkdeval08-design/Snake-Game.git)
    ```
2.  **Compile the Code:**
    ```bash
    gcc snake_game.c -o snake_game.exe
    ```
3.  **Run and Play:**
    ```bash
    ./snake_game.exe
    ```

---

## 📝 Final Reflections
This project was a collaborative effort to master Data Structures in C. **We successfully refactored** the codebase multiple times to improve readability and performance, leading to the final version you see here.

**Happy Coding! ^_^**
