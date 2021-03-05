#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "地窖");
	set("long", @LONG
地窖里寒冷而潮湿，泥土的墙壁上挂着一盏油灯。昏暗的灯光下，这里更显得
阴森可怖。地窖中有一把椅子，椅子上端端正正的坐着一个人。
LONG
	);
	set("exits", ([
                "down" : __DIR__"dijiao2",
	]));
	set("objects", ([
                __DIR__"npc/biaoge" : 1,
	]));
	set("item_desc", ([
	        "椅子" : "一张木椅，左面的把手(handle)有些松动，似乎可以转一下（Turn）。\n",
	        "chair" : "一张木椅，左面的把手(handle)有些松动，似乎可以转一下（Turn）。\n",
    	]));
	set("coor/x",-20);
	set("coor/y",-30);
	set("coor/z",0);
	setup();
	
}

void init(){
        add_action("do_turn", "turn");
}

int do_turn(string arg){
        object me/*, guard*/, nroom;    
        me = this_player();
        if(!arg || (arg != "handle" && arg != "把手")) {
                tell_object(me,"你要转什么？\n");
        	return 1;
        }
        message_vision(HIY "$N在椅子上按了一下，脚下忽然裂开了一个大洞，\n$N大叫了一声，掉了下去。\n"NOR, this_player());
	nroom = find_object(AREA_WUDANG"house3");
	if(!objectp(nroom)) nroom=load_object(AREA_GHOST"house3");
	me->move(nroom);
	message_vision(HIY "\n$N从神龛里滚了出来。\n"NOR, me);
        return 1;
}