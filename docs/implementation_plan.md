# Treasure Hunt – Binary Search Solver: Implementation Plan

## Goal

Build a clean, well-documented Python program that finds the index of a treasure (target value) within a sorted list of coordinates using **Binary Search**, along with comprehensive tests, formatted output, and optional visualization.

---

## User Review Required

> [!IMPORTANT]
> **Language Choice**: This plan assumes **Python 3.10+**. If you prefer C++, Java, or another language, please let me know before I begin execution.

> [!IMPORTANT]
> **Comments Language**: The PRD mentions "Arabic comments if required." This plan defaults to **English** comments. Confirm if you want **Arabic** or **bilingual** comments.

> [!WARNING]
> **Scope Decision**: The PRD lists visualization and GUI as *future enhancements*. This plan includes them as **Phase 5 (optional)**. Confirm if you want them included in the initial delivery or deferred.

---

## Project Structure (Final State)

```
Treasure Hunt – Algo Proj/
├── src/
│   ├── __init__.py
│   ├── binary_search.py          # Core algorithm
│   ├── input_handler.py          # Input validation & parsing
│   └── output_formatter.py       # Result formatting & step logging
├── tests/
│   ├── __init__.py
│   ├── test_binary_search.py     # Unit tests for core algorithm
│   ├── test_input_handler.py     # Unit tests for input validation
│   └── test_edge_cases.py        # Dedicated edge case tests
├── main.py                       # CLI entry point
├── requirements.txt              # Dependencies (minimal)
├── README.md                     # Project documentation
└── PRD.md                        # Product Requirements Document
```

---

## Phase 1: Project Setup & Core Algorithm

**Goal**: Establish the project skeleton and implement the core binary search algorithm with O(log n) time and O(1) space.

**Estimated complexity**: Small — a single agent can complete this in one pass.

---

### [NEW] [main.py](file:///c:/Users/noura/OneDrive/Desktop/Treasure%20Hunt%20–%20Algo%20Proj/main.py)

- CLI entry point using Python's `argparse` or simple `input()` prompts
- Accepts a sorted list of integers (comma-separated) and a target integer
- Calls the binary search function and prints the result
- Clean `if __name__ == "__main__"` guard

### [NEW] [src/\_\_init\_\_.py](file:///c:/Users/noura/OneDrive/Desktop/Treasure%20Hunt%20–%20Algo%20Proj/src/__init__.py)

- Empty init file to make `src` a Python package

### [NEW] [src/binary_search.py](file:///c:/Users/noura/OneDrive/Desktop/Treasure%20Hunt%20–%20Algo%20Proj/src/binary_search.py)

- **`binary_search(arr: list[int], target: int) -> int`**
  - Iterative implementation (O(1) space as required by PRD)
  - Uses `low`, `high`, `mid` pointers
  - Returns 0-based index if found, `-1` if not found
  - Minimizes comparisons (single comparison per iteration using `<`, `>`, `==`)
- **`binary_search_with_steps(arr: list[int], target: int) -> tuple[int, list[dict]]`**
  - Same algorithm but also records each step as a dict: `{"step": int, "low": int, "high": int, "mid": int, "mid_value": int, "action": str}`
  - Returns `(result_index, steps_list)`
  - This variant supports the future visualization feature and the step-logging output

### Acceptance Criteria (Phase 1)

| Scenario | Input | Expected |
|---|---|---|
| Target in middle | `[1, 3, 5, 7, 9]`, target `5` | `2` |
| Target exists | `[10, 20, 30, 40, 50]`, target `30` | `2` |
| Target not found | `[15, 25, 35, 45, 55]`, target `60` | `-1` |
| Basic CLI run | User enters list and target | Correct index printed |

---

## Phase 2: Input Validation & Edge Cases

**Goal**: Add robust input validation and handle all edge cases specified in the PRD.

**Estimated complexity**: Small — focused on validation logic.

---

### [NEW] [src/input_handler.py](file:///c:/Users/noura/OneDrive/Desktop/Treasure%20Hunt%20–%20Algo%20Proj/src/input_handler.py)

- **`parse_list(raw_input: str) -> list[int]`**
  - Parses comma-separated string into a list of integers
  - Raises `ValueError` with descriptive message if:
    - Input contains non-integer values
    - Input is empty (returns empty list, which is valid)
- **`validate_sorted(arr: list[int]) -> bool`**
  - Verifies the list is sorted in ascending order
  - Returns `True`/`False`
- **`parse_target(raw_input: str) -> int`**
  - Parses and validates the target as an integer
  - Raises `ValueError` if not a valid integer

