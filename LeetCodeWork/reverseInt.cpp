int reverseInt(int x)
{
    int number = x;
    int result = 0;    
    while (abs(number) > 0)
    {
        if (number > INT_MAX / 10 || (number == INT_MAX && (number % 10) > 7))
            return 0;
        if (number < INT_MIN / 10 || (number == INT_MIN && (number % 10) < -8))
            return 0;

        result = (result * 10);
        result += (number % 10);
        number /= 10;
    }
    return result;
}