float sum(float a, float b)
{
    return a+b;
}

float difference(float a, float b)
{
    return a-b;
}

float product(float a, float b)
{
    return a*b;
}

float quotient(float a, float b)
{
    if (b != 0)
    {
        return a/b;//checking for invalid input
    }
    else
    {
        return 0;   
    }
}