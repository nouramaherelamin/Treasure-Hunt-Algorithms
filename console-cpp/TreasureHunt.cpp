#include <iostream>
#include <vector>
#include <iomanip>
#include <ctime>      // For clock() - execution time measurement
#include <string>
#include <cstdlib>    // For system() - console color reset
#include <algorithm>  // For sort()

using namespace std;

// ============================================================
//                    UTILITY FUNCTIONS
// ============================================================

/*
 * Function : printSeparator
 * Purpose  : Prints a decorative separator line for formatted output.
 */
void printSeparator(char ch = '=', int width = 60) {
    cout << string(width, ch) << endl;
}

/*
 * Function : printCentered
 * Purpose  : Prints a string centered within a given width.
 */
void printCentered(const string& text, int width = 60) {
    int padding = (width - (int)text.length()) / 2;
    if (padding < 0) padding = 0;
    cout << string(padding, ' ') << text << endl;
}

/*
 * Function : printArray
 * Purpose  : Displays the contents of a vector in a readable format.
 */
void printArray(const vector<int>& arr) {
    cout << "[";
    for (size_t i = 0; i < arr.size(); ++i) {
        cout << arr[i];
        if (i < arr.size() - 1) cout << ", ";
    }
    cout << "]";
}

/*
 * Function : isSorted
 * Purpose  : Validates that the input array is sorted in ascending order.
 *            Binary Search requires a sorted array to function correctly.
 * Returns  : true if sorted, false otherwise.
 */
bool isSorted(const vector<int>& arr) {
    for (size_t i = 1; i < arr.size(); ++i) {
        if (arr[i] < arr[i - 1]) {
            return false;
        }
    }
    return true;
}

// ============================================================
//                  SEARCH ALGORITHM FUNCTIONS
// ============================================================

/*
 * Function : linearSearch
 * Purpose  : Searches for the target value by checking every element
 *            in the array sequentially from the first to the last.
 * Params   : arr    - the sorted array of integers
 *            target - the value to search for
 *            steps  - reference variable to count number of steps
 * Returns  : Index of the target if found, -1 otherwise.
 *
 * Time Complexity:
 *   - Best Case  : O(1)     - Target is the first element.
 *   - Average    : O(n/2)   - Target is somewhere in the middle.
 *   - Worst Case : O(n)     - Target is the last element or not found.
 * Space Complexity: O(1)
 */
int linearSearch(const vector<int>& arr, int target, int& steps) {
    steps = 0;

    cout << "\n";
    printSeparator('-', 50);
    cout << left << setw(10) << "  Step"
        << setw(15) << "Index"
        << setw(15) << "Value"
        << "Match?" << endl;
    printSeparator('-', 50);

    for (size_t i = 0; i < arr.size(); ++i) {
        steps++; // Count each comparison as one step

        // Determine if the current element matches the target
        string match = (arr[i] == target) ? "YES" : "No";

        // Display current step details
        cout << left << "  " << setw(10) << steps
            << setw(15) << i
            << setw(15) << arr[i]
            << match << endl;

        // Target found at index i
        if (arr[i] == target) {
            printSeparator('-', 50);
            return (int)i;
        }
    }

    printSeparator('-', 50);
    // Target not found in the entire array
    return -1;
}

/*
 * Function : binarySearch
 * Purpose  : Searches for the target value by repeatedly dividing
 *            the search interval in half. The array MUST be sorted.
 * Params   : arr    - the sorted array of integers
 *            target - the value to search for
 *            steps  - reference variable to count number of steps
 * Returns  : Index of the target if found, -1 otherwise.
 *
 * Time Complexity:
 *   - Best Case  : O(1)     - Target is at the middle on the first check.
 *   - Average    : O(log n) - Search space halved with each step.
 *   - Worst Case : O(log n) - Target at extreme ends or not present.
 * Space Complexity: O(1) - Iterative implementation.
 */
