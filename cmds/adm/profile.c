// profile.c

int main(object me, string arg)
{
	seteuid(geteuid(me));

	PROFILE_D->make_profile(arg);
	write("Result written to /PROFILE\n");

	return 1;
}
int help (object me)
{
        write(@HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m巫师指令格式 : 	profile[0m
[0;1;37m────────────────────────────────[0m   

turns on command profiling, the result will be saved to /PROFILE

[0;1;37m────────────────────────────────[0m    
HELP
);
        return 1;
}
 
