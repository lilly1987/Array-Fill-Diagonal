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
		cout << "열 갯수:";
		cin >> c;
		//cin.clear();
		//fflush(stdin);//리눅스에선 작동 안됨.

		// 배열 초기화
		int **a;
		int **a1;
		int **b;
		int **b1;
		int **d;
		a = new int *[r];
		b = new int *[r];		
		a1 = new int *[r];
		b1 = new int *[r];
		d = new int *[r];
		for (int i = 0; i < r; i++) {
			//cout << "new int :" << i <<  endl;
			a[i] = new int[c];
			a1[i] = new int[c];
			b[i] = new int[c];
			b1[i] = new int[c];
			d[i] = new int[c];
		}

		int t,v = 0,v1=0,v2=0,v3=0;

		// Y>X 일때 효율적
		// 입력↗
		for (int i = 0; i < r+c-1; i++) { //3:0 -> 5
			for (int j = 0; j < c; j++) { 
				t = i - j;				// Y 좌표값
				if (0<=t&&t<r)
				{
					a[t][j] =  ++v; 
				}
					cout << "i:" << i << " , j:" << j << " , t:" << t << " , v:"<<v << endl;
			} 			
		}		

		// 입력↙
		for (int i = 0; i < r+c-1; i++) { //3:0 -> 5
			for (int j = c-1; j >= 0; j--) { 
				t = i - j;				// Y 좌표값
				if (0<=t&&t<r)
				{
					a1[t][j] =  ++v2; 
				}
					cout << "i:" << i << " , j:" << j << " , t:" << t << " , v2:"<<v2 << endl;
			} 			
		}

		// Y<X 일때 효율적

		// 입력↙
		for (int i = 0; i < r + c - 1; i++) { //3:0 -> 5
			for (int j = 0; j < r; j++) {
				t = i - j;				// X 좌표값
				if (0 <= t && t < c)
				{
					b[j][t] =  ++v1; 
				}
					cout << "i:" << i << " , j:" << j << " , t:" << t << " , v1:"<<v1 << endl;
				
			}
		}
				
		// 입력↗
		for (int i = 0; i < r + c - 1; i++) { //3:0 -> 5
			for (int j = r-1; j >= 0; j--) {
				t = i - j;				// X 좌표값
				if (0 <= t && t < c)
				{
					b1[j][t] =  ++v3; 
				}
					cout << "i:" << i << " , j:" << j << " , t:" << t << " , v1:"<<v3 << endl;
				
			}
		}

		// 최적화

		// 내용 출력
		string s = "",s1="",s2="",s3="";

		for (int i = 0; i < r; i++) { 
			for (int j = 0; j < c; j++) { 
				s+= to_string(a[i][j]) +'\t';
				s2+= to_string(a1[i][j]) +'\t';
				s1+= to_string(b[i][j]) +'\t';
				s3+= to_string(b1[i][j]) +'\t';
			} 
			s+= '\n'; 
			s1+= '\n'; 			
			s2+= '\n'; 
			s3+= '\n'; 
		}
			s+= '\n'; 
			s1+= '\n'; 
			s2+= '\n'; 
			s3+= '\n'; 

		cout << s;
		cout << s1;
		cout << s2;
		cout << s3;

		// 메모리 해제
		for (int i = 0; i < r; i++) {
			delete[] a[i], b[i], a1[i], b1[i],d[i];			
		}
		delete[] a,b,a1,b1,d;
		
	} while (0 <= r|| 0 <= c); // 0 입력시 종료
}