### [MODIFY] [src/binary_search.py](file:///c:/Users/noura/OneDrive/Desktop/Treasure%20Hunt%20–%20Algo%20Proj/src/binary_search.py)

- Add explicit early return for empty list (`return -1`)
- Ensure single-element list works correctly (already should, but add a comment)

### [MODIFY] [main.py](file:///c:/Users/noura/OneDrive/Desktop/Treasure%20Hunt%20–%20Algo%20Proj/main.py)

- Integrate input validation before calling binary search
- Display user-friendly error messages for invalid input
- Add retry loop so the user can correct mistakes without restarting

### Edge Cases Covered

| Case | Input | Expected |
|---|---|---|
| Empty list | `[]`, target `5` | `-1` |
| Single element, match | `[5]`, target `5` | `0` |
| Single element, no match | `[5]`, target `3` | `-1` |
| Target < all elements | `[10, 20, 30]`, target `1` | `-1` |
| Target > all elements | `[10, 20, 30]`, target `99` | `-1` |
| Unsorted list | `[3, 1, 2]`, target `1` | Error message |
| Non-integer input | `[a, b, c]`, target `1` | Error message |

---

## Phase 3: Testing Framework

**Goal**: Build a comprehensive test suite using `pytest` that covers all PRD acceptance criteria, edge cases, and performance characteristics.

**Estimated complexity**: Small-Medium — thorough test coverage.

---

### [NEW] [tests/\_\_init\_\_.py](file:///c:/Users/noura/OneDrive/Desktop/Treasure%20Hunt%20–%20Algo%20Proj/tests/__init__.py)

- Empty init file

### [NEW] [tests/test_binary_search.py](file:///c:/Users/noura/OneDrive/Desktop/Treasure%20Hunt%20–%20Algo%20Proj/tests/test_binary_search.py)

- **PRD acceptance criteria tests** (the 3 scenarios from section 7)
- **Algorithmic correctness tests**:
  - Target at first index
  - Target at last index
  - Target at middle index
  - Large list (1000+ elements) — verify correct result
- **Step tracking tests** (for `binary_search_with_steps`):
  - Verify step count ≤ ⌈log₂(n)⌉ + 1
  - Verify each step's `low ≤ mid ≤ high`

### [NEW] [tests/test_input_handler.py](file:///c:/Users/noura/OneDrive/Desktop/Treasure%20Hunt%20–%20Algo%20Proj/tests/test_input_handler.py)

- Valid list parsing
- Invalid list parsing (non-integers, special characters)
- Sorted validation (ascending, descending, unsorted)
- Target parsing (valid, invalid)

### [NEW] [tests/test_edge_cases.py](file:///c:/Users/noura/OneDrive/Desktop/Treasure%20Hunt%20–%20Algo%20Proj/tests/test_edge_cases.py)

- All 7 edge cases from the table in Phase 2
- Duplicate elements in list (find any valid index)
- Very large numbers (boundary of int range)
- Negative numbers in sorted list

### [NEW] [requirements.txt](file:///c:/Users/noura/OneDrive/Desktop/Treasure%20Hunt%20–%20Algo%20Proj/requirements.txt)

```
pytest>=7.0
```

### Verification

```bash
# Run all tests
python -m pytest tests/ -v

# Run with coverage (optional)
python -m pytest tests/ -v --tb=short
```

---

## Phase 4: Output Formatting & Documentation

**Goal**: Polish the output, add step-by-step search logging, and create comprehensive documentation.

**Estimated complexity**: Small — formatting and docs.

---

### [NEW] [src/output_formatter.py](file:///c:/Users/noura/OneDrive/Desktop/Treasure%20Hunt%20–%20Algo%20Proj/src/output_formatter.py)

- **`format_result(index: int, target: int) -> str`**
  - If found: `"✅ Treasure found! Target {target} is at index {index}."`
  - If not found: `"❌ Treasure not found! Target {target} does not exist in the map."`
- **`format_steps(steps: list[dict]) -> str`**
  - Formats each step as a readable table/log:
    ```
    Step 1: Searching range [0..8], checking index 4 (value=5)
            → Target is smaller, searching left half
    Step 2: Searching range [0..3], checking index 1 (value=3)
            → Target is larger, searching right half
    ...
    ```
- **`format_summary(steps: list[dict], result: int) -> str`**
  - Total steps taken
  - Theoretical maximum steps: ⌈log₂(n)⌉
  - Efficiency assessment

### [MODIFY] [main.py](file:///c:/Users/noura/OneDrive/Desktop/Treasure%20Hunt%20–%20Algo%20Proj/main.py)

- Add `--verbose` / `-v` flag to show step-by-step search details
- Add `--summary` / `-s` flag to show search summary
- Default mode: just print the result index
- Use the output formatter for all display

