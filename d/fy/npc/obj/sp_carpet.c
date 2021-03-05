// magic carpet,annie 7.03.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ITEM;
void create()
{
    set_name("飞毯" NOR, ({ "carpet" }) );
    set_weight(800);
			if( clonep() )
            set_default_object(__FILE__);
    else {

            set("unit", "块");
            set("material", "cloth");
            set("long", "一块神奇的西域飞毯，据说能带人遨游天地。\n");
			set("value",1000);
			set("closed", 1);
			set("desc_ext","飞行(fly)");
		  }
    ::init_item();
}

void init()
{
	if(environment()==this_player())
		add_action("do_fly","fly");
}


string view(string room) {
	int i;
	object *inv,env;
	mapping exits;
	string roomdesc, str, *dirs;
	
	env = load_object(room);

	str = HIR BLK"\n你小心翼翼的从飞毯边缘探出头向下望去。\n\n"NOR;
	
	// room descriptions.
	str += sprintf( "%s \n%s",
			env->query("long"),

	// exits.
			env->query("outdoors")? NATURE_D->outdoor_room_description() : "" );

	// all things in the room.
	inv = all_inventory(env);
	for(i=0; i<sizeof(inv); i++) {
		if( inv[i]->query("no_shown") ) {
			continue;
		}
		str += "  " + inv[i]->short() + "\n";
	}
	return str;
}



int do_fly()
{
	object me,room,env;
	me = this_player();
	room = environment(me);
	if (room->query("is_carpet"))
	{
		tell_object(me,"你已经坐在飞毯上遨游．．．\n");
		return 1;
	}
	if (me->is_fighting() || me->is_busy())
	{
		tell_object(me,"你现在没有空坐上飞毯。\n");
		return 1;
	}
	if (me->query("mana") < 100)
	{
		tell_object(me,"你的法力不足以驾驽飞毯。\n");
		return 1;
	}
	me->add("mana",-100);	// prevent flood.
	if (!room->query("outdoors"))
	{
		message_vision(CYN"$N坐上了飞毯，喝道：起！\n飞毯带着$N向上升了三寸，就啪嗒一声落到地上。\n"NOR,me);
		return 1;
	}
	if (room->query("no_fight") || room->query("no_magic") || room->query("no_spells"))
	{
		message_vision(CYN"$N坐上了飞毯，喝道：起！\n可是飞毯在$N身下一动不动。\n"NOR,me);
		return 1;
	}
	env = new(__DIR__"sp_carpet2");
	message_vision(CYN"$N将一张飞毯铺到地面，盘腿坐了上去，喝道：起！\n\n飞毯带着$N缓缓升起，消失在云雾之中．．．\n\n"NOR,me);
	me->move(env);
	call_out("do_release",1,me,room,env,0);
	return 1;
}

void do_release(object me,object room,object env,int count)
{
        string *msg = ({
CYN"\n飞毯越爬越高，你心下有些兴奋，又有些惊慌。\n\n"NOR,
WHT"\n层层的云雾漫过你身旁，打湿了你的衣衫，你觉得有些发冷。\n\n"NOR,
CYN"\n飞毯一个盘旋，从云层中穿了出去。\n\n"NOR,
"view/d/fy/fysquare",
WHT"\n飞毯微微一晃，又钻进云中。\n\n"NOR,
CYN"\n你听到东方有说话的声音：“玉清道兄，最近世间大乱，那些催命也似的符都忙得我失眠了。”\n\n"NOR,
WHT"\n飞毯震了一震，离开了密密的云层。\n\n"NOR,
"view/d/zhaoze/center",
CYN"\n飞毯转了一个方向，迅速的向海外掠去。\n\n"NOR,
"view/d/baiyun/jietiandian",
WHT"\n海面上风速骤急，吹得飞毯飘向另外一方。\n\n"NOR,
"view/d/changchun/moonding",
CYN"\n离开你认得的常春海岸，飞毯又转向北方。\n\n"NOR,
"view/d/shenshui/ocean1",
CYN"\n海风凛冽，飞毯带着你向陆地荡去。\n\n"NOR,
"view/d/laowu/street3",
WHT"\n一道疾风掠过你身旁，你转头后望，只见一个白发飘飘的仙人踏着一把宝剑在云中穿梭远去。\n\n"NOR,
"view/d/zangbei/nianqing",
"view/d/biancheng/cemetery0",
CYN"\n风乍然急了起来，飞毯在扰动的气流中左右摇晃。\n\n"NOR,
"view/d/quicksand/greenland",
"view/d/huashan/shanlu1",
CYN"\n不远处几只仙鹤缓缓飞过，鹤背上似乎还有几个人影。\n\n"NOR,
"view/d/shanliu/sheshenya",
HIY"\n一道金光冲天而起，自你身边擦过，似乎是萧萧剑芒。\n你听到有极小的声音从地面传来：“他奶奶的，又打偏了。”\n\n"NOR,	// * snicker
"view/d/huangshan/pond",
"view/d/taoyuan/riverbanke",
WHT"\n飞毯在天空中转了大半个圈，开始望来路飞去。\n\n"NOR,
});

	if (!me || !env)
		return;
	if (!room)	// 房间丢失?...应该不会,但是防止意外出错,做一下检测. ; annie.
	{
		room = load_object("/d/fy/fysquare");
		tell_object(me,CYN"\n飞毯突然失去了平衡，在风中翻卷着下坠。\n\n啊啊啊啊啊啊～～～～～～～～\n\n"NOR);
		me->move(room);
		message_vision(CYN"\n一个映在地上的黑影越来越大，终于啪嗒一声掉在干涸的水池里。\n$N灰头土脸的从水池中爬了出来。\n\n"NOR,me);
		destruct(env);	// destruct used carpet
		return;
	}
	if (count < sizeof(msg))
	{
		if (msg[count][0..3]=="view") // view room.. 
			message_vision(view(msg[count][4..sizeof(msg[count])-1]),me);
		else
			message_vision(msg[count],me);
		count ++;
		call_out("do_release",1,me,room,env,count);
	}
	else
	{
		tell_object(me,CYN"\n飞毯载着你在空中绕了一圈，开始缓缓下降。\n\n"NOR);
		me->move(room);
		message_vision(CYN"\n一块飞毯载着$N慢慢的落到了地面上。\n\n"NOR,me);
		destruct(env);	
		return;
	}
}








