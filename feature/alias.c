// alias.c

#define MAX_REPEAT 60
#define MAX_ALIASES 40
#define HISTORY_BUFFER_SIZE 10
#define MAX_IN_A_ROW 20
#define MAX_DO_COMMANDS         20
mapping alias;

nosave string last_input, orginal_input;
nosave string *history;
nosave int last_cmd, repeat_cnt = 0;
nosave int last_check, maxcom  = 0;
string process_input(string str);
string query_last_input() { return last_input; }

string remove_leadspace(string arg)
{
        int i;

        if( !stringp(arg) || arg =="" )
                return "";
        for( i = 0; i < strlen(arg); i++ )
                if( arg[i..i] != " " )
                        return arg[i..strlen(arg)];
        return "";
}

nomask int process_input_do(string verb, string args)
{
        if( verb != "do" ) return 0;
 //       DEBUG_CHANNEL("process_input_do ");
        if( args )
        {
                int do_times;
                int total_cmds;

                foreach( string action in explode(args, ",") )
                {
                        do_times = 1;
                        sscanf(action, "%d %s", do_times, action);

                        action = remove_leadspace(action);

                        if( do_times > MAX_DO_COMMANDS ) do_times = MAX_DO_COMMANDS;

                        if( !strsrch(action, "do ") )
                        {
                                tell_object(this_object(), "指令 do 中不能再有 do 的指令。\n");
                                return 1;
                        }

                        while( do_times-- && ++total_cmds )
                        {
                                if( total_cmds > MAX_DO_COMMANDS && !wizardp(this_object()) )
                                {
                                        tell_object(this_object(), "你不能一次下超过 "+MAX_DO_COMMANDS+" 个指令。\n");
                                        return 1;
                                }
                                // 必须command，否则add_action中query_verb出问题 by Lonely
                                command(process_input(action));
                        }
                }
        }
        else
                tell_object(this_object(), "请输入要连续下达的指令。\n");

        return 1;
}

string process_input(string str)
{
	 string verb, doargs;
	string *args, cmd, argstr;
	int i, j;
//	object room;
	if(this_object()->query_temp("disable_inputs"))
	return "什麽？\n";
	if(maxcom == 0)	last_check = time();
	if(maxcom == (MAX_IN_A_ROW -1 ) && time() == last_check)
	return "";
	else
	maxcom++;
	maxcom = maxcom % MAX_IN_A_ROW ;
	if( str==last_input ) {
		repeat_cnt++;
/*
		if((repeat_cnt > MAX_REPEAT)&& !wizardp(this_object())
		&& !this_object()->is_fighting()) {
		message_vision("忽然一阵闪光罩住了$N。\n",this_object());
        	this_object()->set_temp("last_location", base_name(environment(this_object())));
		tell_object(this_object(),"你被怀疑为机器人．\n");
        	room = load_object(AREA_WIZ"courthouse");
        	this_object()->move(room);
		repeat_cnt = 0;
		}
*/
	} else {
		repeat_cnt = 0;
		last_input = str;
	}

	if( str[0]=='!' ) {
		if( pointerp(history) && sizeof(history) ) {
			if( sscanf(str, "!%d", i) )
				str = (string)history[(HISTORY_BUFFER_SIZE + last_cmd - i) % HISTORY_BUFFER_SIZE];
			else
				str = history[last_cmd];
		} else
			return "";
	} else {
		if( !pointerp(history) ) history = allocate(HISTORY_BUFFER_SIZE);
		last_cmd = (last_cmd + 1) % HISTORY_BUFFER_SIZE;
		history[last_cmd] = str;
	}

	if( mapp(alias) ) {

		if( !undefinedp(alias[str]) )
			return replace_string( alias[str], "$*", "" );

		if( sscanf(str, "%s %s", cmd, argstr)==2 && !undefinedp(alias[cmd]) ) {
			cmd = replace_string( alias[cmd], "$*", argstr );
			args = explode(argstr, " ");
			if( (j = sizeof(args)) )
				for(i=0; i<j; i++)
					cmd = replace_string( cmd, "$" + (i+1), args[i] );
			return cmd;
		}
	}
	   if( sscanf(str, "%s %s", verb, doargs) != 2 ) verb = str;

        if( !doargs || !doargs[0] ) doargs = 0;

        if( process_input_do(verb, doargs) ) return "";
        last_input = (string)ALIAS_D->process_global_alias(str);
	return last_input;
}

int set_alias(string verb, string replace)
{
	if( !replace ) {
		if(mapp(alias) )
		{
			if (member_array(verb, keys(alias))!= -1)
			{
				map_delete(alias, verb);
				write(sprintf("去除 alias ：%s \n", verb));
			}
			else
				write(sprintf("你不曾设置这个 alias ：%s \n", verb));
		}
		return 1;
	} else {
		if( !mapp(alias) ) alias = ([ verb:replace ]);
		else if( sizeof(alias) > MAX_ALIASES )
			return notify_fail("您设定的 alias 太多了，请先删掉一些不常用的。\n");
		else
		{
			alias[verb] = replace;
			write(sprintf("设定：%s ＝　%s \n", verb,replace));
		}
		return 1;
	}
}

mapping query_all_alias()
{
	return alias;
}
