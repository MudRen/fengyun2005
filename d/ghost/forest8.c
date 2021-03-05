
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "原始丛林");
	set("long", @LONG
无边无际的丛林中一片黑暗，就是再烈的日光也穿不透那密密的树叶，黑暗中
充满了各式各样的危险，每一种都可以致命。若是在丛林中迷失了方向，饥渴就足
以致命。如果没人指引的话，生还的可能性是微乎其微的。
LONG
	);
	set("exits", ([
		"north" : __DIR__"forest7",
		"south" : __DIR__"forest1",
		"east" : __DIR__"forest5",
		"west" : __DIR__"forest6",
	]));
	set("objects", ([
		__DIR__"npc/ye": 1,
		__DIR__"obj/tree": 1,
//		__DIR__"npc/gudumei2": 1,
	]));
	set("outdoors", "ghost");
	set("no_lu_letter",1);
	set("coor/x",-80);
	set("coor/y",30);
	set("coor/z",10);
	setup();
}

void reset()
{
        object          *inv;
        object          con, item;
        object		room, fen;
        int             i;

        ::reset();
		set("exits", ([
			"north" : __DIR__"forest7",
			"south" : __DIR__"forest1",
			"east" : __DIR__"forest5",
			"west" : __DIR__"forest6",
		]));	
        room = this_object();
        if(objectp(fen = present("fen yan zi", room)))
        	destruct(fen);
        con = present("big tree", this_object());
        inv = all_inventory(con);
        if( sizeof(inv) != 1) {
                for(i=sizeof(inv)-1; i>=0; i--) destruct(inv[i]);
                item = new(__DIR__"npc/fen");
                item->move(con);
	}
}

void init(){
	add_action("do_go","go");
}

int do_go(string dir)
{
        object env, ye, gudu;
		int brief, brief2, brief3;
		object me= this_player();
		
		env = this_object();
		ye = present("ye gu hong", env);
		gudu = present("gu du mei", env);
	
		if(objectp(gudu)) {
			if(objectp(ye) && !(me->query_temp("marks/okleave"))){ 
				tell_object(me, HIY "\n叶孤鸿冷冷的说道：这位朋友留下孤独美再走。\n"NOR);
				return 1;
			}
			me->delete_temp("marks/okleave");
			me->move(__DIR__"forest9");
			tell_object(me, YEL"\n孤独美说：好，到了。\n"NOR);
			message_vision(YEL "孤独美说道：我还有点事，咱们后会有期。\n\n"NOR, me);
			if (QUESTS_D->verify_quest(me,"帮助孤独美"))
				QUESTS_D->special_reward(me,"帮助孤独美");
			return 1;
		}
		return 0;

}

