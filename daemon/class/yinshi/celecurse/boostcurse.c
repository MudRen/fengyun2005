//	Boostcurse 增加速度5-10， haste +30%
//	By Silencer@FY4 workgroup

#include <ansi.h>
inherit SSERVER;
int curse(object me, object target)
{
	string msg;
	mapping buff;	
	
	int add_agi, add_str, add_haste, celeskill;
		
	if(me->query("class")!="yinshi")
		return notify_fail("只有帝王谷弟子才能下鞭降。\n");
	
	celeskill = me->query_skill("celecurse",1); 
    if( celeskill < 80 )
                return notify_fail("鞭降需要80级通天降！\n");
	
	if( !target ) target = me;
		
	if (target!=me  && !me->team_member(target))
		return notify_fail("鞭降只能施加给队友或自己。\n");
	
    if (ANNIE_D->check_buff(target, "haste")|| ANNIE_D->check_buff(target, "agiup"))
       	return notify_fail("此人正在使用类似的武功。\n");
	
	if( me->query("kee") < 100 )
		return notify_fail("鞭降需要耗费100点的气血！\n");
	if (userp(me))	me->receive_wound("kee", 100);
	
	if (target!=me)
	message_vision(HIW "$N面色惨白如雪，身子抖动，如风中的布幔，双眼微翻，口中念念有词，
愈来愈快，愈来愈急，愈来愈低沉，猛然大喝一声向$n喷出一口鲜血！\n\n" NOR,me,target);
	else
	message_vision(HIW "$N面色惨白如雪，身子抖动，如风中的布幔，双眼微翻，口中念念有词，
愈来愈快，愈来愈急，愈来愈低沉，猛然大喝一声，喷出一口鲜血！\n\n" NOR,me);
	
	if (celeskill>=185 ) {		add_agi = 10;		add_haste = 50;	}	// 33% chance haste in real. 
	else if (celeskill >=125) {	add_agi = 10;		add_haste = 40;	} 
	else  					{	add_agi = 5;		add_haste = 30;	} 
		
	msg = HIG "你的攻击速度加快，身手更为敏锐了！\n"NOR;
	tell_object(target, msg);
	
	buff = 
		([
			"caster": me,
			"who":  	target,
			"type":  "haste",
			"type2": "agiup",
			"att":	"bless",
			"name":	"通天降·鞭降",
			"buff1":"apply/agility",
			"buff1_c":add_agi,
			"buff3": "apply/haste",
			"buff3_c":add_haste,
			"time":  900,
			"buff_msg": "",
		]);
	ANNIE_D->buffup(buff);
    return 1;
        
}