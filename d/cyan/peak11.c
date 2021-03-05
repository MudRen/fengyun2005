// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ROOM;
string look_stone();

void create()
{
	set("short", "映景明湖");
    set("long", @LONG
进山这许多天来，第一次看见湖水的欣喜刹时间满溢心头。近到湖边捧起
一口清甜甘冽的水，你简直不忍心将之饮入腹中。一恍神间，只见掌心盈盈的
水突地起了波动，你讶异地望向湖心，只见湖水波光变幻，倒映着的俨然是风
云城内光景。
LONG
NOR
        );
	set("objects", ([
	]));
	set("item_desc", ([
	"湖水":"你可以借助映景明湖的魔力来观看你想要知道的事情(scry)。\n",
	"湖":"你可以借助映景明湖的魔力来观看你想要知道的事情(scry)。\n"

	]) );
	set("exits",([
  		"northdown" : __DIR__"peak7",
  		"westdown" : __DIR__"peakx",
	]) );

	set("outdoors", "cyan");

	set("coor/x",-20);
	set("coor/y",40);
	set("coor/z",80);
	setup();
}

void init() {
	add_action("do_scry","scry");
	add_action("do_whisper","whistle");
}


int do_whisper()
{
	object me = this_player();
	object yr;
	if (REWARD_D->riddle_check(me,"探流追源") != 1 && REWARD_D->riddle_check(me,"探流追源") != 7 )
		return 0;
	if (present("shanliu yinluren",this_object()))
		return 0;
	message_vision("$N轻轻地吹了声口哨．．．\n",me);
	yr=new(__DIR__"npc/shanliu1");
	yr->move(this_object());

	if (REWARD_D->riddle_check(me,"探流追源") != 7 )
		yr->hi(me);
	else
		yr->hi2(me);
	return 1;
}


// inventory messages.
string inventory_look(object obj, int flag) {
    string str, desc;
    object me, left, right;

    str = obj->short();
    if(obj->query("equipped")) {
        if(!desc = obj->query("armor_worn")) {
            if(!desc=obj->query("weapon_wielded")) {
                desc = "√";
            } else {
                me = environment(obj);
                left = me->query_temp("left_hand");
                right = me->query_temp("right_hand");
                if(obj == left && obj == right) {
                    desc = "双手" + desc + "着";
                } else if(obj == right) {
                    desc = "右手" + desc + "着";
                } else {
                    desc = "左手" + desc + "着";
                }
            }
        }
        str = desc + str;
    } else if(!flag) {
        str = (environment(obj)->is_character() && !environment(obj)->is_corpse() ? 
                "怀藏" : "  ") + str;
    } else {
        return 0;
    }
    
    return str;
}

int do_scry(string arg)
{
	object me = this_player();
	object obj;

    string str, limb_status, pro;
    mixed *inv;
    mapping my_fam, fam;

	if (!arg)
		return notify_fail("你想寻找什么？\n");

	if (me->query_temp("timer/big_cmd")+2 > time())
		return notify_fail("映景明湖中的水波还没有彻底平静，再等一等吧。\n");
	else
		me->set_temp("timer/big_cmd",time());

	me->add("sen",-30);

	obj = find_living(arg);
	if (!obj)
		return notify_fail("映景明湖水波荡漾变幻，又慢慢归于平静。\n");
	if (!environment(obj))
		return notify_fail("映景明湖水波荡漾变幻，又慢慢归于平静。\n");
	if (userp(obj))
		return notify_fail("映景明湖水波荡漾变幻，又慢慢归于平静。\n");
	 if (obj->query("race")=="元素")
		return notify_fail("映景明湖水波荡漾变幻，又慢慢归于平静。\n");


	message_vision("映景明湖水波荡漾变幻，又慢慢归于平静。\n",me);
	message_vision("湖中倒映出了"+obj->name()+"的身影。\n",me);

	str = obj->long();
    pro = (obj==me) ? gender_self(obj->query("gender")) : gender_pronoun(obj->query("gender"));

    if((string)obj->query("race")=="人类" && intp(obj->query("age")))
    {
        if(userp(obj))
		{
            str +=  sprintf("%s看起来象%s多岁的%s人。\n", pro, 
                    chinese_number(obj->query("age") / 10 * 10), obj->query("national"));
		    } else 
			{
            str += sprintf("%s看起来约%s多岁。\n", pro, 
                    chinese_number(obj->query("age") / 10 * 10));
			  }
    }

    // current kee status.
    if(obj->query("max_kee")) {
        str += pro + COMBAT_D->eff_status_msg((int)obj->query("eff_kee") * 100 
                / (int)obj->query("max_kee")) + "\n";
    }
    
    // inventory message.
    if(obj->query("race") == "人类") {
        str += pro + (obj->is_naked() ? "赤身裸体。\n" : "");
    }
    inv = all_inventory(obj);
    if(sizeof(inv)) {
        inv = map_array(inv, "inventory_look", this_object(), (obj == me || obj->is_corpse()) ? 0 : 1 );
        inv -= ({ 0 });
        if(sizeof(inv)) {
            str += sprintf("%s\n", implode(inv, "\n  "));
        }
    }
    // tatoo print
    if (obj->query_temp("body_print") ) str += obj->query_temp("body_print")+ "\n";

    
    // send out message
    message("vision", str + "\n", me);
	return 1;
}

/*

　　　　　　　╔╕
　　　　　　　║╰╮
　　　　　　　║│╰╮
　　　　　　　║││╰╮
　　　　　　　║││││
　　　　　　　╚╧╧╧╛

　　　　　　　- FengYun - 　　　
　　　　　　annie 08.2003
　　　dancing_faery@hotmail.com
*/


