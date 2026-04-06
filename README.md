*This project has been created as part of the 42 curriculum by otlacerd.*

# Philosophers

## Description

This project is part of Milestone 3 of the 42 curriculum and explores the classic Dining Philosophers problem using threads and mutexes.

The goal is to simulate philosophers sitting around a table, alternating between eating, sleeping, and thinking, while sharing limited resources (forks). The challenge lies in preventing data races, avoiding deadlocks, and minimizing starvation.

This implementation focuses on:

* Deterministic fork acquisition order
* Minimal and controlled synchronization
* Clean and reusable locking logic

---

## Implementation Details

### Fork Strategy

Each philosopher picks up forks in the following order:

```
fork (n + 1) -> fork (n)
```

Except for the last one, who is inverted:

```
fork (n) -> fork (n + 1)
```

The last philosopher reverses this order to prevent deadlocks.

---

### Starvation Mitigation

No forced desynchronization based on parity is used.
Instead, fairness is improved by introducing a small delay during the thinking phase for philosophers who have just eaten. This reduces the chance of the same philosopher repeatedly acquiring forks and starving others, wich helps reduce contention and improves overall fairness.

---

### Synchronization Model

A global mutex (`check_stop`) is used to protect the simulation state and prevent race conditions when checking termination.

All logging and critical actions are executed through a centralized locking mechanism.

---

### safex Function

A key feature of this implementation is the `safex` function, which abstracts the "lock → action → unlock" pattern:

```c
int safex(t_mutex *mutex, ..., int function(...))
{
    int function_return;
    
    pthread_mutex_lock(mutex); //-------------------> lock the mutex
    function_return = function(philo, message); // -> execute the action
    pthread_mutex_unlock(mutex); // ----------------> unlock the mutex
    return (function_return);
}
```

This approach:

* Reduces boilerplate code
* Centralizes synchronization logic
* Improves readability and maintainability

As a result, the entire codebase uses only a handful of explicit lock/unlock calls.

---

## Instructions

### Compilation

```bash
make
```

### Execution

```bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

Example:

```bash
./philo 5 800 200 200
```

---

## Resources

* POSIX Threads (pthreads) documentation
* The Dining Philosophers Problem (classic concurrency problem)
* 42 subject documentation


### AI Usage

AI was used as a supplementary tool for concept clarification and validation of concurrency-related topics such as mutex behavior, thread synchronization, shared state management, concept as deadlock, starvation.

All architectural decisions, implementation, and debugging were carried out independently.

## Author

Otávio Lacerda

Intra: otlacerd