int binarySearch(const vector<int>& arr, int target, int& steps) {
    int low = 0;
    int high = (int)arr.size() - 1;
    steps = 0;

    cout << "\n";
    printSeparator('-', 60);
    cout << left << setw(10) << "  Step"
        << setw(10) << "Low"
        << setw(10) << "Mid"
        << setw(10) << "High"
        << setw(12) << "Mid Value"
        << "Action" << endl;
    printSeparator('-', 60);

    while (low <= high) {
        // Calculate mid index safely to prevent integer overflow
        int mid = low + (high - low) / 2;
        steps++; // Count each iteration as one step

        // Determine the action taken based on comparison
        string action;
        if (arr[mid] == target) {
            action = "FOUND!";
        }
        else if (arr[mid] < target) {
            action = "Go Right";
        }
        else {
            action = "Go Left";
        }

        // Display current step details
        cout << left << "  " << setw(10) << steps
            << setw(10) << low
            << setw(10) << mid
            << setw(10) << high
            << setw(12) << arr[mid]
            << action << endl;

        // Check if target is present at mid
        if (arr[mid] == target) {
            printSeparator('-', 60);
            return mid; // Target found
        }

        // If target is greater, ignore the left half
        if (arr[mid] < target) {
            low = mid + 1;
        }
        // If target is smaller, ignore the right half
        else {
            high = mid - 1;
        }
    }

    printSeparator('-', 60);
    // Target is not present in the array
    return -1;
}

// ============================================================
//                    COMPARISON FUNCTION
// ============================================================

/*
 * Function : compareBothAlgorithms
 * Purpose  : Runs both Linear Search and Binary Search on the same
 *            input, measures their execution time using clock(),
 *            counts their steps, and displays a formatted comparison
 *            table side-by-side.
 */
void compareBothAlgorithms(const vector<int>& arr, int target) {
    cout << "\n";
    printSeparator('=', 60);
    printCentered("COMPARISON: Linear Search vs Binary Search", 60);
    printSeparator('=', 60);

    // ---- Run Linear Search ----
    int linearSteps = 0;
    clock_t linearStart = clock();
    int linearResult = linearSearch(arr, target, linearSteps);
    clock_t linearEnd = clock();
    double linearTime = (double)(linearEnd - linearStart) / CLOCKS_PER_SEC * 1000.0; // ms

    // ---- Run Binary Search ----
    int binarySteps = 0;
    clock_t binaryStart = clock();
    int binaryResult = binarySearch(arr, target, binarySteps);
    clock_t binaryEnd = clock();
    double binaryTime = (double)(binaryEnd - binaryStart) / CLOCKS_PER_SEC * 1000.0; // ms

    // ---- Display Formatted Comparison Table ----
    cout << "\n";
    printSeparator('=', 65);
    printCentered("COMPARISON RESULTS TABLE", 65);
    printSeparator('=', 65);

    cout << left
        << "| " << setw(20) << "Criteria"
        << "| " << setw(20) << "Linear Search"
        << "| " << setw(20) << "Binary Search" << "|" << endl;
    printSeparator('-', 65);

    // Row 1: Result Index
    cout << "| " << setw(20) << "Result Index";
    cout << "| " << setw(20) << linearResult;
    cout << "| " << setw(20) << binaryResult << "|" << endl;

    // Row 2: Steps Taken
    cout << "| " << setw(20) << "Steps Taken";
    cout << "| " << setw(20) << linearSteps;
    cout << "| " << setw(20) << binarySteps << "|" << endl;

    // Row 3: Execution Time
    cout << "| " << setw(20) << "Time (ms)";
    cout << "| " << setw(20) << fixed << setprecision(4) << linearTime;
    cout << "| " << setw(20) << fixed << setprecision(4) << binaryTime << "|" << endl;

    // Row 4: Time Complexity
    cout << "| " << setw(20) << "Time Complexity";
    cout << "| " << setw(20) << "O(n)";
    cout << "| " << setw(20) << "O(log n)" << "|" << endl;

    printSeparator('=', 65);

    // ---- Winner Announcement ----
    cout << "\n  >> Winner: ";
    if (binarySteps < linearSteps) {
        cout << "Binary Search is faster with fewer steps!" << endl;
    }
    else if (linearSteps < binarySteps) {
        cout << "Linear Search completed in fewer steps!" << endl;
    }
    else {
        cout << "Both algorithms took the same number of steps!" << endl;
    }
    cout << endl;
}

// ============================================================
//                   TEST CASES FUNCTION
// ============================================================

/*
 * Function : runTestCases
 * Purpose  : Executes the three predefined test cases required by
 *            the project specification and compares both algorithms
 *            on each test case.
 *
 * Test Cases:
 *   1. [1,3,5,7,9],       Target = 5  -> Expected Output = Index 2
 *   2. [10,20,30,40,50],   Target = 30 -> Expected Output = Index 2
 *   3. [15,25,35,45,55],   Target = 60 -> Expected Output = -1
 */
