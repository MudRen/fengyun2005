
inherit ROOM;

void create()
{
        set("short", "古栈道");
        set("long", @LONG
崖壁似垂直，然而在这半山腰上却建了一条栈道，木桩打入拳头般大小的石
洞内，上面铺架着木板，道宽不及三尺不可两人并肩而行。向下看沟道内一片碧
绿，溪流纵横，景色宜人。向前望，飞瀑挂崖，水声轰隆，气势壮观。 
LONG
        );
    set("exits", ([ 
  		"south" : __DIR__"changpu",
  		"northup" : __DIR__"zd2",
	]));
	set("objects", ([
		__DIR__"obj/yabi" : 1,
		__DIR__"npc/chiyang" : 1,
	]) );   
    set("outdoors", "huashan");

	set("coor/x",0);
	set("coor/y",15);
	set("coor/z",-20);
	setup();
    replace_program(ROOM);
}

