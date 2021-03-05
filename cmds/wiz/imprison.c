// imprison.c
#include "/doc/help.h"
#include <ansi.h>

#define SYNTAX	"指令格式：imprison <玩家id> because <原因> for <多少小时>\n"
inherit F_CLEAN_UP;
 
int main(object me, string arg)
{
	object ob;
	object room;
	string name,reason;
	int duration;
	
	if (!wizardp(me)) 
		return notify_fail("你没有权力使用这个指令。\n");
	if (!arg) return notify_fail(SYNTAX);
	if (sscanf(arg, "%s because %s for %d", name, reason, duration)!=3)
		return notify_fail(SYNTAX);
		
	ob = find_player(name);
	if (!ob) return notify_fail("找不到这个玩家。\n");
	
	message_vision(HIR"\n$N手一挥，一阵微风将$n吹入风云监狱．．．\n"NOR,me,ob);
	tell_object(ob,HIR"你违反风云规则，被处罚入狱" + duration + "小时。\n\n"NOR);
	
	seteuid(geteuid(this_player(1)) );
	if(!(room =find_object(AREA_WIZ"jail")))
	room = load_object(AREA_WIZ"jail");
	ob->move(room);
	ob->set("imprison/start",time());
	ob->set("imprison/duration",60*60*duration);
	ob -> save();
	
	log_file("static/imprison", sprintf("[%s] %s imprison %s(%s) because %s for %d 小时.\n",
		ctime(time())[0..15], me->query("id"), ob->query("name"), ob->query("id"), reason, duration));	
	return 1;
}
 
int help(object me)
{
   write(@HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m巫师指令格式 : imprison <玩家id> because <原因> for <多少小时>[0m
[0;1;37m────────────────────────────────[0m   

将某个玩家禁锢在风云的监狱里，在监狱里什么也做不了，
一直到被提出监狱或者待满时间

[0;1;37m────────────────────────────────[0m 
HELP
   );
   return 1;
}
