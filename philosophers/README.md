# philosophers - Threading and Synchronization

## 📖 Description

The philosophers project is an implementation of the classic "Dining Philosophers" problem, designed to teach multithreading, synchronization, and deadlock prevention. This project explores concurrent programming concepts using threads and mutexes (mandatory part) and processes and semaphores (bonus part).

## 🎯 Objectives

- Understand multithreading and concurrent programming
- Learn about mutexes and synchronization primitives
- Master deadlock prevention and race condition handling
- Practice process management and inter-process communication
- Implement efficient resource sharing algorithms

## 🍽 The Dining Philosophers Problem

### The Scenario
- N philosophers sit around a circular table
- Each philosopher has a plate of spaghetti
- There is one fork between each pair of philosophers
- A philosopher needs **two forks** to eat
- Philosophers alternate between **thinking**, **eating**, and **sleeping**

### The Challenge
- **Deadlock**: All philosophers pick up their left fork simultaneously
- **Starvation**: Some philosophers never get to eat
- **Race Conditions**: Multiple threads accessing shared resources

## 🏗 Project Structure

```
philosophers/
├── philo/                  # Mandatory: threads and mutexes
│   ├── Makefile
│   ├── includes/
│   │   └── philo.h        # Header file
│   └── src/
│       ├── main.c         # Program entry point
│       ├── init.c         # Initialization functions
│       ├── philo.c        # Philosopher lifecycle
│       ├── utils.c        # Utility functions
│       ├── monitor.c      # Death monitoring
│       └── cleanup.c      # Memory cleanup
└── philo_bonus/           # Bonus: processes and semaphores
    ├── Makefile
    ├── includes/
    │   └── philo_bonus.h  # Bonus header file
    └── src/
        ├── main_bonus.c   # Bonus main function
        ├── init_bonus.c   # Process initialization
        ├── philo_bonus.c  # Philosopher process
        └── utils_bonus.c  # Bonus utilities
```

## ⚙️ Program Arguments

```bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

### Parameters
- **number_of_philosophers**: Number of philosophers (and forks)
- **time_to_die**: Time in ms after which a philosopher dies if not eating
- **time_to_eat**: Time in ms it takes for a philosopher to eat
- **time_to_sleep**: Time in ms a philosopher spends sleeping
- **[optional] number_of_times_each_philosopher_must_eat**: Simulation stops when all philosophers have eaten this many times

### Examples
```bash
# 5 philosophers, die after 800ms, eat for 200ms, sleep for 200ms
./philo 5 800 200 200

# Same as above, but stop after each philosopher eats 7 times
./philo 5 800 200 200 7

# Edge case: 1 philosopher (should die)
./philo 1 800 200 200
```

## 🧵 Implementation Details (Mandatory)

### Data Structures
```c
typedef struct s_philo
{
    int             id;                 // Philosopher ID (1 to N)
    int             meals_eaten;        // Number of meals consumed
    long            last_meal_time;     // Timestamp of last meal
    pthread_t       thread;             // Philosopher thread
    struct s_data   *data;              // Pointer to shared data
}   t_philo;

typedef struct s_data
{
    int             philo_count;        // Number of philosophers
    int             time_to_die;        // Death timer in ms
    int             time_to_eat;        // Eating duration in ms
    int             time_to_sleep;      // Sleeping duration in ms
    int             max_meals;          // Optional meal limit
    int             simulation_end;     // End flag
    long            start_time;         // Simulation start time
    pthread_mutex_t *forks;             // Fork mutexes
    pthread_mutex_t print_mutex;       // Print synchronization
    pthread_mutex_t meal_mutex;        // Meal tracking mutex
    t_philo         *philosophers;      // Array of philosophers
}   t_data;
```

### Philosopher Lifecycle
```c
void *philosopher_routine(void *arg)
{
    t_philo *philo = (t_philo *)arg;
    
    // Offset even philosophers to prevent deadlock
    if (philo->id % 2 == 0)
        usleep(1000);
    
    while (!simulation_ended(philo->data))
    {
        take_forks(philo);
        eat(philo);
        put_forks(philo);
        sleep_and_think(philo);
    }
    return (NULL);
}
```

### Fork Management (Deadlock Prevention)
```c
void take_forks(t_philo *philo)
{
    int left_fork = philo->id - 1;
    int right_fork = philo->id % philo->data->philo_count;
    
    // Always take lower numbered fork first to prevent deadlock
    if (left_fork < right_fork)
    {
        pthread_mutex_lock(&philo->data->forks[left_fork]);
        print_status(philo, "has taken a fork");
        pthread_mutex_lock(&philo->data->forks[right_fork]);
        print_status(philo, "has taken a fork");
    }
    else
    {
        pthread_mutex_lock(&philo->data->forks[right_fork]);
        print_status(philo, "has taken a fork");
        pthread_mutex_lock(&philo->data->forks[left_fork]);
        print_status(philo, "has taken a fork");
    }
}
```

### Death Monitoring
```c
void *monitor_deaths(void *arg)
{
    t_data *data = (t_data *)arg;
    
    while (!data->simulation_end)
    {
        for (int i = 0; i < data->philo_count; i++)
        {
            pthread_mutex_lock(&data->meal_mutex);
            long time_since_meal = get_current_time() - data->philosophers[i].last_meal_time;
            pthread_mutex_unlock(&data->meal_mutex);
            
            if (time_since_meal > data->time_to_die)
            {
                print_status(&data->philosophers[i], "died");
                data->simulation_end = 1;
                return (NULL);
            }
        }
        usleep(1000);  // Check every 1ms
    }
    return (NULL);
}
```

## 🔄 Bonus Implementation (Processes)

### Process-Based Approach
- Each philosopher is a separate **process**
- Forks are represented by **semaphores**
- Death monitoring handled by parent process
- Inter-process communication via **signals**

### Key Differences
```c
// Semaphore for forks (shared between processes)
sem_t *forks;

