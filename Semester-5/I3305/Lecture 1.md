# Graphical User Interface - Week 1

## Introduction to Software Architecture and Design Patterns

### Software Architecture

- Architecture: join both art and science to create solutions
- Software Architecture: Focuses more high-level structure and organization of sofwtare system
- Non functional Requirements affect Software Architecture
- It's description of the **subsystems** and components of a **software system** and the relationship between them.

#### Component

A  part of a software system

#### Subsystem

A group of components connected together to perform a functionality

#### Architecture Style

Refers to a recurring solution or deisgn approach to solve common problems in software. It provides a set of predefined subsystems, etc...

#### Layer

- They are used to structure an application that can be decomposed into groups of subtasks
- Layer J provides services used by Layer J + 1 and delegates subtasks to Layer J - 1

An Example


#### Package Decomposition

seperate code into packages based on functionality

An Example

#### Layer Core

- Contain business logic classes...
- Use of singleton design pattern...
    - Singleton patterns is a pattern that ensures a class has one instance, and provide a global point of access to it