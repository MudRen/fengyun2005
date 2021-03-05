// Silencer@fy4 workgroup

inherit ROOM;
#include <ansi.h>

int update_player(object me);

void create()
{
	set("short", HIG"灵池"NOR);
	set("long", @LONG
这是一潭碧如翠玉的清池，曰为灵池，池水不深，浅浅可行；据传昔日女娲补
天，散落了些许七彩灵石，坠入此潭，化为碧水，每一个初入风云的新人都要徒步
淌过这里，而得到一些得天独厚，独一无二的造化。（输入[37mｓｃｏｒｅ[32m命令，你会
看到你有[1;32m才智、力量、速度、体质、定力和运气[0;32m六大属性。在这里，可进一步分配
１０点到六个基本属性。命令为[37mｄｉｓｔｒｉｂｕｔｅ[32m，后跟你希望的属性，
[37m例：ｄｉｓｔｒｉｂｕｔｅ　ｃａｉｚｈｉ[32m（或才智）即增加一点才智。属性的说
明参阅[37mｈｅｌｐ　ｎｅｗｂｉｅ[32m中的参数介绍篇（选项６）。）
LONG
	);
	set("exits", ([
  		"down" :  __DIR__"newbie5",
	]));
	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",800);
	set("no_magic",1);
	set("no_fight",1);
	setup();
}



int init(){
	add_action("do_distribute", "distribute");
}


int valid_leave(object me, string dir) {

	if (dir == "down")
	if ( me->query("used_gift_points") != 10)
		return notify_fail("你必须把参数点分配完毕。
例：ｄｉｓｔｒｉｂｕｔｅ　ｃａｉｚｈｉ（或才智）\n");
	me->set_temp("first_time_login",1);
	return ::valid_leave(me, dir);
}

int do_distribute(string arg)
{
	int gift_points;
	int used_gift_points;
	object me;
	
	me = this_player();
	
	if( !arg ) 
		return notify_fail("你要分配到哪个参数上？
例：ｄｉｓｔｒｉｂｕｔｅ　ｃａｉｚｈｉ（或才智）\n");
	gift_points = me->query("gift_points");
	used_gift_points = me->query("used_gift_points");
	if( used_gift_points >= gift_points )
		return notify_fail("你没有参数点剩余了。\n");
	
	switch (arg) {
	case "才智" :
	case "caizhi" :
			if((int) me->query("int") >=15)
				return notify_fail("你的才智不可以用分配的方法再提高了。\n");
			me->add("used_gift_points",1);
			me->add("distribute/int",1);
			me->add("int",1);
			break;
        case "体质" :
        case "tizhi" :
                        if((int) me->query("con") >=15)
                        	return notify_fail("你的体质不可以用分配的方法再提高了。\n");
                        me->add("used_gift_points",1);
                        me->add("con",1);
                        me->add("distribute/con",1);
                        break;
        case "运气" :
        case "yunqi" :
                        if((int) me->query("kar") >=15)
                        return notify_fail("你的运气不可以用分配的方法再提高了。\n");
                        me->add("used_gift_points",1);
                        me->add("kar",1);
                        me->add("distribute/kar",1);
                        break;
        case "力量" :
        case "liliang" :
                        if((int) me->query("str") >=15)
                        return notify_fail("你的力量不可以用分配的方法再提高了。\n");
                        me->add("used_gift_points",1);
                        me->add("str",1);
                        me->add("distribute/str",1);
                        break;
        case "速度" :
        case "sudu" :
                        if((int) me->query("agi") >=15)
                        return notify_fail("你的速度不可以用分配的方法再提高了。\n");
                        me->add("used_gift_points",1);
                        me->add("agi",1);
                        me->add("distribute/agi",1);
                        break;
        case "定力" :
        case "dingli" :
                        if((int) me->query("cps") >=15)
                        return notify_fail("你的定力不可以用分配的方法再提高了。\n");
                        me->add("used_gift_points",1);
                        me->add("cps",1);
                        me->add("distribute/cps",1);
                        break;
        default :
			return notify_fail("没有这个参数。
例：ｄｉｓｔｒｉｂｕｔｅ　ｃａｉｚｈｉ（或才智）\n");

	}
	write("你的"+ arg + "提高了一点。\n");
	if ( used_gift_points < 9)
		write("你还有"+ chinese_number(gift_points - used_gift_points-1) + "点参数，请继续分配。\n");
	else 
		{
			update_player(me);
		}
	return 1;
}

int update_player(object me)
{
        object env, link_ob, obj;

        env = environment(me);

        // First, create the new body.
        link_ob = me->query_temp("link_ob");
        obj = LOGIN_D->make_body(link_ob);
        if (!obj) return 0;

        // Save the data and exec the player to his/her link object.
        me->save();
        exec(link_ob, me);
        destruct(me);

        // Restore new body and exec to it via enter_world in LOGIN_D
        obj->restore();
        LOGIN_D->enter_world(link_ob, obj, 1);

	obj->receive_fulling("sen",500);
	obj->receive_fulling("gin",500);	// Leave kee out to do a demo downstairs
        obj->set("startroom", AREA_FY"fqkhotel");
        write ("所有参数点分配完毕，人物创造完毕，欢迎进入风云世界。\n");
        obj->move(env);
        obj->set_temp("first_time_login",1);
        obj->set_temp("successful_login", 1);
        obj->write_prompt();

        return 1;
}