// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
// emoted.c
#define NEW_PERIOD  32400 // players younger than 9 hours can only use new channel
#include <ansi.h>
#include <globals.h>
inherit F_SAVE;
inherit F_DBASE;
mapping emote;

//	The emote mapping contains the data base of emote definitions. Each emote
//	is defined in a sub-mapping with the following structure:
//
//	myself	- the message emoter will see
//	target	- the message the target will see when targeted
//	others	- the message others will see when no argument.
//
//	The emote mapping is indexed with the emote 'pattern' instead of emote
//	verb. For example, typing "smile" without argument will cause the daemon
//	search the emote mapping with "smile" as key, and typing "smile someone"
//	will cause the daemon search the emote mapping with "smile $" pattern as
//	the key, while $ means one argument.
//
//	In the message string, the following substitutions will be applied before
//	sending the messages:
//
//	$N		- name of emoter
//	$n		- name of target
//	$P		- pronoun of emoter
//	$p		- pronoun of target
//
//	Original by Annihilator@ESII (11/09/94)
void create()
{
	if( !restore() && !mapp(emote) )
		emote = ([]);
	        set("channel_id", "动作精灵");
		set("block_rumor",1);
}

int remove()
{
	save();
	return 1;
}

string query_save_file() { return DATA_DIR + "emoted"; }

