
inherit ROOM;

void create()
{
        set("short", "荒野");
        set("long", @LONG
这是一个无边的荒野地，平坦的地势让人一眼望不到边际，地面上布满了沙石
土块，一条黄土路笔直的伸向西方，路旁的地生长着一丛丛的灌木杂草，不是冒出
几棵高大的树木点缀着路边的景色。
LONG
        );
    set("exits", ([ 
  		"west" : __DIR__"road3",
  		"east" : __DIR__"road1",
	]));
   
    set("outdoors", "huashan");

	set("coor/x",10);
	set("coor/y",30);
	set("coor/z",-40);
    	 set("objects", ([
        __DIR__"npc/sadgirl" : 1,
                        ]) );
    
	setup();
        replace_program(ROOM);
}