void runTestCases() {
    cout << "\n";
    printSeparator('*', 60);
    printCentered("RUNNING PREDEFINED TEST CASES", 60);
    printSeparator('*', 60);

    // Define test cases: { array, target }
    vector<pair<vector<int>, int>> testCases = {
        {{1, 3, 5, 7, 9},       5  },
        {{10, 20, 30, 40, 50},   30 },
        {{15, 25, 35, 45, 55},   60 }
    };

    // Expected results for verification
    int expectedResults[] = { 2, 2, -1 };

    int caseNum = 1;
    for (size_t t = 0; t < testCases.size(); ++t) {
        cout << "\n";
        printSeparator('#', 60);
        cout << "  TEST CASE " << caseNum << ":" << endl;
        cout << "  Array  : ";
        printArray(testCases[t].first);
        cout << endl;
        cout << "  Target : " << testCases[t].second << endl;
        cout << "  Expected Result : Index " << expectedResults[t] << endl;
        printSeparator('#', 60);

        // Compare both algorithms on this test case
        compareBothAlgorithms(testCases[t].first, testCases[t].second);

        caseNum++;
    }
}

// ============================================================
//                     DISPLAY MENU
// ============================================================

/*
 * Function : displayMenu
 * Purpose  : Shows the main menu options to the user.
 */
void displayMenu() {
    cout << "\n";
    printSeparator('=', 50);
    printCentered("SEARCH MENU", 50);
    printSeparator('=', 50);
    cout << "  [l] Search using Linear Search" << endl;
    cout << "  [b] Search using Binary Search" << endl;
    cout << "  [c] Compare Both Algorithms" << endl;
    cout << "  [t] Run Predefined Test Cases" << endl;
    cout << "  [n] New Array " << endl;
    cout << "  [e] Exit" << endl;
    printSeparator('=', 50);
    cout << "  Enter your choice: ";
}

// ============================================================
//                      MAIN FUNCTION
// ============================================================

