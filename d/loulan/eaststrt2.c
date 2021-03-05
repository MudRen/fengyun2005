#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "东天街");
        set("long", @LONG
一条灯火通明的长廊，似乎原先本是繁华的街道，两旁是一些寺院民宅，后来
快活王占据这古楼兰的地下王国后，便将大大小小的民宅修葺改建，以供手下酒色
财气四使、急风三十六骑以及众多嫔妃佳人和一干下人居住。
LONG
        );
        set("exits", ([ 
		"west" : __DIR__"eaststrt",
		"north" : __DIR__"baihuagong",
		"east" : __DIR__"eaststrt3",
		"south": __DIR__"bedroom",
	]));
        set("objects", ([
               __DIR__"npc/guard2" : 1,
	]) );
        set("indoors", "loulan");

	set("coor/x",20);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}

int valid_leave(object me, string dir)
{
    	object ob;
    	object *inv;
    	int i;
    	int j;
    	int k;
    	j=0;
    	k=0;
    	if ( !userp(me) || dir=="west" || dir=="east" || dir == "south")
    		return 1;
    	
//	if( userp(me) && !me->query_temp("marks/jade_to_zhu"))
//		return notify_fail(YEL"“新娘正在上装，非礼勿视”，几个喜娘推推搡搡的把你赶了出来。。。。\n"NOR);
		
    	inv=all_inventory(this_object());
    	for (i=0;i<sizeof(inv);i++)	{
    		if (inv[i]->query("id")=="sun chiqi") j=1;
    	}		
    	if (j==0) return 1;

    	inv=all_inventory(me);
    	for(i=0; i<sizeof(inv); i++)		{
		if(inv[i]->query("item_owner")=="方心骑" && (int)inv[i]->query("equipped"))
			k = 1;
	}
	if (k==0) return notify_fail("孙驰骑伸手拦住你的去路。\n");

	return 1;
}
