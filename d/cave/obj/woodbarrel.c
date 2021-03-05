
#include <ansi.h>
inherit ITEM;
void decay();

void create()
{
        set_name("大木桶", ({ "woodbarrel"}) );
        set_weight(300000);
         set("no_get", 1);
        set_max_encumbrance(800);
	set("unit", "个");
    set("long", "一个散发着血腥气、锈绩斑斑的大圆木桶，几根铜条紧紧箍着\n不知道是否可以把桶硬生生劈开（split）.\n");
	set("closed", 1);
	set("value", 200);
}

int is_container() {return 1;}

void init()
{
         add_action("do_split","split");
}

int do_split(string arg)
{
	object		me, ob, gold;
	int		kar;
	
        if( !arg || arg != "woodbarrel" )
                return notify_fail("你要劈开什么？\n");
	me = this_player();
	ob = this_object();
	if(!query("closed")){
        return notify_fail("大木桶已经被劈开了。\n");
	}
    message_vision("$N力运双臂，咔嚓一声劈开$n。。\n", me, ob);
	kar = me->query("kar");
	if(  random(kar) >15 ) { 
		ob->set("closed",0);
        	message_vision("$N终于把$n打开了。\n", me, ob);
        	seteuid(getuid());
        	gold = new("/obj/money/silver");
       		gold->set_amount(3+random(12));
        	gold->move(ob);
        	set("name", "劈开的大木桶");
        	set("long", "一个散发着血腥气、锈绩斑斑的大圆木桶，箍桶的铜条已经被劈开了。\n");
        	call_out("decay", 120);
	}
	else if (random(kar) >5) {
       		message_vision(RED"只听得一声巨响!!＂轰＂!!木桶炸成碎片。$N全身被笼罩在烟雾和火焰中。\n"NOR, me);
        	me->unconcious();
        	destruct(ob);	
        }
	
	else {
        	message_vision(RED "只听到＂嗤＂的水声，从$n喷出一线黑色的水箭，腥臭无比，激射在$N的脸上！\n"NOR, me, ob);
		me->apply_condition("no_shadow", 10);
        	message_vision(BLU "$N中了黑水的阴毒！\n"NOR, me);
	}
        return 1;
}

void decay() {
	message_vision("$N晃动了几下，碎成一堆朽木散落在地。\n", this_object());
	destruct(this_object());
}
		