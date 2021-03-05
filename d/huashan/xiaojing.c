
inherit ROOM;

void create()
{
        set("short", "小径");
        set("long", @LONG
道路忽然变窄，两侧山势更显高峻，小径犹如在夹缝中向前，西崖壁上修有栈
道供行人通过，天气好时在此隐约可见栈道上的行人。东崖壁上爬满了藤萝，向上
看青崖高耸，天开一线，气势壮观。 
LONG
        );
    set("exits", ([ 
  		"north" : __DIR__"shanmen",
  		"southup" : __DIR__"zhuyu",
	]));
   
    set("outdoors", "huashan");

	set("coor/x",5);
	set("coor/y",15);
	set("coor/z",-40);
	setup();
    replace_program(ROOM);
}

