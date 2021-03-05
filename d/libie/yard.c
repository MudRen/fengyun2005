// Room: yard.c --- by MapMaker
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "小院");

	set("long", @LONG
这是一间萧索冷清的小院，一棵衰老的白杨树已经开始枯萎，一条黄狗蜷伏在
墙角，墙的一角有口水井。院中搁了两个破石凳，一个老者呆呆做在凳上喃喃地不
知在说些什么。院子西首就是杨铮租的小屋，破木门开着，风吹之下，嘎嘎作响。
LONG);

	set("exits",([
	"west":__DIR__"nongjia",
	"south":__DIR__"stoneroad",
	"north":__DIR__"neishi",
	]) );
        set("objects", ([
                __DIR__"npc/oldyu": 1,
        ]) );
        set("item_desc",([
        	"well":		"水井里黑咕隆咚地什么也看不清（approach?）\n",
        	"井":		"水井里黑咕隆咚地什么也看不清（approach?）\n",
        	"白杨树":	"白杨树高高的，看来你是没希望爬上去了。\n",
        	"tree":		"白杨树高高的，看来你是没希望爬上去了。\n",
        	]));	
        set("outdoors", "libie");
        set("yu_home",1);
	set("coor/x",-5);
	set("coor/y",10);
	set("coor/z",0);
	setup();

}


void init()
{
	add_action("do_approach", "approach");
}


int do_approach(string arg)
{
        object me;
        object room;
        me = this_player();
	if(!arg || arg != "井" && arg != "well" ) return 0;
	
	message_vision("$N走近水井探头向里望去。 \n", me); 
	tell_object(me,"水井深不见底，不过你似乎可以听到底下流水的声音。 \n");
	
	if (REWARD_D->riddle_check(me,"离别")<2)	return 1;
        
        room = find_object(__DIR__"well");
	if(!objectp(room)) room=load_object(__DIR__"well");
	
        if (room->usr_in())
        	return notify_fail("井里好像已经有人了，等他上来再说吧。\n");
        
        tell_object(me,"你想起离奇失踪的莲姑，想起苦苦等待的吕素文，一咬牙向井里钻去。\n\n\n");
        
        room->reset();
        room->set("corpse",1);
        me->move(room);
        return 1;
}