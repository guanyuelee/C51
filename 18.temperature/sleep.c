void sleep(unsigned int time){
	unsigned char i, j;
	while(time){	
		i = 2;
		j = 239;
		do
		{
			while (--j);
		} while (--i);
		time--;
	}
}