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
	object *stuff, weapon;
	int skill,i , damage;
	int qin;
	
    if (me->query("class") != "baiyun") 
    	return notify_fail("只有白云岛弟子可以演奏『广陵散』\n");

	if (me->is_ghost())
		return notify_fail("你尚是鬼魂，还是想法先回阳间吧。\n");
	
	skill = me->query_skill("music",1);	
	if (!skill)
		return notify_fail("你于音律一窍不通，瞎拨了几下，顿觉索然无味。\n");
	if (skill < 200)
		return notify_fail("你信手拨弹了几下，发现此谱过于高深，至少需要200级的琴道才能演奏。\n");

	stuff = all_inventory(me);
	qin=0;
	for (i=0;i<sizeof(stuff) ;i++){
		if(qin < stuff[i]->query("timbre")){
		  qin = stuff[i]->query("timbre");
		}
	}  
	if(!qin && userp(me)) return notify_fail("你好像忘记带琴了。\n");

	if( !target ) target = offensive_target(me);        
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("『广陵散』只有在战斗弹奏才有奇效。\n");
        
    if(me->query_temp("max_bird") || me->query_temp("pfm/summoning_crane"))
       	return notify_fail(CYN"你铮铮拨弹了几下，琴声肃杀凄凉，令人潸然泪下。\n"NOR);	
        	
    if( me->query("atman") < skill*2 )
		return notify_fail("弹奏『广陵散』需要"+chinese_number(skill*2)+"点灵力！\n");
	if (userp(me))	me->add("atman",-skill*2);
	
	me->perform_busy(2);
		        
	message_vision(YEL"
$N悲啸一声，指取古劲，似千钧在握，又似一骑绝尘，万古同悲。挥拨之间，
一股萧杀磅礴之意直冲霄汉，但闻其声者无不始而愤，即而悲，终而涕泪之无
从，感人如斯，鬼神为之悲泣，天地为之动容！ \n\n\n"NOR,me);
	me->set_temp("pfm/summoning_crane",1);
	call_out("summoning",3,me);
	return 1;
 		
}

int summoning(object me) {
	
	object bird;
	int skill;
	
	skill = me->query_skill("magic");
	if (!me || me->is_ghost()) return 1;
	
	if (random(me->query_skill("music",1))> 5 ) {
		message_vision(RED"
『广陵散』曲毕，天地之间寂然无声，似乎都已沉醉其中，募然，天地交接之
处宛如天唱般传来清啸一声，万里白云仿佛火烧一般，鲜红如血，一只硕大无
比的火鹤从天而降！\n\n"NOR,me);
			seteuid(getuid());
	        bird = new("/obj/npc/fire_crane");
	        bird->move(environment(me));
	        // 475 500
	        bird->invocation(me, skill);
			bird->set("possessed", me);
			me->add_temp("max_bird",1);
	}
 	else {
 		message_vision(WHT"
募然“铮、铮”的数声，七弦尽断，你但觉生平凄苦伤心之事，历历在目，无
法控制住悲愤之情，伏琴大哭，“哇”的一声喷出大口鲜血！\n\n"NOR,me);
		me->receive_damage("kee",skill);
		me->receive_damage("gin",skill);
		me->receive_damage("sen",skill);
		me->set_temp("last_damage_from","一曲『广陵散』毕，呕血数升而亡。\n");
	}
	me->delete_temp("pfm/summoning_crane");
	return 1;
}