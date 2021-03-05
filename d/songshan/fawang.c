// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
#include "/questnpc/lovestory1/event_place.h"
void create()
{
        set("short", "法王寺");
        set("long", @LONG
法王寺是最早的佛教寺院之一，相传是汉明帝为东来的高僧竺法兰译经而在我
国建造的第二座佛寺，只比洛阳白马寺晚三年。大雄殿前的千年银杏绿叶如荫，树
冠若盖。寺东双峰插天，中豁如门，构成了登封八景之“嵩门待月”奇景。
LONG
        );
        set("exits", ([ 
  "south" : __DIR__"shita", 
]));
        set("outdoors", "songshan");
        set("objects", ([
                __DIR__"obj/tree" : 1,
       ]) );
	set("coor/x",20);
	set("coor/y",40);
	set("coor/z",0);
	setup();

}

int valid_enter(object me)
{

	if(me->query("lovestory1"))
		add_trigger_count(me);
	return 1;
}
