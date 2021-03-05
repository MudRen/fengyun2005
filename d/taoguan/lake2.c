
inherit ROOM;

void create()
{
	set("short", "龙潭瀑");
	set("long", @LONG
湖水尽头是一个大瀑布，于百尺悬崖飞流直下，喷珠吐玉，状如龙舞，故名“
龙潭瀑”。潭中碧水凝寒，清澈见底。山雨过后，洪涌瀑注，飞腾叫啸。湖边稀稀
落落地站着几个道人，有的练剑，有的打坐。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  		"west" : __DIR__"grassland2",
  		"south" : __DIR__"lake1",
	]));
        set("objects", ([ /* sizeof() == 2 */
  		__DIR__"npc/reg_taoist" : 2,
  		__DIR__"npc/shan" : 1,
		
	]));
        set("resource/water",1);
        set("liquid", (["container":"湖",
        				"name": "龙潭瀑水",	
        				
        				]));
	set("outdoors", "taoguan");
	set("coor/x",10);
	set("coor/y",-30);
	set("coor/z",0);
	setup();
}