int main() {
    /*
     * --------------------------------------------------------
     *  Time Complexity Analysis:
     * --------------------------------------------------------
     *  Linear Search:
     *    - Best Case  : O(1)     - Target is the first element
     *    - Average    : O(n)     - Scans through ~half the array
     *    - Worst Case : O(n)     - Target is last or not present
     *    - Space      : O(1)
     *
     *  Binary Search:
     *    - Best Case  : O(1)     - Target is at the middle
     *    - Average    : O(log n) - Halves search space each step
     *    - Worst Case : O(log n) - Maximum divisions required
     *    - Space      : O(1)     - Iterative implementation
     * --------------------------------------------------------
     */

     // ---- Reset console color to default (white on black) ----
    system("color 07");

    // ---- Welcome Message ----
    cout << "\n";
    printSeparator('*', 60);
    cout << "*";
    printCentered("", 58);
    printCentered("TREASURE HUNT", 60);
    printCentered("Search Algorithms Project", 60);
    cout << "*";
    printCentered("", 58);
    printSeparator('*', 60);
    cout << endl;
    cout << "  Welcome, Adventurer!" << endl;
    cout << "  A group of adventurers discovered an ancient map with" << endl;
    cout << "  marked locations sorted in a straight line. The treasure" << endl;
    cout << "  is hidden at one of these locations." << endl;
    cout << "  Use Linear Search or Binary Search to find it!" << endl;

    // ---- Get User Input ----
    int n;
    cout << "\n  Enter the number of marked locations (array size): ";
    while (!(cin >> n) || n <= 0) {
        cout << "  [ERROR] Invalid input. Please enter a positive integer: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }

    vector<int> locations(n);
    cout << "  Enter " << n << " marked locations (space-separated):\n  >> ";
    for (int i = 0; i < n; ++i) {
        while (!(cin >> locations[i])) {
            cout << "  [ERROR] Invalid input. Please enter an integer: ";
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }

    // Automatically sort the array if it is not sorted
    if (!isSorted(locations)) {
        cout << "\n  [INFO] The entered locations are NOT sorted." << endl;
        cout << "  Sorting automatically in ascending order..." << endl;
        sort(locations.begin(), locations.end());
        cout << "  Sorted Array : ";
        printArray(locations);
        cout << endl;
    }

    int target;
    cout << "  Enter the target treasure location: ";
    while (!(cin >> target)) {
        cout << "  [ERROR] Invalid input. Please enter an integer: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }

    cout << "\n  Your input:" << endl;
    cout << "  Array  : ";
    printArray(locations);
    cout << endl;
    cout << "  Target : " << target << endl;

    // ---- Menu Loop ----
    char choice;
    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
        case 'l': {
            // ---- Linear Search ----
            cout << "\n";
            printSeparator('=', 60);
            printCentered("LINEAR SEARCH", 60);
            printSeparator('=', 60);

            int steps = 0;
            clock_t start = clock();
            int result = linearSearch(locations, target, steps);
            clock_t end = clock();
            double timeTaken = (double)(end - start) / CLOCKS_PER_SEC * 1000.0;

            cout << "\n  --- Result ---" << endl;
            if (result != -1) {
                cout << "  Treasure FOUND at index: " << result << endl;
            }
            else {
                cout << "  Treasure NOT found (returned -1)." << endl;
            }
            cout << "  Steps taken    : " << steps << endl;
            cout << "  Execution time : " << fixed << setprecision(4) << timeTaken << " ms" << endl;
            break;
        }

        case 'b': {
            // ---- Binary Search ----
            cout << "\n";
            printSeparator('=', 60);
            printCentered("BINARY SEARCH", 60);
            printSeparator('=', 60);

            int steps = 0;
            clock_t start = clock();
            int result = binarySearch(locations, target, steps);
            clock_t end = clock();
            double timeTaken = (double)(end - start) / CLOCKS_PER_SEC * 1000.0;

            cout << "\n  --- Result ---" << endl;
            if (result != -1) {
                cout << "  Treasure FOUND at index: " << result << endl;
            }
            else {
                cout << "  Treasure NOT found (returned -1)." << endl;
            }
            cout << "  Steps taken    : " << steps << endl;
            cout << "  Execution time : " << fixed << setprecision(4) << timeTaken << " ms" << endl;
            break;
        }

        case 'c': {
            // ---- Compare Both Algorithms ----
            compareBothAlgorithms(locations, target);
            break;
        }

        case 't': {
            // ---- Run Predefined Test Cases ----
            runTestCases();
            break;
        }

        case 'n': {
            cout << "\n";
            printSeparator('=', 60);
            printCentered("ENTER NEW ARRAY", 60);
            printSeparator('=', 60);

            // إدخال حجم جديد
            cout << "\n  Enter new number of marked locations: ";
            while (!(cin >> n) || n <= 0) {
            cout << "  [ERROR] Invalid input. Enter a positive integer: ";
            cin.clear();
            cin.ignore(10000, '\n');
            }

            locations.clear();
            locations.resize(n);

            // إدخال عناصر جديدة
            cout << "  Enter " << n << " new locations:\n  >> ";
            for (int i = 0; i < n; ++i) {
                while (!(cin >> locations[i])) {
                cout << "  [ERROR] Invalid input. Enter an integer: ";
                cin.clear();
                cin.ignore(10000, '\n');
                 }
            }

            // ترتيب تلقائي
             if (!isSorted(locations)) {
                 cout << "\n  [INFO] Array not sorted. Sorting...\n";
                sort(locations.begin(), locations.end());
            }

                cout << "  New Array: ";
                printArray(locations);
                cout << endl;

            // إدخال target جديد
                cout << "  Enter new target: ";
                 while (!(cin >> target)) {
                    cout << "  [ERROR] Invalid input. Enter an integer: ";
                    cin.clear();
                    cin.ignore(10000, '\n');
                }

                cout << "\n  Updated Data:" << endl;
                cout << "  Array  : ";
                printArray(locations);
                cout << endl;
                cout << "  Target : " << target << endl;

            break;
        }

        case 'e': {
            // ---- Exit ----
            cout << "\n";
            printSeparator('*', 60);
            printCentered("Thank you for using Treasure Hunt!", 60);
            printCentered("Happy Adventuring! Goodbye!", 60);
            printSeparator('*', 60);
            cout << endl;
            break;
        }

        default:
        cout << "  [ERROR] Invalid option. Please use l, b, c, t, n, or e." << endl;
            break;
        }

    } while (choice != 'e');

    return 0;
}
