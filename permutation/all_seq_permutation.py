import sys


def all_seq_permutation(n: int) -> int:
    return n if n <= 1 else n * all_seq_permutation(n - 1)

if __name__ == "__main__":
    n = int(sys.argv[1])
    print('all sequence permutation of {}: {}'.format(
        n, all_seq_permutation(n)))
