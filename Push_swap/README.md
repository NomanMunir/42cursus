# Push_swap - Sorting Algorithm

## 📖 Description

Push_swap is a sorting algorithm project where you must sort data on a stack with a limited set of instructions, using the lowest possible number of operations. This project teaches algorithm optimization, complexity analysis, and efficient problem-solving strategies.

## 🎯 Objectives

- Implement efficient sorting algorithms
- Understand stack data structures and operations
- Optimize for minimal number of operations
- Analyze algorithm complexity and performance
- Learn about different sorting strategies and when to apply them

## 📚 The Problem

You have two stacks: **Stack A** and **Stack B**.
- Stack A contains random integers (no duplicates)
- Stack B is initially empty
- Goal: Sort Stack A in ascending order (smallest at top)
- Constraint: Use only the allowed operations

## 🔧 Allowed Operations

| Operation | Description |
|-----------|-------------|
| `sa` | Swap first 2 elements of stack A |
| `sb` | Swap first 2 elements of stack B |
| `ss` | Perform `sa` and `sb` simultaneously |
| `pa` | Push first element of B to top of A |
| `pb` | Push first element of A to top of B |
| `ra` | Rotate stack A up (first element becomes last) |
| `rb` | Rotate stack B up (first element becomes last) |
| `rr` | Perform `ra` and `rb` simultaneously |
| `rra` | Rotate stack A down (last element becomes first) |
| `rrb` | Rotate stack B down (last element becomes first) |
| `rrr` | Perform `rra` and `rrb` simultaneously |

## 🏗 Project Structure

```
Push_swap/
├── Makefile
├── push_swap.h              # Header file
├── main.c                   # Main program
├── parsing.c                # Input validation and parsing
├── init_stack.c             # Stack initialization
├── init_nodes.c             # Node setup and indexing
├── sorting.c                # Main sorting algorithms
├── errors.c                 # Error handling
├── utils.c                  # Utility functions
├── operations/              # Stack operations
│   ├── push.c              # pa, pb operations
│   ├── swap.c              # sa, sb, ss operations
│   ├── rotate.c            # ra, rb, rr operations
│   └── reverse_rotate.c    # rra, rrb, rrr operations
├── bonus_checker/           # Bonus: checker program
└── lib/
    └── libft/              # Custom library functions
```

## 🧮 Sorting Strategies

### Small Stack Sorting (2-5 elements)
- **2 elements**: `sa` if needed
- **3 elements**: Hardcoded optimal solution (max 2 operations)
- **4-5 elements**: Optimized small sorting algorithms

### Large Stack Sorting (100+ elements)
The project implements a **Turk Algorithm** inspired approach:

1. **Push to B**: Move elements to stack B strategically
2. **Calculate Costs**: For each element in B, calculate the cost to move it to its correct position in A
3. **Find Cheapest**: Select the element with the lowest move cost
4. **Execute Move**: Perform the calculated operations
5. **Repeat**: Until all elements are back in A, sorted

### Algorithm Details

#### Cost Calculation
For each element in stack B:
- Calculate rotations needed in stack A to position correctly
- Calculate rotations needed in stack B to bring element to top
- Consider using simultaneous operations (`rr`, `rrr`) to optimize
- Choose the path with minimum total operations

#### Optimization Techniques
- **Simultaneous Operations**: Use `rr`, `rrr`, `ss` when beneficial
- **Direction Choice**: Choose between rotate up or rotate down based on position
- **Target Finding**: Efficiently find the correct position for each element
- **Pre-sorting**: Strategic initial pushes to stack B

## 🛠 Compilation

```bash
make                    # Compile push_swap
make bonus             # Compile checker (bonus)
make clean             # Remove object files
make fclean            # Remove object files and executables
make re                # Recompile everything
```

## 📋 Usage

### Basic Usage
```bash
./push_swap 4 67 3 87 23    # Sort these numbers
./push_swap "4 67 3 87 23"  # Alternative format
```

