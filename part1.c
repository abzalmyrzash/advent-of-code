#include <stdio.h>
#include <assert.h>

constexpr int MAX_PRESENTS = 6;
constexpr int MAX_REGIONS = 1000;
constexpr int P_WIDTH = 3;
constexpr int P_LENGTH = 3;

char presents[MAX_PRESENTS][P_LENGTH][P_WIDTH];
int num_presents = 0;

typedef struct {
	int width;
	int length;
	int presents[MAX_PRESENTS];
} Region;

Region regions[MAX_REGIONS];
int num_regions = 0;

int main() {
	FILE* file = fopen("input.txt", "r");
	int p = 0;
	int x;
	int ret;
	while (1) {
		ret = fscanf(file, "%d", &x);
		assert(ret == 1);
		char ch = getc(file);
		if (ch == 'x') break;
		assert(x == p);
		assert(ch == ':');
		ch = getc(file);
		assert(ch == '\n');

		for (int i = 0; i < P_LENGTH; i++) {
			for (int j = 0; j < P_WIDTH; j++) {
				ch = getc(file);
				assert(ch == '#' || ch == '.');
				presents[p][i][j] = ch;
			}
			ch = getc(file);
			assert(ch == '\n');
		}
		ch = getc(file);
		assert(ch == '\n');
		p++;
	}
	num_presents = p;

	for (int p = 0; p < num_presents; p++) {
		for (int i = 0; i < P_LENGTH; i++) {
			for (int j = 0; j < P_WIDTH; j++) {
				printf("%c", presents[p][i][j]);
			}
			printf("\n");
		}
		printf("\n");
	}

	regions[0].length = x;
	int r = 0;
	while (1) {
		ret = fscanf(file, "%d", &x);
		assert(ret == 1);
		regions[r].width = x;
		if (fscanf(file, "%d", &x) != 1) break;
		r++;
		regions[r].length = x;
		ch = getc(file);
		assert(ch == 'x');
	}
	num_regions = r;
	printf("%d\n", num_regions);
}

