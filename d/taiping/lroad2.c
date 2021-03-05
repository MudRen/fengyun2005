inherit ROOM;
void create()
{
        set("short", "鹅卵小道");
        set("long", @LONG
花树假山交错，鹅卵石砌成的路，小径纵横，迷朦夜色中，简直八阵图也似，
建造这座庄园的人必非寻常之辈。只是现在的主人似乎从不照料，到处是枯枝败叶，
萧瑟的树梢，深深的避进黑暗里，象在怀念旧日的辉煌。
LONG
        );
        set("exits", ([ 
		"north" : __DIR__"lroad3",
		"south" : __DIR__"lroad1",
	]));
        set("outdoors", "taiping");
        set("no_fly",1);
	set("item_desc", ([
		    
	]));
	set("coor/x",70);
	set("coor/y",-70);
	set("coor/z",0);
	set("map","taiping");
	setup();
	replace_program(ROOM);
}
