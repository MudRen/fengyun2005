#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "孟婆亭");
        set("long", @LONG
孟婆亭由孟婆主掌，其乃奉玉帝之命，负责投生前之醧忘工作，因人若不喝下
「醧忘汤」，则投生后犹记前生之事，如此一来，小孩追认前生亲属，造成长幼无
序、五伦不分或生而寻仇报怨，天下势将大乱，故造物妙化，以「醧忘汤」使投生
者饮下，忘记前生一切事。此汤有甘辛苦酸咸五味混合，故喝下后不知东西南北，
迷迷糊糊乱闯，而自堕落于六道轮回。
LONG
        );
        set("exits", ([
		"southwest" : __DIR__"pingan",
        ]) );
        set("no_meal","你忽然发现口中的食物饮水成了苦涩的浊泥，赶快哇哇地吐了出来。\n");
        set("objects", ([
                __DIR__"npc/mengpo" : 1,
        ]) );
	set("coor/x",40);
	set("coor/y",0);
	set("coor/z",-190);
	set("no_fight",1);
	setup();
        
}
 
