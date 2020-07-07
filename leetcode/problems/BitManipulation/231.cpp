
bool check_power_of_two(int n)
{
	if(n<=0) return 0;
	// return (ceil(log2(n)) == floor(log2(n))); => slow..
    return !(n&(n-1));    
}
