char *ft_strcat(char *dest, char *src)
{
	char *cd;

	cd = dest;
	while (*cd)
	{
		cd++;
	}
	while (*src)
	{
		*cd = *src;
		src++;
		cd++;
	}
	*cd = '\0';
	return (dest);
}
