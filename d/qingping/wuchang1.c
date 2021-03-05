inherit ROOM;
void create()
{
        set("short", "武场");
        set("long", @LONG
这是清平山庄的武场，平日这里一片呼喝之声，清平门下，最重修习基本，清
平剑客白三空对弟子管教极为严格，也正因为如此，门下弟子武功大都不弱，而且
品行端正，武林之中莫不敬仰，此时武场之上却空无一人，想必有大事发生。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"wuchang2",
  "south" : __DIR__"wuchang3",
  "west" : __DIR__"gate",
  "east" : __DIR__"ting",
]));

   	set("outdoors","qingping");
	set("coor/x",-60);
	set("coor/y",0);
	set("coor/z",0);
	setup();
	
}

int valid_leave(object me, string dir)
{
   tell_room(__DIR__"treetop", "武场上，"+me->name()+"往"+to_chinese(dir)+"离去。\n" );
   return 1;
}

