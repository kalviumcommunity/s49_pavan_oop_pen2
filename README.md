# SRP C++ Example

This C++ program demonstrates the implementation of the **Single Responsibility Principle (SRP)**.

## Key Concepts:
- **Single Responsibility Principle (SRP)**: Every class should have only one reason to change. 
  - `Item` class holds the shared properties for all items.
  - `Barrel` and `Pen` classes focus on their specific item responsibilities.
  - `BarrelManager` and `PenManager` classes are responsible for creating barrels and pens, respectively.

