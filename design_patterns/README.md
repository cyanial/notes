# Notes on Design Patterns

- [Notes on Design Patterns](#notes-on-design-patterns)
  - [The SOLID Design Principes](#the-solid-design-principes)
    - [Single Responsibility Principle (SRP)](#single-responsibility-principle-srp)
    - [Open-Closed Principle (OCP)](#open-closed-principle-ocp)
    - [Liskov Substitution Principle (LSP)](#liskov-substitution-principle-lsp)
    - [Interface Segregation Principle (ISP)](#interface-segregation-principle-isp)
    - [Dependency Inversion Principle (DIP)](#dependency-inversion-principle-dip)
  - [Creational Patterns](#creational-patterns)
    - [Builder](#builder)
    - [Factories](#factories)
    - [Prototype](#prototype)

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

## Creational Patterns

### Builder

> The goal of the Builder pattern is to define a component dedicated entirely to piecewise construction of a complicated object or set of objects.

`Simple Builder` && `Fluent Builder`

### Factories

> Factory is different from Builder in that, with a Factory, you typically create an object in one go, whereas with Builder, you construct the object piecewise by providing information in parts.

`Factor Method` &&  `Factor`

With the `friend` features in C++, it may be no need to use `inner factory`.

### Prototype

> The prototype design pattern embodies the notion of deep copying of objects so that, instead of doing full initialization each time, you can take a premade object, copy it, fiddle it a little bit, and then use it independently of the original.