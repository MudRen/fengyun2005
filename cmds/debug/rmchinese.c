inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string key, chinz;
        if(!me->query("env/yesiknow")) return notify_fail("这个指令已经被废除了！\n");
	if( !arg || arg=="" )
		return notify_fail("指令格式：rmchinese <英文>\n");

	if( sscanf(arg, "<%s>", key)==1 ) {
		CHINESE_D->remove_translate(key);
		write( "remove " + key + "\nOk.\n");
		return 1;
	}

	return 0;
}

int help()
{
	write ( @HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m巫师指令格式 : 	rmchinese <英文>[0m
[0;1;37m────────────────────────────────[0m   
指令格式：rmchinese <英文>

[0;1;37m────────────────────────────────[0m   
HELP
	);
	return 1 ;
}
