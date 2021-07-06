/// <summary>
/// CodeSignal bullshittery. Given a string number, find out how many substrings are evenly 
///     divisible by a divisor. Prints the process.
/// </summary>
/// <param name="n">: The number to substring </param>
/// <param name="d">: the divisor </param>
/// <returns>An int indicating how many substrings are divisible</returns>
int substrDivisible(string n, int d)
{
    int count = 0;
    cout << "Number: " << n << " | Divider: " << d << endl;
    for (int i = 0; i < n.length(); i++)
    {
        for (int j = 1; j <= n.length() - i; j++)
        {
            cout << n.substr(i, j) << " % " << d;
            int temp = std::stoi(n.substr(i, j));
            if (temp % d == 0)
            {
                cout << " | Y";
                count++;
            }
            cout << endl;
        }
    }
    cout << "divisible times:" << count << endl;
    return count;
}