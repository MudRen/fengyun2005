inherit ROOM;
void create()
{
        set("short", "青石路");
        set("long", @LONG
泰山脚下向东一条长而窄的青石路，路的尽头便是赫赫有名的[33m『清平山庄』[32m，
路上行人不多，来往的多半是武林豪杰，因为清平剑客白三空正是中原武林的第一
剑手，一手清平剑法早已无敌天下，慕名而来者甚多。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : AREA_QINGPING"gate",
  "southwest" : __DIR__"road2",
  "north" : __DIR__"road3",
]));

   	set("outdoors","jinan");
	set("coor/x",70);
	set("coor/y",130);
	set("coor/z",0);
	setup();
	
	replace_program(ROOM);
}
