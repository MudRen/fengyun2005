//Copyright (C) 1996-2000 Apstone, Inc. All Rights Reserved.
//Original from FY3
//Rewritten by Tie 8/98
//		Last Modified 
//			- 12/30/2001 by Justdoit
//			* Add control to prevent player flood screen

#include <ansi.h>
#include <net/dns.h>
#include <mudlib.h>

inherit F_SAVE;
inherit F_DBASE;
mapping emote;

//The emote mapping contains the data base of emote definitions. Each emote
//is defined in a sub-mapping with the following structure:
//
//myself	- the message emoter will see
//target	- the message the target will see when targeted
//others	- the message others will see when no argument.
//
//The emote mapping is indexed with the emote 'pattern' instead of emote
//verb. For example, typing "smile" without argument will cause the daemon
//search the emote mapping with "smile" as key, and typing "smile someone"
//will cause the daemon search the emote mapping with "smile $" pattern as
//the key, while $ means one argument.
//
//In the message string, the following substitutions will be applied before
//sending the messages:
//
//$N		- name of emoter
//$n		- name of target
//$P		- pronoun of emoter
//$p		- pronoun of target
//
//Original by Annihilator@ESII (11/09/94)
#define MAX_CHANNEL_ONE_SECTION		12
//#define BAN_CHANNEL_PERIOD		180
#define C_WIZ 1 //For wiz only
#define C_SYS 2 //For sys only, no one can talk on it
#define C_LIMITNEW 4 //no newbie can talk (see NEW_* defs)
#define C_ANONYMOUS 8 //show names as ANON_NAME
#define C_LOG 16 //If true, will log to LOG_FILE
#define C_ANN 32 //Announce Channel,a special channel. only wizard and system can talk, but announce everyone. annie 10.30/2003

#define NEW_PERIOD 32400
#define NEW_MSG "你联线时间必须超过九小时才能使用这个频道！\n"
#define ANON_NAME "某人"
#define LOG_FILE "channel.log"


int valid_channel(object me, string verb);		// 合法性校验
int do_sys_channel(string verb, string arg);		// 只读sys频道信息
varargs int do_channel(object me, string verb, string arg,int cemote);	// 常用的频道调用
object* team_listener(object me);			// 找出所有队友
object* bang_listener(object me);			// 找出同一门派成员
object* org_listener(object me);			// 找出同一组织成员

