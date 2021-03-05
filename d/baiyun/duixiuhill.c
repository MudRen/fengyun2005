//Sinny@fengyun 2003 
//All Rights Reserved 
inherit ROOM;
void create()
{
    set("short", "堆秀山");
    set("long", @LONG
倚墙而筑的石山恰似“堆秀”，山势险峻，磴道陡峭，甚为新颖。山石，采用了
不同的堆垒技巧，既有单树的奇石，又有成群的山峦，崖谷峻峭，洞壑幽邃，同周围
的建筑物相配合，给人以华美、精巧的印象。
LONG
    );
    set("exits",
      ([
	"northwest" : __DIR__"emaze1",
	"southup" : __DIR__"hillroad",
	// 	     "west"  : __DIR__"beach1",
	// 	     "east"  : __DIR__"beach2",
      ]));
    set("objects",
      ([ 
	__DIR__"obj/shanshi" : 1,
      ]));
    set("outdoors", "baiyun");
    set("coor/x",0);
    set("coor/y",-90);
    set("coor/z",10);
    setup();
    replace_program(ROOM);
}