### [NEW] [README.md](file:///c:/Users/noura/OneDrive/Desktop/Treasure%20Hunt%20–%20Algo%20Proj/README.md)

- Project title and description
- How to install and run
- Usage examples (with sample output)
- Algorithm explanation with complexity analysis
- Testing instructions
- Project structure overview
- Future enhancements roadmap

### [NEW] [PRD.md](file:///c:/Users/noura/OneDrive/Desktop/Treasure%20Hunt%20–%20Algo%20Proj/PRD.md)

- Copy of the Product Requirements Document (for deliverables completeness)

---

## Phase 5: Future Enhancements (Optional)

**Goal**: Implement the PRD's "Future Enhancements" — descending list support, step visualization, and a basic GUI.

> [!NOTE]
> This phase is **optional** and only executed if the user requests it. Each sub-phase is independent.

---

### Phase 5A: Descending Sorted List Support

#### [MODIFY] [src/binary_search.py](file:///c:/Users/noura/OneDrive/Desktop/Treasure%20Hunt%20–%20Algo%20Proj/src/binary_search.py)

- Add **`detect_sort_order(arr: list[int]) -> str`** — returns `"ascending"`, `"descending"`, or `"unsorted"`
- Modify `binary_search` to accept an optional `order` parameter
- When `order="descending"`, reverse the comparison logic (`<` becomes `>`)

#### [MODIFY] [src/input_handler.py](file:///c:/Users/noura/OneDrive/Desktop/Treasure%20Hunt%20–%20Algo%20Proj/src/input_handler.py)

- Update `validate_sorted` to accept and validate both ascending and descending

#### [NEW] [tests/test_descending.py](file:///c:/Users/noura/OneDrive/Desktop/Treasure%20Hunt%20–%20Algo%20Proj/tests/test_descending.py)

- Mirror all existing tests but with descending lists

---

### Phase 5B: Terminal Visualization

#### [NEW] [src/visualizer.py](file:///c:/Users/noura/OneDrive/Desktop/Treasure%20Hunt%20–%20Algo%20Proj/src/visualizer.py)

- **`visualize_search(arr: list[int], steps: list[dict], target: int)`**
  - Prints the array with highlighting:
    - Current search range in **bold/color**
    - Current `mid` element in **highlight**
    - Found element in **green**
    - Eliminated elements in **dim/gray**
  - Uses ANSI color codes (with `colorama` for Windows compatibility)
  - Adds a brief pause between steps for animation effect

#### [MODIFY] [requirements.txt](file:///c:/Users/noura/OneDrive/Desktop/Treasure%20Hunt%20–%20Algo%20Proj/requirements.txt)

- Add `colorama>=0.4.6`

---

### Phase 5C: Web-based GUI

#### [NEW] [gui/](file:///c:/Users/noura/OneDrive/Desktop/Treasure%20Hunt%20–%20Algo%20Proj/gui/)

- `index.html` — Single-page application
- `style.css` — Modern, dark-themed design
- `script.js` — Binary search logic in JS + animated visualization
- Features:
  - Input fields for list and target
  - Animated array visualization showing search narrowing
  - Step counter and result display
  - Responsive design

---

## Open Questions

> [!IMPORTANT]
> 1. **Language**: Python 3.10+ is assumed. Do you want a different language?
> 2. **Comments**: English or Arabic comments?
> 3. **Phase 5**: Should any of the future enhancements be included in the initial delivery?
> 4. **Duplicate handling**: If the sorted list contains duplicates (e.g., `[1, 3, 3, 3, 5]`, target `3`), should the algorithm return the **first**, **last**, or **any** matching index?

---

## Verification Plan

### Automated Tests

```bash
# Phase 3 — Run full test suite
python -m pytest tests/ -v

# Verify O(log n) behavior
python -m pytest tests/test_binary_search.py::test_step_count_logarithmic -v
```

### Manual Verification

- Run `main.py` interactively and test all 3 PRD acceptance scenarios
- Run with `--verbose` flag to verify step logging output
- Test invalid inputs (unsorted list, non-integers, empty input) to verify error handling
- Test on Windows (primary target environment)

### CLI Smoke Test Sequence

```bash
# Test 1: PRD Scenario — Target exists (middle)
python main.py
# Enter: 1, 3, 5, 7, 9
# Enter: 5
# Expected: 2

# Test 2: PRD Scenario — Target not found
python main.py
# Enter: 15, 25, 35, 45, 55
# Enter: 60
# Expected: -1

# Test 3: Edge case — Empty list
python main.py
# Enter: (empty)
# Enter: 5
# Expected: -1
```
