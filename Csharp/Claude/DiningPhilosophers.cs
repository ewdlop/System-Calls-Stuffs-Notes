using System;
using System.Collections.Generic;
using System.Threading;
using System.Threading.Tasks;

public class DiningPhilosophers
{
    private class Philosopher
    {
        public int Id { get; }
        public Semaphore LeftFork { get; }
        public Semaphore RightFork { get; }
        public Random Random { get; } = new Random();

        public Philosopher(int id, Semaphore leftFork, Semaphore rightFork)
        {
            Id = id;
            LeftFork = leftFork;
            RightFork = rightFork;
        }

        public async Task StartDiningAsync(CancellationToken cancellationToken)
        {
            try
            {
                while (!cancellationToken.IsCancellationRequested)
                {
                    await Think();
                    await Eat();
                }
            }
            catch (OperationCanceledException)
            {
                Console.WriteLine($"Philosopher {Id} is leaving the table");
            }
        }

        private async Task Think()
        {
            Console.WriteLine($"Philosopher {Id} is thinking");
            await Task.Delay(Random.Next(1000, 3000));
        }

        private async Task Eat()
        {
            Console.WriteLine($"Philosopher {Id} is hungry and trying to pick up forks");

            // Try to acquire both forks
            bool hasLeftFork = false;
            bool hasRightFork = false;

            try
            {
                // Prevent deadlock by either:
                // 1. Using a timeout approach
                // 2. Having an ordering for resource acquisition
                // 3. Allowing only n-1 philosophers to eat at the same time
                
                // Here we use approach #1 - timeout to avoid deadlock
                hasLeftFork = LeftFork.WaitOne(1000);
                if (hasLeftFork)
                {
                    Console.WriteLine($"Philosopher {Id} picked up left fork");
                    
                    // Wait a bit before trying the right fork
                    await Task.Delay(Random.Next(100, 500));
                    
                    hasRightFork = RightFork.WaitOne(1000);
                    if (hasRightFork)
                    {
                        Console.WriteLine($"Philosopher {Id} picked up right fork and is eating");
                        await Task.Delay(Random.Next(1000, 2000));
                        Console.WriteLine($"Philosopher {Id} finished eating");
                    }
                    else
                    {
                        Console.WriteLine($"Philosopher {Id} couldn't get right fork, putting down left fork");
                    }
                }
                else
                {
                    Console.WriteLine($"Philosopher {Id} couldn't get left fork");
                }
            }
            finally
            {
                // Always release the forks that were acquired
                if (hasRightFork)
                {
                    RightFork.Release();
                    Console.WriteLine($"Philosopher {Id} put down right fork");
                }
                
                if (hasLeftFork)
                {
                    LeftFork.Release();
                    Console.WriteLine($"Philosopher {Id} put down left fork");
                }
            }
        }
    }

    public static async Task RunSimulationAsync(int numberOfPhilosophers, TimeSpan duration)
    {
        // Create forks (resources)
        var forks = new List<Semaphore>();
        for (int i = 0; i < numberOfPhilosophers; i++)
        {
            forks.Add(new Semaphore(1, 1));
        }

        // Create philosophers
        var philosophers = new List<Philosopher>();
        for (int i = 0; i < numberOfPhilosophers; i++)
        {
            // Each philosopher picks up the fork to their left and right
            // Note the modulo to create a circular table
            var leftFork = forks[i];
            var rightFork = forks[(i + 1) % numberOfPhilosophers];
            
            philosophers.Add(new Philosopher(i, leftFork, rightFork));
        }

        // Start the simulation
        Console.WriteLine($"Starting dinner with {numberOfPhilosophers} philosophers");
        
        using var cts = new CancellationTokenSource(duration);
        var diningTasks = philosophers.Select(p => p.StartDiningAsync(cts.Token));
        
        try
        {
            await Task.WhenAll(diningTasks);
        }
        catch (OperationCanceledException)
        {
            Console.WriteLine("Dinner has ended");
        }
    }

    // Example usage
    public static async Task Main()
    {
        await RunSimulationAsync(5, TimeSpan.FromSeconds(30));
    }
}
