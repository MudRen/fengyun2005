inherit ROOM;
void create()
{
        set("short", "后花园");
        set("long", @LONG
花树假山交错，鹅卵石砌成的路，小径纵横，迷朦夜色中，简直八阵图也似。
山叠岷峨怪石，花栽阆苑奇葩。水阁遥通竹坞，只是现在的主人似乎从不照料，到
处是枯枝败叶，萧瑟的树梢，深深的避进黑暗里。
LONG
        );
        set("exits", ([ 
		"north" : __DIR__"lroad2",
		"east": __DIR__"yuanzi",
		"west": __DIR__"pond",
	]));
        set("outdoors", "taiping");
        set("no_fly",1);
	set("item_desc", ([
		    
	]));
	set("coor/x",70);
	set("coor/y",-80);
	set("coor/z",0);
	set("map","taiping");
	setup();
	replace_program(ROOM);
}
