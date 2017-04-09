#include <cstdio>
#include <cstring>

int rab[100+20][200];

void add(int a, int b) {
	for (int i = 0; i < 200; i++) {
		rab[b+1][i] += rab[a][i] + rab[b][i];
		rab[b+1][i+1] += rab[b+1][i] / 10;
		rab[b+1][i] %= 10;
	}
	return;
}

int main() {

	int m, d, i;
	while (scanf("%d %d", &m, &d) && m &&d) {
		memset(rab, 0, sizeof(rab));

		for (i=1; i<=m; i++)rab[i][0]=1;
		for (; i <= m+d; i++) {
			add(i-m,i-1);
		}
		i = 200;

		while (rab[m+d][i] == 0) i--;
		for (; i >= 0; i--) {
			printf("%d",rab[m+d][i]);
		}

		printf("\n");
	}
	return 0;
}

