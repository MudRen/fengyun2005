#define TRACE_DETAIL_LENGTH_LIMIT	300
#define SPRINTF_OVERFLOW		65535
#define LOG		"static/crashes"
object connect()
{
	object login_ob;
	mixed err;

	err = catch(login_ob = new(LOGIN_OB));

	if (err) {
		write("现在有人正在修改使用者连线部份的程式，请待会再来。\n");
		write(err);
		destruct(this_object());
	}
	return login_ob;
}

// compile_object: This is used for loading MudOS "virtual" objects.
// It should return the object the mudlib wishes to associate with the
// filename named by 'file'.  It should return 0 if no object is to be
// associated.
mixed compile_object(string file)
{
	object daemon;
	if( daemon = find_object(VIRTUAL_D) )
		return daemon->compile_object(file);
	else
		return 0;
}



protected void crash(string error, object command_giver, object current_object)
{
	log_file(LOG, MUD_NAME + " crashed on: " + ctime(time()) +", error: " + error + "\n");
	log_file(LOG, "command_giver: " + (command_giver ? file_name(command_giver) : "none") + "\n");
	log_file(LOG, "current_object: " + (current_object ? file_name(current_object) : "none") + "\n");
	log_file(LOG, "call_stack(0): "+sprintf("%O\n", call_stack(0)));
	log_file(LOG, "call_stack(1): "+sprintf("%O\n", call_stack(1)));
	log_file(LOG, "call_stack(2): "+sprintf("%O\n", call_stack(2)));
	log_file(LOG, "call_stack(3): "+sprintf("%O\n", call_stack(3)));
	log_file(LOG, "this_player(): "+sprintf("%O\n", this_player()));
	log_file(LOG, "this_player(1): "+sprintf("%O\n", this_player(1)));
	log_file(LOG, "this_player_command: " + (this_player() ? sprintf("%O\n",this_player()->query_last_input()) : "none"));
	log_file(LOG, "previous_object(): "+sprintf("%O\n", previous_object()));

	foreach( object ob in users() )
	{
		reset_eval_cost();

		if( objectp(ob) && objectp(environment(ob)) )
			ob->save();
	}
	reset_eval_cost();

	efun::shout("风云核心发生系统错误！\n");
	efun::shout("重新启动风云系统。\n");

	foreach( object ob in users() )
		flush_messages(ob);
}

// Function name:   update_file
// Description:     reads in a file, ignoring lines that begin with '#'
// Arguements:      file: a string that shows what file to read in.
// Return:          Array of nonblank lines that don't begin with '#'
// Note:            must be declared nosave (else a security hole)
protected string *update_file(string file)
{
	string *list;
	string str;
	int i;
	str = read_file(file);
	if (!str)
		return ({});
	list = explode(str, "\n");
	for (i = 0; i < sizeof(list); i++) {
		if (list[i][0] == '#') {
			list[i] = 0;
		}
	}
	return list;
}

// Function name:       epilog
// Return:              List of files to preload
string *epilog(int load_empty)
{
	string *items;

	items = update_file(CONFIG_DIR + "preload");
	return items;
}

// preload an object
void preload(string file)
{
	int t1;
	string err;

	if (file_size(file + ".c") == -1)
		return;

	t1 = time();
	write("Preloading : " + file );
	err = catch(call_other(file, "??"));
	if (err)
		write(" -> Error " + err + " when loading " + file + "\n");
	else
		write(".... Done.\n");

}

void log_error(string file, string message)
{
        string error_type;
        string name, home;
        object user;


        /*
        user = this_player(1);
        if( !objectp(user) ) user = this_player();
        if( !objectp(user) ) user = previous_object();
        */
        user = this_interactive() || this_player() || previous_object();

        error_type = strsrch(message, "Warning") == -1 ? "错误" : "警告";

        if( objectp(user) && userp(user) )
        {
                if( !wizardp(user) )
                {
                        if( find_object(CHANNEL_D) )
                                CHANNEL_D->do_sys_channel("sys", user->query("id")+" "+user->query("name")+"编译时段"+error_type+"："+message);
                }
                if (error_type == "错误")
                {
                        /* code */
                        tell_object(user, "\n编译时段" + error_type + "：" + message);
                }
        }
        else
        {
                if( find_object(CHANNEL_D) )
                        CHANNEL_D->do_sys_channel("sys", (objectp(user) ? base_name(user)+" " : "")+"编译时段"+error_type+"："+message);
        }
        efun::write_file(LOG_DIR + "log", message);
}


// save_ed_setup and restore_ed_setup are called by the ed to maintain
// individual options settings. These functions are located in the master
// object so that the local admins can decide what strategy they want to use.
int save_ed_setup(object who, int code)
{
	string file;

    if (!intp(code))
        return 0;
    file = user_path(getuid(who)) + ".edrc";
    rm(file);
    return write_file(file, code + "");
}

// Retrieve the ed setup. No meaning to defend this file read from
// unauthorized access.
int retrieve_ed_setup(object who)
{
   string file;
   int code;

    file = user_path(getuid(who)) + ".edrc";
    if (file_size(file) <= 0) {
        return 0;
    }
    sscanf(read_file(file), "%d", code);
    return code;
}

