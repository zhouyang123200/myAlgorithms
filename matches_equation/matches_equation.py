'''
compute how many equations can be got using 24 matches
A + B = C
+, = use two matches
'''

digital_num = [6, 2, 5, 5, 4, 5, 6, 3, 7, 6]


def calc_nums(x):
    matches = 0
    if (int(x/10) != 0):
        while(int(x/10) != 0):
            last_num = x % 10
            last_num_matches = digital_num[last_num]
            matches += last_num_matches
            x = int(x / 10)
        else:
            matches += digital_num[x]
    else:
        matches = digital_num[x]
    return matches


def main():
    for a in range(11111):
        matches = 18
        matches -= 4
        for b in range(11111):
            c = a + b
            if (calc_nums(a) + calc_nums(b) + calc_nums(c) == matches):
                print('{} + {} = {}'.format(a, b, c))

if __name__ == "__main__":
    main()
