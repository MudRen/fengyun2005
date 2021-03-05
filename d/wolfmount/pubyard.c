#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", "客栈后院");

    set("long", @LONG
这里是太平客栈的后院。虽说是院子，但四下没有半点篱笆土墙，一条飘满落
花的山溪自一旁汩汩地流着，另一旁是蜿蜒小路，延伸至远方的狼山山巅，在云雾
缭绕中一切都变得如同梦幻般虚无缥缈。
LONG);

    set("type","street");
    set("exits",([
	"north":__DIR__"safepub",
	"southeast":__DIR__"fogpath2",
      ]) );
    set("outdoors", "wolfmount");
    set("objects",([
	__DIR__"npc/bigfoot":1,
      ]) ); 
    set("coor/x",0);
    set("coor/y",-10);
    set("coor/z",0);
    set("item_desc", ([
	"山溪": "一条蜿蜒曲折的山溪，溪水清澈见底似乎可以游（ｓｗｉｍ）过去。\n",
	"brook": "一条蜿蜒曲折的山溪，溪水清澈见底似乎可以游（ｓｗｉｍ）过去。\n",
      ]) );

    setup();
}

void init()
{		
    add_action("do_swim","swim");
}

int do_swim()
{
    object me;
    object room;
    me = this_player();
    if( me->query_skill("dodge") > 40 )
    {
	message_vision(HIY"$N一个猛子扎入山溪中。。。\n"NOR,me);
	tell_object(me, "冰凉的溪水，使你不由地打了个寒战。\n");
	room = find_object(__DIR__"river");
	if(!objectp(room)) room = load_object(__DIR__"river");
	me->move(room);
	me->start_busy(1);

	return 1;
    }
    else
    {
    tell_object(me, HIY"你颤抖的伸脚试了试冰冷的溪水，又连忙收了回来．．．\n（需要至少４１级有效闪躲之术）\n"NOR);
	return 1;
    }

}
