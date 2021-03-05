// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", "劫余岭");
    set("long", @LONG
再向前去，只见山脊渐渐收窄，最后凝成一条只有半尺来宽的巍巍险道
。如果贸然踏上险道，莫说转身，就是连双足并立也是有所不能。探头向窄
脊两侧望去，只见万仞危崖下云雾迷蒙，若是失足坠下，再回头已是百年之
身。
LONG
    );
    set("objects", ([
	//		__DIR__"npc/ghost" : 1,
      ]));
    set("exits",([
	"east" : __DIR__"wuzhang",
	"west" : "/d/bashan/enterance",
	"southup" : "/d/bashan/hf",
      ]) );
    
    set("outdoors", "xiangsi");
    
    set("objects", ([
	__DIR__"npc/ghost" : 1,
      ]));
    
    set("coor/x",-10);
    set("coor/y",0);
    
    set("boss_room",24);
    
    set("boss",__DIR__"npc/ghostmaster");
    set("ph",__DIR__"npc/ghost");
    
    set("coor/z",0);
    setup();
}


int ph_here()
{
    object env,*inv;
    int i;
    env = this_object();
    inv = all_inventory(env);
    for (i=0;i<sizeof(inv) ; i++)
	if (inv[i]->query("real_boss") || inv[i]->query("real_ph"))	// 依然存活。
	    return 1;
    
    return 0;
}

void reset()
{
    object npc;
    
    if (!ph_here())
    {
	if (!random(query("boss_room")))	
	{
	    npc = new(query("boss"));
	    npc->move(this_object());
	}
	else
	{
	    npc = new(query("ph"));
	    npc->move(this_object());
	}
    }
    ::reset();
}

