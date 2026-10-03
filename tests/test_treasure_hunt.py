import os
import sys

sys.path.insert(0, os.path.join(os.path.dirname(__file__), "..", "python"))
from treasure_hunt import treasure_hunt  # noqa: E402


def test_problem_statement_cases():
    assert treasure_hunt([1, 3, 5, 7, 9], 5) == 2
    assert treasure_hunt([10, 20, 30, 40, 50], 30) == 2
    assert treasure_hunt([15, 25, 35, 45, 55], 60) == -1


def test_edge_cases():
    assert treasure_hunt([], 5) == -1
    assert treasure_hunt([5], 5) == 0
    assert treasure_hunt([5], 3) == -1
    assert treasure_hunt([10, 20, 30], 1) == -1
    assert treasure_hunt([10, 20, 30], 99) == -1


def test_first_and_last():
    arr = list(range(0, 1000, 2))
    assert treasure_hunt(arr, arr[0]) == 0
    assert treasure_hunt(arr, arr[-1]) == len(arr) - 1


def test_negative_numbers():
    assert treasure_hunt([-9, -4, 0, 3, 8], -4) == 1
