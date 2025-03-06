#include <iostream>
#include <windows.h>

// ȫ�ֹ��Ӿ��
HHOOK hHook = NULL;

// ���̹��ӻص�����
LRESULT CALLBACK KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam) {
    if (nCode >= 0) {
        // wParam ��ʾ������Ϣ���ͣ��� WM_KEYDOWN �� WM_KEYUP
        if (wParam == WM_KEYDOWN) {
            // lParam �����˰�������ϸ��Ϣ
            KBDLLHOOKSTRUCT* pKeyboardHook = (KBDLLHOOKSTRUCT*)lParam;
            std::cout << "���������£�����: " << pKeyboardHook->vkCode << std::endl;
        }
    }
    // ������һ������
    return CallNextHookEx(hHook, nCode, wParam, lParam);
}

// ��װ���̹���
BOOL InstallKeyboardHook() {
    // WH_KEYBOARD_LL ��ʾ�ͼ����̹���
    hHook = SetWindowsHookEx(WH_KEYBOARD_LL, KeyboardProc, NULL, 0);
    return hHook != NULL;
}

// ж�ؼ��̹���
BOOL UninstallKeyboardHook() {
    if (hHook != NULL) {
        return UnhookWindowsHookEx(hHook);
    }
    return FALSE;
}

int main() {
    if (InstallKeyboardHook()) {
        std::cout << "���̹����Ѱ�װ" << std::endl;

        // ������Ϣѭ��
        MSG msg;
        while (GetMessage(&msg, NULL, 0, 0) > 0) {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }

        // ж�ؼ��̹���
        UninstallKeyboardHook();
        std::cout << "���̹�����ж��" << std::endl;
    } else {
        std::cerr << "�޷���װ���̹���" << std::endl;
    }

    return 0;
}