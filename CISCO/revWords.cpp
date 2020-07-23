// i.like.this.program.very.much
// pqr.mno

// Output:
// much.very.program.this.like.i


/*Function to reverse words*/
void reverseWords(char *s) {
    int k=0;
    for(int i=0;s[i]!='\0';i++)
    {
        k++;
    }

    string s;
    int start=k-1;
    int len=0;
    for(int i=k-1;i>=0;i--)
    {  len=0;
        while(s[i]!='.'&&i!=-1)
        {
            i--;
            len++;

        }

        s+=s.substr(i+1,len);

    }
    cout<<s;
}
