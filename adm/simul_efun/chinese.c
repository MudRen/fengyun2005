
string chinese_number(int i)
{
	return CHINESE_D->chinese_number(i);
}

string to_chinese(string str)
{
	return CHINESE_D->chinese(str);
}

int is_chinese(string name)
{
	if(!name)
		return 0;
	name=SIMUL_EFUN_OB->filter_color(name);
    return pcre_match(name,"^\\p{Han}+$");
}

string time_period(int time)
{
        int t, d, h, m, s;
        string str;

        t = time;
        s = t % 60;             t /= 60;
        m = t % 60;             t /= 60;
        h = t % 24;             t /= 24;
        d = t;

        if( d ) str = chinese_number(d) + "天";
        else str = "";

        if( h ) str += chinese_number(h) + "小时";
        if( m ) str += chinese_number(m) + "分";
        str += chinese_number(s) + "秒";

        return str;
}