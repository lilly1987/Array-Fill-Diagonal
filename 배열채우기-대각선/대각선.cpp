#include <iostream> //std
#include <string> //getline

using namespace std;

int main(int argc, char* argv[]) {

	unsigned int r,c;//r:��,c:��

	do
	{
		// �ܼ��� ��� ��¿����� cout �ݺ����� ���°� ���ɻ� ���� ����
		// ���������� ������ �ִٸ� �𸦱�
		// ������ �̸� ó���� �ѹ��� ����ϴ°� �� ����

		// �Է� �ޱ�
		cout << "���ڸ� �Է�." << endl;
		cout << "0 �Է½� ����" << endl;
		cout << "�� ����:";
		//getline(cin, v);
		cin >> r;
		if (r<=0)
		{
			break;
		}
		cout << "�� ����:";
		cin >> c;
		if (c <= 0)
		{
			break;
		}
		//cin.clear();
		//fflush(stdin);//���������� �۵� �ȵ�.

		// �迭 �ʱ�ȭ
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

		// Y>X �϶� ȿ����

		if (r<c)
		{

			// �Է¢�
			for (int i = 0; i < r+c-1; i++) { //3:0 -> 5
				for (int j = 0; j < c; j++) { 
					t = i - j;				// Y ��ǥ��
					if (0<=t&&t<r)
					{
						a[t][j] =  ++n; 
					}
						//cout << "i:" << i << " , j:" << j << " , t:" << t << " , n:"<<n << endl;
				} 			
				//cout << endl;
			}		

			// �Է¢�
			for (int i = 0; i < r+c-1; i++) { //3:0 -> 5
				for (int j = c-1; j >= 0; j--) { 
					t = i - j;				// Y ��ǥ��
					if (0<=t&&t<r)
					{
						b[t][j] =  ++m; 
					}
						//cout << "i:" << i << " , j:" << j << " , t:" << t << " , m:"<<m << endl;
				} 			
				//cout << endl;
			}

		}
		// Y<X �϶� ȿ����
		else {

			// �Է¢�
			for (int i = 0; i < r + c - 1; i++) { //3:0 -> 5
				for (int j = 0; j < r; j++) {
					t = i - j;				// X ��ǥ��
					if (0 <= t && t < c)
					{
						b[j][t] = ++m;
					}
					//cout << "i:" << i << " , j:" << j << " , t:" << t << " , m:"<<m << endl;

				}
				//cout << endl;
			}

			// �Է¢�
			for (int i = 0; i < r + c - 1; i++) { //3:0 -> 5
				for (int j = r - 1; j >= 0; j--) {
					t = i - j;				// X ��ǥ��
					if (0 <= t && t < c)
					{
						a[j][t] = ++n;
					}
					//cout << "i:" << i << " , j:" << j << " , t:" << t << " , n:"<<n << endl;				
				}
				//cout << endl;
			}
		}

		// ���� ���

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


		// �޸� ����

		for (int i = 0; i < r; i++) {
			delete[] a[i], b[i];			
		}
		delete[] a,b;
		
	} while (true); // 0 �Է½� ����
}