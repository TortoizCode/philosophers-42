*This project has been created as part of the 42 curriculum by rodmorei*

## Description
Philosophers is a C implementation of the Dining Philosophers concurrency problem, with the objective of learning how to implement threads/processes, utilizing mutexes in order to avoid data races and other possible issues to come.

The program launched with 4 or 5 arguments, this being : number of philosophers, the time they take to die, the time they take to eat, the time they take to sleep and the optional argument of the number of times each philosopher must eat (after which the program ends).

The general idea is that each philosopher sits at a dining table, and brings a fork. In order to eat, a philosopher needs 2 forks (so you need at least 2 philosophers, or else the philosopher will just starve). After taking 2 forks, the philosopher eats, puts down his forks, sleeps, thinks and repeats the process. Since they share forks, philosophers must manage (without communicating) the usage of their forks so that everyone eats and doesn't starve. Depending on the variables (time to eat, time to die, etc.) this may be impossible and one philosopher might starve. If it IS possible though, they should all live and eat indefinitely or until the optional variable "number of times each philosopher must eat" is met.

## Instructions
To create the program run "make" in the shell. Then "./philo" plus the 4 or 5 arguments mentioned in front. Make sure these numbers are valid and not absurdly high or low numbers. Then just see your philosophers try to survive while juggling forks!

## Resources

- The gitbook of course: https://42-cursus.gitbook.io/guide/3-rank-03/philosophers ;

- Dining Philosophers problem on Wikipedia: https://en.wikipedia.org/wiki/Dining_philosophers_problem ;

- Man pages for thread creation and mutexes;

- This guy to explain deadlocking and asymetric fork picking: https://medium.com/@kaustubh.saha/dining-philosophers-problem-2b7370bd0f3e ;
