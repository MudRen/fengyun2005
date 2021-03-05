inherit ROOM;
void create()
{
        set("short", "小街口");
        set("long", @LONG
这儿也许是太平镇最热闹的地方，来往的客商们打个弯儿就去了西首的胡同，
因为胡同里有远近闻名的鹦鹉楼，楼里有千姿百媚的血奴姑娘。小街往南通向镇外
的沼泽地，两旁零零散散有些住家，东南面是李家庄。
LONG
        );
        set("exits", ([ 
		"west" : __DIR__"sroad4",
		"east" : __DIR__"house3",
		"southeast": __DIR__"eroad1",
		"north": __DIR__"mroad45",
		"south": __DIR__"mroad6",
	]));
        set("outdoors", "taiping");
	set("item_desc", ([
		    
	]));
	set("coor/x",-20);
      set("coor/y",-50);
      set("coor/z",0);
	set("map","taiping");
	setup();
	
}
