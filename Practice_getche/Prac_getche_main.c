
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>

int main(void)
{
	// �ִ� 31���� ���ڸ� �Է¹޾� ����
	//char input[32];

	//gets(input); // ���ڿ��� �Է¹޴´�.
	//printf("Input string : %s\n", input); // �Էµ� ���ڿ��� ���

	/*gets �Լ��� ������� �ʰ� getche �Լ��� ����ؼ� �����ϰ� �����ϵ���
	�����ÿ�
	*/

	int input;

	input = _getche();

	//printf("Input string : %c\n", (char)input); // �Էµ� ���ڿ��� ���

	return 0;
}
