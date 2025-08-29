#include <Windows.h> 
#include "sp_pr1.h"
 int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int nCmdShow)
/** {
	LPCTSTR lpszHelloText = TEXT("Hello World Win32 GUI Application");
	LPCTSTR lpszHelloWndTitle = TEXT("Окно сообщения");
	MessageBox(NULL, lpszHelloText, lpszHelloWndTitle, MB_OK);
	return 0;

}*/

/** {
	LPCTSTR lpszHelloText = MESSAGE_TEXT;
	LPCTSTR lpszHelloWndTitle = MESSAGE_TITLE;
	MessageBox(NULL, lpszHelloText, lpszHelloWndTitle, MB_OK);
	return 0;

}*/

/** {
	// Реализация пункта 4.8
	LPCTSTR lpszHelloWndTitle = MESSAGE_TITLE;
	TCHAR textMessage[200], worldTime[100], locTime[100];
	wsprintf(textMessage,
		TEXT("Привет из Win32 приложения с графическим интерфейсом.\nАвтор Мирзоева О.Ю., группа ПОИС-40331\n"));
	SYSTEMTIME st_GMT, st_Local;
	GetSystemTime(&st_GMT);// время по Гринвичу
	GetLocalTime(&st_Local);// локальное время
	wsprintf(worldTime, TEXT("Design time = день %d месяц %d год %d час %d мин %d\n"),
		st_GMT.wDay, st_GMT.wMonth, st_GMT.wYear, st_GMT.wHour, st_GMT.wMinute);
	lstrcat(textMessage, worldTime);
	wsprintf(locTime, TEXT("Run time = день %d месяц %d год %d час %d мин %d"),
		st_Local.wDay, st_Local.wMonth, st_Local.wYear, st_Local.wHour, st_Local.wMinute);
	lstrcat(textMessage, locTime);
	MessageBox(NULL, textMessage, lpszHelloWndTitle, MB_OK);
}*/
/** {
	// Реализация пункта 5.2
	int iRetValue1, iRetValue2;
	LPCTSTR lpszMesBoxTitle = TEXT("Изучаем MessageBox");
	LPTSTR lpszResponce;
	do {
		iRetValue1 = MessageBox(NULL, TEXT("Нажмите одну из кнопок."), lpszMesBoxTitle,
			MB_ABORTRETRYIGNORE | MB_ICONEXCLAMATION | MB_SETFOREGROUND);

		switch (iRetValue1)
		{
		case IDABORT:
			lpszResponce = (LPTSTR)TEXT("Нажата кнопка Прервать (ABORT)");
			break;
		case IDRETRY:
			lpszResponce = (LPTSTR)TEXT("Нажата кнопка Повторить (RETRY)");
			break;
		case IDIGNORE:
			lpszResponce = (LPTSTR)TEXT("Нажата кнопка Пропустить (IGNORE)");
			break;
		default: lpszResponce = (LPTSTR)TEXT("Ответ мне не понятен.");
		}

		TCHAR buf[200] = TEXT("");

		lstrcat(buf, lpszResponce);
		lstrcat(buf, TEXT(" Продолжить изучение возвращаемых значений ? "));
			iRetValue2 = MessageBox(NULL, buf, lpszMesBoxTitle,
				MB_YESNO | MB_ICONQUESTION | MB_SETFOREGROUND);
	} while (iRetValue2 != IDNO);

}*/

{
	// Реализация Задания 1
	int iRetValue1, iRetValue2;
	LPCTSTR lpszMesBoxTitle = TEXT("Изучаем MessageBox");
	LPTSTR lpszResponce;
	do {
		iRetValue1 = MessageBox(NULL, TEXT("The message box contains two push buttons: Retry and Cancel"),
			lpszMesBoxTitle,MB_RETRYCANCEL | MB_ICONEXCLAMATION | MB_DEFBUTTON1);

		switch (iRetValue1)
		{
		case IDRETRY:
			lpszResponce = (LPTSTR)TEXT("Нажата кнопка Повторить (RETRY)\n");
			break;
		case IDCANCEL:
			lpszResponce = (LPTSTR)TEXT("Нажата кнопка Отмена (CANCEL)\n");
			break;
		default: lpszResponce = (LPTSTR)TEXT("Ответ мне не понятен.");
		}

		TCHAR buf[200] = TEXT("");

		lstrcat(buf, lpszResponce);
		lstrcat(buf, TEXT(" Продолжить изучение возвращаемых значений? "));
		iRetValue2 = MessageBox(NULL, buf, lpszMesBoxTitle,
			MB_YESNO | MB_ICONQUESTION | MB_SETFOREGROUND);
	} while (iRetValue2 != IDNO);
}

