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
		cout << "�� ����:";
		cin >> c;
		//cin.clear();
		//fflush(stdin);//���������� �۵� �ȵ�.

		// �迭 �ʱ�ȭ
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

		// Y>X �϶� ȿ����
		// �Է¢�
		for (int i = 0; i < r+c-1; i++) { //3:0 -> 5
			for (int j = 0; j < c; j++) { 
				t = i - j;				// Y ��ǥ��
				if (0<=t&&t<r)
				{
					a[t][j] =  ++v; 
				}
					cout << "i:" << i << " , j:" << j << " , t:" << t << " , v:"<<v << endl;
			} 			
		}		

		// �Է¢�
		for (int i = 0; i < r+c-1; i++) { //3:0 -> 5
			for (int j = c-1; j >= 0; j--) { 
				t = i - j;				// Y ��ǥ��
				if (0<=t&&t<r)
				{
					a1[t][j] =  ++v2; 
				}
					cout << "i:" << i << " , j:" << j << " , t:" << t << " , v2:"<<v2 << endl;
			} 			
		}

		// Y<X �϶� ȿ����

		// �Է¢�
		for (int i = 0; i < r + c - 1; i++) { //3:0 -> 5
			for (int j = 0; j < r; j++) {
				t = i - j;				// X ��ǥ��
				if (0 <= t && t < c)
				{
					b[j][t] =  ++v1; 
				}
					cout << "i:" << i << " , j:" << j << " , t:" << t << " , v1:"<<v1 << endl;
				
			}
		}
				
		// �Է¢�
		for (int i = 0; i < r + c - 1; i++) { //3:0 -> 5
			for (int j = r-1; j >= 0; j--) {
				t = i - j;				// X ��ǥ��
				if (0 <= t && t < c)
				{
					b1[j][t] =  ++v3; 
				}
					cout << "i:" << i << " , j:" << j << " , t:" << t << " , v1:"<<v3 << endl;
				
			}
		}

		// ����ȭ

		// ���� ���
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

		// �޸� ����
		for (int i = 0; i < r; i++) {
			delete[] a[i], b[i], a1[i], b1[i],d[i];			
		}
		delete[] a,b,a1,b1,d;
		
	} while (0 <= r|| 0 <= c); // 0 �Է½� ����
}