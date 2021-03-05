// uptime.c
//	当地时间 modified from hy2002, credit goes to whoever created it.
//		--- Silencer@fy4

inherit F_CLEAN_UP;
#include <ansi.h>
// This command is also called by LOGIN_D, so we don't want it use 
// arguments.
string chinese_time(int type,string get_time);

int main()
{
	int t, d, h, m, s,x;
	string time;
	string mudver;
	t = uptime();
	s = t % 60;		t /= 60;
	m = t % 60;		t /= 60;
	h = t % 24;		t /= 24;
	d = t;

	if(d) time = chinese_number(d) + "天";
	else time = "";

	if(h) time += chinese_number(h) + "小时";
	if(m) time += chinese_number(m) + "分";
	time += chinese_number(s) + "秒";
	mudver = read_file("/doc/help/version.txt");
	if(!stringp(mudver)) {
		mudver = "CAN NOT READ FILE version.txt\n";	
	}
	mudver = replace_string(mudver, "\n","");
	write(GRN "风云2005（"+mudver+"）已经运行了" + time + "。\n" NOR);
	write("风云时间" + NATURE_D->game_time() + "。\n");
	write("风云站当地时间" + chinese_time(5,""+time()) + "。\n");
	write("风云世界当前Quest的奖励为："+ HIR + (QUESTS_D->query_holiday()+100)+ NOR +"％\n\n");
	
	x = "/d/fy/fysquare"->refresh();
	if (x>0 && x!=99999)
		write ("系统还有"+ (x/60)+"分"+ (x%60) +"秒更新，误差正负30秒钟。\n");
	return 1;
}

string chinese_time(int type,string get_time)
{
        string e_time, week, month, year;
        string c_week, c_year, c_month, c_time;
        int day, hour, minute, second;
        string *month_name = ({"Jan","Feb","Mar","Apr","May","Jun","Jul",
		"Aug","Sep","Oct","Nov","Dec"});
        string *week_name = ({"Mon","Tue","Wed","Thu","Fri","Sat","Sun"});

        e_time = ctime(atoi(get_time));

        // e_time must is ctime(time string) like "Sun May  3 00:52:12 1998"
        sscanf(e_time,"%s %s %d %d:%d:%d %s", week, month, day, hour, minute, second, year);

        c_week  = chinese_number(member_array(week, week_name) + 1);
        c_month = chinese_number(member_array(month, month_name) + 1);

        c_year  = sprintf("%s%s%s%s",
                         chinese_number(year[0]-48),
                         chinese_number(year[1]-48),
                         chinese_number(year[2]-48),
                         chinese_number(year[3]-48));

        c_year = c_year + "年";
        c_month  = c_month + "月";
        c_week = " 星期"+c_week;

        c_time = chinese_number(day) + "日";
        c_time += chinese_number(hour) + "点";
        c_time += chinese_number(minute) + "分";
        // maybe not need srcond to show
        // c_time += chinese_number(second) + "秒";

        if (type) {
                switch( type ) {
                        case 7: return year+"年"+(member_array(month, month_name) + 1)+"月"+day+"日";
                        case 1: return c_year+c_month+c_time+c_week;
                        case 2: return c_year+c_month+c_time;
                        case 3: return c_month+c_time+c_week;
                        case 4: return c_month+c_time;
                        case 5: return year+"年"+(member_array(month, month_name) + 1)+
				"月"+day+"日"+hour+"点"+minute+"分";
                        case 6: return (member_array(month, month_name) + 1)+
				"月"+day+"日"+hour+"点"+minute+"分";
                        default: return c_year+c_month+c_time+c_week;
                        }
                }
        return c_year+c_month+c_time+c_week;
}

int help(object me)
{
	write(@HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m指令格式 : 	uptime
[0;1;37m────────────────────────────────[0m   

这个指令告诉你现在风云世界的时间，站点的当地时间，
风云的版本和连续运行的时间。

[0;1;37m────────────────────────────────[0m 
HELP
    );
    return 1;
}
