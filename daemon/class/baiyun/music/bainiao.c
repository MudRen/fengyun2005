
#include <ansi.h>
inherit SSERVER;

int conjure(object me, object target)
{
	string msg;
	object weapon;
	int skill;
	object *stuff;
	int qin,i;
	
    	if (me->query("class") != "baiyun") 
    		return notify_fail("只有白云岛弟子可以演奏『百鸟朝凤曲』\n");

	if (me->is_ghost())
		return notify_fail("你尚是鬼魂，还是想法先回阳间吧。\n");
	
	stuff = all_inventory(me);
	qin=0;
	for (i=0;i<sizeof(stuff) ;i++){
		if(qin < stuff[i]->query("timbre")){
		  qin = stuff[i]->query("timbre");
		}
	}  
	if(!qin && userp(me)) return notify_fail("你好像忘记带琴了。\n");
		
	skill = me->query_skill("music",1);	
	if (!skill)
		return notify_fail("你于音律一窍不通，瞎拨了几下，顿觉索然无味。\n");
	
	if (skill < 120)
		return notify_fail("你信手拨弹了几下，发现此谱过于高深，至少需要100级的琴道才能演奏。\n");

	if (me->query_temp("shield_force"))
		return notify_fail(CYN"你信手拨弹了几下，琴声清丽，平正中和，隐隐有王者之意。\n"NOR);	
	  
        if( me->query("atman") < 1 )
		return notify_fail("弹奏『百鸟朝凤曲』需要灵力！\n");
	me->add("atman",-1);
	me->start_busy(2);

	skill = skill ;
	
	message_vision(CYN"
$N轻拨琴弦，琴声清丽，平正中和，隐隐有王者之意，忽听得空中振翼之声
大作，各处飞来无数青鸟，或止歇树巅，或上下翱翔，毛羽缤纷，蔚为奇观。
未几，竟纷纷环飞在$N身畔。\n\n"NOR,me);
 
	me->set_temp("shield_force/type","atman");
	me->set_temp("shield_force/ratio",skill);
	me->set_temp("shield_force/msg",
		CYN"青鸟来回盘旋，舍身扑向$N，挡住了$N的攻势。\n"NOR);
	me->start_call_out( (: call_other, __FILE__, "remove_effect", me :), skill/2);     
	return 1;
}


void remove_effect(object me)
{
        me->delete_temp("shield_force");
        message_vision(CYN"$N身畔的青鸟展翅长鸣，消失在云端不见了。\n"NOR,me);
}

