code unsigned char arr[] = "ALL IS WELL";
//absolute memory location accessing (using _at_ keyword)
idata unsigned char arr1[15] _at_ 0x30;
xdata unsigned char arr2[15] _at_ 0x1000;


main()
{
	unsigned char i;
	 
	for(i=0;i<11;i++)
	{
		arr1[i] = arr[i];
		arr2[i] = arr[i];
	}
	while(1);

}
