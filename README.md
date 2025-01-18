<p align="center">
  <img src="img/philo.png" width="70%"/>
</p>

## 🚀 SYNOPSIS

The `philosophers` project at 42 school challenges students to solve the classic "Dining Philosophers" problem using thread-based solutions in the C programming language.

This project focuses on understanding multithreading, mutexes, and synchronization issues. The task involves managing concurrent threads representing philosophers who alternate between eating, thinking, and sleeping, while ensuring there are no data races or deadlocks.

Successfully completing `philosophers` demonstrates a deep understanding of thread-based programming, critical sections, and resource management, essential skills for tackling concurrency challenges.

## 🛠️ PROGRAM SPECIFICITIES AND CONSIDERATIONS

Clone the project:

```bash
git clone git@github.com:maitreverge/philosophers.git && cd philosophers
```

> [!IMPORTANT]
> The program must handle concurrent threads efficiently, avoiding race conditions and ensuring philosophers do not starve.

> [!WARNING]
> Incorrect handling of threads or mutexes can lead to undefined behavior, such as deadlocks or starvation.

The program should:

- Simulate the dining philosophers problem with a given number of philosophers.

- Log the actions of philosophers in real-time.

- Terminate correctly when a philosopher dies or all have eaten a specified number of times.

## ⚙️ USAGE

The primary program is called philo, and it will be compiled using:

```bash
make
```

The program can be executed as follows:
```bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

#### Arguments:

- `number_of_philosophers`: Number of philosophers and forks at the table.

- `time_to_die`: Time (in milliseconds) a philosopher can live without eating.

- `time_to_eat`: Time (in milliseconds) a philosopher spends eating.

- `time_to_sleep`: Time (in milliseconds) a philosopher spends sleeping.

- `number_of_times_each_philosopher_must_eat` (optional): If specified, the simulation ends when each philosopher has eaten at least this many times.

#### Logs Format:

Each action by a philosopher is logged with the following format:

```text
timestamp_in_ms X has taken a fork
timestamp_in_ms X is eating
timestamp_in_ms X is sleeping
timestamp_in_ms X is thinking
timestamp_in_ms X died
```

Where `timestamp_in_ms` is the current time in milliseconds, and X is the philosopher's ID.

#### Core Features

The program implements the following core functionalities:

##### Thread Management

- Each philosopher is represented as a thread.

- Forks are protected using mutexes to prevent race conditions.

##### Philosopher Behavior

- Philosophers alternate between eating, thinking, and sleeping.

- To eat, a philosopher must acquire the fork on their left and right.

- Philosophers release forks after eating and then sleep.

##### Synchronization

- Use mutexes to ensure forks are picked up and put down without conflicts.

- Avoid deadlocks by carefully managing the order in which forks are picked up.

##### Termination Conditions

- A philosopher dies if they fail to eat within time_to_die milliseconds.

- The simulation ends if all philosophers eat the specified number of times (if provided).

## 💻 EXAMPLE

Here’s an example session:

```bash
./philo 5 800 200 200
```

Output:
```
0 1 has taken a fork
0 1 has taken a fork
0 1 is eating
200 1 is sleeping
400 1 is thinking
```

This simulates `5` philosophers with a `time_to_die` of 800 ms, a `time_to_eat` of 200 ms, and a `time_to_sleep` of 200 ms.

## 🤝 CONTRIBUTION
Contributions are open, open a Github Issue or submit a PR 🚀
