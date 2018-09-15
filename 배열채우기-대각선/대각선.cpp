#include <iostream> //std
#include <string> //getline

using namespace std;

int main(int argc, char* argv[]) {

	unsigned int r,c;//r:행,c:열

	do
	{
		// 단순히 모양 출력용으로 cout 반복으로 쓰는건 성능상 좋지 않음
		// 수학적으로 쓸일이 있다면 모를까
		// 변수에 미리 처리후 한번만 출력하는게 젤 좋음

		// 입력 받기
		cout << "숫자만 입력." << endl;
		cout << "0 입력시 종료" << endl;
		cout << "행 갯수:";
		//getline(cin, v);
		cin >> r;
		if (r<=0)
		{
			break;
		}
		cout << "열 갯수:";
		cin >> c;
		if (c <= 0)
		{
			break;
		}
		//cin.clear();
		//fflush(stdin);//리눅스에선 작동 안됨.

		// 배열 초기화
		int **a;
		int **b;

		a = new int *[r];
		b = new int *[r];		

		for (int i = 0; i < r; i++) {
			//cout << "new int :" << i <<  endl;
			a[i] = new int[c];
			b[i] = new int[c];
		}

		int t,n = 0,m=0;

		// Y>X 일때 효율적

		if (r<c)
		{

			// 입력↗
			for (int i = 0; i < r+c-1; i++) { //3:0 -> 5
				for (int j = 0; j < c; j++) { 
					t = i - j;				// Y 좌표값
					if (0<=t&&t<r)
					{
						a[t][j] =  ++n; 
					}
						//cout << "i:" << i << " , j:" << j << " , t:" << t << " , n:"<<n << endl;
				} 			
				//cout << endl;
			}		

			// 입력↙
			for (int i = 0; i < r+c-1; i++) { //3:0 -> 5
				for (int j = c-1; j >= 0; j--) { 
					t = i - j;				// Y 좌표값
					if (0<=t&&t<r)
					{
						b[t][j] =  ++m; 
					}
						//cout << "i:" << i << " , j:" << j << " , t:" << t << " , m:"<<m << endl;
				} 			
				//cout << endl;
			}

		}
		// Y<X 일때 효율적
		else {

			// 입력↙
			for (int i = 0; i < r + c - 1; i++) { //3:0 -> 5
				for (int j = 0; j < r; j++) {
					t = i - j;				// X 좌표값
					if (0 <= t && t < c)
					{
						b[j][t] = ++m;
					}
					//cout << "i:" << i << " , j:" << j << " , t:" << t << " , m:"<<m << endl;

				}
				//cout << endl;
			}

			// 입력↗
			for (int i = 0; i < r + c - 1; i++) { //3:0 -> 5
				for (int j = r - 1; j >= 0; j--) {
					t = i - j;				// X 좌표값
					if (0 <= t && t < c)
					{
						a[j][t] = ++n;
					}
					//cout << "i:" << i << " , j:" << j << " , t:" << t << " , n:"<<n << endl;				
				}
				//cout << endl;
			}
		}

		// 내용 출력

		string s = "",s1="";

		for (int i = 0; i < r; i++) { 
			for (int j = 0; j < c; j++) { 
				s+= to_string(a[i][j]) +'\t';
				s1+= to_string(b[i][j]) +'\t';
			} 
			s+= '\n'; 
			s1+= '\n'; 			
		}

		s+= '\n'; 
		s1+= '\n'; 

		cout << s;
		cout << s1;


		// 메모리 해제

		for (int i = 0; i < r; i++) {
			delete[] a[i], b[i];			
		}
		delete[] a,b;
		
	} while (true); // 0 입력시 종료
}