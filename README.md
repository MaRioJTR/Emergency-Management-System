# Emergency Management System

## Overview
This project is an **Emergency Management System** implemented in C++ with a graphical user interface (GUI) using the **Qt Framework**. The system manages emergency events, organizes them in a **Binary Search Tree (BST)** based on priority, and visualizes the tree structure. The program ensures that high-priority emergencies are placed on the right and low-priority emergencies on the left in the BST.

## Features
- **Emergency Management**: Add, view, and manage emergency events with priority and timestamp.
- **Binary Search Tree (BST)**:
  - High-priority nodes are placed on the right.
  - Low-priority nodes are placed on the left.
- **Visualization**: Graphical representation of the BST using Qt.
- **Priority Handling**:
  - Priority values are reversed only in the visualizer for better understanding.
  - Original priority values remain intact in the program logic.

## Technologies Used
- **C++**: Core programming language.
- **Qt Framework**: For GUI development and visualization.
- **CLion IDE**: Development environment.

## Installation
1. **Prerequisites**:
   - Install [Qt Framework](https://www.qt.io/download).
   - Install a C++ compiler (e.g., GCC or MSVC).
   - Install CLion IDE (optional but recommended).

2. **Clone the Repository**:
   ```bash
   git clone <repository-url>
   cd <repository-folder>
   ```

3. **Build the Project**:
   - Open the project in CLion or your preferred IDE.
   - Configure the Qt environment in the IDE.
   - Build the project.

4. **Run the Application**:
   - Execute the compiled binary or run the project from the IDE.

## Usage
1. Launch the application.
2. Use the GUI to:
   - Add emergency events with priority and timestamp.
   - View the BST structure in the visualizer.
3. The visualizer will display the BST with high-priority nodes on the right and low-priority nodes on the left.

## Code Structure
- `main.cpp`: Entry point of the application.
- `mainwindow.h` and `mainwindow.cpp`: Main GUI logic.
- `EmergencyBST.h` and `EmergencyBST.cpp`: Binary Search Tree implementation.
- `BSTVisualizationDialog.h` and `BSTVisualizationDialog.cpp`: Visualization logic for the BST.

## Priority Rules
- **Priority Mapping**:
  - High priority (e.g., 1) is placed on the right.
  - Low priority (e.g., 4) is placed on the left.
- **Visualization**:
  - Priority values are reversed only in the visualizer for clarity.

