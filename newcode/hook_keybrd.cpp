#include <iostream>
#include <windows.h>

HHOOK hHook = NULL;

// Define a callback function for the low-level keyboard hook
LRESULT CALLBACK KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam) {
    // Check if the hook procedure must process the message
    if (nCode >= 0) {
        // Check if the message is a key press event
        if (wParam == WM_KEYDOWN) {
            
            // Cast the lParam to a pointer to KBDLLHOOKSTRUCT to access the key information
            KBDLLHOOKSTRUCT* pKeyboardHook = (KBDLLHOOKSTRUCT*)lParam;
            // Output the virtual key code of the pressed key to the console
            std::cout << "Key down: " << pKeyboardHook->vkCode << std::endl;
        }
    }
    
    // Pass the hook information to the next hook procedure in the current hook chain
    return CallNextHookEx(hHook, nCode, wParam, lParam);
}

// Function to install a low-level keyboard hook
BOOL InstallKeyboardHook() {

    // SetWindowsHookEx function is used to install a hook
    // WH_KEYBOARD_LL parameter specifies a low-level keyboard input event hook
    // KeyboardProc is the pointer to the hook procedure
    // NULL specifies that the hook procedure is in the same address space as the calling thread
    // 0 specifies that the hook is associated with the current thread
    hHook = SetWindowsHookEx(WH_KEYBOARD_LL, KeyboardProc, NULL, 0);
    // Return TRUE if the hook was successfully installed, otherwise FALSE
    return hHook != NULL;
}

BOOL UninstallKeyboardHook() {
    if (hHook != NULL) {
        return UnhookWindowsHookEx(hHook);
    }
    return FALSE;
}

int main() {
    if (InstallKeyboardHook()) {
        std::cout << "install keyboard hook success" << std::endl;


        MSG msg;
        while (GetMessage(&msg, NULL, 0, 0) > 0) {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        UninstallKeyboardHook();
        std::cout << "uninstall keyboard hook success" << std::endl;
    } else {
        std::cerr << "error installing keyboard hook" << std::endl;
    }

    return 0;
}