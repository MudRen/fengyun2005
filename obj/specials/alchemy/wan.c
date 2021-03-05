#include <ansi.h>
inherit ITEM;
void generate_name();
void create()
{
	generate_name();
	set_weight(1);
	set("unit", "粒");
    set("long", "一粒道家炼制的"+name()+"。\n");
	set("value", 0);
	set("no_get", 1);
	set("no_give", 1);
	::init_item();
}

void init(){
	add_action("do_use", "use");
}

int do_use(string arg){
	object me;
	
	string usage;
	me = this_player();
	if(!arg || (arg != "wan" && arg != "medicine")){
		return notify_fail("你要用什么？\n");;
	}
	usage =(string) query_temp("usage");
	if (usage == "石乳") me->set("water", me->max_water_capacity());
	if (usage == "大力") me->set("force",(int) me->query("max_force"));
	if (usage == "济食") me->set("food",me->max_food_capacity());
	if (usage == "回法") me->set("mana",(int) me->query("max_mana"));
	if (usage == "聚灵") me->set("atman",(int) me->query("max_atman"));
	if (usage == "极乐") me->apply_condition("hehe", 2 + random(8));
	if (usage == "驱毒") me->clear_condition();
	message_vision( HIY"$N取出一粒$n"HIY"吞入口中，一缕缕淡淡的黄光透出$N体外！！\n" NOR, me, this_object());
   
	destruct(this_object());
	return 1;
}

void generate_name(){
	string *color = ({HIC, HIG, HIW, HIY, HIR, MAG});
	string *number = ({"甲", "乙", "丙", "丁", "戊", "己", "庚","辛","壬","癸"});
	string *part = ({"金", "木", "水","火", "土"});
	string *race = ({"石乳", "大力","济食", "回法", "聚灵","驱毒","极乐"});
	string usage = (race[random(sizeof(race))]);
	set_name( (color[random(sizeof(color))])+(number[random(sizeof(number))]) 
		   + (part[random(sizeof(part))])
		   + usage
		   + "丸"NOR, ({ "wan" , "medicine"}) );
	
	set_temp("usage", usage);
}
