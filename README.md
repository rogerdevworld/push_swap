*This project has been created as part of the 42 curriculum.*

# Push_swap - Record-Breaking Turk Algorithm Implementation

## Description
**push_swap** is an algorithmic project from 42 that challenges us to sort a stack of integers using a restricted set of instructions with the lowest possible number of operations. 

This repository implements an ultra-optimized version of the **Turk Algorithm** combined with advanced mathematical enhancements:
- **Longest Increasing Subsequence (LIS):** Keeps optimal anchor elements untouched in Stack A.
- **Chunk Pre-sorting with Lookahead (`rr`):** Intentionally groups elements into spatial bands during the $A \to B$ transfer.
- **4-Route Greedy Cost Evaluation:** Dynamically calculates and selects the absolute minimum instruction cost among parallel (`rr`, `rrr`) and crossed (`ra + rrb`, `rra + rb`) rotations during the $B \to A$ return.

---

## Instructions & Compilation

### Compilation
To compile the project and generate the `push_swap` binary, run:
```bash
make
```

### Execution
Run the program with a list of integers or a single quoted string:
```bash
./push_swap 4 67 3 87 23
# or
./push_swap "4 67 3 87 23"
```

### Cleaning
Remove object files:
```bash
make clean
```
Remove object files and binaries:
```bash
make fclean
```
Rebuild everything:
```bash
make re
```

---

## Algorithm Architecture (The Turk Strategy & Optimizations)

1. **Ranking and Normalization:** 
   Values are mapped to discrete ordinal ranks ($0$ to $N-1$) to simplify relative distance comparisons without altering the numerical integrity.
2. **LIS Identification:** 
   An advanced circular sequence analysis identifies the longest increasing chain. These elements remain safely in Stack A, drastically reducing unnecessary movements.
3. **Chunk Partitioning ($A \to B$):** 
   Non-LIS elements are pushed into Stack B across controlled quartile bands, leveraging `rr` lookaheads whenever consecutive elements qualify for simultaneous rotation.
4. **Greedy Cost Analysis ($B \to A$):** 
   Every node in Stack B evaluates its target position in Stack A and computes the exact cost across 4 distinct rotational paths, executing the cheapest one.

---

## Bonus Section (The Checker)

*(If applicable in your local repository structure)*
The bonus part implements a `checker` program that reads instructions from the standard input and verifies whether they successfully sort Stack A. 

All operations (`sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`) share the core double-linked list modular architecture, accepting a boolean flag (`print`) to execute silently during internal validation or output to `stdout` during standard usage.

---

## Resources & AI Assistance
- **Methodology Reference:** The mechanical/Turk algorithm concepts popularized within the 42 student community.
- **AI Collaboration:** Used as an architectural coach and algorithmic sparring partner to design the LIS circular mapping, 4-route cost mathematical models, and the modular Norm-compliant directory structure.