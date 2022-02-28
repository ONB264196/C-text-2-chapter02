#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define _0206

int sleep(unsigned long x) {
	clock_t c1 = clock(), c2 = 0;

	do {
		if ((c2 = clock()) == (clock_t)-1) {
			return 0;
		}
	} while (1000.0 * (c2 - c1) / CLOCKS_PER_SEC < x);
	return 1;
}

#ifdef _0200
int main(void) {
	int stage = 0;
	int a = 0, b = 0, c = 0;
	int x = 0;
	int n = 0;
	clock_t start = 0, end = 0;

	srand((unsigned)time(NULL));

	printf("視野拡大暗算トレーニング開始!!\n");
	start = clock();

	for (stage = 0; stage < 5; stage++) {
		a = 10 + rand() % 90;
		b = 10 + rand() % 90;
		c = 10 + rand() % 90;
		n = rand() % 24;

		printf("%d%*s+%*s%d%*s+%*s%d : ", a, n, "", n, "", b, n, "", n, "", c);

		do {
			scanf_s("%d", &x);
			if (x == a + b + c) {
				break;
			}
			sleep(3000);
			printf("\a違います。再入力してください : ");
		} while (1);
	}

	end = clock();
	printf("%.1f秒かかりました。\n", (double)(end - start) / CLOCKS_PER_SEC);

	return 0;
}
#endif

#ifdef _0201
int main(void) {
	time_t c = 0;

	for (int i = 10; i > 0; i--) {
		printf("\r%2d", i);
		fflush(stdout);
		sleep(1000);
	}
	printf("\r\aFIRE!!\n");
	c = clock();
	printf("プログラム開始から%.1f秒、%dクロック経過しました。\n", (double)c / CLOCKS_PER_SEC, (int)c);

	return 0;
}
#endif

#ifdef _0202
void gput(const char* s, int speed) {
	for (int i = 0; i < strlen(s); i++) {
		putchar(s[i]);
		sleep(speed);
	}
}
int main(void) {
	char str[256] = { 0 };
	float s = 0;

	printf("表示する文字列を入力してください : ");
	scanf_s("%s", str, 256);
	printf("表示スピード(秒)を入力してください : ");
	scanf_s("%f", &s);
	s *= 1000;

	gput(str, s);

	return 0;
}
#endif

#ifdef _0203
void bput(const char* s, int d, int e, int n) {
	for (n; n > 0; n--) {
		printf("\r%s", s);
		fflush(stdout);
		sleep(d);
		putchar('\r');
		printf("%*s", (unsigned)strlen(s), "");
		sleep(e);
	}
}
int main(void) {
	char str[64] = { 0 };
	int num = 0;
	float a = 0, da = 0;

	printf("表示する文字列 : ");
	scanf_s("%s", str, 64);
	printf("表示時間(秒) : ");
	scanf_s("%f", &a);
	printf("非表示時間(秒) : ");
	scanf_s("%f", &da);
	printf("繰り返し回数 : ");
	scanf_s("%d", &num);

	a *= 1000.0f;
	da *= 1000.0f;

	bput(str, (int)a, (int)da, num);

	return 0;
}
#endif

#ifdef _0204
void telop(const char* s, int direction, int speed, int n) {
	int cnt = 0;
	int len = (int)strlen(s);

	while (n >= 0) {
		putchar('\r');

		for (int i = 0; i < len; i++) {
			if (cnt + i < len) {
				putchar(s[cnt + i]);
			}
			else {
				putchar(s[cnt + i - len]);
			}
		}

		fflush(stdout);
		sleep(speed);

		if (direction == 0) {
			if (cnt < len - 1) {
				cnt++;
			}
			else {
				cnt = 0;
				n--;
			}
		}
		else {
			if (cnt > 0) {
				cnt--;
			}
			else {
				cnt = len - 1;
				n--;
			}
		}
	}
}

