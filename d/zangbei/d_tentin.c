
inherit ROOM;

void create()
{
        set("short", "帐篷");
        set("long", @LONG
这帐篷里连丝毫凶险的徵象都没有，事宾上，这帐篷里简直可以说是世上最不
凶险的地方。帐篷外有一片柔软而美丽的草地，帐篷里却铺着比世上任何草地都柔
软十倍，也美丽十倍的地毡。地毡上排着几张矮儿，几上堆满了鲜果和酒菜，好几
个穿着鲜衣的人，正开开心心地坐在地毡上喝酒。
LONG
        );
        set("exits", ([ 
	  	"out" : __DIR__"d_tent",
	  	
			]));
	set("objects", ([
		__DIR__"npc/king": 1,
		__DIR__"npc/princess2": 1,
	]));
	set("item_desc",([
		
	]));
        
        set("coor/x",-55);
	set("coor/y",310);
	set("coor/z",0);
	set("map","zbeast");
	setup();
}
