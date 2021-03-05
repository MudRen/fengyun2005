#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "华山密洞");
        set("long", @LONG
这是一个在天然洞穴基础上而建造的密洞，洞不算很大却很高，这里的空气也
不沉闷，可见另有通气的地方。洞内的石壁上挂着几盏水晶灯把洞内照耀得如同白
昼，紧靠石壁放着几个彩色锦垫。一面的洞壁似乎可以打开。
LONG
        );
    set("exits", ([ 
//  		"northdown" : __DIR__"shaluo",
	]));
	set("item_desc", ([
		"洞壁" : "洞壁似乎可以打开。（ｓｌｉｄｅ　ｒｏｃｋ）\n",
	]));
	set("valid_startroom", 1);
	set("objects", ([
		__DIR__"npc/zhenzhen" : 1,
	]));
	set("listen", 0);
    set("indoors", "huashan");
	set("coor/x",-11);
	set("coor/y",-56);
	set("coor/z",-116);
	setup();
}

void init(){
	object me;
	
	me = this_player();
	if(!me->query("marks/华山密洞")) {
		tell_object(me, "听华真真道：“这是华山密洞，是本派前辈设计开凿的。\n");
		tell_object(me, "下次可以推开山壁（ｓｌｉｄｅ　ｒｏｃｋ），就能进来了。”\n" );
		me->set("marks/华山密洞", 1);
	}
	add_action("do_slide", "slide");
}

int do_slide(string arg){
	object me, room;
	
	me = this_player();

	if(!arg || arg != "rock") {
		return notify_fail("你要推开什么？\n");
	}
	if(me->is_busy() || me->is_fighting()) {
		return notify_fail("你正在忙。\n");
	}
	message_vision("$N伸手在石壁上推了一下，闪身转了出去。\n", me);
	room = find_object(__DIR__"yunv");
	if(!objectp(room)) {
		room = load_object(__DIR__"yunv");
	}
	me->move(room);
	message("vision", "石壁旁不知何时忽然多了一个人影。\n",  
			environment(me), me);
	return 1;	
}
