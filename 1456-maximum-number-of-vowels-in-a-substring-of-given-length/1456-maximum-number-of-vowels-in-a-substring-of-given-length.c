int maxVowels(char* s, int k) {
    int mc=0;
    int c=0;
    int n = strlen(s);

    for(int i=0;i<k;i++)
    {
        if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
        {
            c++;
        }
        
    }
    mc=c;

    for(int i=k;i<n;i++)
    {
        if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
        {
            c++;
        }

        if(s[i-k]=='a'||s[i-k]=='e'||s[i-k]=='i'||s[i-k]=='o'||s[i-k]=='u')
        {
            c--;
        }
        if(c>mc)
        mc=c;
    }
return mc;

}