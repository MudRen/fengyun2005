//Sinny@fengyun 2003
//All Rights Reserved ^_^

inherit ROOM;
void create()
{
    set("short", "挂剑碑");
    set("long", @LONG
路行至此，可俯视岛下碧海黄沙，也可远眺岛上白云孤城，而白云朵朵似乎就在
身边，可谓得白云岛天地之菁华所在，叶孤城立碑于此，尽抒其志：

                           君
                           临
                           天
                           下

LONG
    );
    set("exits", 
      ([ 
	"northdown" : __DIR__"jianlin",
	"southwest" : __DIR__"hillroad",
      ]));
    set("objects", 
      ([ 
	__DIR__"npc/guard2" : 1,
	__DIR__"npc/guard3" : 1,
      ]));
    set("outdoors", "baiyun");
    set("coor/x",15);
    set("coor/y",-80);
    set("coor/z",20);
    setup();
}


int valid_leave(object me, string dir)
{
    object *inv, ob;
    int i;

    if( userp(me) && me->query("class")!="baiyun") {
	if( dir == "northdown"  && ob=present("swords man", this_object())) {
	    inv = all_inventory(me);
	    for(i=0; i<sizeof(inv); i++) {
		if((int)(inv[i]->query("weapon_prop")) && (int)(inv[i]->query("equipped")))
		    return notify_fail(ob->name()+"拱了拱手道：请取下佩剑。\n");
	    }
	}
    }

    return 1;
}
