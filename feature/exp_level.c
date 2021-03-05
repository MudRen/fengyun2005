/* 	此文件是用来处理新版风云经验值与等级间的换算。	-- Silencer@fy workgroup

	经验等级对照表
	2k - 99k		L0--L9			Delta_L= 10k
	100k-1.1M		L10-L30			Delta_L= 50k
	1.1M- 3.1M		L30-L70			Delta_L = 50k
	3.1- 11.1M		L70-L150		Delta_L = 100k
	11.1-21.1M and above	L150-L200		Delta_L = 200k
*/


mapping exp_to_level(int exp);		//给出经验值转化成的等级值信息。
int get_level(int exp);			// 得出经验值转化成的等级值。。
int exp_to_pot(int exp); 		//给出该经验值所对应的奖励潜能值
int level_to_exp(int level, int sub);	//給出對應級別的exp.; annie.
int level_to_pot (int level);		//给出该等级所对应的奖励潜能值


mapping	exp_to_level(int exp) {
	
	int level, sub, base, next_level, unit;
	mapping data = ([]);

	unit = exp /100000;	
	
	if (unit == 0)
	{
		level = exp/10000;
		sub = (exp - level * 10000) /10;
		next_level = 10000;
		base = (level -1) * 10000;
		if (base < 0 )	base = 0;
	}
	else if (unit<=30)
	{
		level = 10 + (exp -100000)/50000;
		sub = (exp - (level-10) * 50000 - 100000) / 50;
		next_level = 50000;
		base = (level -10) * 50000 + 100000;
	} 
	else if (unit<=110)
	{
		level = 70 + (exp -3100000)/100000;
		sub = (exp - (level-70) * 100000 - 3100000) / 100;
		next_level = 100000;
		base = (level -70) * 100000 + 3100000;
		
	} 
	else
	{
		level = 150 + (exp -11100000)/200000;
		sub = (exp - (level-150) * 200000 - 11100000) / 200;
		next_level = 200000;
		base = (level -150) * 200000 + 7100000;		
	}

//	level 为等级，
//	sub为该等级完成的百分数，
//	next_level为到下一级需要的经验值，
//	base为这一级的初始经验值。
		
	data = ([ 	"level": 	level, 
			"sub": 		sub,	// *10传递以精确到小数点后一位。 
			"next_level": 	next_level, 
			"level_exp": 	base, 
		]);
	return data;
}

int get_level(int exp) {
	mapping data;
	data = exp_to_level(exp);
	return data["level"];
}


int level_to_exp(int level, int sub){	//此处传入的sub为百分比*10
	int exp;
	
	if (level <= 10)
	{
		exp = level * 10000 + sub * 10;			
	}
	else if (level <=70)
	{
		exp = 100000 + (level - 10)* 50000 + sub * 50;
	}
	else if (level <= 150)
	{
		exp = 3100000 + (level - 70) * 100000 + sub * 100;
	}
	else
		exp = 11000000 + (level - 150) * 200000 + sub * 200;
	
	return exp;
}


/*
		L0-9,  	100000/8 = 12500, 					each level = 1250
		L11-L30  total = 12500 + (1100000-100000)/6 = 12500 + 166666 = 179166 	each level = 8333
		L35-L139  total = 179166 + (5000000-1100000)/4 = 1154166, each level = 12500 (0-70), 25000 (70+) 
		max= 2.4M
*/

int exp_to_pot(int exp) {
	int pot;
	if (exp <= 100000)		pot = exp/8;
	else if (exp <=1100000)	pot = 12500 + (exp-100000) / 6;
	else pot = 179166 + (exp-1100000) / 4;
//	else if (exp <=5000000) pot = 179166 + (exp-1100000) / 4;
//	else		 		pot = 1154166 + (exp - 5000000)/5;
	return pot;
}


int level_to_pot(int level) {
	int exp;
	exp = level_to_exp(level, 0);
	return exp_to_pot(exp);
}

