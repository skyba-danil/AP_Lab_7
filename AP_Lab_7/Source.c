#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

void dateNumberToWords(char* str, FILE* tmp);


int main(void) 
{
	system("chcp 1251");
	char str[50], ftmpname[] = "tmp file.txt";
	FILE* oldFile, * tmpFile;
	char* foldname = "date.txt";
	oldFile = fopen(foldname, "r");
	if ((tmpFile = fopen(ftmpname, "w")) == NULL)
	{
		printf("TMP file isn`t created!");
		return 1;
	}
	while (fgets(str, 12, oldFile) != NULL)
	{
		printf("%s", str);
		dateNumberToWords(str, tmpFile);
	}
	fclose(oldFile);
	fclose(tmpFile);
	if (remove(foldname) == 0) { /* витираємо початковий файл */
		rename(ftmpname, foldname); /* перейменовуємо створений */
		printf("Файл %s відредаговано.\n", foldname);
	}
	else
		printf("Створено новий файл - %s \n", ftmpname);
}

void dateNumberToWords(char* str, FILE* tmp)
{
	char buf[3];
	char* month[] = { "січня","лютого","березня","квітня","травня","червня","липня","серпня","вересня","жовтня","листопаду","грудня" };
	buf[0] = str[3];
	buf[1] = str[4];
	buf[2] = '\0';
	int monNumb = atoi(buf);
	fprintf(tmp, "%c%c %s %c%c%c%c р.\n", str[0], str[1], month[monNumb - 1], str[6], str[7], str[8], str[9]);
}