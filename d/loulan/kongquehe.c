#include <ansi.h>;
inherit ROOM;

void create()
{
        set("short", "孔雀河");
        set("long", @LONG
据传古楼兰的城池、寺院和村落便广布于孔雀河下游两岸。这里也原本是条急
湍的河流，千百年前也曾有如一条绿带般在草原上蜿蜒，但如今一切都已是过眼烟
云，昔日的长河现今不复存在，只有条也如同绸带一样的[37m沙流[32m在昔日的河道中慢慢
流淌，不知通向何方。。。
LONG
        );

        set("exits", ([ 
		"southeast" : AREA_QUICKSAND"yangguan",
	]));
        set("outdoors", "loulan");
        set("objects", ([
                __DIR__"npc/xiongmaoer" : 1,
        ]) );
	set("item_desc", ([
                "沙流":"
孔雀河中浸满了沙石，宛如黄金玉带般，在阳光下耀眼夺目，细细看去，沙流
似乎在缓缓流动，不知道能不能趟（WADE）过去。。 。\n",
		"sand":"
孔雀河中浸满了沙石，宛如黄金玉带般，在阳光下耀眼夺目，细细看去，沙流
似乎在缓缓流动，不知道能不能趟（WADE）过去。。 。\n",
                "sandstream": "
孔雀河中浸满了沙石，宛如黄金玉带般，在阳光下耀眼夺目，细细看去，沙流
似乎在缓缓流动，不知道能不能趟（WADE）过去。。 。\n",
	
        ]) );
		set("coor/x",0);
		set("coor/y",0);
		set("coor/z",100);
		setup();
}

 void init()
{
		add_action("do_wade","wade");
}

int do_wade(string arg)
{
		object room;
        object me;  
		me=this_player();
		
		if (me->is_busy())
			return notify_fail("你现在正忙。\n");
					
		if (!arg || arg == "sand" || arg = "sandstream" || arg = "沙流"
			|| arg = "沙")
		{
			if(!objectp(room = find_object(__DIR__"sandstream")))
			room = load_object(__DIR__"sandstream");
			message_vision("$N小心翼翼踩进沙河流......\n",this_player());
			me->start_busy(2);
			me->move(room);
			return 1;
		} 
}
