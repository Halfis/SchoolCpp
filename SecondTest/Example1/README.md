# Case and Repository Management System

This C++ repository implements a system for managing cases within a repository. The program defines an abstract class for cases and concrete classes for specific case types such as BrickCase, TubeCase, and PrismCase. Additionally, it introduces a Repository class to handle the storage and management of these cases.

## Table of Contents

- [Class Overview](#class-overview)
- [Exceptions](#exceptions)
- [Folder Structure](#folder-structure)

## Class Overview

### Case

- Abstract class representing a generic case.
- Contains a text label, a numerical color, and a static method for counting the number of cases.
- Provides a pure virtual method `getCapacity()` for computing the capacity (volume) of a case.

### BrickCase

- Inherits from Case.
- Represents a cuboid case with length, width, and height.
- Overrides `getCapacity()` to calculate the volume of a cuboid.

### TubeCase

- Inherits from Case.
- Represents a cylindrical case with base radius and height.
- Overrides `getCapacity()` to calculate the volume of a cylinder.

### PrismCase

- Inherits from Case.
- Represents a regular triangular prism with base side length and height.
- Overrides `getCapacity()` to calculate the volume of a triangular prism.

### Repository

- Manages a dynamic list of cases with a description, a total capacity, and free space.
- Provides methods to add and remove cases, check the summary volume, and more.
- Overloads the indexing operator (`[]`) for direct access to items in the repository list.
- Overloads the shift-left operator (`<<`) for printing repository details.

## Exceptions

### CapacityError

- Thrown when attempting to add a case exceeds the total capacity of the repository.

### NameError

- Thrown when attempting to remove a case by label, but the case does not exist.

### IndexError

- Thrown when attempting to access a case at an invalid index.

## Folder Structure

- [README.md](./Example1/README.md): Description of the project, requirements, and instructions.
- [main.cpp](./Example1/main.cpp): Main program to test the Repository and Case classes.
