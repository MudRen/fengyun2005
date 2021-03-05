inherit ROOM;
void create()
{
        set("short", "丝绸之路");
        set("long", @LONG
丝绸之路，起点是长安，当时各地丝绸和其它商品集中在长安以后，各国商人
把一捆捆的生丝和一匹匹绸缎，用油漆麻布和皮革装备，然后浩浩荡荡地组成商队，
爬上陕甘高原，越过乌鞘岭，经过甘肃的武威，穿过河西走廊，到达敦煌。一条看
起来很不起眼的土路，似乎一个三岁的孩子都可以将其踩在脚下。但在它千年的历
史中，曾经吞食了无数人的性命，将他们的白骨吐在道路两旁。
LONG
        );
        set("exits", ([ 
  "northwest" : __DIR__"huoyan",
  "southeast" : __DIR__"sichou5",
]));
        set("objects", ([
        __DIR__"npc/trader" : 3,
                        ]) );
        //set("no_pk",1);
        
        
        set("outdoors", "xinjiang");
	set("coor/x",100);
	set("coor/y",-60);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
