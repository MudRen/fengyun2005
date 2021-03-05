
// 为什么要用scroll，不用point? 为什么要凑齐n本才可以一次阅读，而不能一次增一点？
// ——目的依然是让玩家可以并尽可能的进行互相交换。

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("卷轴", ({ "scroll" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long",YEL"一卷薄薄的丝绢。\n"NOR);
                set("value", 1000);
                set("material", "paper");
        }
}

void init()
{
   	add_action("do_read","read");
}
    
int do_read(string arg)
{
	object me,*inv;
	mapping data;
	int lev,req,i,count;
	string t;

	if (!arg)
		return 0;

	count = 0;

	me = this_player();

	if (present(arg,me)!=this_object())
		return 0;

	t = query("teaching");

	lev = ANNIE_D->check_ability(me,t);
	if (lev >= 10)
		return notify_fail("这门技巧你已经修炼到了极致，再也不能长进了。\n");
	req = lev + 1;

	inv = all_inventory(me);
	for (i=0; i<sizeof(inv); i++)
		if (inv[i]->query("teaching") == t)
			count++;
	if (count < req)
		return notify_fail("继续修炼这门技巧，你必须找齐至少"+chinese_number(req)+"本"+query("name")+"。\n");

   	if( me->query("potential") - me->query("learned_points") < req*req*req*50 )
       	return notify_fail("继续修炼这门技巧，你必须至少拥有"+chinese_number(req*req*req*50)+"点潜能。\n");

	me->add("learned_points",req*req*req*50);
	message_vision(HIW"$N小心翼翼地打开卷轴。\n"NOR,me);
	tell_object(me,HIC"你照着卷轴上的法门运气练功，果真是奥秘无穷．．．．\n"NOR);
	tell_object(me,HIC"一炷香的功夫，你的武学修为又上了一层楼。\n"NOR);
	message_vision(HIG"片刻，$N手中的卷轴翩翩碎落，像蝴蝶一样飘散在风中。\n"NOR,me);
	me->perform_busy(1);

	ANNIE_D->improve_ability(me,t);

	count=0;
	for (i=0; i<sizeof(inv); i++)
		if (inv[i]->query("teaching") == t && count < req-1 && inv[i] != this_object())
		{
			destruct(inv[i]);
			count++;
		}
	
	destruct(this_object());
	return 1;
}

/*
╔[ 　- FengYun -　 ]┄┄┄┄╗
┊[dancing_faery@hotmail.com]├──╗
┊[ 　annie 09.2003　 ]┄┄┄╝    │
┊[ 离离漫惹三秋露，脉脉时凝九月霜 │
╚————————————————-╝
*/
