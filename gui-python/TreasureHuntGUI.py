import tkinter as tk
from tkinter import ttk, messagebox
import time

class TreasureHuntApp:
    def __init__(self, root):
        """
        Initializes the main window and all GUI components.
        Sets up the input fields, buttons, and output text area.
        """
        self.root = root
        self.root.title("Treasure Hunt Search Algorithms")
        self.root.geometry("900x750")
        self.root.configure(bg="#f4f6f9")
        
        # Configure styles for a clean, modern look
        style = ttk.Style()
        style.theme_use('clam')
        style.configure('TButton', font=('Segoe UI', 10, 'bold'), padding=8, background="#3498db", foreground="white")
        style.map('TButton', background=[('active', '#2980b9')])
        style.configure('TLabel', font=('Segoe UI', 11), background="#f4f6f9")
        style.configure('Header.TLabel', font=('Segoe UI', 16, 'bold'), foreground="#2c3e50")
        style.configure('TLabelframe', background="#f4f6f9")
        style.configure('TLabelframe.Label', font=('Segoe UI', 12, 'bold'), foreground="#34495e", background="#f4f6f9")
        
        # Main container
        main_frame = tk.Frame(self.root, bg="#f4f6f9", padx=20, pady=20)
        main_frame.pack(fill=tk.BOTH, expand=True)
        
        # Title
        title_label = ttk.Label(main_frame, text="Treasure Hunt Search Algorithms", style='Header.TLabel')
        title_label.pack(pady=(0, 20))
        
        # Input Frame
        input_frame = ttk.LabelFrame(main_frame, text="Input Data", padding="15")
        input_frame.pack(fill=tk.X, pady=5)
        
        ttk.Label(input_frame, text="Array Values (space-separated):").grid(row=0, column=0, padx=10, pady=10, sticky=tk.W)
        self.array_entry = ttk.Entry(input_frame, width=50, font=('Segoe UI', 11))
        self.array_entry.grid(row=0, column=1, padx=10, pady=10, sticky=tk.W)
        self.array_entry.insert(0, "1 3 5 7 9")
        
        ttk.Label(input_frame, text="Target Value:").grid(row=1, column=0, padx=10, pady=10, sticky=tk.W)
        self.target_entry = ttk.Entry(input_frame, width=20, font=('Segoe UI', 11))
        self.target_entry.grid(row=1, column=1, padx=10, pady=10, sticky=tk.W)
        self.target_entry.insert(0, "5")
        
        # Button Frame
        btn_frame = tk.Frame(main_frame, bg="#f4f6f9")
        btn_frame.pack(fill=tk.X, pady=15)
        
        # Row 1 buttons
        ttk.Button(btn_frame, text="Linear Search", command=self.do_linear_search).grid(row=0, column=0, padx=8, pady=8)
        ttk.Button(btn_frame, text="Binary Search", command=self.do_binary_search).grid(row=0, column=1, padx=8, pady=8)
        ttk.Button(btn_frame, text="Compare Both", command=self.do_compare).grid(row=0, column=2, padx=8, pady=8)
        ttk.Button(btn_frame, text="Run Test Cases", command=self.run_test_cases).grid(row=0, column=3, padx=8, pady=8)
        
        # Row 2 buttons
        ttk.Button(btn_frame, text="New Array / Update Input", command=self.update_input).grid(row=1, column=0, padx=8, pady=8)
        ttk.Button(btn_frame, text="Clear Output", command=self.clear_output).grid(row=1, column=1, padx=8, pady=8)
        ttk.Button(btn_frame, text="Exit", command=self.root.quit).grid(row=1, column=2, padx=8, pady=8)
        
        # Output text area
        output_frame = ttk.LabelFrame(main_frame, text="Output Console", padding="10")
        output_frame.pack(fill=tk.BOTH, expand=True, pady=10)
        
        self.output_text = tk.Text(output_frame, font=('Consolas', 11), wrap=tk.NONE, bg="#212f3d", fg="#ecf0f1", insertbackground="white")
        self.output_text.pack(fill=tk.BOTH, expand=True, side=tk.LEFT)
        
        scrollbar = ttk.Scrollbar(output_frame, orient=tk.VERTICAL, command=self.output_text.yview)
        scrollbar.pack(side=tk.RIGHT, fill=tk.Y)
        self.output_text.configure(yscrollcommand=scrollbar.set)
        
        # Configure colors for text tags
        self.output_text.tag_configure("header", foreground="#f1c40f", font=('Consolas', 12, 'bold')) # Yellow
        self.output_text.tag_configure("success", foreground="#2ecc71", font=('Consolas', 11, 'bold')) # Green
        self.output_text.tag_configure("error", foreground="#e74c3c", font=('Consolas', 11, 'bold')) # Red
        self.output_text.tag_configure("info", foreground="#3498db") # Blue
        self.output_text.tag_configure("table", foreground="#bdc3c7") # Light Gray
        
        # State variables
        self.current_array = []
        self.current_target = None
        
        # Initial greeting
        self.print_out("Welcome to the Treasure Hunt Search Algorithms Project!", "header")
        self.print_out("Please update your input or run test cases to begin.\n")

    def print_out(self, text, tag=None):
        """Helper to print text to the output text area with an optional color tag."""
        self.output_text.insert(tk.END, text + "\n", tag)
        self.output_text.see(tk.END)

    def clear_output(self):
        """Clears all text from the output text area."""
        self.output_text.delete(1.0, tk.END)

    def update_input(self):
        """
        Reads input from the GUI entry fields, validates them,
        checks if the array is sorted (sorts if not), and updates internal state.
        Returns True if successful, False if invalid input.
        """
        arr_str = self.array_entry.get().strip()
        target_str = self.target_entry.get().strip()
        
        if not arr_str or not target_str:
            self.print_out("Error: Please enter both array and target values.", "error")
            return False
            
        try:
            arr = [int(x) for x in arr_str.split()]
            target = int(target_str)
        except ValueError:
            self.print_out("Error: Please enter valid integer numbers separated by spaces.", "error")
            return False
            
        self.current_target = target
        
        # Check if sorted and sort automatically if needed
        is_sorted = all(arr[i] <= arr[i+1] for i in range(len(arr)-1))
        if not is_sorted:
            self.print_out("Notice: Array is not sorted. Sorting automatically...", "info")
            arr.sort()
            
        self.current_array = arr
        self.print_out(f"Current Array: {self.current_array}", "header")
        self.print_out(f"Current Target: {self.current_target}\n", "header")
        
        return True

    def linear_search_algo(self, arr, target):
        """
        Implements the Linear Search algorithm.
        Returns the index found (or -1), steps taken, time in ms, and step-by-step log.
        """
        steps = 0
        result_idx = -1
        
        log = []
        log.append(f"{'Step':<6} | {'Index':<6} | {'Value':<6} | {'Match?':<6}")
        log.append("-" * 35)
        
        start_time = time.perf_counter()
        
        for i, val in enumerate(arr):
            steps += 1
            match = "YES" if val == target else "No"
            log.append(f"{steps:<6} | {i:<6} | {val:<6} | {match:<6}")
            if val == target:
                result_idx = i
                break
                
        end_time = time.perf_counter()
        exec_time = (end_time - start_time) * 1000 # convert to ms
        
        return result_idx, steps, exec_time, log

    def binary_search_algo(self, arr, target):
        """
        Implements the Binary Search algorithm.
        Returns the index found (or -1), steps taken, time in ms, and step-by-step log.
        """
        steps = 0
        result_idx = -1
        low = 0
        high = len(arr) - 1
        
        log = []
        log.append(f"{'Step':<6} | {'Low':<4} | {'Mid':<4} | {'High':<5} | {'Mid Value':<10} | {'Action':<10}")
        log.append("-" * 60)
        
        start_time = time.perf_counter()
        
        while low <= high:
            steps += 1
            mid = low + (high - low) // 2
            mid_val = arr[mid]
            
            if mid_val == target:
                action = "FOUND!"
                log.append(f"{steps:<6} | {low:<4} | {mid:<4} | {high:<5} | {mid_val:<10} | {action:<10}")
                result_idx = mid
                break
            elif mid_val < target:
                action = "Go Right"
                log.append(f"{steps:<6} | {low:<4} | {mid:<4} | {high:<5} | {mid_val:<10} | {action:<10}")
                low = mid + 1
            else:
                action = "Go Left"
                log.append(f"{steps:<6} | {low:<4} | {mid:<4} | {high:<5} | {mid_val:<10} | {action:<10}")
                high = mid - 1
                
        end_time = time.perf_counter()
        exec_time = (end_time - start_time) * 1000 # convert to ms
        
        return result_idx, steps, exec_time, log

    def do_linear_search(self):
        """Triggered by the Linear Search button. Runs and displays the result."""
        if not self.update_input(): return
        
        self.print_out("--- Linear Search ---", "header")
        idx, steps, t_ms, log = self.linear_search_algo(self.current_array, self.current_target)
        
        for line in log:
            self.print_out(line, "table")
            
        self.print_out(f"\nResult: {'Found at index ' + str(idx) if idx != -1 else 'Not found (-1)'}", "success" if idx != -1 else "error")
        self.print_out(f"Steps: {steps}")
        self.print_out(f"Time: {t_ms:.6f} ms")
        self.print_out("Time Complexity: O(n)\n", "info")

    def do_binary_search(self):
        """Triggered by the Binary Search button. Runs and displays the result."""
        if not self.update_input(): return
        
        self.print_out("--- Binary Search ---", "header")
        idx, steps, t_ms, log = self.binary_search_algo(self.current_array, self.current_target)
        
        for line in log:
            self.print_out(line, "table")
            
        self.print_out(f"\nResult: {'Found at index ' + str(idx) if idx != -1 else 'Not found (-1)'}", "success" if idx != -1 else "error")
        self.print_out(f"Steps: {steps}")
        self.print_out(f"Time: {t_ms:.6f} ms")
        self.print_out("Time Complexity: O(log n)\n", "info")

    def do_compare(self, array_to_use=None, target_to_use=None, no_update=False):
        """
        Triggered by Compare Both button or Test Cases. 
        Runs both algorithms and displays a comparison table.
        """
        if not no_update:
            if not self.update_input(): return
            arr = self.current_array
            target = self.current_target
        else:
            arr = array_to_use
            target = target_to_use
            
        self.print_out("--- Compare Linear vs Binary Search ---", "header")
        
        l_idx, l_steps, l_time, _ = self.linear_search_algo(arr, target)
        b_idx, b_steps, b_time, _ = self.binary_search_algo(arr, target)
        
        self.print_out(f"{'Criteria':<20} | {'Linear Search':<15} | {'Binary Search':<15}", "table")
        self.print_out("-" * 56, "table")
        self.print_out(f"{'Result Index':<20} | {l_idx:<15} | {b_idx:<15}", "table")
        self.print_out(f"{'Steps Taken':<20} | {l_steps:<15} | {b_steps:<15}", "table")
        self.print_out(f"{'Time (ms)':<20} | {l_time:<15.6f} | {b_time:<15.6f}", "table")
        self.print_out(f"{'Time Complexity':<20} | {'O(n)':<15} | {'O(log n)':<15}", "table")
        
        self.print_out("\nWinner:", "header")
        if b_steps < l_steps:
            self.print_out("Binary Search is faster with fewer steps.", "success")
        elif l_steps < b_steps:
            self.print_out("Linear Search completed in fewer steps.", "success")
        else:
            self.print_out("Both algorithms took the same number of steps.", "info")
        self.print_out("\n")

    def run_test_cases(self):
        """Runs predefined test cases and shows the comparison results for each."""
        self.clear_output()
        self.print_out("=== Running Predefined Test Cases ===\n", "header")
        
        test_cases = [
            {"arr": [1, 3, 5, 7, 9], "target": 5, "expected": 2},
            {"arr": [10, 20, 30, 40, 50], "target": 30, "expected": 2},
            {"arr": [15, 25, 35, 45, 55], "target": 60, "expected": -1}
        ]
        
        for i, tc in enumerate(test_cases, 1):
            arr = tc["arr"]
            target = tc["target"]
            expected = tc["expected"]
            
            self.print_out(f"Test Case {i}:", "header")
            self.print_out(f"Array: {arr}")
            self.print_out(f"Target: {target}")
            self.print_out(f"Expected Result: {expected}\n")
            
            # Since test cases are pre-sorted, we just pass them to compare directly
            self.do_compare(array_to_use=arr, target_to_use=target, no_update=True)
            self.print_out("=" * 60 + "\n", "info")

if __name__ == "__main__":
    root = tk.Tk()
    app = TreasureHuntApp(root)
    root.mainloop()
