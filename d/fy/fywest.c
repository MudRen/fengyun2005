
inherit ROOM;

void create()
{
        set("short", "风云西");
        set("long", @LONG
这是风云城西的一个市集，一条布满车痕的官道向西方和东方伸展。
由这向西就是进入沙漠，往来的商人很多，偶尔还有些士兵会巡逻到
这里。没天总有金狮镖局的镖头们押着镖车西去大漠，有些从此就没
有再回来过。
LONG
        );
        set("exits", ([ 
  "north" : __DIR__"road1",
  "east" : "/d/fy/wgate",
  "south": __DIR__"sroad1",
  "west" : AREA_QUICKSAND"dengfeng",
]));
        set("outdoors", "quicksand");
	set("coor/x",-480);
	set("coor/y",0);
	set("coor/z",0);
            replace_program(ROOM);

	set("coor/x",-480);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}
