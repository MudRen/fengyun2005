#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me)
{
        string msg;
        
        tell_object(me,MAG"\n★"HIY"色彩精灵向您报告"MAG"★\n\n"NOR);
        tell_object(me,
"  	黑色- BLK"BLK"■■■■■■"NOR" \n"                       
"  	红色- RED"RED"■■■■■■"NOR"	HIR"HIR"■■■■■■"NOR" \n"
"  	绿色- GRN"GRN"■■■■■■"NOR" 	HIG"HIG"■■■■■■"NOR" \n"
"  	黄色- YEL"YEL"■■■■■■"NOR" 	HIY"HIY"■■■■■■"NOR" \n"
"  	蓝色- BLU"BLU"■■■■■■"NOR" 	HIB"HIB"■■■■■■"NOR" \n"
"  	粉色- MAG"MAG"■■■■■■"NOR" 	HIM"HIM"■■■■■■"NOR" \n"
"  	青色- CYN"CYN"■■■■■■"NOR" 	HIC"HIC"■■■■■■"NOR" \n"
"  	白色- WHT"WHT"■■■■■■"NOR" 	HIW"HIW"■■■■■■"NOR" \n\n\n");

	if (wizardp(me))
	{
	msg = 
BGRN	"  	黑色- BLK"BLK"风云天下"" \n"                       
BGRN	"  	红色- RED"RED"风云天下""	HIR"HIR"风云天下"NOR" \n"
BGRN	"  	绿色- GRN"GRN"风云天下"" 	HIG"HIG"风云天下"NOR" \n"
BGRN	"  	黄色- YEL"YEL"风云天下"" 	HIY"HIY"风云天下"NOR" \n"
BGRN	"  	蓝色- BLU"BLU"风云天下"" 	HIB"HIB"风云天下"NOR" \n"
BGRN	"  	粉色- MAG"MAG"风云天下"" 	HIM"HIM"风云天下"NOR" \n"
BGRN	"  	青色- CYN"CYN"风云天下"" 	HIC"HIC"风云天下"NOR" \n"
BGRN	"  	白色- WHT"WHT"风云天下"" 	HIW"HIW"风云天下"NOR" \n\n";

	msg += 
BRED	"  	黑色- BLK"BLK"风云天下"" \n"                       
BRED	"  	红色- RED"RED"风云天下""	HIR"HIR"风云天下"NOR" \n"
BRED	"  	绿色- GRN"GRN"风云天下"" 	HIG"HIG"风云天下"NOR" \n"
BRED	"  	黄色- YEL"YEL"风云天下"" 	HIY"HIY"风云天下"NOR" \n"
BRED	"  	蓝色- BLU"BLU"风云天下"" 	HIB"HIB"风云天下"NOR" \n"
BRED	"  	粉色- MAG"MAG"风云天下"" 	HIM"HIM"风云天下"NOR" \n"
BRED	"  	青色- CYN"CYN"风云天下"" 	HIC"HIC"风云天下"NOR" \n"
BRED	"  	白色- WHT"WHT"风云天下"" 	HIW"HIW"风云天下"NOR" \n\n";

	msg += 
BYEL	"  	黑色- BLK"BLK"风云天下"" \n"                       
BYEL	"  	红色- RED"RED"风云天下""	HIR"HIR"风云天下"NOR" \n"
BYEL	"  	绿色- GRN"GRN"风云天下"" 	HIG"HIG"风云天下"NOR" \n"
BYEL	"  	黄色- YEL"YEL"风云天下"" 	HIY"HIY"风云天下"NOR" \n"
BYEL	"  	蓝色- BLU"BLU"风云天下"" 	HIB"HIB"风云天下"NOR" \n"
BYEL	"  	粉色- MAG"MAG"风云天下"" 	HIM"HIM"风云天下"NOR" \n"
BYEL	"  	青色- CYN"CYN"风云天下"" 	HIC"HIC"风云天下"NOR" \n"
BYEL	"  	白色- WHT"WHT"风云天下"" 	HIW"HIW"风云天下"NOR" \n\n";
	msg += 
BCYN	"  	黑色- BLK"BLK"风云天下"" \n"                       
BCYN	"  	红色- RED"RED"风云天下""	HIR"HIR"风云天下"NOR" \n"
BCYN	"  	绿色- GRN"GRN"风云天下"" 	HIG"HIG"风云天下"NOR" \n"
BCYN	"  	黄色- YEL"YEL"风云天下"" 	HIY"HIY"风云天下"NOR" \n"
BCYN	"  	蓝色- BLU"BLU"风云天下"" 	HIB"HIB"风云天下"NOR" \n"
BCYN	"  	粉色- MAG"MAG"风云天下"" 	HIM"HIM"风云天下"NOR" \n"
BCYN	"  	青色- CYN"CYN"风云天下"" 	HIC"HIC"风云天下"NOR" \n"
BCYN	"  	白色- WHT"WHT"风云天下"" 	HIW"HIW"风云天下"NOR" \n\n";

	msg += 
BBLU	"  	黑色- BLK"BLK"风云天下"" \n"                       
BBLU	"  	红色- RED"RED"风云天下""	HIR"HIR"风云天下"NOR" \n"
BBLU	"  	绿色- GRN"GRN"风云天下"" 	HIG"HIG"风云天下"NOR" \n"
BBLU	"  	黄色- YEL"YEL"风云天下"" 	HIY"HIY"风云天下"NOR" \n"
BBLU	"  	蓝色- BLU"BLU"风云天下"" 	HIB"HIB"风云天下"NOR" \n"
BBLU	"  	粉色- MAG"MAG"风云天下"" 	HIM"HIM"风云天下"NOR" \n"
BBLU	"  	青色- CYN"CYN"风云天下"" 	HIC"HIC"风云天下"NOR" \n"
BBLU	"  	白色- WHT"WHT"风云天下"" 	HIW"HIW"风云天下"NOR" \n\n";

	msg += 
BMAG	"  	黑色- BLK"BLK"风云天下"" \n"                       
BMAG	"  	红色- RED"RED"风云天下""	HIR"HIR"风云天下"NOR" \n"
BMAG	"  	绿色- GRN"GRN"风云天下"" 	HIG"HIG"风云天下"NOR" \n"
BMAG	"  	黄色- YEL"YEL"风云天下"" 	HIY"HIY"风云天下"NOR" \n"
BMAG	"  	蓝色- BLU"BLU"风云天下"" 	HIB"HIB"风云天下"NOR" \n"
BMAG	"  	粉色- MAG"MAG"风云天下"" 	HIM"HIM"风云天下"NOR" \n"
BMAG	"  	青色- CYN"CYN"风云天下"" 	HIC"HIC"风云天下"NOR" \n"
BMAG	"  	白色- WHT"WHT"风云天下"" 	HIW"HIW"风云天下"NOR" \n\n";

	msg += 
HBWHT	"  	黑色- BLK"BLK"风云天下"" \n"                       
HBWHT	"  	红色- RED"RED"风云天下""	HIR"HIR"风云天下"NOR" \n"
HBWHT	"  	绿色- GRN"GRN"风云天下"" 	HIG"HIG"风云天下"NOR" \n"
HBWHT	"  	黄色- YEL"YEL"风云天下"" 	HIY"HIY"风云天下"NOR" \n"
HBWHT	"  	蓝色- BLU"BLU"风云天下"" 	HIB"HIB"风云天下"NOR" \n"
HBWHT	"  	粉色- MAG"MAG"风云天下"" 	HIM"HIM"风云天下"NOR" \n"
HBWHT	"  	青色- CYN"CYN"风云天下"" 	HIC"HIC"风云天下"NOR" \n"
HBWHT	"  	白色- WHT"WHT"风云天下"" 	HIW"HIW"风云天下"NOR" \n\n";
	write(msg);

	}

        return 1;
}



int help(object me)
{
        write(@HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m指令格式 : 	指令格式 : color[0m
[0;1;37m────────────────────────────────[0m   

这个指令可以让你知道游戏中各种色彩的ANSI控制字元及色彩的
试样，从而方便您选择中意的色彩。

[0;1;37m────────────────────────────────[0m 
HELP );
        return 1;
}
