inherit ROOM;
void create()
{
        set("short", "山庄大门");
        set("long", @LONG
这里便是清平山庄的大门，红色的大门看上去普普通通，只有门额上的“清平
山庄”四字甚是惹人注目。门口立着几位劲装少年，正是清平门下弟子，一棵老槐
树，枝叶茂密，似乎体现着庄主的独特风骨。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"wuchang1",
  "west" : AREA_JINAN"road",
]));
   set("objects", ([
      __DIR__"npc/lu": 1,
      __DIR__"npc/young": 2,
   ]) );

   	set("outdoors","qingping");
	set("coor/x",-70);
	set("coor/y",0);
	set("coor/z",0);
	setup();
	
	replace_program(ROOM);
}
