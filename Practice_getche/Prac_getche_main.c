
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>

int main(void)
{
	// 최대 31개의 문자를 입력받아 저장
	//char input[32];

	//gets(input); // 문자열을 입력받는다.
	//printf("Input string : %s\n", input); // 입력된 문자열을 출력

	/*gets 함수를 사용하지 않고 getche 함수를 사용해서 동일하게 동작하도록
	만들어보시오
	*/

	int input;

	input = _getche();

	//printf("Input string : %c\n", (char)input); // 입력된 문자열을 출력

	return 0;
}
