"""Treasure Hunt - core binary search solution (Python)."""


def treasure_hunt(arr, target):
    """Binary search: return the index of target in sorted arr, or -1."""
    low, high = 0, len(arr) - 1
    while low <= high:
        mid = low + (high - low) // 2
        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            low = mid + 1
        else:
            high = mid - 1
    return -1


if __name__ == "__main__":
    tests = [
        ([1, 3, 5, 7, 9], 5, 2),
        ([10, 20, 30, 40, 50], 30, 2),
        ([15, 25, 35, 45, 55], 60, -1),
    ]
    for arr, target, expected in tests:
        result = treasure_hunt(arr, target)
        status = "PASS" if result == expected else "FAIL"
        print(f"{arr}, target {target} -> {result} ({status})")