// command_hook() of F_COMMAND call this as an alternate command processor.
int do_emote(object me, string verb, string arg)
{
	string str, my_gender, target_gender, msg_postfix, target_name;
	object target;
	string arg1;
	int chat_flag;
	int rumor_flag;
	int fy_flag;
	int new_flag;
	if( !environment(me) ) return 0;
	if( !wizardp(me) && userp(me) && (int)me->query("mud_age") < NEW_PERIOD &&  (
	verb == "chat*" || 
        verb == "rumor*" || 
        verb == "fy*" 
	)
	)
	{
	write("你只可以使用【新手】（ｎｅｗ）频道。\n");
	return 1;
	}
	chat_flag = 0;
	rumor_flag = 0;
	if (verb == "chat*" && arg ) {
        	if (sscanf(arg , "%s %s", verb, arg1)==0) 
         	       verb = arg;
		arg = arg1;
		chat_flag = 1;
	}
        if (verb == "new*" && arg ) {
                if (sscanf(arg , "%s %s", verb, arg1)==0) 
                       verb = arg;
                arg = arg1;
                new_flag = 1;
		chat_flag = 1;
        }
        if (verb == "fy*" && arg ) {
                if (sscanf(arg , "%s %s", verb, arg1)==0)
                       verb = arg;
                arg = arg1;
		chat_flag = 1;
                fy_flag = 1;
        }
        if (verb == "rumor*" && arg ) {
                if (sscanf(arg , "%s %s", verb, arg1)==0)
                       verb = arg;
                arg = arg1;
                chat_flag = 1;
		rumor_flag =1;

        }
        if ((int)me->query("chblk_on") && !wizardp(me))
             return notify_fail("你的频道被关闭了！\n");
        if ((int)query("block_rumor") && (verb == "rumor"||verb == "rumor*") )
                return notify_fail("遥言频道被关闭了！\n");
        if ((int)query("block_chat") && (verb == "chat"||verb == "chat*") )
                return notify_fail("聊天频道被关闭了！\n");
        if ((int)query("block_new") && (verb == "new"||verb == "new*") )
                return notify_fail("新手频道被关闭了！\n");
        if ((int)query("block_fy") && (verb == "fy"||verb == "fy*") )
                return notify_fail("风云频道被关闭了！\n");


	if ( !mapp(emote) || undefinedp(emote[verb]) ) return 0;
        if(rumor_flag)
        {
        	CHANNEL_D->do_channel(this_object(),"sys", sprintf("谣言：%s。", me->name()));
        }
	// Determine the pattern to be searched and the target.
	if ( stringp(arg) && arg != "" ) {
		target = present(arg, environment(me));
		if (!target && chat_flag) target = find_player(arg);
		if (!target && chat_flag) target = find_living(arg);
		if( !target && !fy_flag)
			return notify_fail("你要对谁做这个动作？\n"); 
		if( target && !me->visible(target))
			return notify_fail("你要对谁做这个动作？\n");
		if(target)
		{
			target_gender = target->query("gender");
			target_name = target->name();
		}
		else
		{
			target_gender = "男性";
			target_name = arg;
		}
		if( target==me ) {
			msg_postfix = "_self";
			target = 0;
		} else msg_postfix = "_target";
	} else msg_postfix = "";

	my_gender = me->query("gender");

	if( stringp(str = emote[verb]["myself" + msg_postfix]) ) {
		if( !rumor_flag)
			str = replace_string(str, "$N", me->name());
		else
			str = replace_string(str, "$N", "某人");
		str = replace_string(str, "$P", gender_self(my_gender));
		if( arg ) {
			str = replace_string(str, "$n", target_name);
			str = replace_string(str, "$p", gender_pronoun(target_gender));
			str = replace_string(str, "$S", RANK_D->query_self(me));
			str = replace_string(str, "$s", RANK_D->query_self_rude(me));
			str = replace_string(str, "$C", RANK_D->query_self_close(target));
			str = replace_string(str, "$c", RANK_D->query_close(target));
			str = replace_string(str, "$R", RANK_D->query_respect(target));
			str = replace_string(str, "$r", RANK_D->query_rude(target));
			str = replace_string(str, "$n", target->name());
			str = replace_string(str, "$p", gender_pronoun(target_gender));
		}
		if (!chat_flag && me)
			message("emote", CYN + str + NOR, me);
	}
	if( arg && stringp(str = emote[verb]["target"]) ) {
                if( !rumor_flag)
                	str = replace_string(str, "$N", me->name());
                else
                	str = replace_string(str, "$N", "某人");
		str = replace_string(str, "$P", gender_pronoun(my_gender));
		str = replace_string(str, "$n", target_name);
		str = replace_string(str, "$p", gender_self(target_gender));
		if( objectp(target) ) {
				str = replace_string(str, "$S", RANK_D->query_self(me));
				str = replace_string(str, "$s", RANK_D->query_self_rude(me));
				str = replace_string(str, "$C", RANK_D->query_self_close(target));
				str = replace_string(str, "$c", RANK_D->query_close(target));
				str = replace_string(str, "$R", RANK_D->query_respect(target));
				str = replace_string(str, "$r", RANK_D->query_rude(target));
				str = replace_string(str, "$n", target->name());
				str = replace_string(str, "$p", gender_pronoun(target_gender));
		}
		if (!chat_flag && target)
			message("emote", CYN + str + NOR, target);
	}
	if( stringp(str = emote[verb]["others"+msg_postfix]) ) {
                if( !rumor_flag)
                str = replace_string(str, "$N", me->name());
                else
                str = replace_string(str, "$N", "某人");
		str = replace_string(str, "$P", gender_pronoun(my_gender));
		if( arg ) {
			str = replace_string(str, "$n", target_name);
			str = replace_string(str, "$p", gender_pronoun(target_gender));
			if( objectp(target) ) {
				str = replace_string(str, "$S", RANK_D->query_self(me));
				str = replace_string(str, "$s", RANK_D->query_self_rude(me));
				str = replace_string(str, "$C", RANK_D->query_self_close(target));
				str = replace_string(str, "$c", RANK_D->query_close(target));
				str = replace_string(str, "$R", RANK_D->query_respect(target));
				str = replace_string(str, "$r", RANK_D->query_rude(target));
				str = replace_string(str, "$n", target->name());
				str = replace_string(str, "$p", gender_pronoun(target_gender));
			}
		}
                if( str==(string)me->query_temp("last_channel_msg") && chat_flag)
                        return notify_fail("用交谈频道说话请不要重复相同的讯息。\n");
		if (!chat_flag)
		message("emote", CYN + str + NOR, environment(me), ({me, target}));
		else {
	if(chat_flag && !fy_flag && !rumor_flag && !new_flag)
		message("channel:chat", GRN +"【闲聊】"+ str + NOR, users());
		if(new_flag && !fy_flag && !rumor_flag && chat_flag)
			message("channel:new", CYN +"【新手】"+ str + NOR, users());
		if( rumor_flag)
			message("channel:rumor", HIM +"【谣言】"+ str + NOR, users());
		if( fy_flag)
			CHANNEL_D->do_channel(me, "fy", str,1);
		}
	}

	if( objectp(target) ) target->relay_emote(me, verb);
	        if( userp(me) && chat_flag) 
                me->set_temp("last_channel_msg", str);

	return 1;
}

int set_emote(string pattern, mapping def)
{
	emote[pattern] = def;
	save();
	return 1;
}

int delete_emote(string pattern)
{
	map_delete(emote, pattern);
	save();
	return 1;
}

mapping query_emote(string pattern)
{
	if( !undefinedp(emote[pattern]) ) return emote[pattern];
	else return ([]);
}

string *query_all_emote()
{
	return keys(emote);
}
int set_block(string channel, int d)
{
        set("block_"+channel,d);
        return 1;
}

