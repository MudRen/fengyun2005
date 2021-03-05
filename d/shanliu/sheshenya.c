// Room: sheshenya.c --- by MapMaker

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "舍身崖");

	set("long", @LONG
这是一段极窄极险的山崖，传说自古以来都是得道高僧化羽西去之所，四周白
云悠悠，云雾缭绕，下面渊深无底。如不小心，一失足掉下去，只怕连尸骨都找不
到。你不禁望而却步，心惊胆战，还是往回走吧，前面似乎也没什么路好走了。崖
顶有一个青衣文士迎风而立，衣襟飘飘，似乎要踏空而去。
LONG);
	//{{ --- by MapMaker
	set("outdoors","shanliu");
	set("exits",([
	"south":__DIR__"fodian",
	]) );
	//}}
	set("objects", ([
	__DIR__"npc/liu" :1,
	]) );
	set("coor/x",-5);
	set("coor/y",70);
	set("coor/z",70);
	setup();

}

void init()
{
	add_action("do_jump","jump");
}

int do_jump(string arg)
{
	object liu,me;
	
	me=this_player();
	if(!arg||arg!="down")
		return 0;
	if(liu=present("liu fenggu",this_object()))
	{
		if(!living(liu))
			return 0;
		if(!me->query_temp("山流/jump"))
		{
			message_vision(
HIY"$N对$n微微笑道：“兄台有什么想不开的呢？这大好花花世界，
还是别乱来的好。”\n"NOR,liu,me);
		me->add_temp("山流/jump",1);
		}
		else
			message_vision("$N微微一笑，伸手拦住$n的去路。\n",liu,me);
		return 1;
	}
	if(me->query_cor()<20)
		message_vision(
BLU"山风凛冽，白云悠悠，$N望了望崖下的万丈深渊，心惊胆颤，不禁望
而却步，瘫倒在地。\n",me);
	else
	{
		message_vision(HIW"$N咬了咬牙，两眼一闭，纵身跳了下去。\n"NOR,me);
		tell_object(me,HIR"你只觉耳边风声呼啸，心里一慌，昏了过去，什么都不知道了。\n"NOR);
		me->unconcious();
		if(me->query_temp("山流/舍身崖"))
		{
			me->move(__DIR__"mishi");
			me->unconcious();
		}
		else
			me->die();

	}
	return 1;
}
			
		
				