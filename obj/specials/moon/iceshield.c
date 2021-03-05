// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIW"冰魄晶壁"NOR, ({"wall of ice","ice shield","wall","shield" }));
    set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
            set("unit", "面");
			set("long", "一圈晶莹剔透的冰晶雾气，密密的笼在你身边。\n");
            set("value", 0);
			set("no_get", 1);
			set("no_give", 1);
			set("no_drop", 1);
			set("no_sell", 1);
			set("no_burn", 1);
			set("no_stack",1);
			set("p_amount",10);
        }
	::init_item();
}

void protect(object me,int level)
{
	int skill;
	object *pros;
	skill = me->query_skill("snowforce",1);

	if (level >= 2)
		set("p_amount",20);
	if (level >= 3)	
		set("p_amount",30);
	
	pros = me->query_temp("protectors");
	if(sizeof(pros))
		pros += ({ this_object() });
	else
		pros = ({ this_object() });
	me->set_temp("protectors",pros);
	set("owner",me);
	skill = 60;
	call_out("dest",skill);
}

void dest()
{
	object me;
	me = query("owner");
	if (me)
		message_vision(HIW"$N身边冰壁逐渐溶解，化为一片水雾。\n"NOR,me);
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
	int result;
	
	result = random(100) > query("p_amount") ? 0 : 1;
	set("protected", result);
	return result;
}

string protection_msg()
{
	return query("protected") ? WHT"$n"WHT"微挪半尺，$N"WHT"力道尽数落在$n"WHT"身侧冰壁之上。\n"NOR : "";
}


void init()
{
	if (query("owner"))
		if (query("owner") != this_player())
			dest();
}

/*
HIW"$N垂手合目，身边白雾缭绕，云气升腾，再睁眼时，已是神光湛然。\n"NOR,
*/