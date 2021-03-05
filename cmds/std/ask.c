// ask.c -- by silencer@fy4 9/28/2002

#include <ansi.h>
inherit F_CLEAN_UP;

string in_this_room(object me,string arg);
string look_for_company(object me, object room, string information, int n);
string check_being(object room, string arg, object me);
string *msg_dunno = ({
	"$n对$N说道：嗯....这问题你可以问问自己吗？\n",
	"$n对$N说道：对不起，这个问题你还是去问别人吧。\n",
	"$n耸了耸肩，很惋惜地对$N说：无可奉告！\n",
	"$n对$N说道：嗯....这问题的答案我要好好想一想。\n",
	"$n睁大眼睛望著$N：这么简单的问题都要问吗？\n",
	"$n摇了摇头对$N说：我不知道。\n",
	"$n摇了摇头对$N说：没听说过。\n",
	"$n沉吟了片刻对$N说：好像有点印象，不过怎么也想不起来了。\n",
	"$n疑惑地看着$N,显然对$N的问题一无所知。\n",
});


int main(object me, string arg)
{
	string dest, topic, msg /*, file_msg*/, char_name;
	string *chat_msg;
	object ob;
	int i;
//	mapping inquiry;

	
	seteuid(getuid());

	if( !arg || sscanf(arg, "%s about %s", dest, topic)!=2 )
		return notify_fail("你要问谁什麽事？\n");

	if( !objectp(ob = present(dest, environment(me))) )
		return notify_fail("这里没有这个人。\n");

	if( !ob->is_character() ) {
		message_vision("$N对著$n自言自语....\n", me, ob);
		return 1;
	}

	if( !ob->query("can_speak") ) {
		message_vision("$N向$n打听有关『" + topic + "』的消息，但是$p显然听不懂人话。\n", me, ob);
		return 1;
	}

	if (me->query_temp("inquiry_time")+1>time()) {
		message_vision("$N对$n说：慢慢来，太快了我听不清你的问题。\n"NOR,ob,me);
		return 1;
	}
	
	me->set_temp("inquiry_time",time());
	
	if( !INQUIRY_D->parse_inquiry(me, ob, topic) )
		message_vision("$N向$n打听有关『" + topic + "』的消息。\n", me, ob);

	if( userp(ob) ) return 1;
	if( !living(ob) ) {
		tell_object(me,"但是很显然的，"+ob->name()+"现在的状况没有办法给你任何答覆。\n",
			me, ob);
		return 1;
	}

	if (ob->query("NO_ASK"))
	{
		tell_object(me,ob->query("NO_ASK"));
		return 1;
	}

//	ask for name.
	if(topic == "name" || topic == ob->query("id") || topic == ob->query("name")){
		message_vision("$n说道：$n就是我，我就是$n，有什么事么？\n",me,ob);
		return 1;
	}


//	ask for spouse
        if ( ob->query("marry"))
        if ( topic == ob->query("marry") || topic == ob->query("marry_name")) {
        	message_vision("$n说道："+ob->query("marry_name")+"是"+(ob->query("gender") == "女性" ? "外子":"内子")+"，有什么事么？\n",me,ob);
        	return 1;
       	}


//	ask for chat_chance message.
	if(topic == "here"){
		chat_msg = ob->query("chat_msg");
		i = random(sizeof(chat_msg));
		if(sizeof(chat_msg) > 0) {
			if (stringp(chat_msg[i])){
				message_vision(chat_msg[i], me, ob);
				
			} else { 
				message_vision("$n说道：嗯....这个问题嘛，让我想一下先！\n", me, ob);
			}
		} else {
			message_vision("$n说道：嗯，你想具体问什么事呢？\n",me,ob);
		}	
		return 1;
	}

//	hijack the old "leave" msg here
	if (topic == "leave" && me->is_apprentice_of(ob))
	{
		message_vision(CYN"$N沉吟许久道：想要另攀高枝了。。人各有志，不能勉强，不过各门各派都有
自己运气练功的法门，出了师门，原来的武功特技多半就没法用了，而且新师傅
也不会尽心尽力地教你（叛师一次少学20级技能），好好想想吧，出了门就没有
回头路了。\n"NOR, ob);
		return 1;	
	}
	
	if (topic == "叛师" || topic == "betray" ) {
		if (me->is_apprentice_of(ob))	{
			message_vision("$N说：人各有志，你若要走，我不勉强，以后就不要再回来了。\n",ob);
			ob->betray_action(me);
			me->set_temp("marks/apprentice_others",1);
		
		} else
			message_vision("$N说：你又不是我的徒儿，此事与我何干？\n",ob);
		return 1;
	}
	
//	check for specified msg (in NPC) or general msg	(under that area/NPC directory)
	if( msg = ob->query("inquiry/" + topic)) {
		if( stringp(msg)) {
			if (msg[0..5]=="action")  // 这里允许设置一个没有“某某说”的msg。这个msg必须以action打头。
				message_vision(CYN""+msg[6..sizeof(msg)-1]+"\n"NOR,ob);
			else 
				message_vision( CYN "$N说道：" + msg + "\n" NOR, ob);
		}
		return 1;
	}	
	
		
	if( stringp(ob->query_inquiry_msg(topic))) {
		message_vision( CYN "$N说道：" + ob->query_inquiry_msg(topic) + "\n" NOR, ob);
		return 1;
	}

//	check for nearby characters --- NPC is aware of his environment

	if (char_name= in_this_room(me,topic)) {
		message_vision(CYN "$N"+CYN"说道："+char_name+CYN"不就在你眼前么？\n"NOR,ob);
		return 1;
	}
	
	if (char_name = look_for_company(me, environment(ob),topic, 3)) {
		message_vision(CYN "$N"+CYN"说道：嗯，最近好像见过"+char_name+CYN"，应该就在左近。\n"NOR,ob);
		return 1;
	}
	
//	check for general replies	
	if (msg = ob->query("inquiry/" + "*")){
		if (msg[0..5]=="action")  // 这里允许设置一个没有“某某说”的msg。这个msg必须以action打头。
				message_vision(CYN""+msg[6..sizeof(msg)-1]+"\n"NOR,ob);
			else 
				message_vision( CYN "$N说道：" + msg + "\n" NOR, ob);
	} else {
		message_vision(msg_dunno[random(sizeof(msg_dunno))], me, ob);
	}
	return 1;

}

int help(object me)
{
   write( @HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m指令格式 : 	ask <某人> about <某事>    询问某人某件事  
		ask <某人> about <某人>    询问某人的情况
		ask <某人> about here      询问某人的聊天信息[0m
[0;1;37m────────────────────────────────[0m   

当遇到一个新的NPC时，你可以使用
ask <某人> about here 来得知他的日常聊天信息或平时所作的动作，

如果你对这个NPC的背景熟悉的话，可以用
ask <某人> about <某事> 来得知他对其他人/其他物件的评价。

如果你知道某人就在附近，但一时找不到，可以用
ask <某人> about <某人>   如果NPC最近见过此人，会给你一定提示。

这个指令在解谜时很重要，许多谜题都是由询问NPC某个关键人物或物品
的名字来触发的，关键人物物品的名字就要看你观察力是否敏锐，对有关
古龙小说是否熟悉了。
[0;1;37m────────────────────────────────[0m
HELP
   );
   return 1;
}


string in_this_room(object me,string arg) {
	object *inv;
	int i;
	
	inv=all_inventory(environment(me));
	for (i=0;i<sizeof(inv);i++) {
		if (inv[i]->query("id")== arg || inv[i]->query("name")== arg) 
			return inv[i]->query("name");
	}
	return 0;
}


string look_for_company(object me, object room, string information, int n) {

        object /**inv,*/ next_room;
	int i;	
	mapping exits;
	string *dirs, dest, id_name;
        
        if( mapp(exits = room->query("exits")) ) 
	{
		dirs=keys(exits);
		for(i=0;i<sizeof(dirs);i++)
		{
			dest=room->query("exits/"+dirs[i]);
			if(!next_room=find_object(dest))
				next_room=load_object(dest);
			if (!objectp(next_room)) continue;
			if (next_room==environment(me)) continue;
			if (next_room->query("summoned")) continue;
			if (!n) continue;
			if (id_name=check_being(next_room, information, me)) {
				room->delete("summoned");
				next_room->delete("summoned");
				return id_name;
			}	
			if (id_name=look_for_company(me,next_room,information,n-1)) {
				room->delete("summoned");
				next_room->delete("summoned");
				return id_name;
			}
		}
	}
	room->delete("summoned");
	return 0;
}


string check_being(object room, string arg, object me) {
	object *inv;
	int i;
//	tell_object(me,"room is"+ (string)room->query("short")+"\n");
	room->set("summoned",1);
	inv=all_inventory(room);
	if (!sizeof(inv)) return 0;
	for(i=0;i<sizeof(inv);i++){
		if (!inv[i]->is_character()) continue;
		if (inv[i]->query("id")== arg || inv[i]->query("name")==arg) {
			return 	inv[i]->query("name");
		}
	}
	return 0;
}