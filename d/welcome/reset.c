// Silencer@fy4 workgroup

// 属性重置，存盘

// 其他属性清零、技能清零，存盘

// 补回基本的技能、书籍



inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", HIW"属性分配房间"NOR);
	set("long", @LONG
LONG
	);
	set("exits", ([
	]));
	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",700);
	set("no_magic",1);
	set("no_fight",1);
	set("valid_startroom", 1);
	setup();
}

int init(){
	object me;
	string *att = ({"int","cps","agi","str","con","kar"});
	string *att_c = ({ "才智","定力","速度","力量","体质","运气" });
	int i;
	
	// 重新分配属性点
	me = this_player();
	if (me->query("id") != "tester")	return 1;
	
	tell_object(me,"==========================================\n");
	for (i=0;i<sizeof(att);i++){
		tell_object(me,"你曾经分配了"+ me->query("distribute/"+ att[i])+ "点"+ att_c[i]+"\n");		
	}
	
	tell_object(me,"\n现在开始重新分配属性点，原来的都已经置零。\n\n");
	tell_object(me,"命令为[37mｄｉｓｔｒｉｂｕｔｅ[32m，后跟你希望的属性，
[37m例：ｄｉｓｔｒｉｂｕｔｅ　ｃａｉｚｈｉ[32m（或才智）
即增加一点才智。\n");

	tell_object(me,"==========================================\n");
	
//	me->delete("distribute");
//	me->delete("used_gift_points");
	me->save();
	add_action("do_distribute","distribute");
		
}

int update_player(object me)
{
        object env, link_ob, obj;
        me->save();
        write ("所有参数点分配完毕，自动进入下一个房间。\n");
        obj->move(__DIR__"reset2");
        return 1;
}

int do_distribute(string arg)
{
	int gift_points;
	int used_gift_points;
	object me;
	
	me = this_player();
		
	me->set("update/fy51_attr_reset",1);
	
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
			if((int) me->query("distribute/int") >=5)
				return notify_fail("你的才智不可以用分配的方法再提高了。\n");
			me->add("used_gift_points",1);
			me->add("distribute/int",1);
			me->add("int",1);
			break;
        case "体质" :
        case "tizhi" :
                        if((int) me->query("distribute/con") >=5)
                        	return notify_fail("你的体质不可以用分配的方法再提高了。\n");
                        me->add("used_gift_points",1);
                        me->add("con",1);
                        me->add("distribute/con",1);
                        break;
        case "运气" :
        case "yunqi" :
                        if((int) me->query("distribute/kar") >=5)
                        return notify_fail("你的运气不可以用分配的方法再提高了。\n");
                        me->add("used_gift_points",1);
                        me->add("kar",1);
                        me->add("distribute/kar",1);
                        break;
        case "力量" :
        case "liliang" :
                        if((int) me->query("distribute/str") >=5)
                        return notify_fail("你的力量不可以用分配的方法再提高了。\n");
                        me->add("used_gift_points",1);
                        me->add("str",1);
                        me->add("distribute/str",1);
                        break;
        case "速度" :
        case "sudu" :
                        if((int) me->query("distribute/agi") >=15)
                        return notify_fail("你的速度不可以用分配的方法再提高了。\n");
                        me->add("used_gift_points",1);
                        me->add("agi",1);
                        me->add("distribute/agi",1);
                        break;
        case "定力" :
        case "dingli" :
                        if((int) me->query("distribute/cps") >=15)
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




	
	
	


