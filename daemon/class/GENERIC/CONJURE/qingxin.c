// 琴 思路 by Sinny/Silencer@fy4.
// 清心普善曲： 
// 十面埋伏曲：
// 百鸟朝凤曲： 
// 碧海潮生曲:  
// 潇湘水云曲：
// 广陵散


#include <ansi.h>
inherit SSERVER;

int conjure(object me, object target)
{
	string msg;
	object *weapon,*inv;
	int skill, your_exp, my_exp, damage, i;
	
	if (me->is_ghost())
		return notify_fail("你尚是鬼魂，还是想法先回阳间吧。\n");
	
	weapon = filter_array(all_inventory(me),(:$1->query("timbre"):));
		
	if (!sizeof(weapon))	
		return notify_fail("你手边无琴，何以成乐？ \n");
		
	if (me->is_busy())
		return notify_fail("你现在正忙，有何闲暇弹琴？\n");
	
	skill = me->query_skill("music",1);	
	if (!skill)
		return notify_fail("你于音律一窍不通，瞎拨了几下，顿觉索然无味。\n");
	
	if (me->query("annie/music_choose") != 4 && userp(me))
		return notify_fail("这曲子你似乎没学会诶。\n");

	if (skill < 150)
		return notify_fail("你发现此谱过于高深，至少需要150级的琴道才能演奏。\n");
        
    if (me->query_condition("qingxin"))
    	return notify_fail("你刚弹奏过清心普善曲。\n");
    
    if( me->query("atman") < 200 )
		return notify_fail("弹奏『清心普善曲』需要200点灵力！\n");
	me->add("atman",-200);
			        
	skill = skill + weapon[0]->query("timbre");
	
	message_vision(HIG"
$N手抚琴弦，铮铮几声，曲调却是柔和之至，宛如一人轻轻叹息，又似是朝露
暗润花瓣，晓风低拂柳梢。。。。。 \n"NOR,me);


	me->apply_condition("qingxin", 10);
	me->set_temp("marks/music-qx", skill);
		
	return 1;	
}
