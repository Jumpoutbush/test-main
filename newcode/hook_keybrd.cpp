#include <iostream>
#include <windows.h>

// 全局钩子句柄
HHOOK hHook = NULL;

// 键盘钩子回调函数
LRESULT CALLBACK KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam) {
    if (nCode >= 0) {
        // wParam 表示按键消息类型，如 WM_KEYDOWN 或 WM_KEYUP
        if (wParam == WM_KEYDOWN) {
            // lParam 包含了按键的详细信息
            KBDLLHOOKSTRUCT* pKeyboardHook = (KBDLLHOOKSTRUCT*)lParam;
            std::cout << "按键被按下，键码: " << pKeyboardHook->vkCode << std::endl;
        }
    }
    // 调用下一个钩子
    return CallNextHookEx(hHook, nCode, wParam, lParam);
}

// 安装键盘钩子
BOOL InstallKeyboardHook() {
    // WH_KEYBOARD_LL 表示低级键盘钩子
    hHook = SetWindowsHookEx(WH_KEYBOARD_LL, KeyboardProc, NULL, 0);
    return hHook != NULL;
}

// 卸载键盘钩子
BOOL UninstallKeyboardHook() {
    if (hHook != NULL) {
        return UnhookWindowsHookEx(hHook);
    }
    return FALSE;
}

int main() {
    if (InstallKeyboardHook()) {
        std::cout << "键盘钩子已安装" << std::endl;

        // 创建消息循环
        MSG msg;
        while (GetMessage(&msg, NULL, 0, 0) > 0) {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }

        // 卸载键盘钩子
        UninstallKeyboardHook();
        std::cout << "键盘钩子已卸载" << std::endl;
    } else {
        std::cerr << "无法安装键盘钩子" << std::endl;
    }

    return 0;
}