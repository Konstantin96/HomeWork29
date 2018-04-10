#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include <locale.h>
#include "Header.h"

int nz;

void main()
{
	FILE *file;
	setlocale(LC_ALL, "Ru");
	srand(time(NULL));
	while (true)
	{
		printf("Введите номер задания: ");
		scanf("%d", &nz);
		if (nz == 0)
		{
			break;
			system("exit");
		}
		else if (nz == 1)
		{
			/*1. Дана последовательность целых чисел, оканчивающаяся нулем. Записать все числа последовательности в типизированный файл*/
			system("cls");
			int r = 4 + rand() % 50;
			if ((file = fopen("chisla.txt", "w")) == NULL)
				perror("Произошла ошибка ");
			else
			{
				for (int i = 0; i < r; i++)
				{
					if (i < r - 1) fprintf(file, "%d\n", 1 + rand() % 200);
					else fprintf(file, "%d", 1 + rand() % 200);
				}
			}
			fclose(file);
			int razm = 0;
			int *arr = NULL;
			int *numb;
			if ((file = fopen("chisla.txt", "r")) == NULL)
				perror("Произошла ошибка ");
			else
			{
				while (!feof(file))
				{
					razm++;
					numb = (int*)realloc(arr, razm * sizeof(int));
					if (numb != NULL)
					{
						arr = numb;
						fscanf(file, "%d", &arr[razm - 1]);
					}
				}
			}
			fclose(file);

			printf("Ñîçäàíèå íîâîãî ôàéëà è çàïèñü â íåãî ÷èñåë\n");
			if ((file = fopen("chisla1.txt", "w")) == NULL)
				perror("Произошла ошибка ");
			else
			{
				for (int i = 0; i < razm; i++)
				{
					if (i < razm - 1) fprintf(file, "%d\n", arr[i]);
					else fprintf(file, "%d", arr[i]);
				}
			}
			fclose(file);
		}
		else if (nz == 2)
		{
			/*2. Дан файл f, компоненты которого являются целыми числами. Записать в файл g все четные числа файла f, а в файл h — все нечетные. Порядок следования чисел сохраняется*/
			system("cls");
			int razm = 0;
			int *arr = NULL;
			int *numb;
			printf("Ñ÷èòûâàíèå ÷èñåë ñ ôàéëà\n");
			if ((file = fopen("chisla.txt", "r")) == NULL)
				perror("Произошла ошибка ");
			else
			{
				while (!feof(file))
				{
					razm++;
					numb = (int*)realloc(arr, razm * sizeof(int));
					if (numb != NULL)
					{
						arr = numb;
						fscanf(file, "%d", &arr[razm - 1]);
					}
				}
			}
			fclose(file);
			printf("Ñîçäàíèå íîâîãî ôàéëà è çàïèñü â íåãî ÷èñåë\n");
			if ((file = fopen("chisla2.txt", "w")) == NULL)
				perror("Произошла ошибка ");
			else
			{
				for (int i = 0; i < razm - 1; i++)
				{
					if (i < 4)
					{
						fprintf(file, "%d\n", arr[i]);
					}
					else if (i >= 4)
					{
						fprintf(file, "%d\n", arr[i + 1]);
					}
					else if (i < razm - 2)
					{
						fprintf(file, "%d", arr[i + 1]);
					}
				}
			}
			fclose(file);
		}
		else if (nz == 3)
		{
			/*4.	Дан файл f, компоненты которого являются целыми числами. Никакая из компонент файла не равна нулю. Файл f содержит столько же отрицательных чисел, сколько и положительных. Используя вспомогательный файл h, переписать компоненты файла f в файл g так, чтобы в файле g:
a.	не было двух соседних чисел с одним знаком
b.	сначала шли положительные, потом отрицательные числа
c.	числа шли в следующем порядке: два положитель¬ных, два отрицательных, два положительных, два отрица¬тельных и т. д. (предполагается, что число компонент в файле f делится на 4)
*/
			system("cls");
			int razm = 0;
			char arr[80];
			if ((file = fopen("text.txt", "r")) == NULL)perror("Îøèáêà îòêðûòèÿ ôàéëà: ");
			else
			{
				while (!feof(file))
				{
					razm++;
					fgets(arr, 80, file);
				}
			}
			fclose(file);
			printf("à. Êîëè÷åñòâî ñòðîê â ôàéëå: %d\n", razm);
			char r;
			razm = 0;
			if ((file = fopen("text.txt", "r")) == NULL)perror("Îøèáêà îòêðûòèÿ ôàéëà: ");
			else
			{
				while (!feof(file))
				{
					r = fgetc(file);
					if (r != '\n')
						razm++;
				}
			}
			fclose(file);
			printf("b. Êîëè÷åñòâî ñèìâîëîâ â ôàéëå: %d\n", razm);
			printf("c. Êîëè÷åñòâî ñèìâîëîâ â ñòðîêàõ:\n");
			if ((file = fopen("text.txt", "r")) == NULL)perror("Îøèáêà îòêðûòèÿ ôàéëà: ");
			else
			{
				int s = 0, count;
				while (!feof(file))
				{
					arr[0] = '\0';
					fgets(arr, 80, file);
					s++;
					count = strlen(arr);
					printf("%d - %d\n", s, count - 1);
				}
			}
			fclose(file);
		}

		else if (nz == 4)
		{
			/*9.В существующем типизированном файле, элементами которого являются отдельные слова, изменить на заданное слово
a.	s-е слово
b.	последнее слово
*/
			system("cls");
			char arr[80];
			char sim;
			if ((file = fopen("text.txt", "r")) == NULL)
				perror("Îøèáêà îòêðûòèÿ ôàéëà: ");
			else
			{
				while (!feof(file))
				{
					fscanf(file, "%s", arr);
					printf("%s", arr);
					sim = fgetc(file);
					if (sim != 'ÿ')
						printf("%c", sim);
				}
			}
			fclose(file);
			printf("\n");

			char wordR[20];
			printf("a.\n");
			int s, sch = 0;
			printf("Ââåäèòå íîìåð ñëîâà êîòîðîå íàäî çàìåíèòü "); scanf("%d", &s);
			printf("Ââåäèòå ñëîâî íà êîòîðîå íàäî çàìåíèòü "); scanf("%s", &wordR);
			if ((file = fopen("text.txt", "r")) == NULL)perror("Îøèáêà îòêðûòèÿ ôàéëà: ");
			else
			{
				while (!feof(file))
				{
					fscanf(file, "%s", arr);
					sch++;
					if (sch == s)
						printf("%s", wordR);
					else
						printf("%s", arr);
					sim = fgetc(file);
					if (sim != 'ÿ')
						printf("%c", sim);
				}
			}
			fclose(file);
			printf("\n");
			printf("b.\n");
			s = 27, sch = 0;
			printf("Ââåäèòå ñëîâî íà êîòîðîå íàäî çàìåíèòü ïîñëåäíåå ñëîâî "); scanf("%s", &wordR);
			if ((file = fopen("text.txt", "r")) == NULL)perror("Îøèáêà îòêðûòèÿ ôàéëà: ");
			else
			{
				while (!feof(file))
				{
					fscanf(file, "%s", arr);
					sch++;
					if (sch == s)
						printf("%s", wordR);
					else
						printf("%s", arr);
					sim = fgetc(file);
					if (sim != 'ÿ')
						printf("%c", sim);
				}
			}
			fclose(file);
			printf("\n");
		}
		else if (nz == 5)
		{
			/*10.Элементами типизированного файла являются отдельные слова. Изменить все его элементы на другие слова (их значения вводятся с клавиатуры).*/
			system("cls");
			char arr[80];
			char sim;
			if ((file = fopen("text.txt", "r")) == NULL)perror("Îøèáêà îòêðûòèÿ ôàéëà: ");
			else
			{
				while (!feof(file))
				{
					fscanf(file, "%s", arr);
					printf("%s", arr);
					sim = fgetc(file);
					if (sim != 'ÿ')
						printf("%c", sim);
				}
			}
			fclose(file);
			printf("\n");
			char word[20];
			char wordR[20];
			int ln;
			printf("Ââåäèòå ñëîâî êîòîðîå íàäî çàìåíèòü "); scanf("%s", &word);
			printf("Ââåäèòå ñëîâî íà êîòîðîå íàäî çàìåíèòü "); scanf("%s", &wordR);
			if ((file = fopen("text.txt", "r")) == NULL)perror("Îøèáêà îòêðûòèÿ ôàéëà: ");
			else
			{
				while (!feof(file))
				{
					fscanf(file, "%s", arr);
					ln = strlen(arr);

					if (strcmp(arr, word) == 0)
						printf("%s", wordR);
					else
						printf("%s", arr);

					sim = fgetc(file);
					if (sim != 'ÿ')
						printf("%c", sim);
				}
			}
			fclose(file);
			printf("\n");
		}
		else if (nz == 6)
		{
			/*11.	Имеется типизированный файл, элементами которого являются отдельные буквы, составляющие последовательность орпцессор. */
			char *simb;
			int i = 1;
			simb = (char*)malloc(i * sizeof(char));
			simb[0] = '\0';
			if ((file = fopen("1.txt", "r")) == NULL)perror("Îøèáêà îòêðûòèÿ ôàéëà: ");
			else
			{
				while (!feof(file))
				{
					simb[i - 1] = fgetc(file);
					i++;
					simb = (char*)realloc(simb, i * sizeof(char));
				}
			}
			fclose(file);
			simb[i - 2] = '\0';
			char t;
			t = simb[0];
			simb[0] = simb[2];
			simb[2] = t;
			printf("\n%s\n", simb);
			if ((file = fopen("2.txt", "w")) == NULL)
				perror("Îøèáêà îòêðûòèÿ ôàéëà: ");
			else
			{
				fprintf(file, "%s", simb);
			}
			fclose(file);
		}
		else
		{
			printf("Такого задания нету! \n");
		}
	}
}