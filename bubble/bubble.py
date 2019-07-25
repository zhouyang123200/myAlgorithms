#! /usr/bin/python


def bubble(seq):
    length = len(seq)
    for i in range(length - 1, 0, -1):
        swp = False
        for j in range(i):
            if seq[j] > seq[j + 1]:
                swp = True
                seq[j], seq[j + 1] = seq[j + 1], seq[j]
        if not swp:
            break


if __name__ == '__main__':
    import random
    seq = [random.randint(1, 10) for _ in range(10)]
    print(seq)
    bubble(seq)
    print(seq)
