*This project has been created as part
of the 42 curriculum by TortoizCode.*

## Description
philosophers-42 is a C implementation of the classic Dining Philosophers concurrency problem, a standard 42 curriculum project. The goal is to learn and demonstrate correct use of threads/processes, synchronization primitives (mutexes/semaphores), and timing to avoid data races, deadlocks, and starvation while simulating philosophers who alternate between thinking, eating, and sleeping.

The program launches a configurable number of philosophers and simulates their lifecycle while enforcing the constraints of the assignment (time to die/eat/sleep and optional number of meals). It reports state changes (taking forks, eating, sleeping, thinking, death) in a deterministic, timestamped way.

## Instructions
### Requirements
- A POSIX environment (Linux/macOS)
- A C compiler (e.g., `cc`, `gcc`, or `clang`)
- `make`

### Build
From the repository root:
```sh
make
```
Common targets (if provided by the project Makefile):
```sh
make clean
make fclean
make re
```

### Run
Typical usage (philo / philosophers):
```sh
./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_times_each_philosopher_must_eat]
```
Example:
```sh
./philo 5 800 200 200
./philo 5 800 200 200 7
```
Arguments are usually expressed in milliseconds.

> Note: The exact binary name and arguments depend on the project variant and Makefile in this repository. If your executable is named differently (e.g., `philosophers`), adjust the commands accordingly.

## Resources
### Classic references
- The Dining Philosophers problem (overview): https://en.wikipedia.org/wiki/Dining_philosophers_problem
- POSIX Threads Programming (pthreads):
  - `pthread_create`, `pthread_join`: https://man7.org/linux/man-pages/man3/pthread_create.3.html
  - Mutexes (`pthread_mutex_*`): https://man7.org/linux/man-pages/man3/pthread_mutex_init.3p.html
- Semaphores (if applicable):
  - `sem_open`, `sem_wait`, `sem_post`: https://man7.org/linux/man-pages/man3/sem_open.3.html
- Time measurement:
  - `gettimeofday`: https://man7.org/linux/man-pages/man2/gettimeofday.2.html
  - `clock_gettime`: https://man7.org/linux/man-pages/man2/clock_gettime.2.html
- Concurrency pitfalls:
  - Deadlock: https://en.wikipedia.org/wiki/Deadlock
  - Starvation: https://en.wikipedia.org/wiki/Starvation_(computer_science)

### How AI was used
- Drafting: AI (ChatGPT / GitHub Copilot) was used to draft this README structure and wording.
- No code generation claim: This README does not assert that AI generated any portion of the project source code. If AI was used to write, refactor, or debug code in this repository, add details here specifying the exact files/parts and tasks (e.g., “mutex strategy review”, “race condition debugging”, “argument parsing improvements”).