int main(void) {
	char str[64] = { 0 };
	char space[] = " ";
	int d = 0, num = 0;
	float s = 0;

	printf("表示する文字列 : ");
	scanf_s("%s", str, 64);
	strcat_s(str, space);
	printf("テロップの方向(左 → 0,右 → 1) : ");
	scanf_s("%d", &d);
	printf("表示スピード(秒) : ");
	scanf_s("%f", &s);
	printf("表示回数 : ");
	scanf_s("%d", &num);

	if (strlen(str) < 64 && (d == 0 || d == 1)) {
		s *= 1000;
		telop(str, d, (int)s, num);
	}
	else {
		printf("\a入力に不正");
	}
	return 0;
}
#endif

#ifdef _0205
#define NUMQ 5 //問題数

int main(void) {
	int stage = 0;
	int a = 0, b = 0, c = 0;
	int x = 0;
	int n = 0;
	clock_t start = 0, end = 0;
	double T[NUMQ] = { 0 };
	double numT = 0;

	srand((unsigned)time(NULL));

	printf("視野拡大暗算トレーニング開始!!\n");

	for (stage = 0; stage < NUMQ; stage++) {
		start = clock();
		a = 10 + rand() % 90;
		b = 10 + rand() % 90;
		c = 10 + rand() % 90;
		n = rand() % 24;

		printf("%d%*s+%*s%d%*s+%*s%d : ", a, n, "", n, "", b, n, "", n, "", c);

		do {
			scanf_s("%d", &x);
			if (x == a + b + c) {
				break;
			}
			sleep(3000);
			printf("\a違います。再入力してください : ");
		} while (1);

		end = clock();
		T[stage] = (double)(end - start) / CLOCKS_PER_SEC;
		numT += (double)(end - start) / CLOCKS_PER_SEC;
	}

	puts("\n\n所要時間");
	for (int i = 0; i < NUMQ; i++) {
		printf("%d問目 : %f秒\n", i - 1, T[i]);
	}
	printf("平均時間 : %f秒", numT / (double)NUMQ);

	return 0;
}
#endif

#ifdef _0206
#define NUMQ 5

int main(void) {
	int stage = 0;
	int a = 0, b = 0, c = 0;
	int x = 0;
	int ans = 0;
	int n = 0;
	clock_t start = 0, end = 0;
	double T[NUMQ] = { 0 };
	double numT = 0;
	int type = 0;
	int cnt = 0;


	printf("視野拡大暗算トレーニング開始!!\n");

	for (stage = 0; stage < NUMQ; stage++) {
		srand((unsigned)time(NULL));
		start = clock();
		a = 10 + rand() % 90;
		b = 10 + rand() % 90;
		c = 10 + rand() % 90;
		n = rand() % 24;
		type = rand() % 4;
		
		switch (type) {
		case 0:
			printf("%d%*s+%*s%d%*s+%*s%d : ", a, n, "", n, "", b, n, "", n, "", c);
			ans = a + b + c;
			break;
		case 1:
			printf("%d%*s+%*s%d%*s-%*s%d : ", a, n, "", n, "", b, n, "", n, "", c);
			ans = a + b - c;
			break;
		case 2:
			printf("%d%*s-%*s%d%*s+%*s%d : ", a, n, "", n, "", b, n, "", n, "", c);
			ans = a - b + c;
			break;
		case 3:
			printf("%d%*s-%*s%d%*s-%*s%d : ", a, n, "", n, "", b, n, "", n, "", c);
			ans = a - b - c;
			break;
		}

		do {
			scanf_s("%d", &x);
			if (x == ans) {
				break;
			}
			sleep(3000);
			printf("\a違います。再入力してください : ");
			cnt++;
		} while (1);

		end = clock();
		T[stage] = (double)(end - start) / CLOCKS_PER_SEC;
		numT += (double)(end - start) / CLOCKS_PER_SEC;
	}

	puts("\n\n所要時間");
	for (int i = 0; i < NUMQ; i++) {
		printf("%d問目 : %f秒\n", i + 1, T[i]);
	}
	printf("平均時間 : %f秒\n", numT / (double)NUMQ);
	printf("正答率 : %f%%", (double)NUMQ / (NUMQ + cnt) * 100);

	return 0;
}
#endif