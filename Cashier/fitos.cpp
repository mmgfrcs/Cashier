#include<string.h>
#include<math.h>

char sep[] = ",";
int fitos(int num, char * out)
{
	if (num == 0)
	{
		strcpy(out,"0");
		return 1;
	}
	int itos[10];
	for(int i = 0;i<10;i++)
	{
		int divby = 1000000000/(int)(pow(10.0f,i));
		itos[i] = (num/divby);
	}
	for(int i = 9;i>=0;i--)
	{
		if (itos[i-1] != 0 && i != 0) itos[i]-= itos[i-1]*10;
	}
	char ichar[10] = {};
	int count = 0;
	bool digitall = false;
	for (int i = 0;i<10;i++)
	{
		if(itos[i] == 0 && !digitall) continue;
		else
		{
			digitall = true;
			ichar[count] = itos[i]+48;
			count++;
		}
	}
	/*if(num<1000) 
	{
		char temp[3]={ichar[0],ichar[1], ichar[2]};
		strcpy(out,ichar);
		return sizeof(out);
	}*/
	int len = strlen(ichar);
	int start = 0;
	int startbuf=0;
	char buf[14]={};
	while(true)
	{
		int idx = (len - start) % 3;
		
		if (idx != 0)
		{
			for(int p = start; p < idx;p++)
			{
				buf[p+startbuf]=ichar[p];
			}
			startbuf++;
			start += idx;
			strcat(buf,sep);
		}
		else
		{
			for(int p = start; p < start + 3;p++)
			{
				buf[p+startbuf]=ichar[p];
			}
			startbuf++;
			start += 3;
			if(len - start > 0) strcat(buf,sep);
		}
		if (start >= len) break;
	}
	strcpy(out,buf);
	return sizeof(buf);
}