nosave mapping channels = ([
    "info" :(["name"     : "传闻",
              "msg_speak": HIY"【%s】%s\n"NOR,
              "flag"     : C_SYS|C_LOG ]),
    "vote" :(["name"     : "投票",
              "msg_speak": HIY"【%s】%s\n"NOR,
              "flag"     : C_SYS ]),
    "sys"  :(["name"     : "系统",
              "msg_speak": HIY"【%s】%s\n"NOR,
              "flag"     : C_WIZ|C_SYS ]),
    "qst"  :(["name"     : "任务",
              "msg_speak": HIB"【%s】%s\n"NOR,
              "flag"     : C_WIZ|C_SYS ]),
    "wiz"  :(["name"     :"巫师",
              "msg_speak": HIY"【%s】%s：%s\n"NOR,
              "msg_emote": HIY"【%s】%s" NOR,
              "flag"     : C_WIZ|C_LOG]),
    "announce" :(["name"     : "公示",
              "msg_speak": HIW"【%s】%s：%s\n"NOR,
              "msg_emote": HIW"【%s】%s" NOR,
              "flag"     : C_ANN ]),
    "chat" :(["name"     :"闲聊",
              "msg_speak": HIC"【%s】%s：%s\n"NOR ,
              "msg_emote": HIC"【%s】%s"NOR,
              "flag"     : C_LIMITNEW|C_LOG ]),
    "new"  :(["name"     :"新手",
              "msg_speak": HIG"【%s】%s：%s\n" NOR,
              "msg_emote": HIG"【%s】%s" NOR,
              "flag"     : C_LOG ]),
    "gab"  :(["name"     :"市井",
              "msg_speak": BLU"【%s】%s：%s\n" NOR,
              "msg_emote": BLU"【%s】%s" NOR ]),
    "fy"   :(["name"     :"风云",
              "msg_speak": HIR"【%s】%s：%s\n"NOR,
              "msg_emote": HIR"【%s】%s"NOR,
              "flag"     : C_LIMITNEW|C_LOG,
              "intermud" : GCHANNEL,
              "channel"  : "fy",
              "filter"   :(: $1["VERSION"]==MUDLIB_VERSION :)  ]),
    "fywiz":(["name"     :"风云巫师",
              "msg_speak": HIY"【%s】%s：%s\n"NOR,
              "msg_emote": HIY"【%s】%s"NOR,
              "flag"     : C_WIZ | C_LOG,
              "intermud" : GCHANNEL,
              "channel"  : "fywiz",
              "filter"   :(: $1["VERSION"]==MUDLIB_VERSION :)  ]),
    "rumor":(["name"     :"谣言",
              "msg_speak": HIM"【%s】%s：%s\n" NOR,
              "msg_emote": HIM"【%s】%s\n" NOR,
              "flag"     : C_LIMITNEW|C_ANONYMOUS|C_LOG ]),
    "teamtalk":(["name"     :"队伍",
              "msg_speak": WHT"【%s】%s：%s\n" NOR,
              "msg_emote": WHT"【%s】%s\n" NOR,
              "listeners": (:team_listener:) ]),
    "bangtalk":(["name"     :"帮会", //will be changed
              "msg_speak": HIW"【%s】%s：%s\n" NOR,
              "msg_emote": HIW"【%s】%s\n" NOR,
              "listeners": (:bang_listener:),
              "flag"     : C_LOG ]),
	"orgtalk":(["name"     :"组织", //will be changed
				"msg_speak": YEL"【%s】%s：%s\n" NOR,
				"msg_emote": YEL"【%s】%s\n" NOR,
				"listeners": (:org_listener:) ]),
    ]);

string query_save_file() { return DATA_DIR + "emoted"; }

void create()
{
	if( !restore() && !mapp(emote) )
		emote = ([]);
	seteuid(getuid());
	set("channel_id", "频道精灵");
	//set("id", "channeld");
	delete("block");
}

int valid_channel(object me, string verb)
{
	return(!undefinedp(channels[verb]) &&
		(wizardp(me) || (channels[verb]["flag"]&C_WIZ)==0));
}

int do_sys_channel(string verb, string arg)
{
	mapping channel;
	object* obs;
        
	if(undefinedp(channel=channels[verb])
	|| (channel["flag"]&C_SYS)==0 ) return 0;

	obs = filter_array(users(),"filter_listener",this_object(), channel);
	message("channel"+verb,
		sprintf(channel["msg_speak"],channel["name"],arg),obs);
	// Do the logging
	if(channel["flag"]& C_LOG ) log_file(LOG_FILE,sprintf("%s 『%s』%s\n",
			ctime(time()),channel["name"],arg));
	return 1;
}

