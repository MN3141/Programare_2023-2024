int permutations(int n)
{
    int result=1;
    for(n;n>=1;n--)
        result*=n;
    return result;
}