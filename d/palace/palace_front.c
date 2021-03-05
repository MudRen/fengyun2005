
inherit ROOM;

void create()
{
        set("short", "翠障");
        set("long", @LONG
自门进来，只见一带翠障挡在面前．往前一望，见白石狰狞，或似猛兽，或如
鬼怪，纵横拱立；上面苔藓斑驳．又见藤萝掩映，其中微露羊肠小径。
LONG
        );
        set("exits", ([ 
  		"south" : __DIR__"palace_gate",
  		"northup" : __DIR__"palace_palace",
]));
        set("outdoors", "palace");

	set("coor/x",-120);
	set("coor/y",120);
	set("coor/z",10);
	setup();
        replace_program(ROOM);
}

