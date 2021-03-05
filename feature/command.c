// command.c

#include <command.h>
#include <dbase.h>
#include <origin.h>

// Let command path be static, thus we can make sure no one can get command
// path directly from restore_object().
protected string *path;
nosave int hook_flag = 0;

// Leave this to allow other objects can search your commands such as
// help, which...
string find_command(string verb)
{
	return (string)COMMAND_D->find_command(verb, path);
}

// This is the add_action hook handling movement, commands, emotes and
// channels. Optimization is needed.
nomask int command_hook(string arg)
{
    string verb, file;

#ifdef PROFILE_COMMANDS
    int mem, utime, stime;
    mapping info;

    mem = memory_info();
    info = rusage();
    utime = info["utime"];
    stime = info["stime"];
#endif

    verb = query_verb();

    // going to an exit
    if( !arg 
        &&(environment() && stringp(environment()->query("exits/" + verb)))
	&&stringp(file = find_command("go"))
	&&call_other(file, "main", this_object(), verb))
        ;
    //execute a command
    else if( stringp(file = find_command(verb)) 
             && call_other(file, "main", this_object(), arg))
        ;
    //issue a emote
    //else if( EMOTE_D->do_emote( this_object(), verb, arg ) )
    //    ;
    //do channel.
    else if( CHANNEL_D->do_channel( this_object(), verb, arg ) )
        ;

    else return 0;

#ifdef PROFILE_COMMANDS
    info = rusage();
    PROFILE_D->log_command(verb, memory_info() - mem, info["stime"] - stime,
                           info["utime"] - utime);
#endif
    return 1;
}

nomask void set_path(string *p)
{
//	if( origin() != ORIGIN_LOCAL
//	&&	geteuid(previous_object()) != ROOT_UID )
//		return;
	path = p;
}

string *query_path() { return path; }
mixed *query_commands() { return commands(); }


int force_me(string cmd)
{
        int ret;

        if( !is_root(previous_object()) )
                return 0;

        ret = command(this_object()->process_input(cmd));
        if( objectp(this_object()) && !in_input() )
                this_object()->write_prompt();
        return ret;
}
nomask void enable_player()
{
	if(query_temp("disable_inputs"))
		 delete_temp("disable_inputs");
	else
	{
		if( stringp(query("id")) ) set_living_name(query("id"));
		else set_living_name(query("name"));
	
		enable_commands();
		
		// fix the double add from those enable_player() in other codes.	
		if (hook_flag==0) {
			hook_flag = 1;
			add_action("command_hook", "", 1);
		}

		if( !userp(this_object()) )
			set_path(NPC_PATH);
		else
		switch( wizhood(this_object()) ) {
			case "(admin)":
				set_path(ADM_PATH);
				enable_wizard();
				break;
			case "(arch)":
				set_path(ARC_PATH);
				enable_wizard();
				break;
			case "(wizard)":
				set_path(WIZ_PATH);
				enable_wizard();
				break;
			case "(apprentice)":
				set_path(APR_PATH);
				enable_wizard();
				break;
			case "(immortal)":
				set_path(IMM_PATH);
				break;
			default:
				set_path(PLR_PATH);
		}
	}
}

nomask void disable_player(string type)
{
        if( geteuid(previous_object())!=ROOT_UID
        &&      previous_object()!=this_object()) return;

        set("disable_type", type);
//      I hate to do this, but to fix the call crash bug
        if(!userp(this_object()))
        	disable_commands();
        else
        	set_temp("disable_inputs",1);
}


