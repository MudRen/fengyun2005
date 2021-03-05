// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "不老寒泉");
        set("long", @LONG
这是一口沿染着青碧苍苔的水井，井口水雾迷蒙，隐约透着缕缕寒气。
井缘上的轱辘看起来已经很老了，老到了绳索的磨痕已经深深的印进了轴中
，却依然履行着自己的职责，将山流中的清泉供给给整个天宫。传说这井本
是天女的取水之处，喝了井中的水就能永保容颜。没有人知道传说是真是假
，只是皓月中人终日倚之为生，岁岁年年。(ｄｉｐ 兵器)
LONG
        );
	set("objects", ([
		__DIR__"npc/girl" : 2,
	]));
	set("exits",([
  		"west" : __DIR__"nanzoulang",
  		"east" : __DIR__"gelou",
  		"north" : __DIR__"zoulang",
	]) );

	set("outdoors", "xiangsi");
	set("coor/x",10);
	set("coor/y",-30);
	set("coor/z",20);
	setup();
}

void init()
{
	add_action("do_fill", "fill");
	add_action("do_dip","dip");

}


int do_dip(string arg){
	
	object weapon, me;
	
	me = this_player();
	
	if (me->is_busy())
		return notify_fail("你现在正忙。\n");
		
	weapon = me->query_temp("weapon");
	
	if (objectp(weapon))
	{
		if (weapon->query("owner")) {
			message_vision(WHT"$N把"+ weapon->name()+NOR WHT"浸入泉中，只觉一股寒气传了上来，拿捏不住，
			
"+weapon->name()+NOR WHT"似有灵性般激射入水，

倾许，一毕光芒万丈的白练祭起，刀刃清清如秋水，瑞气蒸腾，飞回$N手中。	\n"NOR,me);
			weapon->set("ice_blade",1);
			weapon->save();
		} else
			message_vision(WHT"$N蹲下身子把"+weapon->name()+NOR WHT"浸入井水之中，透心的寒意啊！\n"NOR,me);
	} else
		tell_object(me,WHT"你蹲下身子把手浸入井水之中，透心的寒意啊！\n"NOR);
	
	me->perform_busy(1);	
	return 1;
}

int do_fill(string arg)
{
    string name, type, container;
	object me,skin,dew;
    int drunk_apply;
    function f;
    
	me = this_player();
	if (!arg)
		return 0;
	skin = present(arg,me);
	if (!skin)	return 0;
    if( me->is_busy() )
	{
		write("你上一个动作还没有完成。\n");
		return 1;
	}

	if (!skin->query("liquid/name"))
	{
		write("你没有装水的东西啊。\n");
		return 1;
	}

    if( skin->query("liquid/remaining") )
        message_vision("$N将" + skin->name() + "里剩下的" + 
                       skin->query("liquid/name") + "倒掉。\n", this_player());

    type="water";
    name="不老寒泉";
    container="井";
    drunk_apply = 6;

    message_vision("$N从"+container+"中将" + skin->name() + "装满"+name+"。\n",me);

    if( me->is_fighting() ) me->start_busy(2);
    skin->set("liquid/type", type);
    skin->set("liquid/name", name);
    skin->set("liquid/remaining", skin->query("max_liquid"));

	f = (: call_other, __FILE__, "drink_drug" :);    
    
    if(drunk_apply) skin->set("liquid/drunk_apply",drunk_apply);
 	skin ->set("liquid/drink_func", bind(f, skin));  
    return 1;
}


int drink_drug(object ob)
{
    object me = this_player();
    int amount;
    
    if (me->query("class") == "moon") {
		tell_object(me,HIG"沁骨的冰凉流入喉咙，你只觉浑身上下犹如脱胎换骨，处处舒畅。\n"NOR); 	
		amount = me->query_skill("snowforce",1)* (100 + me->query_skill("prescription",1)/4)/100;
		amount = COMBAT_D->magic_modifier(me, me, "kee", amount);		
		me->receive_curing("kee",amount);
		me->add("water",-1);
	}
    return 0;
}