varargs int do_channel(object me, string verb, string arg,
                       //optional args below:
                       // cemote=1 for cemote/cfy etc. use only
                       int cemote)
{
	int isemote, flag,t/*,openchanneltime*/,timetocount;
	string *tuned_ch;
	mapping channel; //the channel
	object *obs; //channel listeners
	object target;
	string msg, who;
	string emverb, emarg, msg_postfix;
	string target_gender,target_name,my_gender,my_name;
	
	if(cemote && undefinedp(channels[verb])) return 0;

	if(strlen(verb)>0 && verb[strlen(verb)-1]=='*' ) //is it a public emote?
	{
		if(!arg || arg=="")
		return 0;//notify_fail("你要使用什么动作表情？\n");
		verb=verb[0..strlen(verb)-2];
		isemote=1;
	}
	else isemote=0;

	if (interactive(me) && !wizardp(me))
	{
		// Prevent #space[80+] flood
		if (strlen(arg) >= 80 || strlen(verb) >= 80)
			return notify_fail("你输入的文字太长了。\n"); 

		t = time();
		timetocount=me->query_temp("time_to_count");
		if ( timetocount +2 < t ) 
		{
			me->set_temp("time_to_count",t);
			me->set_temp("user_channel_message",1);
		} 
		else
			me->add_temp("user_channel_message",1);

		if (me->query_temp("user_channel_message") > MAX_CHANNEL_ONE_SECTION) 
			return notify_fail("你不能在一秒内送出这么多条信息。\n" NOR);

	}

/*	if (interactive(me) && !wizardp(me))
	{
		t = time();
		timetocount=(int)me->query_temp("time_to_count");
		if ( timetocount +2 < t ) 
		{
			me->set_temp("time_to_count",t);
			me->set_temp("user_channel_message",1);
		} 
		else
			me->add_temp("user_channel_message",1);

		if ((int)me->query_temp("user_channel_message") > MAX_CHANNEL_ONE_SECTION && !wizardp(me)) 
		{
			me->set_temp("ban_channel",1);
			me->set_temp("openchannel",t + BAN_CHANNEL_PERIOD);
			me->delete_temp("user_channel_message");
			me->delete_temp("time_to_count");
			return notify_fail(HIR "由于你发布的信息太多，因此系统暂时"
						"禁止你发出信息。\n" NOR);
		}
	}
	if ((int)me->query_temp("ban_channel"))   
	{
		openchanneltime=(int)me->query_temp("openchannel");
		if ( openchanneltime > time() && !wizardp(me) ) 
		{
			return notify_fail("系统禁止你送出信息，请于 " +
				(openchanneltime - time()) + " 秒钟以后再尝试。\n");
		}
		else 
		{
			me->delete_temp("ban_channel");
			me->delete_temp("openchannel");
		}
	}
	else 
	{
*/			
	//is it a room emote (or invalid command)?
	if(undefinedp(channel=channels[verb]))
	{
		if(!undefinedp(emote[verb])) // This is a single-room emote!
		{
			if(stringp(arg)) //there is a target
			{
				if(environment(me)) {
					target = present(arg, environment(me));
				}
				//if(!target) target = find_player(arg);
				//if(!target) target = find_living(arg);
 				if(target && me->visible(target))
				{
					target_gender = target->query("gender");
					target_name = target->query("name");
				}
				else
				{
				// We have an argument BUT we can't find the target object!
				// target_gender = "男性";
				// target_name = arg;
				// if no target, then not allow do room emote
					return notify_fail("你要对谁做这个动作？\n"); 
				}
				msg_postfix = (target==me)?"_self":"_target";
			}
			else msg_postfix = "";
            
			my_gender=me->query("gender");
			my_name=me->query("name");

			if( userp(me) &&
			stringp(msg = emote[verb]["myself" + msg_postfix]) )
			{
				msg = replace_string(msg,"$N",my_name);
				msg = replace_string(msg,"$P",gender_self(my_gender));
				if(stringp(arg))
				{
					msg = replace_string(msg,"$n",target_name);
					msg = replace_string(msg,"$p",gender_pronoun(target_gender));
				}
				message("emote", CYN + msg + NOR, me);
			}
			if( target && (target != me)  &&
			stringp(msg = emote[verb]["target"]) )
			{
				msg = replace_string(msg, "$N", my_name);
				msg = replace_string(msg, "$P", gender_self(my_gender));
				msg = replace_string(msg, "$n", target_name);
				msg = replace_string(msg, "$p", gender_self(target_gender));
				message("emote", CYN + msg + NOR, target);
			}
			if(stringp(msg=emote[verb]["others"+msg_postfix]) && environment(me))
			{
				msg = replace_string(msg, "$N",my_name);
				msg = replace_string(msg,"$P",gender_pronoun(my_gender));
				if(stringp(arg))
				{
					msg = replace_string(msg, "$n", target_name);
					msg = replace_string(msg, "$p",gender_pronoun(target_gender));
				}
				message("emote", CYN + msg + NOR, environment(me),({me, target}));
			}
 		}
		else return 0; //an illegal command.
	}
	else //It's a public channel (verb is mapped in channels)
	{
		// Common requirements to use public channel
		flag=channel["flag"];

		//Need to pass 0 to speak in C_SYS channels!
		if( (flag&C_SYS) && me!=0 ) return 0;

		// If you are not a wiz, don't talk in wiz_only channels
		if(userp(me) && ((flag&C_WIZ) || (flag&C_ANN)) && !wizardp(me) ) return 0;

		// If you speak in this channel, turn on it
		if (userp(me)) 
		{
			tuned_ch =  me->query("channels");
			if(!pointerp(tuned_ch)) me->set("channels", ({ verb }));
			else if( member_array(verb, tuned_ch) == -1)
			me->set("channels", tuned_ch + ({ verb }));

			// if you are banned from using public channels, so be it
			if ((int)me->query("chblk_on") && !wizardp(me))
			return notify_fail("你的公共频道被关闭了！\n");

			// Check for blocks
			if((int)query("block/"+verb))
			return notify_fail(sprintf("%s频道被关闭了！\n",channel["name"]));

			// Check for Age requirement
			if( (flag&C_LIMITNEW) &&
			!wizardp(me) && me->query("mud_age") < NEW_PERIOD)
			return notify_fail(NEW_MSG);

			// Do the logging
			if( (flag & C_LOG) && userp(me))
			{
			// All wiz talks are recorded
			// All public talks are recorded
				log_file(LOG_FILE,sprintf("%s 『%s』%s(%s)：%s\n",
					ctime(time()),channel["name"],me->query("name"),
					me->query("id"),arg));			
			}
			
			// modified by justdoit 2001.12.7  
			// Let wizards can see who use rumor and let player have 10% changce to see who use rumor 
			if( (flag&C_ANONYMOUS) && userp(me)) 
			{
				if(!((int)me->query_temp("last_channel_same"))) 
				{
					do_sys_channel( "sys", sprintf("谣言：%s。", me->query("name") + "(" + me->query("id") +")" ));
					if (!random(10) && !wizardp(me))
					do_sys_channel( "info", sprintf("下面这条谣言的散播者为：%s！^_^", me->query("name") + "(" + me->query("id") +")" ));
				}
			}
		}
		// Individual requirements for channels
		// put something in mapping as a function pointer there.
		// Composing the message (for public channel)
		if(functionp(channel["listeners"]))
		obs=evaluate(channel["listeners"], me);
		else obs = users();
		if(!arrayp(obs)||sizeof(obs)==0) return 0; //Sometimes will get failed
		obs=filter_array(obs,"filter_listener",this_object(), channel);
        
		if(isemote) {			
			if(sscanf(arg,"%s %s", emverb, emarg) == 0) {
				emverb = arg;
			}
			if(!undefinedp(emote[emverb])) { //it is a public emote
				if(stringp(emarg)) { //there is a target
					if(objectp(environment(me))) {		
						target = present(emarg, environment(me));
					}
					if(!objectp(target)) target = find_player(emarg);
					if(!objectp(target)) target = find_living(emarg);
					if(objectp(target) && me->visible(target)) {
						target_gender = target->query("gender");
						target_name = target->query("name");
					} else {
					// We can't find the target object!
						if(channel["channel"] != "fy") {
							return notify_fail("你要对谁做这个动作？\n"); 
						}else if(objectp(target) && !target->query("wiz_invis")) {
							target_gender = target->query("gender");
							target_name = target->query("name");						
						}else {
							target_gender = "男性";
							target_name = emarg;
						}
					}
					msg_postfix = (target==me)?"_self":"_target";
				} else {
					msg_postfix = "";
                }

				my_gender=me->query("gender");
				if(flag & C_ANONYMOUS) {
					my_name=ANON_NAME;
				} else {
					my_name= me->query("name");
				}
				
				if(stringp(msg=emote[emverb]["others"+msg_postfix])) {	
					msg = replace_string(msg,"$N",my_name);				
					msg = replace_string(msg,"$P",gender_pronoun(my_gender));
					if(emarg) {
						msg = replace_string(msg,"$n",target_name);
						msg = replace_string(msg,"$p",gender_pronoun(target_gender));
					}
				}				
				msg=sprintf(channel["msg_emote"],channel["name"],msg);
			} else {
				return notify_fail("没有这个动作表情："+emverb+"\n");
			}
		} else if(!cemote) {
			if(flag & C_ANONYMOUS) {
				who=ANON_NAME;
			} else if(me->is_character()) {
				who = me->query("name")+"("+capitalize(me->query("id"))+")";
			} else if(stringp(who = me->query("channel_id")));
			else who="";

			if(!stringp(arg)) arg="......";
			msg=sprintf(channel["msg_speak"],channel["name"],who,arg);
		}
		else //cemote
		msg=sprintf(channel["msg_emote"],channel["name"],arg+"\n");
        
		// don't repeat public msgs, same for wiz and players
		if(userp(me)) /*&& !wizardp(me)) */
		if(msg == (string)me->query_temp("last_channel_msg"))
		{
			if(me->query_temp("last_channel_same") > 0) //allow max 2 times
			return notify_fail("请不要多次重复相同的讯息。\n");
			else me->add_temp("last_channel_same",1);
		}
		else
		{
			me->set_temp("last_channel_same",0);
			me->set_temp("last_channel_msg",msg);
		}
        
		message("channel:"+verb,msg,obs);
       	return 1;
		//Intermud stuff
		if( !undefinedp(channel["intermud"])
			&& base_name(me) != channel["intermud"] )
			
		channel["intermud"]->
			send_msg(channel["channel"], me->query("id"),
			me->name(1), arg, isemote, channel["filter"] );
	}
	
//	}
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

string *query_all_emote() { return keys(emote); }

string search_emote(string strsearch)
{
	string verbs="";
	string *everb = keys(emote);
	for (int i = 0;i< sizeof(everb) ; i++ )
	{
		mapping temp = emote[everb[i]];
		string *tempkeys = keys(temp);
		for(int j = 0; j<sizeof(tempkeys);j++)
		{
			if (tempkeys[j] != "updated")
			{
				if (strsrch(temp[tempkeys[j]],strsearch) != -1)
				{
					verbs += everb[i] + "+";
					break;
				}
			}
		}
	}
	return verbs;
}

int remove()
{
	save();
	return 1;
}

int set_block(string channel, int d)
{
	set("block/"+channel,d);
	return 1;
}

int filter_listener(object ppl, mapping ch)
{
    // Don't bother those in the login limbo.
	if (!objectp(ppl)) return 0;
	if( !environment(ppl) ) return 0;
	if( ch["flag"] & C_WIZ  ) return wizardp(ppl);
	return 1;
}

object* team_listener(object me)
{
	object* obs=me->query_team();
	if(!arrayp(obs)) notify_fail("你现在并没有和别人组成队伍。\n");
	channels["teamtalk"]["name"] = me->query_temp("team_name");
	return obs;
}

object* bang_listener(object me)
{
	object *obs, *target;
	int i;
	string mebang,obbang;

	mebang = (string)me->query("family/family_name");
	if(!mebang)
	{
		notify_fail("你不属于任何帮派！\n");
		return ({});
	}

	channels["bangtalk"]["name"]=mebang;
    
	obs=users();
	i = sizeof(obs);
	while (i--)
	{
		obbang = (string)obs[i]->query("family/family_name");
		if((mebang == obbang || wizardp(obs[i])))
		{
			if (sizeof(target)==0)
				target=({obs[i]});
			else 
				target+=({obs[i]});
		}
	}
	return target;
}

object* org_listener(object me)
{
	object *obs, *target;
	int i;
	string meorg,oborg;

	meorg = (string)me->query("organization/org_name");
	if(!meorg)
	{
		notify_fail("你不属于任何组织！\n");
		return ({});
	}

	channels["orgtalk"]["name"]=meorg;
    
	obs=users();
	i = sizeof(obs);
	while (i--)
	{
		oborg = (string)obs[i]->query("organization/org_name");
		if((meorg == oborg || wizardp(obs[i])))
		{
			if (sizeof(target)==0)
				target=({obs[i]});
			else 
				target+=({obs[i]});
		}
	}
	return target;
}


/*
 
               (\~~~/)            
               ( ．．)        

               (_____)~．      
   
　　　　　　　- FengYun - 　　　
　　　　　　annie 10.2003
　　　dancing_faery@hotmail.com
*/