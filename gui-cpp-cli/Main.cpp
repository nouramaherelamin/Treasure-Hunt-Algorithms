/*
 * ============================================================
 *  Treasure Hunt - Binary Search Algorithm (GUI Version)
 *  ============================================================
 *  Main Entry Point
 *
 *  This file launches the Windows Forms GUI application.
 *  All algorithm logic and UI are defined in TreasureHuntForm.h
 * ============================================================
 */

#include "TreasureHuntForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(array<String^>^ args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    TreasureHuntGUI::TreasureHuntForm form;
    Application::Run(% form);

    return 0;
}