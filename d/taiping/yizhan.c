inherit ROOM;
void create()
{
        set("short", "驿站");
        set("long", @LONG
“一骑红尘妃子笑，无人知是荔枝来。“杜牧的诗句，生动地描写了唐代驿站
的快骑传送。其实驿站可上溯到周代诸侯纷争之时，到宋时，专门的军事驿站改名
为“急递铺”，因此驿站亦称驿铺、驿堡。太平镇远近八百里人烟稀少，这个驿站
成了当地最高的官家象征，驿丞就是八十三户百姓的父母官。
LONG
        );
        set("exits", ([ 
		"west":  __DIR__"mroad1",
		"east": __DIR__"xiangfang",
		"north": __DIR__"stable",
	]));
        set("objects",([
                       __DIR__"npc/anzihao" : 1,
                      ])  );
           

        set("item_desc", ([
	
	 ]));
	set("coor/x",10);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}
