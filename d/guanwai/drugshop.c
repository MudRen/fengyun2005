
inherit ROOM;

void create()
{
        set("short", "黑羽之帐");
        set("long", @LONG
一个顶上挂着黑色鹰羽的华丽无比的帐篷，在这无边无际的大草原里，生
存下去便是最艰难的事，于是在藏边，黑色的鹰羽象征的便是疾病，灾难，死
亡。这是间满是草药味的帐篷，四下搁的也都是些知名不知名的草药，氤氲烟
雾后面一个白发老者正闭目养神。
LONG
        );
        set("exits", ([ 
        "south" : __DIR__"grassland3",
	]));
        set("objects", ([
               __DIR__"npc/songfuzi" : 1,
        ]) );   
        set("indoors", "guanwai");
	set("coor/x",60);
	set("coor/y",40);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
