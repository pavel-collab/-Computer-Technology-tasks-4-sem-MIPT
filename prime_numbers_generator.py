from time import sleep

# greedy algorithm
def prime_number_generator():
    prime = 2
    while True:
        yield prime
        flag = True
        while (flag == True):
            prime+=1
            for i in range(2, prime):
                if (prime % i == 0):
                    flag = True
                    break
                else:
                    flag = False

iterator = prime_number_generator()
try:
    while True:
        print(next(iterator))
        sleep(1)
except KeyboardInterrupt:
    print("\nend of work")