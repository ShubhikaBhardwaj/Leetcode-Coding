//Counting Sort
char* countSort(char arr[])
{

int m[256]={0};

for(int i=0;arr[i]!='\0';i++)
{
    m[arr[i]]++;
}

for(int i=1;i<256;i++)
{
    arr[i]=arr[i]+arr[i-1];
}

char *ans[]=new char[strlen(arr)];

for(int i=0;arr[i]!='\0';i++)
{
    ans[m[arr[i]]]=arr[i];
}

return ans;
 

}