
inherit ROOM;

void create()
{
        set("short", "红羽之帐");
        set("long", @LONG
一个宽敞华丽的帐篷，顶上挂着红色鹰羽——红色的鹰羽，在藏边象征的
是战争，流血和胜利。帐篷中摆满了藏人擅长用的各式兵器，虽然远不如中原
那般精致华贵，但质地坚硬，实用耐久。而屋中摆弄着各式刀枪的竟是个如阳
光般可爱的女孩。
LONG
        );
        set("exits", ([ 
        "north" : __DIR__"grassland3",
	]));
        set("objects", ([
               __DIR__"npc/sunshine" : 1,
        ]) );   
        set("indoors", "guanwai");
	set("coor/x",60);
	set("coor/y",-20);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
