#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <Windows.h>
#define n 6
int MinYear, i;
struct stu {char FIO [20]; char Place [20]; int Year; char Fac [20];} s; // ���������� ��������� s
struct stu uni[n]; //���������� ������� �������� uni[n]
main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	printf ("������� ���������� � ��������� \n");
	for (i=0; i<n; i++){
		printf ("������� ��������, ����� ��������, ��� ��������, ��������� \n");
		scanf("%s%s%d%s", s.FIO, &s.Place, &s.Year, &s.Fac); //���������� ���������� ��������� s
		uni[i]=s;
		}
	MinYear = uni[0].Year;
	for (i=0; i<n; i++)
		if (uni[i].Year < MinYear) MinYear = uni[i].Year; //������� ����������� ��������� s.Year
	for (i=0; i<n; i++)
		if (uni[i].Year == MinYear) printf ("%s %s %d %s \n", uni[i].FIO, uni[i].Place, uni[i].Year, uni[i].Fac);
	
getch();
}
				
	
	
	

