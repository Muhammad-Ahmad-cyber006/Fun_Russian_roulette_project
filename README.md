# 🎲 Fun Russian Roulette (C Project)

> “One bullet. Zero regrets. Infinite loops (maybe).”

## 💻 About This Project

This is a dark-humor-themed **Russian Roulette** game written in **pure C**. It's made for fun, chaos, and some learning too. Built completely on **Windows**, so... if you're on Linux or Mac, sorry — this will break harder than your GPA during finals.

## 🧠 Features

- 🧍‍♂️ **Solo mode** – Just you and a deadly spinner
- 👥 **Multiplayer mode** – Play with friends (if you still have any after playing)
- 🎯 **Training mode** – Practice dying, professionally
- 🏆 **Leaderboard** – So your shame is recorded permanently
- 🎭 **Humor** – Because if you're gonna die, might as well laugh

## 📁 File Structure

```
.
├── main.c                   # Game driver
├── design.c / design.h      # UI design and console effects
├── gamemodes.c / gamemodes.h # Game modes logic
├── input.c / input.h        # Input handling and validation
├── training.c / training.h  # Training mode logic
├── roulette_leaderboard.txt # Persistent leaderboard (pure file I/O magic)
```

## ⚙️ How to Compile (Windows Only)

If you’re using GCC:

```bash
gcc main.c design.c gamemodes.c input.c training.c -o russian_roulette
```

Then run it with:

```bash
./russian_roulette
```

Or just double-click the `.exe` file because you're on Windows anyway.

### ❗ Important: Windows-Only Stuff Used

This project uses some built-in Windows-only functions, so it won’t work on Linux/macOS without changes:

| Function         | Why It's Here                      |
|------------------|------------------------------------|
| `Sleep(ms)`      | To delay stuff                     |
| `system("cls")`  | Clears the screen (Windows only)   |
| `_kbhit()`       | Detects keypress without blocking  |
| `getch()`        | Gets a single char input           |

## 😂 Sample Messages from the Game

- “You are not Death_Himself. You are barely Alive_Probably.”
- “Even the code is judging you right now.”
- “Pro tip: Luck is just probability with a bad attitude.”

## 🧠 What I Learned

- Splitting C code using `.c` and `.h` files
- Handling character arrays and user input
- Using file I/O for a basic leaderboard
- Making console games with a touch of humor



## 🚧 Features I Promised During a Sleep-Deprived Coding Session

- 🐧 **Add full Linux support** — Because death shouldn't be exclusive to Windows. Terminal users deserve their doom in style too. Bonus points if it runs on Arch with a single compile command.
- 🔊 **Add gun sounds** — Maybe make the terminal whisper "BANG!" or play a .wav file if we get fancy (or unhinged).
- 🧠 **Smarter bullets (AI mode)** — What if the gun had a mind of its own? Could it spare you? Could it hunt you? Could it ask for healthcare benefits?
- 🖼️ **ASCII GUI** — Explosions made of symbols, a revolver drawn with `#`, maybe even dramatic slow-motion death messages.
- 🪦 **Gravestone Generator** — Automatically generate an epitaph when you die: “Here lies a brave fool who trusted a C program.”
- 🌐 **Online mode??** — Russian Roulette over the internet. What could go wrong? (Everything.)



## 📝 License

No official license yet. You can play with the code, modify it, and vibe with it. Just don’t sell it as your own without giving credit (that’s just lame).

---

Made for fun and learning. If you died in-game, don’t worry — it’s just C.
