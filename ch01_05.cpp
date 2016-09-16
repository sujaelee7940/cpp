//============================================================================
// Name        : ch01_05.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
/*
 *
아래처럼2차원배열의바깥부터숫자를달팽이모양으로채우시오.
• 입력
• 한 줄에 <배열의 너비> <시작 위치> <방향>이 공백을 사이에 두고 주어진다.
• <배열의 너비>: 1 이상 20 이하의 자연수. 2차원 배열의 너비(=높이) • <시작위치>:0,1,2,3중하나
• 0:왼쪽위,1:오른쪽위,2:오른쪽아래,3:왼쪽아래 • <방향>: C 혹은 CC
• C: 시계 방향으로 채우기 (clockwise)
• CC: 반시계 방향으로 채우기 (counter clockwise)
 */
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	int width, start;
	string direction;

	cin >> width >> start >> direction ;

	int a[width][width];
	// col 초기화
	for(auto &row :a)
		for(auto &col : row)
			{
			col=0;
			}
	int d,putting_direction;
	if(direction == "C")  {d = 1; putting_direction = (start + 1) % 4;}
	if(direction == "CC")  {d = 3; putting_direction = (start + 2) % 4;}
	int current_number = 1 ;


	int current_row, current_col;

	if(start == 0)
		{current_row = 0; current_col = 0;}
	if(start == 1) {current_row = 0; current_col = width-1;}
	if(start == 2) {current_row = width-1; current_col = width-1;}
	if(start == 3) {current_row = width-1; current_col = 0;}

	a[current_row][current_col] = current_number;

	while(current_number < width * width)
	{
		if(putting_direction == 1)
			if(current_col+1 < width && a[current_row][current_col+1]==0)
				{
				a[current_row][++current_col] = ++current_number;
				}
			else
			{
			putting_direction = (putting_direction+d) % 4;
			}
		if(putting_direction == 2)
			if(current_row+1 < width && a[current_row+1][current_col]==0)
				{
				a[++current_row][current_col] = ++current_number;
				}
			else putting_direction = (putting_direction+d) % 4;
		if(putting_direction == 3)
			if(current_col-1 >= 0 && a[current_row][current_col-1]==0)
				{
				a[current_row][--current_col] = ++current_number;
				}
			else putting_direction = (putting_direction+d) % 4;
		if(putting_direction == 0)
			if(current_row-1 >= 0 && a[current_row-1][current_col]==0)
				{
				a[--current_row][current_col] = ++current_number;
				}
			else putting_direction = (putting_direction+d) % 4;
	}

	for(int i = 0 ; i < width ; i++)
	{
		for(int j = 0 ; j < width ; j++)
			cout << setfill(' ') << setw(4) << a[i][j];
		cout << endl;
	}
}
