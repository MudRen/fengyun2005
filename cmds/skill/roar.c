//	Silencer@fy4 workgroup

#include <ansi.h>
inherit F_CLEAN_UP;

int main (object me, object target)
{
	object *ob;
	int skill, iron, duration;
	mapping buff;
	string msg;
	
	if (me->query("class")!= "lama")
		return notify_fail("只有大昭弟子才能宣『明尊护身』\n");
		
	if (me->query_skill_mapped("force")!="bolomiduo")
		return notify_fail("『明尊护身』是婆萝蜜多心经的特殊功能。\n");
	skill = me->query_skill("bolomiduo",1);
	if (skill < 160)
		return notify_fail("『明尊护身』需要160级婆萝蜜多心经和150级金刚不坏功。\n");
	
	iron = me->query_skill("jin-gang",1);
	if (iron < 150)
		return notify_fail("『明尊护身』需要160级婆萝蜜多心经和150级金刚不坏功。\n");
		
	if (ANNIE_D->check_buff(me,"invul"))
		return notify_fail("你已经在使用类似的武功了。\n");
		
	duration = me->query("timer/pfm/dz_roar")-time() + 1800 - F_ABILITY->check_ability(me,"mz_add")* 60;     
	if (duration>0)
      	return notify_fail("你还需要等待"+(int)(duration/60+1)+"分钟左右才能再次使用『明尊护身』。\n");
		
	if( !me->is_fighting() )
		return notify_fail("『明尊护身』只能在战斗中使用。\n");
	
	me->set("timer/pfm/dz_roar",time());
	
	msg = BRED + HIY "$N右手指天，左手指地，绕行七步，气沉丹田，猛然咏出低沉有力的佛号，\n";
	msg += BRED + HIY"『唵　嚩　囉　谟　穆』，佛音乍落，面散金光，身罩霞霓！\n\n"NOR;
	
	buff = 
		([
			"caster":me,
			"who":me,
			"type":"invul",
			"att":"bless",
			"name":"婆萝蜜多心经·明尊护身",
			"time":	20,
			"buff_msg":msg,
			"buff1": "resistance/kee",
			"buff1_c":100,
			"buff2": "pfm/dz_roar",
			"buff2_c": 1,
		]);
	ANNIE_D->buffup(buff);
	return 1;
}


int help(object me)
{
write(@HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m指令格式 : 	roar[0m
[0;1;37m────────────────────────────────[0m   

无南佛号是大昭高僧的专用指令，婆罗蜜多心经与金刚不坏功炼至极致，
一声断喝，如金佛附体，人不可伤。此式极耗元气，每30分钟使用一次，
每次延续20秒钟，期间不受气血伤害。需要160级婆罗蜜多心经和150级
金刚不坏功。

[0;1;37m────────────────────────────────[0m   
HELP
    );
    return 1;
}