// When an object is destructed, this function is called with every
// item in that room.  We get the chance to save users from being destructed.
void destruct_env_of(object ob)
{
	if (!interactive(ob))
		return;
	tell_object(ob, "你所存在的空间被毁灭了。\n");
	ob->move(VOID_OB);
}

// make_path_absolute: This is called by the driver to resolve path names in ed.
string make_path_absolute(string file)
{
	file = resolve_path((string)this_player()->query("cwd"), file);
	return file;
}

// called if a user connection is broken while in the editor; allows
// the mudlib to save the changes in an alternate file without modifying
// the original
string get_save_file_name(string fname)
{
    return fname + "." + time();
}

string get_root_uid()
{
   return ROOT_UID;
}

string get_bb_uid()
{
   return BACKBONE_UID;
}

string creator_file(string str)
{
	return (string)call_other(SIMUL_EFUN_OB, "creator_file", str);
}

string domain_file(string str)
{
	return (string)call_other(SIMUL_EFUN_OB, "domain_file", str);
}

string author_file(string str)
{
	return (string)call_other(SIMUL_EFUN_OB, "author_file", str);
}

string tracert_error(mapping error, int caught)
{
        int count;
        string err_msg;
        mapping trace;

        err_msg = "\n"+sprintf(@ERR
──────────────<Bugs Report>──────────────
[ 错误时间 ]: %-s
[ 错误内容 ]: %-s[m
[ 错误档案 ]: %-s
[ 错误行数 ]: %-d[m
[ 资料回溯 ]:
ERR,
        ctime(time()),
        replace_string(error["error"], "\n", " "),
        error["file"],
        error["line"]);

        foreach( trace in error["trace"] )
        {
                count++;
                err_msg +=sprintf(@ERR
    -- 第 %|3d 笔 --
        [ 触动物件 ]: %O
        [ 程式档案 ]: %s
        [ 函式名称 ]: %s(%s)
        [ 呼叫行数 ]: %s
ERR,
                count,
                trace["object"],
                trace["program"]||"",
                trace["function"]||"",
                trace["arguments"] ? implode(map(trace["arguments"], (:typeof($1):)), ", ") : "",
                (trace["line"] || "未知")+"");

                if( trace["arguments"] )
                {
                        err_msg += "        [ 传入参数 ]:\n";
                        err_msg += implode(map(trace["arguments"], (: "                   ** ("+typeof($1)+")"+implode(explode(sprintf("%."+TRACE_DETAIL_LENGTH_LIMIT+"O\n", $1)+(strlen(sprintf("%O", $1)) > TRACE_DETAIL_LENGTH_LIMIT ? "... 讯息过长省略\n" : ""), "\n"),"\n                      ") :)), "\n")+"\n";
                }
                if( trace["locals"] )
                {
                        err_msg += "        [ 程式变数 ]:\n";
                        err_msg += implode(map(trace["locals"], (: "                   ** ("+typeof($1)+")"+implode(explode(sprintf("%."+TRACE_DETAIL_LENGTH_LIMIT+"O\n", $1)+(strlen(sprintf("%O", $1)) > TRACE_DETAIL_LENGTH_LIMIT ? "... 讯息过长省略\n" : ""), "\n"),"\n                      ") :)), "\n")+"\n";
                }
        }
        err_msg += "──────────────<Bugs Report>──────────────\n\n";
        return err_msg;
}

// simulate the old behavior of the driver
string standard_trace(mapping error, int caught)
{
        int i, s;
        string res;
        object me;
        mixed *cmds;

        /* keep track of number of errors per object...if you're into that */

        res = (caught) ? "错误讯息被拦截：" : "";
        res = sprintf("%s\n执行时段错误：%s\n程式：%s 第 %i 行\n物件：%s\n",
                      res, error["error"],
                      error["program"], error["line"],
                      error["object"] ? file_name(error["object"]) : "0");

        if( !error["object"] && (me = this_player()) ) {
                res += sprintf("当前玩家：%s(%s) - %O  所在环境：%O\n",
                               me->query("name"), me->query("id"), me, environment(me));
                cmds = me->query_commands();
                res += me->name(1) + "身上及四周的物品与所在的环境提供以下指令：\n";
                for(i = 0; i<sizeof(cmds); i++)
                        res += sprintf("%-15s  %2d %O\n",
                                       cmds[i][0], cmds[i][1], cmds[i][2]);

                res += sprintf("当前的命令：%O\n", me->query_last_input());
        }

        i = 0;
        s = sizeof(error["trace"]);

        for (; i < s; i++)
        {
                res = sprintf("%s呼叫来自：%s 的 %s() 第 %i 行，物件： %O\n",
                              res,
                              error["trace"][i]["program"],
                              error["trace"][i]["function"],
                              error["trace"][i]["line"],
                              error["trace"][i]["object"]);
        }
        return res;
}

void error_handler(mapping error, int caught)
{
        string msg;
        object user;

        /*
        user = this_player(1);
        if( !objectp(user) ) user = this_player();
        if( !objectp(user) ) user = previous_object();
        */
        user = this_interactive() || this_player() || previous_object();

        efun::write_file(LOG_DIR + "debug.log", standard_trace(error, caught));

        // 避免陷入无限错误回报回圈
        if( previous_object() == this_object() )
        {
                if( find_object(CHANNEL_D) )
                        CHANNEL_D->do_sys_channel("sys", "Master object 发生无限错误回圈，"+error["file"]+" 第 "+error["line"]+" 行，错误："+error["error"]+"，已强制中止。");
                return;
        }

        msg = tracert_error(error, caught);
        efun::write_file(LOG_DIR + "debug.full", msg);

        if( objectp(user) && userp(user) )
        {
                if( strlen(msg) >= SPRINTF_OVERFLOW-50000 ) msg = msg[0..SPRINTF_OVERFLOW-50000] + "\n\n[讯息过长省略...]\n";
                user->set_temp("bug_msg", msg);

                if( !wizardp(user) )
                {
                        tell_object(user, "[1;5;33mWARNING[m 这里发现了臭虫，请用 bug 指令将详细情况报告给巫师或相关人员...\n");

                        if( find_object(CHANNEL_D) )
                        {
                                CHANNEL_D->do_sys_channel("sys", user->query("id")+" "+user->query("name")+"执行时段错误"+(caught ? "(Catch)" : "")+"："+error["file"]+" 第 "+error["line"]+" 行。");
                                CHANNEL_D->do_sys_channel("sys", "错误："+replace_string(error["error"],"\n", " ")+"。");
                        }
                }
                else
                        tell_object(user, "[1;33m执行时段错误[m：请执行 bug 检查详细错误回溯。\n"+
                                "[1;33m........档案[m："+error["file"]+"\n[1;33m........行数[m：第 "+error["line"]+" 行\n[1;33m........错误[m："+replace_string(error["error"],"\n", " ")+"\n");
        }
        else
        {
                if( find_object(CHANNEL_D) )
                {
                        CHANNEL_D->do_sys_channel("sys", (objectp(user) ? base_name(user)+" " : "")+"执行时段错误"+(caught ? "(Catch)" : "")+"："+error["file"]+" 第 "+error["line"]+" 行。");
                        CHANNEL_D->do_sys_channel("sys", "错误："+replace_string(error["error"],"\n", " ")+"。");
                }
        }

        return;
}






// valid_shadow: controls whether an object may be shadowed or not
// now we open it,unless me,seems no one use it.:D
// or if any security problems,we should reconsider it.
int valid_shadow( object ob ) { return 1; }

// valid_override: controls which simul_efuns may be overridden with
//   efun:: prefix and which may not.  This function is only called at
//   object compile-time
int valid_override( string file, string name )
{
	// simul_efun can override any simul_efun by Annihilator
	if (file == SIMUL_EFUN_OB || file==MASTER_OB)
		return 1;

	// Must use the move() defined in F_MOVE.
	if(((name == "move_object") || (name == "destruct")) && (file != F_MOVE))
		return 0;

    //  may also wish to protect destruct, shutdown, snoop, and exec.
	return 1;
}

// valid_seteuid: determines whether an object ob can become euid str
int valid_seteuid( object ob, string str )
{
    return (int)SECURITY_D->valid_seteuid( ob, str );
}

// valid_socket: controls access to socket efunctions
int valid_socket( object eff_user, string fun, mixed *info )
{
	return 1;
}

// valid_asm: controls whether or not an LPC->C compiled object can use
//   asm { }
int valid_asm( string file )
{
    return 1;
}

// valid_compile_to_c: controls whether or not an object may be compiled
//   via LPC->C
int valid_compile_to_c( string file )
{
    return 1;
}

// valid_hide: controls the use of the set_hide() efun, to hide objects or
//   see hidden objects
int valid_hide( object who )
{
    return 1;
}

// valid_object: controls whether an object loaded by the driver should
//   exist
int valid_object( object ob )
{
    return (!clonep(ob)) || inherits(F_MOVE, ob);
}

// valid_link: controls use of the link() efun for creating hard links
//   between paths
int valid_link( string original, string reference )
{
    return 0;
}

// valid_save_binary: controls whether an object can save a binary
//   image of itself to the specified "save binaries directory"
//   (see config file)
int valid_save_binary( string filename )
{
    return 1;
}

// valid_write: write privileges; called with the file name, the object
//   initiating the call, and the function by which they called it.
int valid_write( string file, mixed user, string func )
{
	object ob;

	if( ob = find_object(SECURITY_D) )
		return (int)SECURITY_D->valid_write(file, user, func);

	return 0;
}

// valid_read: read privileges; called exactly the same as valid_write()
int valid_read( string file, mixed user, string func )
{
	return 1;
}

string object_name(object ob)
{
	if( ob ) return ob->name();
}

void create()
{
	write("master: loaded successfully.\n");
}

int valid_bind(object binder, object old_owner, object new_owner)
{
	if( geteuid(binder)==ROOT_UID ) return 1;
	if( userp(new_owner) ) return 0;
	if( clonep(new_owner) ) return 1;
	return 0;
}
