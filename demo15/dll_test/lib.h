#pragma once

// ��̬ ����  ����DLL
#pragma comment(lib,"dlltest")

extern "C" void ext_test();

// ��̬���� ���� DLL
typedef void (*PMessageBox)();

PMessageBox get_box()
{
	// ���� DLL ���ڴ�ռ�
	HMODULE hMpdule = LoadLibrary(TEXT("dlltest.dll"));

	if (hMpdule == NULL)
	{
		MessageBox(NULL, TEXT("�������"), TEXT("ERROR"), MB_OK);
		return nullptr;
	}

	// ָ��DLL �м��غ�����ַ
	PMessageBox pMsg = (PMessageBox)GetProcAddress(hMpdule, TEXT("ext_test"));
	return pMsg;
}