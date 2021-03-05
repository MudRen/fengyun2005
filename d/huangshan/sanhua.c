// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
    set("short", "散花坞");
    set("long", @LONG
散花坞乃一宽谷，谷中峰峦参差，笔架峰，骆驼石等怪石错列其间，远观峰峦
叠嶂，近顾怪石献巧。每当春夏之季，花卉盛开，更是繁花似锦，似天女散花，形
成一片锦绣谷地。北面便是著名的怪石梦笔生花。
LONG
        );
	set("exits", ([ 
		"south" : __DIR__"guangming",
  		"northwest" : __DIR__"shisun",
  		"north" : __DIR__"mengbi",
		"west" : __DIR__"shizi",
	]));
    set("outdoors", "huangshan");
	set("coor/x",-90);
	set("coor/y",0);
	set("coor/z",30);
	setup();

}