### With Checker (Bonus)
```bash
# Generate operations and check if they sort correctly
./push_swap 4 67 3 87 23 | ./checker 4 67 3 87 23

# Manual operation testing
echo -e "pb\nra\npa" | ./checker 4 67 3 87 23
```

### Performance Testing
```bash
# Test with 100 random numbers
ARG=$(shuf -i 1-1000 -n 100 | tr '\n' ' '); ./push_swap $ARG | wc -l

# Test with 500 random numbers  
ARG=$(shuf -i 1-1000 -n 500 | tr '\n' ' '); ./push_swap $ARG | wc -l
```

## 📊 Performance Requirements

### Operation Count Limits
| Stack Size | Excellent | Good | Acceptable |
|------------|-----------|------|------------|
| 3 elements | ≤ 2 | ≤ 3 | No limit |
| 5 elements | ≤ 8 | ≤ 12 | No limit |
| 100 elements | ≤ 700 | ≤ 900 | ≤ 1300 |
| 500 elements | ≤ 5500 | ≤ 7000 | ≤ 11500 |

## 🧪 Testing

### Manual Testing
```bash
# Test small stacks
./push_swap 2 1 3
./push_swap 1 5 2 4 3

# Test edge cases
./push_swap 1               # Single element
./push_swap 1 2 3 4 5       # Already sorted
./push_swap 5 4 3 2 1       # Reverse sorted

# Test errors
./push_swap 1 2 2           # Duplicates
./push_swap abc             # Non-numeric
./push_swap 1 2147483648    # Overflow
```

### Automated Testing
```bash
# Generate and test multiple random stacks
for i in {1..100}; do
    ARG=$(shuf -i 1-100 -n 5 | tr '\n' ' ')
    RESULT=$(./push_swap $ARG | ./checker $ARG)
    if [ "$RESULT" != "OK" ]; then
        echo "Error with: $ARG"
    fi
done
```

## 📏 Technical Requirements

- **Language**: C
- **Norm**: 42 Coding Standard
- **External Functions**: `read`, `write`, `malloc`, `free`, `exit`
- **Memory**: No memory leaks allowed
- **Error Handling**: Must handle all invalid inputs gracefully
- **Integer Range**: Handle 32-bit signed integers

## 🎁 Bonus Features

### Checker Program
The bonus checker program:
- Reads the list of numbers to sort
- Reads operations from standard input
- Executes operations on the stack
- Outputs "OK" if sorted correctly, "KO" if not
- Outputs "Error" for invalid operations

```bash
# Checker usage examples
echo -e "sa\nrra\npb" | ./checker 3 2 1
./push_swap 3 2 1 | ./checker 3 2 1
```

## 💡 Key Learning Points

1. **Algorithm Design**: Creating efficient sorting strategies
2. **Complexity Analysis**: Understanding time and space complexity
3. **Optimization**: Minimizing operations through smart choices
4. **Data Structures**: Deep understanding of stack operations
5. **Problem Decomposition**: Breaking complex problems into smaller parts
6. **Performance Tuning**: Balancing different optimization approaches

## 🔗 Mathematical Concepts

- **Permutation Sorting**: Understanding different ways to arrange elements
- **Graph Theory**: Viewing sorting as finding shortest path
- **Greedy Algorithms**: Making locally optimal choices
- **Dynamic Programming**: Considering optimal subproblems

## ⚠️ Common Pitfalls

1. **Over-optimization**: Spending too much time optimizing small cases
2. **Memory Leaks**: Not freeing allocated memory on errors
3. **Edge Cases**: Not handling single elements or already sorted arrays
4. **Operation Order**: Incorrect implementation of stack operations
5. **Integer Overflow**: Not validating input ranges properly

---

*This project significantly enhances your algorithmic thinking and prepares you for more complex optimization challenges in advanced projects.*
