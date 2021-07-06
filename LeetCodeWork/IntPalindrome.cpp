//the more efficient way
bool isPalindrome(int x) {
	int reverse = 0;
	if(x < 0 || (x > 0 && x % 10 == 0))
		return false;
	while(reverse < x)
	{
		reverse = (reverse * 10) + (x % 10);
		 x/= 10;
	}
	if(reverse == x || x == reverse/10)
		return true;
	else
		return false;
}

// original idea was to convert to string and use stack.
//		then was going to use the method for reverseInt.
//		all ideas have the method of only seeing half.

bool isPalindrome_string_half(int x)
{
	if(x < 0 || (x > 0 && x % 10 == 0))
		return false;
	string s = std::to_string(x);
    return ( equal(s.begin(), s.begin() + s.size()/2, s.rbegin()) );
	
}