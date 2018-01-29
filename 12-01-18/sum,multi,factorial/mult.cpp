#include <iostream>
#include <string.h>
#define MAX_STR 10000
using namespace std;
void reverse(char[], int);
void multiply(char[], char, int, char[], int);
int add(char m[], char sum[], int l);

int main() {

	int la, lb, i, j, len_m = 0, lx;
	char a[100], b[100], sum[100][MAX_STR], m[MAX_STR], temp;

	cout<<"Enter first number: \n";
	cin>>a;
	la = strlen(a);
	cout<<"Enter second number: \n";
	cin>>b;
	lb = strlen(b);

	for(i = 0; i<MAX_STR; i++)
		m[i] = '0';

	if(la > lb) {
		temp = lb;
		reverse(b,lb);
		reverse(a,la);
		
		for(i = 0; i < lb; i++)
			multiply(a,b[i],la,sum[i],i);
	}
	else {
		temp = la;
		reverse(a,la);
		reverse(b,lb);
		
		for(i = 0; i < la; i++)
			multiply(b,a[i],lb,sum[i],i);
	}

	
	for(i = 0; i < temp; i++)
		len_m = add(m,sum[i],strlen(sum[i]));

	cout<<"Multiplied value is: \n";
	reverse(m,len_m);
	for(i = 0; i < len_m; i++)
		printf("%c",m[i]);
	cout<<("\n");
	return 0;
}



void reverse(char a[], int l) {
	if (l == 1)
		return;
	int i = 0, j = l-1;
	char t;
	while(i < j) {
		t = a[i];
		a[i] = a[j];
		a[j] = t;
		i++;
		j--;
	}
}

void multiply(char a[], char x, int la, char sum[], int i) {

	int d1, d2 = x - '0', d, ca = 0, s, j = 0, len;
	while(j < la) {
		d1 = a[j] - '0';
		s = d1*d2 + ca;
		d = s%10;
		ca = s/10;
		sum[j] = d + '0';
		j++;
	}
	len = j;
	if(ca > 0) {
		sum[j] = ca+'0';
		len = j + 1;
	}
	reverse(sum, len); 
	j = 0;
	while(j < i) {
		sum[len] = '0';
		len++;
		j++;
	}
	reverse(sum,len);

}



int add(char m[], char sum[], int l) {
	int i = 0, j = 0, d1, d2, s = 0, ca = 0, d = 0, len;
	while(i < l) {
		d1 = sum[i] - '0';
		d2 = m[i] - '0';
		s = d1 + d2 + ca;
		if(s > 9) {
			d = s-10;
			ca = 1;
		}
		else {
			d = s;
			ca = 0;
		}
		m[i] = d + '0';
		i++;
	}
	if(ca > 0) {
		m[i] = ca + '0';
		i++;
	}
	return i;
}
