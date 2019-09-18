'''
find shortest path to save someone in maze
'''
import random

CELL_NUM = 50
OBSTACLE_RANGE = 3
START_POINT_RANGE = 4
OBSTACLE_NUNS = 6

maze_map = [
    ['0'] * CELL_NUM for _ in range(50)
]


def shuffle():
    pass


def init_start_end_point():
    start_up = START_POINT_RANGE - 1
    end_down = CELL_NUM - START_POINT_RANGE
    end_up = CELL_NUM - 1
    return (
        (random.randint(0, start_up), random.randint(0, start_up)),
        (random.randint(end_down, end_up), random.randint(end_down, end_up))
        )


def generate_obstacle():
    ele_nums = random.randint(
        OBSTACLE_RANGE, OBSTACLE_RANGE ^ 2 - OBSTACLE_RANGE)
    steps = [-1, 0, 1]

    start_point = (0, 0)
    point_set = set()
    point_set.add(start_point)
    pre_point = start_point
    while ele_nums != 0:
        next_point = (
            pre_point[0] + random.choice(steps),
            pre_point[1] + random.choice(steps)
            )
        if next_point not in point_set:
            point_set.add(next_point)
            pre_point = next_point
            ele_nums -= 1


def print_map(maze_map):
    for row in maze_map:
        for item in row:
            print(item, end=' ')
        print()


if __name__ == "__main__":
    print_map(maze_map)
