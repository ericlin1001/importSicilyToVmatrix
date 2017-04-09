#include <iostream>
#include <string>
using namespace std;
int main(void) {
	string ch;
	getline(cin,ch);
	static int i,j,count,n;
	n=ch.size();
	for(i=0; i<n; i++) {
		if(ch[i]==' ') count++;
	}
	count+=1;
	//cout<<ch<<endl<<count<<endl;
	char a[count][20];
	int key = 0;
	for(i=0; i<n; i++) {
		//please call me handsome boy.
		if(ch[i]==' ') {
			a[key][j]='\0';
			key++;
			j=0;

			//i++;
		} else a[key][j++] = ch[i];
		if(i==(n-1)) a[count-1][j]='\0';
	}

	int k=0;
	for(j=0; j<count; j++) {
		for(i=j,k=0; k<count; k++,i++) {
			if(i>=count) i = 0;
			cout<<a[i];
			if(k!=count-1) cout<<' ';
		}
		cout<<endl;
	}
}

