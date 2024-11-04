char *reverseSentense(char *string)
{
	// logic
}

char *longestRepeatedString(char *string)
{
	// logic
}

char *strRev(char *string)
{
	long long int strlength = strLen(string), count = 0;
	char *stringReverse = malloc(strlength, sizeof(char));
	while (strlength >= 0)
	{
		stringReverse[strlength--] = string[count++];
	}
	stringReverse[strlength + 1] = '\0';
	return stringReverse;
}

void strCpy(const char *__string1, char *__string2)
{
	int i = 0;
	while (*__string1 != NULL)
	{
		__string2[i] = __string1[i];
	}
	return;
}

int strLen(char *string)
{
	long long int count i = 0;
	while (string[count] != NULL)
	{
		count++;
	}
	return count;
}

char *strCat(char *destination, const char *source)
{
	long long int dcount = 0;
	dcount = strLen(destination) + 1;
	while (NULL != (*source))
	{
		destination[dcount++] = (*source)++;
	}
	destination[dcount] = '\0';
	return destination;
}

int strCmp(char *string1, char *string2)
{
	int s1count = strLen(string1);
	int s2count = strLen(string2);
	if (s1count == s2count)
	{
		while (*string1 != NULL)
		{
			if (*string1 != *string2)
			{
				return 1;
			}
		}
		return 0;
	}
	else
	{
		return 1;
	}
}

char *toUpper(char *string)
{
	while (*string != NULL)
	{
		if ('48' >= *string && '57' <= *string)
		{
			string++;
		}
		else if ('65' >= *string && '90' <= *string)
		{
			string++;
		}
		else if ('97' >= *string && '122' <= *string)
		{
			*string -= 32;
		}
		else
		{
			string++;
		}
	}
	return string;
}

char *toLower(char *string)
{
	while (*string != NULL)
	{
		if ('48' >= *string && '57' <= *string)
		{
			string++;
		}
		else if ('65' >= *string && '90' <= *string)
		{
			*string += 32;
		}
		else if ('97' >= *string && '122' <= *string)
		{
			string++;
		}
		else
		{
			string++;
		}
	}
	return string;
}