// Process creation instead of threads
for (int i = 0; i < data->philo_count; i++)
{
    pid_t pid = fork();
    if (pid == 0)
        philosopher_process(data, i);  // Child process
    data->pids[i] = pid;
}

// Parent monitors and kills children when done
monitor_simulation(data);
kill_all_philosophers(data);
```

## 📊 Output Format

### Status Messages
```
timestamp_in_ms X has taken a fork
timestamp_in_ms X is eating
timestamp_in_ms X is sleeping
timestamp_in_ms X is thinking
timestamp_in_ms X died
```

### Example Output
```
0 1 has taken a fork
0 1 has taken a fork
0 1 is eating
0 3 has taken a fork
0 3 has taken a fork
0 3 is eating
200 1 is sleeping
200 3 is sleeping
200 2 has taken a fork
...
```

## 🧪 Testing

### Basic Tests
```bash
# Should run indefinitely (no deaths)
./philo 5 800 200 200

# Should stop after each philosopher eats 7 times
./philo 5 800 200 200 7

# Edge case: 1 philosopher should die
./philo 1 800 200 200
```

### Stress Tests
```bash
# Large number of philosophers
./philo 200 410 200 200

# Tight timing (high chance of death)
./philo 4 310 200 100

# Many philosophers, many meals
./philo 100 800 200 200 1000
```

### Race Condition Tests
```bash
# Run multiple times to check for data races
for i in {1..100}; do
    timeout 10s ./philo 5 800 200 200 7
    if [ $? -ne 0 ]; then
        echo "Test $i failed"
        break
    fi
done
```

## 📏 Technical Requirements

### Mandatory Part
- **Language**: C
- **Functions**: `pthread_create`, `pthread_detach`, `pthread_join`, `pthread_mutex_init`, `pthread_mutex_destroy`, `pthread_mutex_lock`, `pthread_mutex_unlock`
- **Timing**: Use `usleep`, `gettimeofday`
- **No Data Races**: Protect all shared data with mutexes
- **No Deadlocks**: Implement proper resource ordering

### Bonus Part
- **Processes**: Each philosopher is a separate process
- **Semaphores**: `sem_open`, `sem_close`, `sem_post`, `sem_wait`, `sem_unlink`
- **Process Management**: `fork`, `kill`, `exit`, `waitpid`
- **IPC**: Inter-process communication for coordination

## ⚠️ Common Issues and Solutions

### Deadlock Prevention
1. **Resource Ordering**: Always acquire forks in the same order
2. **Timeout Mechanisms**: Implement timeouts for resource acquisition
3. **Philosopher Offset**: Delay even-numbered philosophers

### Race Condition Prevention
1. **Mutex Protection**: Protect all shared variables
2. **Atomic Operations**: Use proper synchronization primitives
3. **Critical Sections**: Minimize time in critical sections

### Performance Optimization
1. **Minimal Locking**: Lock only when necessary
2. **Fine-Grained Locking**: Use separate mutexes for different resources
3. **Efficient Monitoring**: Optimize death checking frequency

## 💡 Key Learning Points

1. **Concurrency**: Understanding parallel execution and shared resources
2. **Synchronization**: Using mutexes and semaphores effectively
3. **Deadlock Prevention**: Implementing resource ordering strategies
4. **Race Conditions**: Identifying and preventing data races
5. **Process vs Threads**: Understanding different concurrency models
6. **Real-Time Constraints**: Meeting timing requirements in concurrent systems

## 🔗 Real-World Applications

These concepts are essential for:
- Multi-threaded server applications
- Database transaction management
- Operating system design
- Distributed systems programming
- Game engine development
- High-performance computing

---

*This project provides deep insight into concurrent programming challenges and prepares you for complex multi-threaded system development.*
