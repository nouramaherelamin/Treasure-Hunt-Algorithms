#pragma once

/*
 * ============================================================
 *  Treasure Hunt - Search Algorithms (GUI Version)
 *  ============================================================
 *  Course:  Algorithms
 *  Topic:   Linear Search & Binary Search
 *  Type:    C++/CLI Windows Forms Application
 *
 *  Description:
 *  A GUI application that finds the treasure location
 *  in an array using Linear and Binary Search algorithms.
 *  Converted from a console application while preserving
 *  all original search logic, test cases, and comparisons.
 * ============================================================
 */

namespace TreasureHuntGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;
	using namespace System::Diagnostics; // For Stopwatch

	/// <summary>
	/// Main form for the Treasure Hunt GUI application.
	/// </summary>
	public ref class TreasureHuntForm : public System::Windows::Forms::Form
	{
	public:
		TreasureHuntForm(void)
		{
			InitializeComponent();
		}

	protected:
		~TreasureHuntForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		System::ComponentModel::Container ^components;

		// --- Header ---
		System::Windows::Forms::Label^ lblTitle;
		System::Windows::Forms::Label^ lblSubtitle;
		System::Windows::Forms::Label^ lblTreasureIcon;

		// --- Input Section ---
		System::Windows::Forms::Label^ lblArrayInput;
		System::Windows::Forms::TextBox^ txtArrayInput;
		System::Windows::Forms::Label^ lblTargetInput;
		System::Windows::Forms::TextBox^ txtTargetInput;

		// --- Buttons ---
		System::Windows::Forms::Button^ btnLinearSearch;
		System::Windows::Forms::Button^ btnBinarySearch;
		System::Windows::Forms::Button^ btnCompare;
		System::Windows::Forms::Button^ btnTestCases;
		System::Windows::Forms::Button^ btnClear;
		System::Windows::Forms::Button^ btnExit;

		// --- Result Section ---
		System::Windows::Forms::Label^ lblResultTitle;
		System::Windows::Forms::Label^ lblResultValue;
		
		System::Windows::Forms::Label^ lblStepsTitle;
		System::Windows::Forms::Label^ lblStepsValue;

		System::Windows::Forms::Label^ lblTimeTitle;
		System::Windows::Forms::Label^ lblTimeValue;

		System::Windows::Forms::Label^ lblWinnerTitle;
		System::Windows::Forms::Label^ lblWinnerValue;

		// --- Steps Display ---
		System::Windows::Forms::Label^ lblLogTitle;
		System::Windows::Forms::RichTextBox^ rtbSteps;

		// --- Panels ---
		System::Windows::Forms::Panel^ panelHeader;
		System::Windows::Forms::Panel^ panelInput;
		System::Windows::Forms::Panel^ panelResults;
		System::Windows::Forms::Panel^ panelSteps;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->components = gcnew System::ComponentModel::Container();

			this->panelHeader = gcnew System::Windows::Forms::Panel();
			this->panelInput = gcnew System::Windows::Forms::Panel();
			this->panelResults = gcnew System::Windows::Forms::Panel();
			this->panelSteps = gcnew System::Windows::Forms::Panel();

			this->lblTitle = gcnew System::Windows::Forms::Label();
			this->lblSubtitle = gcnew System::Windows::Forms::Label();
			this->lblTreasureIcon = gcnew System::Windows::Forms::Label();

			this->lblArrayInput = gcnew System::Windows::Forms::Label();
			this->txtArrayInput = gcnew System::Windows::Forms::TextBox();
			this->lblTargetInput = gcnew System::Windows::Forms::Label();
			this->txtTargetInput = gcnew System::Windows::Forms::TextBox();

			this->btnLinearSearch = gcnew System::Windows::Forms::Button();
			this->btnBinarySearch = gcnew System::Windows::Forms::Button();
			this->btnCompare = gcnew System::Windows::Forms::Button();
			this->btnTestCases = gcnew System::Windows::Forms::Button();
			this->btnClear = gcnew System::Windows::Forms::Button();
			this->btnExit = gcnew System::Windows::Forms::Button();

			this->lblResultTitle = gcnew System::Windows::Forms::Label();
			this->lblResultValue = gcnew System::Windows::Forms::Label();
			this->lblStepsTitle = gcnew System::Windows::Forms::Label();
			this->lblStepsValue = gcnew System::Windows::Forms::Label();
			this->lblTimeTitle = gcnew System::Windows::Forms::Label();
			this->lblTimeValue = gcnew System::Windows::Forms::Label();
			this->lblWinnerTitle = gcnew System::Windows::Forms::Label();
			this->lblWinnerValue = gcnew System::Windows::Forms::Label();

			this->lblLogTitle = gcnew System::Windows::Forms::Label();
			this->rtbSteps = gcnew System::Windows::Forms::RichTextBox();

			this->SuspendLayout();

			// Main Form Settings
			this->Text = L"Treasure Hunt - Search Algorithms";
			this->Size = System::Drawing::Size(760, 850);
			this->StartPosition = FormStartPosition::CenterScreen;
			this->BackColor = Color::FromArgb(20, 20, 40); // Deep dark navy background
			this->ForeColor = Color::White;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Font = gcnew System::Drawing::Font(L"Segoe UI", 10);

			// Header Panel
			this->panelHeader->Location = System::Drawing::Point(0, 0);
			this->panelHeader->Size = System::Drawing::Size(760, 100);
			this->panelHeader->BackColor = Color::FromArgb(30, 30, 60);

			this->lblTreasureIcon->Text = L"*";
			this->lblTreasureIcon->Font = gcnew System::Drawing::Font(L"Segoe UI", 36, FontStyle::Bold);
			this->lblTreasureIcon->ForeColor = Color::Gold;
			this->lblTreasureIcon->Location = System::Drawing::Point(20, 18);
			this->lblTreasureIcon->AutoSize = true;

			this->lblTitle->Text = L"TREASURE HUNT";
			this->lblTitle->Font = gcnew System::Drawing::Font(L"Segoe UI", 26, FontStyle::Bold);
			this->lblTitle->ForeColor = Color::Gold;
			this->lblTitle->Location = System::Drawing::Point(80, 12);
			this->lblTitle->AutoSize = true;

			this->lblSubtitle->Text = L"Linear Search & Binary Search Comparison";
			this->lblSubtitle->Font = gcnew System::Drawing::Font(L"Segoe UI", 11, FontStyle::Italic);
			this->lblSubtitle->ForeColor = Color::FromArgb(180, 180, 220);
			this->lblSubtitle->Location = System::Drawing::Point(85, 62);
			this->lblSubtitle->AutoSize = true;

			this->panelHeader->Controls->Add(this->lblTreasureIcon);
			this->panelHeader->Controls->Add(this->lblTitle);
			this->panelHeader->Controls->Add(this->lblSubtitle);

			// Input Panel
			this->panelInput->Location = System::Drawing::Point(20, 110);
			this->panelInput->Size = System::Drawing::Size(705, 150);
			this->panelInput->BackColor = Color::FromArgb(35, 35, 65);
			this->panelInput->Padding = System::Windows::Forms::Padding(15);

			this->lblArrayInput->Text = L"Enter Locations (space-separated) - Auto-sorted if needed:";
			this->lblArrayInput->Font = gcnew System::Drawing::Font(L"Segoe UI", 10, FontStyle::Bold);
			this->lblArrayInput->ForeColor = Color::FromArgb(130, 200, 255);
			this->lblArrayInput->Location = System::Drawing::Point(15, 12);
			this->lblArrayInput->AutoSize = true;

			this->txtArrayInput->Location = System::Drawing::Point(15, 38);
			this->txtArrayInput->Size = System::Drawing::Size(675, 30);
			this->txtArrayInput->Font = gcnew System::Drawing::Font(L"Consolas", 12);
			this->txtArrayInput->BackColor = Color::FromArgb(50, 50, 85);
			this->txtArrayInput->ForeColor = Color::White;
			this->txtArrayInput->BorderStyle = BorderStyle::FixedSingle;
			this->txtArrayInput->Text = L"1 3 5 7 9";

			this->lblTargetInput->Text = L"Enter Target Treasure Location:";
			this->lblTargetInput->Font = gcnew System::Drawing::Font(L"Segoe UI", 10, FontStyle::Bold);
			this->lblTargetInput->ForeColor = Color::FromArgb(130, 200, 255);
			this->lblTargetInput->Location = System::Drawing::Point(15, 78);
			this->lblTargetInput->AutoSize = true;

			this->txtTargetInput->Location = System::Drawing::Point(15, 104);
			this->txtTargetInput->Size = System::Drawing::Size(200, 30);
			this->txtTargetInput->Font = gcnew System::Drawing::Font(L"Consolas", 12);
			this->txtTargetInput->BackColor = Color::FromArgb(50, 50, 85);
			this->txtTargetInput->ForeColor = Color::White;
			this->txtTargetInput->BorderStyle = BorderStyle::FixedSingle;
			this->txtTargetInput->Text = L"5";

			this->panelInput->Controls->Add(this->lblArrayInput);
			this->panelInput->Controls->Add(this->txtArrayInput);
			this->panelInput->Controls->Add(this->lblTargetInput);
			this->panelInput->Controls->Add(this->txtTargetInput);

			// Buttons Area
			int btnY1 = 275;
			int btnY2 = 325;
			int btnHeight = 40;
			int btnWidth = 155;
			int spacing = 15;

			// Row 1 Buttons
			this->btnLinearSearch->Text = L"Linear Search";
			this->btnLinearSearch->Location = System::Drawing::Point(20, btnY1);
			this->btnLinearSearch->Size = System::Drawing::Size(btnWidth, btnHeight);
			this->btnLinearSearch->Font = gcnew System::Drawing::Font(L"Segoe UI", 11, FontStyle::Bold);
			this->btnLinearSearch->BackColor = Color::FromArgb(0, 150, 200); // Blue
			this->btnLinearSearch->ForeColor = Color::White;
			this->btnLinearSearch->FlatStyle = FlatStyle::Flat;
			this->btnLinearSearch->FlatAppearance->BorderSize = 0;
			this->btnLinearSearch->Cursor = Cursors::Hand;
			this->btnLinearSearch->Click += gcnew System::EventHandler(this, &TreasureHuntForm::btnLinearSearch_Click);

			this->btnBinarySearch->Text = L"Binary Search";
			this->btnBinarySearch->Location = System::Drawing::Point(20 + btnWidth + spacing, btnY1);
			this->btnBinarySearch->Size = System::Drawing::Size(btnWidth, btnHeight);
			this->btnBinarySearch->Font = gcnew System::Drawing::Font(L"Segoe UI", 11, FontStyle::Bold);
			this->btnBinarySearch->BackColor = Color::FromArgb(0, 180, 80); // Green
			this->btnBinarySearch->ForeColor = Color::White;
			this->btnBinarySearch->FlatStyle = FlatStyle::Flat;
			this->btnBinarySearch->FlatAppearance->BorderSize = 0;
			this->btnBinarySearch->Cursor = Cursors::Hand;
			this->btnBinarySearch->Click += gcnew System::EventHandler(this, &TreasureHuntForm::btnBinarySearch_Click);

			this->btnCompare->Text = L"Compare Both";
			this->btnCompare->Location = System::Drawing::Point(20 + 2 * (btnWidth + spacing), btnY1);
			this->btnCompare->Size = System::Drawing::Size(btnWidth, btnHeight);
			this->btnCompare->Font = gcnew System::Drawing::Font(L"Segoe UI", 11, FontStyle::Bold);
			this->btnCompare->BackColor = Color::FromArgb(200, 100, 200); // Purple
			this->btnCompare->ForeColor = Color::White;
			this->btnCompare->FlatStyle = FlatStyle::Flat;
			this->btnCompare->FlatAppearance->BorderSize = 0;
			this->btnCompare->Cursor = Cursors::Hand;
			this->btnCompare->Click += gcnew System::EventHandler(this, &TreasureHuntForm::btnCompare_Click);

			this->btnTestCases->Text = L"Run Test Cases";
			this->btnTestCases->Location = System::Drawing::Point(20 + 3 * (btnWidth + spacing), btnY1);
			this->btnTestCases->Size = System::Drawing::Size(btnWidth + 40, btnHeight); // Slightly wider
			this->btnTestCases->Font = gcnew System::Drawing::Font(L"Segoe UI", 11, FontStyle::Bold);
			this->btnTestCases->BackColor = Color::FromArgb(100, 100, 180); // Indigo
			this->btnTestCases->ForeColor = Color::White;
			this->btnTestCases->FlatStyle = FlatStyle::Flat;
			this->btnTestCases->FlatAppearance->BorderSize = 0;
			this->btnTestCases->Cursor = Cursors::Hand;
			this->btnTestCases->Click += gcnew System::EventHandler(this, &TreasureHuntForm::btnTestCases_Click);

			// Row 2 Buttons
			this->btnClear->Text = L"Clear / New Array";
			this->btnClear->Location = System::Drawing::Point(20, btnY2);
			this->btnClear->Size = System::Drawing::Size(btnWidth * 2 + spacing, btnHeight);
			this->btnClear->Font = gcnew System::Drawing::Font(L"Segoe UI", 11, FontStyle::Bold);
			this->btnClear->BackColor = Color::FromArgb(220, 150, 0); // Orange
			this->btnClear->ForeColor = Color::White;
			this->btnClear->FlatStyle = FlatStyle::Flat;
			this->btnClear->FlatAppearance->BorderSize = 0;
			this->btnClear->Cursor = Cursors::Hand;
			this->btnClear->Click += gcnew System::EventHandler(this, &TreasureHuntForm::btnClear_Click);

			this->btnExit->Text = L"Exit";
			this->btnExit->Location = System::Drawing::Point(20 + 2 * (btnWidth + spacing), btnY2);
			this->btnExit->Size = System::Drawing::Size(btnWidth * 2 + spacing + 40, btnHeight);
			this->btnExit->Font = gcnew System::Drawing::Font(L"Segoe UI", 11, FontStyle::Bold);
			this->btnExit->BackColor = Color::FromArgb(200, 60, 60); // Red
			this->btnExit->ForeColor = Color::White;
			this->btnExit->FlatStyle = FlatStyle::Flat;
			this->btnExit->FlatAppearance->BorderSize = 0;
			this->btnExit->Cursor = Cursors::Hand;
			this->btnExit->Click += gcnew System::EventHandler(this, &TreasureHuntForm::btnExit_Click);

			// Results Panel
			this->panelResults->Location = System::Drawing::Point(20, 380);
			this->panelResults->Size = System::Drawing::Size(705, 100);
			this->panelResults->BackColor = Color::FromArgb(35, 35, 65);

			// Column 1
			this->lblResultTitle->Text = L"Result Index:";
			this->lblResultTitle->Font = gcnew System::Drawing::Font(L"Segoe UI", 10, FontStyle::Bold);
			this->lblResultTitle->ForeColor = Color::FromArgb(130, 200, 255);
			this->lblResultTitle->Location = System::Drawing::Point(15, 15);
			this->lblResultTitle->AutoSize = true;

			this->lblResultValue->Text = L"---";
			this->lblResultValue->Font = gcnew System::Drawing::Font(L"Segoe UI", 12, FontStyle::Bold);
			this->lblResultValue->ForeColor = Color::Gold;
			this->lblResultValue->Location = System::Drawing::Point(120, 13);
			this->lblResultValue->AutoSize = true;

			this->lblStepsTitle->Text = L"Total Steps:";
			this->lblStepsTitle->Font = gcnew System::Drawing::Font(L"Segoe UI", 10, FontStyle::Bold);
			this->lblStepsTitle->ForeColor = Color::FromArgb(130, 200, 255);
			this->lblStepsTitle->Location = System::Drawing::Point(15, 55);
			this->lblStepsTitle->AutoSize = true;

			this->lblStepsValue->Text = L"---";
			this->lblStepsValue->Font = gcnew System::Drawing::Font(L"Segoe UI", 12, FontStyle::Bold);
			this->lblStepsValue->ForeColor = Color::FromArgb(255, 200, 100);
			this->lblStepsValue->Location = System::Drawing::Point(120, 53);
			this->lblStepsValue->AutoSize = true;

			// Column 2
			this->lblTimeTitle->Text = L"Time (ms):";
			this->lblTimeTitle->Font = gcnew System::Drawing::Font(L"Segoe UI", 10, FontStyle::Bold);
			this->lblTimeTitle->ForeColor = Color::FromArgb(130, 200, 255);
			this->lblTimeTitle->Location = System::Drawing::Point(280, 15);
			this->lblTimeTitle->AutoSize = true;

			this->lblTimeValue->Text = L"---";
			this->lblTimeValue->Font = gcnew System::Drawing::Font(L"Segoe UI", 12, FontStyle::Bold);
			this->lblTimeValue->ForeColor = Color::LightGreen;
			this->lblTimeValue->Location = System::Drawing::Point(380, 13);
			this->lblTimeValue->AutoSize = true;

			this->lblWinnerTitle->Text = L"Winner:";
			this->lblWinnerTitle->Font = gcnew System::Drawing::Font(L"Segoe UI", 10, FontStyle::Bold);
			this->lblWinnerTitle->ForeColor = Color::FromArgb(130, 200, 255);
			this->lblWinnerTitle->Location = System::Drawing::Point(280, 55);
			this->lblWinnerTitle->AutoSize = true;

			this->lblWinnerValue->Text = L"---";
			this->lblWinnerValue->Font = gcnew System::Drawing::Font(L"Segoe UI", 11, FontStyle::Bold);
			this->lblWinnerValue->ForeColor = Color::Cyan;
			this->lblWinnerValue->Location = System::Drawing::Point(380, 53);
			this->lblWinnerValue->AutoSize = true;

			this->panelResults->Controls->Add(this->lblResultTitle);
			this->panelResults->Controls->Add(this->lblResultValue);
			this->panelResults->Controls->Add(this->lblStepsTitle);
			this->panelResults->Controls->Add(this->lblStepsValue);
			this->panelResults->Controls->Add(this->lblTimeTitle);
			this->panelResults->Controls->Add(this->lblTimeValue);
			this->panelResults->Controls->Add(this->lblWinnerTitle);
			this->panelResults->Controls->Add(this->lblWinnerValue);

			// Steps Panel
			this->panelSteps->Location = System::Drawing::Point(20, 495);
			this->panelSteps->Size = System::Drawing::Size(705, 300);
			this->panelSteps->BackColor = Color::FromArgb(35, 35, 65);

			this->lblLogTitle->Text = L"Steps / Log Output:";
			this->lblLogTitle->Font = gcnew System::Drawing::Font(L"Segoe UI", 10, FontStyle::Bold);
			this->lblLogTitle->ForeColor = Color::FromArgb(130, 200, 255);
			this->lblLogTitle->Location = System::Drawing::Point(15, 10);
			this->lblLogTitle->AutoSize = true;

			this->rtbSteps->Location = System::Drawing::Point(15, 35);
			this->rtbSteps->Size = System::Drawing::Size(675, 250);
			this->rtbSteps->Font = gcnew System::Drawing::Font(L"Consolas", 10);
			this->rtbSteps->BackColor = Color::FromArgb(18, 18, 35);
			this->rtbSteps->ForeColor = Color::FromArgb(200, 220, 255);
			this->rtbSteps->ReadOnly = true;
			this->rtbSteps->BorderStyle = BorderStyle::None;
			this->rtbSteps->ScrollBars = RichTextBoxScrollBars::Vertical;
			this->rtbSteps->Text = L"Welcome to Treasure Hunt!\nEnter locations and a target, then choose an algorithm.";

			this->panelSteps->Controls->Add(this->lblLogTitle);
			this->panelSteps->Controls->Add(this->rtbSteps);

			// Add Controls to Form
			this->Controls->Add(this->panelHeader);
			this->Controls->Add(this->panelInput);
			this->Controls->Add(this->btnLinearSearch);
			this->Controls->Add(this->btnBinarySearch);
			this->Controls->Add(this->btnCompare);
			this->Controls->Add(this->btnTestCases);
			this->Controls->Add(this->btnClear);
			this->Controls->Add(this->btnExit);
			this->Controls->Add(this->panelResults);
			this->Controls->Add(this->panelSteps);

			this->ResumeLayout(false);
			this->PerformLayout();
		}
