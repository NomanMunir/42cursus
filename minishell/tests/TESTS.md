# Test Cases for Minishell

This directory contains comprehensive test cases for the Minishell project, organized into different categories for thorough validation.

## Test Structure

```
tests/
├── test_runner.sh      # Main test runner with comprehensive categories
├── unit_tests.sh       # Focused unit tests for edge cases  
├── stress_tests.sh     # Performance and stress testing
├── logs/              # Test execution logs (created during runs)
└── temp/              # Temporary files for testing (created during runs)
```

## Test Categories

### 1. Main Test Runner (`test_runner.sh`)

The primary test suite covering all essential functionality:

- **Basic Commands**: Echo, PWD, Exit
- **Built-ins**: CD, Export, Unset, Env
- **Pipes**: Simple and complex pipe operations
- **Redirections**: Input, output, append, here-documents
- **Environment Variables**: Variable expansion and manipulation
- **Quote Handling**: Single quotes, double quotes, mixed quotes
- **Error Handling**: Invalid commands, syntax errors, file errors
- **Signal Handling**: Ctrl+C, Ctrl+D, Ctrl+\ behavior
- **Memory Management**: Valgrind leak detection
- **Performance**: Command execution speed tests
- **Bash Compatibility**: Direct comparison with bash behavior

### 2. Unit Tests (`unit_tests.sh`)

Focused tests for edge cases and corner scenarios:

- **Parsing Edge Cases**: Empty commands, whitespace handling
- **Quote Edge Cases**: Nested quotes, unclosed quotes
- **Variable Edge Cases**: Special characters, concatenation, exit status
- **Pipe Edge Cases**: Multiple pipes, empty commands
- **Redirection Edge Cases**: Multiple redirections, permissions
- **Built-in Edge Cases**: Invalid arguments, special behaviors
- **Error Recovery**: Continuation after errors

### 3. Stress Tests (`stress_tests.sh`)

Performance and stability testing under extreme conditions:

- **Large Commands**: 1000+ word commands, long pipe chains
- **Many Variables**: 1000+ environment variables
- **Deep Nesting**: Complex quote and command nesting
- **Rapid Execution**: High-frequency command execution
- **Memory Intensive**: Large data processing, memory stress
- **File Operations**: Bulk file creation/deletion
- **Error Flood**: Handling many consecutive errors
- **Performance Benchmarks**: Execution time measurements

## Usage

### Quick Start

```bash
# Run all tests
./tests/test_runner.sh

# Run specific test category
./tests/test_runner.sh basic
./tests/test_runner.sh pipes
./tests/test_runner.sh memory

# Run with verbose output
./tests/test_runner.sh all -v

# Run unit tests
./tests/unit_tests.sh

# Run stress tests (may take several minutes)
./tests/stress_tests.sh
```

### Available Test Categories

- `basic` - Basic command execution
- `builtins` - Built-in command testing
- `pipes` - Pipe operation testing
- `redirections` - Redirection testing
- `env` - Environment variable testing
- `quotes` - Quote handling testing
- `errors` - Error handling testing
- `signals` - Signal handling testing
- `memory` - Memory leak testing (requires Valgrind)
- `performance` - Performance testing
- `compatibility` - Bash compatibility testing
- `all` - Run all test categories (default)

### Command-Line Options

- `-v, --verbose` - Show detailed output for failed tests
- `-s, --save` - Save log files after test completion
- `-t, --timeout N` - Set timeout for individual tests (default: 10s)
- `--no-cleanup` - Don't clean up temporary files
- `-h, --help` - Show help information

## Test Requirements

### Prerequisites

- Compiled minishell binary in project root
- Bash shell environment
- Standard Unix utilities (cat, wc, grep, etc.)
- Valgrind (optional, for memory tests)
- bc calculator (optional, for performance measurements)

### Environment Setup

Tests automatically create necessary temporary directories and files:
- `tests/temp/` - Temporary files for testing
- `tests/logs/` - Test execution logs
- Various test files in `/tmp/` (stress tests)

## Test Output

### Success Indicators
- ✅ PASS - Test completed successfully
- 📈 Performance metrics for benchmarks
- 🎉 All tests passed (summary)

### Failure Indicators  
- ❌ FAIL - Test failed to meet expectations
- ⏰ TIMEOUT - Test exceeded time limit
- ⚠️ SKIP - Test skipped (missing dependencies)

### Information
- ℹ️ INFO - Additional information or manual test notes
- 🧹 Cleanup operations
- 🔧 Setup operations

## Interpreting Results

### Memory Tests
Memory tests use Valgrind with suppression files to ignore false positives from external libraries (readline, termcap). Real leaks in minishell code will still be detected.

### Performance Tests
Performance benchmarks provide baseline measurements. Significant deviations may indicate performance regressions or improvements.

### Compatibility Tests
Compatibility tests compare minishell output directly with bash. Minor formatting differences are typically acceptable.

### Signal Tests
Signal handling tests often require manual verification due to the interactive nature of signal processing.

## Extending Tests

### Adding New Test Categories

1. Add test function to `test_runner.sh`:
```bash
test_new_category() {
    echo -e "${PURPLE}🆕 Testing New Feature${NC}"
    run_minishell_test "Test name" "command input" "expected pattern"
}
```

2. Add category to main switch statement
3. Update help text and documentation

### Adding Individual Tests

Use the test utility functions:
- `run_minishell_test` - Test against expected output pattern
- `run_comparison_test` - Compare directly with bash output
- `run_stress_test` - Performance/stress testing

### Custom Test Files

Add custom tests directly to the main test scripts (`test_runner.sh`, `unit_tests.sh`, or `stress_tests.sh`) using the provided utility functions.

## Troubleshooting

### Common Issues

**Tests fail with "command not found"**
- Ensure minishell is compiled: `make` in project root
- Check minishell binary permissions

**Memory tests always fail**
- Install Valgrind: `sudo apt-get install valgrind`
- Check suppression file: `config/minishell.supp`

**Performance tests show "N/A"**
- Install bc calculator: `sudo apt-get install bc`

**Permission denied errors**
- Ensure test scripts are executable: `chmod +x tests/*.sh`
- Check temporary directory permissions

### Debug Mode

Run tests with verbose output to see detailed failure information:
```bash
./tests/test_runner.sh all -v
```

Save logs for later analysis:
```bash
./tests/test_runner.sh all --save
cat tests/logs/test.log
```

## Integration with Build System

The test suite integrates with the project Makefile:

```bash
make test            # Run comprehensive test suite
make test-unit       # Run unit tests for edge cases
make test-stress     # Run stress and performance tests  
make test-all        # Run all test categories
make test-basic      # Run basic functionality tests
make test-memory     # Run memory leak tests
make test-performance # Run performance tests
```

## Continuous Integration

For automated testing environments:

```bash
# Non-interactive test run
./tests/test_runner.sh all --no-cleanup

# Get exit code for CI systems
echo $?  # 0 = success, 1 = failures
```

## Performance Baselines

Expected performance characteristics:
- Basic commands: < 0.1s per command
- Pipe operations: < 0.2s per pipe
- Variable expansion: < 0.05s per expansion
- 100 rapid commands: < 5s total

Significant deviations from these baselines may indicate performance issues.
