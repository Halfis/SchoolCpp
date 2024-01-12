# Store and Box Management System

This repository contains a C++ implementation of a Store class managing different types of boxes. The program defines abstract classes for boxes and concrete classes for specific box types like BrickBox, TubeBox, and BubbleBox. It also implements a Store class to manage these boxes.

## Table of Contents

1. [Class Overview](#class-overview)
2. [Exceptions](#exceptions)
3. [Folder Structure](#folder-structure)

## Class Overview

### Box

- Abstract class representing a generic box.
- Contains a text label, a number, and a static method for counting the number of boxes.
- Provides a pure virtual method `getCapacity()` for computing the capacity (volume) of a box.

### BrickBox

- Inherits from Box.
- Represents a cuboid box with length, width, and height.
- Overrides `getCapacity()` to calculate the volume of a cuboid.

### TubeBox

- Inherits from Box.
- Represents a cylindrical box with base radius and height.
- Overrides `getCapacity()` to calculate the volume of a cylinder.

### BubbleBox

- Inherits from Box.
- Represents a hemispherical box with a radius.
- Overrides `getCapacity()` to calculate the volume of a hemisphere.

### Store

- Manages a dynamic list of boxes with a description and a total capacity.
- Provides methods to add and remove boxes, check the summary volume, and more.
- Overloads the indexing operator (`[]`) for direct access to items in the store list.
- Overloads the shift-left operator (`<<`) for printing store details.

## Exceptions

### CapacityError

- Thrown when attempting to add a box exceeds the total capacity of the store.

### IndexError

- Thrown when attempting to access a box at an invalid index.

### EmptyError

- Thrown when attempting to remove a box from an empty store.

## Folder Structure

- [README.md](#): Description of the project, requirements, and instructions.
- [main.cpp](#): Main program to test the Store and Box classes.
