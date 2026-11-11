# C++ Playlist Manager (Singly Linked List)

A robust console-based Music Playlist application built in C++ leveraging **Singly Linked Lists** to demonstrate Object-Oriented Programming (OOP) concepts, efficient dynamic memory management, and data structure manipulation.

---

## 🎵 Features

* **Add Songs:** Inserts new songs at the end of the playlist while preventing duplicate entries.
* **Remove Songs:** Deletes songs dynamically (handles head, middle, and tail deletions) with safe memory cleanup (`delete`).
* **Display Playlist:** Shows the current list of songs with indexed numbering.
* **Repeat Song:** Searches for a specific song and repeats its playback a user-defined number of times.
* **Shuffle Play:** Selects and plays a random song using `rand()` and `srand(time(0))`.
* **Interactive Menu:** CLI menu using `cin` and `getline()` for seamless user interaction.

---

## 🛠️ Data Structure Overview

The project uses a custom **Singly Linked List** implementation:

* **Node Structure:**
  ```cpp
  struct Node {
      string songName;
      Node* next;
  };
