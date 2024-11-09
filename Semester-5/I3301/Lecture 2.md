# Software Engineering

## Lecture 2 (Week 1) - Software Engineering From 20,000 Feet

### Steps/Tasks in Software Engineering

#### Requirements Gathering

- Figure out the requirements
- What customer wants and needs
- Can be time consuming depending on how defined the needs are
- In any project, try to identify the customer and interact with them as much as possible so you design a suitable application for them
- After determining the wants and needs, create **Requirement Documents**
  - tells the **customer** what they will be **getting**
  - tells the **project members** what they will be building
- Reffer to requirements to check for directions
- Changes always happen and requirements change often

#### High-Level Design

- Make decisions about
  - **Platform:** (Desktop, Mobile, etc..)
  - **Data Design:** (direct access, 2-tier, 3-tier)
  - **Interfaces:** with other systems (example external purshasing systems)
- include information about the **project architecture** at high leve
  
#### Low-Level Design

- After breaking project into pieces with high-level design
- Say how every piece will work
- Doesn't need **every last detail**, just enough guidance for devs

#### Development

- Programmer's job
- Programmer continue refining low-level design until they know how to implement in code
- write unit tests and try to remove bugs

#### Testing

- Testing **your** code is hard
- First devs test their own code, then testers who didn't write it test it
- Do **Unit Test** to test the feature alone, then **Integration Test** to see how it functions with other feature and if it broke anything
- Bug fixes can create new bugs and the longer a bug exists in code the harder it is to fix

#### Deployment

- can be difficult, time-consuming, and expensive.
- so many needs(new network, new computers, trainings, so much nonsense that's unpredictable)

#### Maintenance

- As soon as you release users will find bugs
- Users might also like to add new features immediately
  
#### Wrap-up

- After project examination
- Evaluate project and see what went wrong and right
- Decide how to irpove for feature