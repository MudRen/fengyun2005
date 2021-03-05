
inherit ROOM;

void create()
{
        set("short", "十八盘");
        set("long", @LONG
此处山势陡峭，盘山土路陡峭艰辛，路随山势曲折盘环，十有八折盘山而上，
路旁荆棘丛生，你不时的被荆棘牵挂衣冠。
LONG
        );
    set("exits", ([ 
  		"east" : __DIR__"qingke",
  		"northeast" : __DIR__"shibapan1",
	]));
	set("objects", ([
		__DIR__"obj/jingji" : 1,
		__DIR__"npc/explorer2" : 1,
	]));   
    set("outdoors", "huashan");

	set("coor/x",-20);
	set("coor/y",-30);
	set("coor/z",0);
	setup();
    replace_program(ROOM);
}

