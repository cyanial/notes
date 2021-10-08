# Notes on Design Patterns

- [Notes on Design Patterns](#notes-on-design-patterns)
  - [The SOLID Design Principes](#the-solid-design-principes)
    - [Single Responsibility Principle (SRP)](#single-responsibility-principle-srp)
    - [Open-Closed Principle (OCP)](#open-closed-principle-ocp)
    - [Liskov Substitution Principle (LSP)](#liskov-substitution-principle-lsp)
    - [Interface Segregation Principle (ISP)](#interface-segregation-principle-isp)
    - [Dependency Inversion Principle (DIP)](#dependency-inversion-principle-dip)

## The SOLID Design Principes

### Single Responsibility Principle (SRP)

> Each class has only one responsibility, and therefore has only one reason to change.

### Open-Closed Principle (OCP)

> Open for extension, closed for modification. 

### Liskov Substitution Principle (LSP)

> If an interface takes an object of type `Parent`, it should equally take an object of type `Child` without anything breaking.

### Interface Segregation Principle (ISP)

> Split up interfaces so that implementors can pick and choose depending on their needs.

### Dependency Inversion Principle (DIP)

> A. High-level modules should not depend on low-level modules. Both should depend on abstractions.
> B. Abstractions should not depend on details. Details should depend on absctractions.