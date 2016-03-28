// http://bailian.openjudge.cn/practice/2715
#include <iostream>
#include <string>
using namespace std;

/*
1)	院士奖学金，每人8000元，期末平均成绩高于80分（>80），并且在本学期内发表1篇或1篇以上论文的学生均可获得；
2)	五四奖学金，每人4000元，期末平均成绩高于85分（>85），并且班级评议成绩高于80分（>80）的学生均可获得；
3)	成绩优秀奖，每人2000元，期末平均成绩高于90分（>90）的学生均可获得；
4)	西部奖学金，每人1000元，期末平均成绩高于85分（>85）的西部省份学生均可获得；
5)	班级贡献奖，每人850元，班级评议成绩高于80分（>80）的学生干部均可获得
*/

struct Student
{
	string name;
	int finalScore, classScore, numOfPapers, scholarship;
	bool isLeader, isWestern;

	int cal() {
		scholarship = 0;
		if (finalScore > 80 && numOfPapers >= 1)
			scholarship += 8000;
		if (finalScore > 85 && classScore > 80)
			scholarship += 4000;
		if (finalScore > 90)
			scholarship += 2000;
		if (finalScore > 85 && isWestern)
			scholarship += 1000;
		if (classScore > 80 && isLeader)
			scholarship += 850;
		return scholarship;
	}
};

Student s[105];

void sort(int n) {
	for (int i = 1; i < n; ++i) {
		int cutIn = i - 1;
		Student now = s[i];
		while (cutIn >= 0 && now.scholarship > s[cutIn].scholarship) {
			swap(s[cutIn], s[cutIn+1]);
			--cutIn;
		}
		s[++cutIn] = now;
	}
}

int main() {
	/*输入的第一行是一个整数N（1 <= N <= 100），表示学生的总数。接下来的N行每行是一位学生的数据，
	从左向右依次是姓名，期末平均成绩，班级评议成绩，是否是学生干部，是否是西部省份学生，以及发表的论文数。
	姓名是由大小写英文字母组成的长度不超过20的字符串（不含空格）；
	期末平均成绩和班级评议成绩都是0到100之间的整数（包括0和100）；
	是否是学生干部和是否是西部省份学生分别用一个字符表示，Y表示是，N表示不是；
	发表的论文数是0到10的整数（包括0和10）。每两个相邻数据项之间用一个空格分隔。*/
	int n, allScholarship = 0;
	char isLeader, isWestern;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> s[i].name >> s[i].finalScore >> s[i].classScore >> isLeader >> isWestern >> s[i].numOfPapers;
		if (isLeader == 'Y')
			s[i].isLeader = true;
		if (isWestern == 'Y')
			s[i].isWestern = true;
		allScholarship += s[i].cal();
	}

	sort(n);
	cout << s[0].name << '\n' << s[0].scholarship << '\n' << allScholarship << endl;

	return 0;
}