#pragma endregion

	// ============================================================
	//  CORE LOGIC & UTILITIES
	// ============================================================

	private:
		bool parseInput(System::String^ input, List<int>^% result) {
			result = gcnew List<int>();
			array<String^>^ parts = input->Trim()->Split(gcnew array<wchar_t>{' '}, StringSplitOptions::RemoveEmptyEntries);
			if (parts->Length == 0) return false;
			for each (String^ part in parts) {
				int value;
				if (!Int32::TryParse(part->Trim(), value)) {
					return false;
				}
				result->Add(value);
			}
			return true;
		}

		bool isSorted(List<int>^ arr) {
			for (int i = 1; i < arr->Count; i++) {
				if (arr[i] < arr[i - 1]) return false;
			}
			return true;
		}

		void ensureSortedAndDisplayed(List<int>^ arr, String^% logMsg) {
			if (!isSorted(arr)) {
				arr->Sort();
				logMsg += "[INFO] Array was not sorted. Automatically sorted in ascending order.\r\n\r\n";
				
				// Update the UI textbox with sorted array
				String^ sortedText = "";
				for (int i = 0; i < arr->Count; i++) {
					sortedText += arr[i].ToString();
					if (i < arr->Count - 1) sortedText += " ";
				}
				txtArrayInput->Text = sortedText;
			}
		}

		// Linear Search
		int linearSearch(List<int>^ arr, int target, int% steps, String^% stepsLog) {
			steps = 0;
			stepsLog += String::Format("{0,-10} {1,-15} {2,-15} {3}\r\n", "Step", "Index", "Value", "Match?");
			stepsLog += "------------------------------------------------------------\r\n";
			
			for (int i = 0; i < arr->Count; i++) {
				steps++;
				String^ match = (arr[i] == target) ? "YES" : "No";
				stepsLog += String::Format("{0,-10} {1,-15} {2,-15} {3}\r\n", steps, i, arr[i], match);
				
				if (arr[i] == target) {
					return i;
				}
			}
			return -1;
		}

		// Binary Search
		int binarySearch(List<int>^ arr, int target, int% steps, String^% stepsLog) {
			int low = 0;
			int high = arr->Count - 1;
			steps = 0;

			stepsLog += String::Format("{0,-8} {1,-8} {2,-8} {3,-8} {4,-12} {5}\r\n", "Step", "Low", "Mid", "High", "Mid Value", "Action");
			stepsLog += "------------------------------------------------------------\r\n";

			while (low <= high) {
				int mid = low + (high - low) / 2;
				steps++;
				
				String^ action;
				if (arr[mid] == target) action = "FOUND!";
				else if (arr[mid] < target) action = "Go Right";
				else action = "Go Left";

				stepsLog += String::Format("{0,-8} {1,-8} {2,-8} {3,-8} {4,-12} {5}\r\n", steps, low, mid, high, arr[mid], action);

				if (arr[mid] == target) return mid;
				if (arr[mid] < target) low = mid + 1;
				else high = mid - 1;
			}
			return -1;
		}

	// ============================================================
	//  EVENT HANDLERS
	// ============================================================

	private:
		System::Void btnLinearSearch_Click(System::Object^ sender, System::EventArgs^ e) {
			runSingleSearch(true);
		}

		System::Void btnBinarySearch_Click(System::Object^ sender, System::EventArgs^ e) {
			runSingleSearch(false);
		}

		void runSingleSearch(bool isLinear) {
			List<int>^ locations;
			if (!parseInput(txtArrayInput->Text, locations) || locations->Count == 0) {
				MessageBox::Show("Invalid input! Please enter integers separated by spaces.", "Input Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}

			int target;
			if (!Int32::TryParse(txtTargetInput->Text->Trim(), target)) {
				MessageBox::Show("Invalid target! Please enter a valid integer.", "Input Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}

			String^ logMsg = "";
			ensureSortedAndDisplayed(locations, logMsg);

			logMsg += "============================================================\r\n";
			logMsg += (isLinear ? "  LINEAR SEARCH\r\n" : "  BINARY SEARCH\r\n");
			logMsg += "============================================================\r\n\r\n";

			int steps = 0;
			String^ stepsLog = "";
			int result = -1;

			Stopwatch^ sw = gcnew Stopwatch();
			sw->Start();

			if (isLinear) {
				result = linearSearch(locations, target, steps, stepsLog);
			} else {
				result = binarySearch(locations, target, steps, stepsLog);
			}

			sw->Stop();
			double timeTaken = sw->Elapsed.TotalMilliseconds;

			logMsg += stepsLog;

			rtbSteps->Text = logMsg;
			lblStepsValue->Text = steps.ToString();
			lblTimeValue->Text = timeTaken.ToString("F4");
			lblWinnerValue->Text = "---";

			if (result != -1) {
				lblResultValue->Text = String::Format("Index {0}", result);
				lblResultValue->ForeColor = Color::LightGreen;
			} else {
				lblResultValue->Text = "-1 (Not Found)";
				lblResultValue->ForeColor = Color::FromArgb(255, 80, 80);
			}
		}

		System::Void btnCompare_Click(System::Object^ sender, System::EventArgs^ e) {
			List<int>^ locations;
			if (!parseInput(txtArrayInput->Text, locations) || locations->Count == 0) {
				MessageBox::Show("Invalid input!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}

			int target;
			if (!Int32::TryParse(txtTargetInput->Text->Trim(), target)) {
				MessageBox::Show("Invalid target!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}

			String^ logMsg = "";
			ensureSortedAndDisplayed(locations, logMsg);

			logMsg += "============================================================\r\n";
			logMsg += "  COMPARISON: Linear Search vs Binary Search\r\n";
			logMsg += "============================================================\r\n\r\n";

			int linSteps = 0, binSteps = 0;
			String^ linLog = "";
			String^ binLog = "";

			Stopwatch^ swLin = gcnew Stopwatch();
			swLin->Start();
			int linResult = linearSearch(locations, target, linSteps, linLog);
			swLin->Stop();
			double linTime = swLin->Elapsed.TotalMilliseconds;

			Stopwatch^ swBin = gcnew Stopwatch();
			swBin->Start();
			int binResult = binarySearch(locations, target, binSteps, binLog);
			swBin->Stop();
			double binTime = swBin->Elapsed.TotalMilliseconds;

			logMsg += "--- LINEAR SEARCH STEPS ---\r\n" + linLog + "\r\n";
			logMsg += "--- BINARY SEARCH STEPS ---\r\n" + binLog + "\r\n";
			
			logMsg += "============================================================\r\n";
			logMsg += String::Format("{0,-20} | {1,-15} | {2,-15}\r\n", "Criteria", "Linear Search", "Binary Search");
			logMsg += "------------------------------------------------------------\r\n";
			logMsg += String::Format("{0,-20} | {1,-15} | {2,-15}\r\n", "Result Index", linResult, binResult);
			logMsg += String::Format("{0,-20} | {1,-15} | {2,-15}\r\n", "Steps Taken", linSteps, binSteps);
			logMsg += String::Format("{0,-20} | {1,-15:F4} | {2,-15:F4}\r\n", "Time (ms)", linTime, binTime);
			logMsg += String::Format("{0,-20} | {1,-15} | {2,-15}\r\n", "Time Complexity", "O(n)", "O(log n)");
			logMsg += "============================================================\r\n";

			rtbSteps->Text = logMsg;

			lblResultValue->Text = String::Format("{0}", linResult);
			lblResultValue->ForeColor = (linResult != -1) ? Color::LightGreen : Color::FromArgb(255, 80, 80);
			lblStepsValue->Text = String::Format("L: {0} | B: {1}", linSteps, binSteps);
			lblTimeValue->Text = String::Format("L: {0:F3} | B: {1:F3}", linTime, binTime);

			if (binSteps < linSteps) {
				lblWinnerValue->Text = "Binary Search!";
			} else if (linSteps < binSteps) {
				lblWinnerValue->Text = "Linear Search!";
			} else {
				lblWinnerValue->Text = "Tie!";
			}
		}

		System::Void btnTestCases_Click(System::Object^ sender, System::EventArgs^ e) {
			rtbSteps->Clear();
			String^ fullLog = "";
			fullLog += "************************************************************\r\n";
			fullLog += "  RUNNING PREDEFINED TEST CASES\r\n";
			fullLog += "************************************************************\r\n\r\n";

			array<array<int>^>^ testArrays = gcnew array<array<int>^>{
				gcnew array<int>{ 1, 3, 5, 7, 9 },
				gcnew array<int>{ 10, 20, 30, 40, 50 },
				gcnew array<int>{ 15, 25, 35, 45, 55 }
			};
			array<int>^ testTargets = gcnew array<int>{ 5, 30, 60 };
			array<int>^ expected = gcnew array<int>{ 2, 2, -1 };

			for (int t = 0; t < 3; t++) {
				List<int>^ arr = gcnew List<int>();
				String^ arrayStr = "[";
				for (int i = 0; i < testArrays[t]->Length; i++) {
					arr->Add(testArrays[t][i]);
					arrayStr += testArrays[t][i].ToString();
					if (i < testArrays[t]->Length - 1) arrayStr += ", ";
				}
				arrayStr += "]";

				fullLog += "############################################################\r\n";
				fullLog += String::Format("  TEST CASE {0}:\r\n", t + 1);
				fullLog += String::Format("  Array  : {0}\r\n", arrayStr);
				fullLog += String::Format("  Target : {0}\r\n", testTargets[t]);
				fullLog += String::Format("  Expected Result : Index {0}\r\n", expected[t]);
				fullLog += "------------------------------------------------------------\r\n";

				int linSteps = 0, binSteps = 0;
				String^ linLog = "";
				String^ binLog = "";
				int linResult = linearSearch(arr, testTargets[t], linSteps, linLog);
				int binResult = binarySearch(arr, testTargets[t], binSteps, binLog);

				fullLog += String::Format("{0,-20} | {1,-15} | {2,-15}\r\n", "Criteria", "Linear Search", "Binary Search");
				fullLog += "------------------------------------------------------------\r\n";
				fullLog += String::Format("{0,-20} | {1,-15} | {2,-15}\r\n", "Result Index", linResult, binResult);
				fullLog += String::Format("{0,-20} | {1,-15} | {2,-15}\r\n", "Steps Taken", linSteps, binSteps);
				
				if (binSteps < linSteps) fullLog += "\n  >> Winner: Binary Search\r\n\r\n";
				else if (linSteps < binSteps) fullLog += "\n  >> Winner: Linear Search\r\n\r\n";
				else fullLog += "\n  >> Winner: Tie\r\n\r\n";
			}

			rtbSteps->Text = fullLog;
			lblResultValue->Text = "Tests Done";
			lblResultValue->ForeColor = Color::Gold;
			lblStepsValue->Text = "See Log";
			lblTimeValue->Text = "---";
			lblWinnerValue->Text = "---";
		}

		System::Void btnClear_Click(System::Object^ sender, System::EventArgs^ e) {
			txtArrayInput->Clear();
			txtTargetInput->Clear();
			lblResultValue->Text = "---";
			lblResultValue->ForeColor = Color::Gold;
			lblStepsValue->Text = "---";
			lblTimeValue->Text = "---";
			lblWinnerValue->Text = "---";
			rtbSteps->Text = L"Welcome to Treasure Hunt!\nEnter locations and a target, then choose an algorithm.";
			txtArrayInput->Focus();
		}

		System::Void btnExit_Click(System::Object^ sender, System::EventArgs^ e) {
			Application::Exit();
		}
	};
}
