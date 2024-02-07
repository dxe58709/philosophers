<h1 align="center">
	Philosophers
</h1>
<h2 align="center">
<img src="https://github.com/dxe58709/philosophers/assets/133973097/b37fdd85-2efd-470a-ba8a-9ca9dc9152b0" alt=42 project philosophers>
</h2>

## Summary
> <i>Philosophers is a 42 school project designed around Edsger Dijkstra's famous dining philosophers problem.<br>
>  In this project we will learn about concurrent programming. It uses only threads and mutexes. <br>
And a bonus part must be created using processes and semaphores, which are exclusive processes. </i>

## Getting started

First, clone this repository and `cd` into it:

```zsh
#!/bin/zsh
git clone https://github.com/dxe58709/philosophers; cd philosophers
```

Compile using `make`:

```zsh
#!/bin/zsh
make
```

Compile bonus part:
```zsh
#!/bin/zsh
make bonus
```
## Usage

### Mandatory Part - Threads and Mutexes

To run the program:
```zsh
#!/bin/zsh
./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_times_each_philosopher_must_eat]
```

Run the program with the following arguments:

```zsh
#!/bin/zsh
./philo 4 800 200 200 5
```
If the arguments are valid, the program will output the actions of each philosopher until one of them dies or until all of them have eaten number_of_times_each_philo_must_eat, if specified.

### Bonus Part - Processes and Semaphores
For the bonus part of this project, the problem is the same with a few differences: philosophers are now processes and the forks are now a counting semaphore. The forks are arranged at the center of the table when not in use and any philosopher can take any fork.

To run the program:
```zsh
#!/bin/zsh
./philo_bonus <number_of_philosophers> <time_to_die time_to_eat> <time_to_sleep> [number_of_times_each_philosopher_must_eat]
```

Run the program with the following arguments:

```zsh
#!/bin/zsh
./philo_bonus 4 800 200 200 5
```
If the arguments are valid, the program will output the actions of each philosopher until one of them dies or until all of them have eaten number_of_times_each_philo_must_eat, if specified.
