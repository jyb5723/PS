#define N 4

typedef struct {
	int strike;
	int ball;

} Result;

// API

extern Result query(int guess[]);


Result query1(int guess[], int list[]) {
	int digits_c[10] = {0,};
	for (int i = 0; i < 4; i++)
		digits_c[guess[i]]++;

	Result result;
	result.strike = 0;
	result.ball = 0;
	for (int idx = 0; idx < N; ++idx)
		if (guess[idx] == list[idx])
			result.strike++;
		else if (digits_c[list[idx]] > 0)
			result.ball++;
	return result;
}

void num_init(int(*list)[5]) {
	int pt = 0; 
	for (int i = 123; i <= 9876; ++i) {
		int number = i;
		int temp[4] = { 0,0,0,0 };
		int idx = 3;
		while (number > 0) {
			temp[idx--] = number % 10;
			number /= 10;
		} 
		if (temp[0] == temp[1] || temp[0] == temp[2] || temp[0] == temp[3] || temp[1] == temp[2] || temp[1] == temp[3] || temp[2] == temp[3])
			continue;
		for (int j = 0; j < 4; j++)
			list[pt][j] = temp[j];
		list[pt][4] = 0;
		pt++;
	}
}

void doUserImplementation(int guess[]) {
	int list[5040][5];
	num_init(list);
	int qcnt = 0; 
	while (true) { 
		int k = 0;
		for (int i = 0; i < 5040; i++) { 
			if (list[i][4] == -1)
				continue;
			else {
				for (int j = 0; j < 4; j++) {
					guess[j] = list[i][j];
				}
				k = i; 
				break; 
			}
		}
		Result r = query(guess); 
		if (r.strike == 4) {
			break; 
		}
		else {
			for (int i = 0; i < 5040; ++i) {
				if (i == k)
					continue; 
				if (list[i][4] == -1) {
					continue; 
				}
				int x[5]; 
				for (int j = 0; j < 5; j++)
					x[j] = list[i][j]; 
				
				Result newR = query1(guess, x); 
 				if (r.strike != newR.strike || r.ball != newR.ball) {
					list[i][4] = -1;
					continue; 
				}
			}
			list[k][4] = -1; 
		}
		qcnt++;
	}
}