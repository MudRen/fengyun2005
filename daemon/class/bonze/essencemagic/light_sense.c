// Silencer@fengyun	June.2005
// 『光识』(light_sense)   -〉400+random(400)对鬼魂杀伤力*2	（需120级八识神通） 

#include <ansi.h>
inherit SSERVER;

int bbqthem(object me, object obj);

int conjure(object me, object target)
{
	int lvl, i, j ,k;
	object env, *inv, obj;
	object *myteam;
	string id_enemy;

	if( me->query("class")!="bonze" ) {
		return notify_fail("只有兴国禅寺的弟子才可以使用『光识』\n");
	}
	lvl = (int) me->query_skill("magic");
	if( (int)me->query_skill("essencemagic",1) < 120 ) {
		return notify_fail("『光识』需要120级八识神通！");
	}
	if( !me->is_fighting() ) {
		return notify_fail("只有在战斗中才能使用光识。\n");
	}
	if( me->query("atman") < 200 ) {
		return notify_fail("『光识』需要200点的灵力。\n");
	}
	if( userp(me) ) {
		me->add("atman", -200);
	}
	message_vision(WHT "
$N双手虚握，掌间聚成寸许大小一朵莲花，每片莲叶分"HIC"青、"HIR"红、"HIY"黄、"HIW"白，"BLK"黑、"HIB"蓝、\n"+
HIM"紫"NOR+WHT"七样颜色。片刻，光华愈加强盛，如银龙闹海，倏忽电掣，"WHT"猛地一团火光从中飞
出，爆为万点寒星，四方飞散。。。。\n" NOR, me);

	inv = me->query_enemy();
	for( i = 0; i < sizeof(inv); i++) {
		bbqthem(me, inv[i]);
	}
	me->perform_busy(2);
	return 1;
}


int bbqthem(object me, object obj)
{
	int magic, skill;
	string id_enemy;

	magic = (int) me->query_skill("magic");
	skill = me->query_skill("essencemagic",1);
	message_vision(HIR "\n炽热的红光象利剑般射向$N，\n" NOR, obj);
	me->add_temp("apply/magic", skill*2);
	if( COMBAT_D->do_magic_attack(me, obj, "magic", "sen") ) {
		magic = random(magic) + magic; // random(400)+ 400;
		magic = magic*(100+F_ABILITY->check_ability(me,"lightsense_add")*2)/100;
		if( ANNIE_D->check_buff(me,"xg-evil") ) {
			magic = magic*(150+F_ABILITY->check_ability(me,"3_zhuxian_add",3)*2)/100;
		}
		if( !obj->query("ghostcurse") ) {
			if( obj->is_ghost() || obj->is_zombie() ) {
				magic = magic*2;
			}
		}
		magic = COMBAT_D->magic_modifier(me, obj, "sen", magic);
		obj->receive_damage("sen", magic, me);
		COMBAT_D->report_status(obj);
		COMBAT_D->win_lose_check(me,obj,magic);
	} else {
		message_vision(YEL"光芒过后，$N却毫发无损！\n"NOR, obj);
	}
	me->add_temp("apply/magic", -skill*2);
	return 1;
}



