#include <ansi.h>
#include <armor.h>
inherit NECK;

void create()
{
	set_name(HIW"天都水月"NOR, ({"moon stone" }));
    set_weight(200);
	if( clonep() )
			set_default_object(__FILE__);
	else {
		set("unit", "枚");
		set("long", "一枚极其稀有罕见的水柔玉，触手冰凉。\n");
		set("value", 0);
		set("no_get", 1);
		set("no_give", 1);
		set("no_drop", 1);
		set("no_sell", 1);
		set("no_burn", 1);
		set("no_stack",1); 
	}
	::init_neck();
}

void protect(object me)
{
	int skill;
	object *pros;
	pros = me->query_temp("protectors");
	if(sizeof(pros))
		pros += ({ this_object() });
	else
		pros = ({ this_object() });
	me->set_temp("protectors",pros);
	set("owner",me);
}

void dest()
{
	object me;
	destruct(this_object());
}

void rmp(object me)
{
	object *pros;

	if (!me) return;
	pros = me->query_temp("protectors");
	pros -= ({ this_object() });
	me->set_temp("protectors",pros);
	return;	
}

void remove_all_killer()	// 因为destruct函式中呼叫了这个func，而item没有原定义，因此可以利用来解除protect防止错误。
{
	rmp(query("owner"));
//	::remove_all_killer();
	return;
}

int protection() {
	set("protected", 1);
	return 1;
}

string protection_msg()
{
	return WHT"$N的招式甫近$n，就为天都水月上散出的一层微光所阻。\n"NOR;
}


void init()
{
	protect(this_player());
	if (query("owner"))
		if (query("owner") != this_player())
			dest();
}

/*
╔[ 　- FengYun -　 ]┄┄┄┄╗
┊[dancing_faery@hotmail.com]├──╗
┊[ 　annie 09.2003　 ]┄┄┄╝    │
┊[ 离离漫惹三秋露，脉脉时凝九月霜 │
╚————————————————-╝
*/
