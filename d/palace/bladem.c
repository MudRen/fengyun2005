
inherit ROOM;

void create()
{
        set("short", "刀山");
        set("long", @LONG
只见刀林中两旁塑有石像。石像俱是面目狰狞，咬牙切齿之态，正是描绘这些
恶人纵然上了刀山，心中却仍然丝毫不知悔悟，而只有怀恨，当真将其之恶毒心肠，
刻划得入木三分。
LONG
        );
        set("exits", ([ 
  "west" : __DIR__"holeopen",
  "east" : __DIR__"keng",
]));
        set("objects", ([
        __DIR__"npc/laoren" : 1,
                        ]) );

        set("outdoors", "palace");

	set("coor/x",-40);
	set("coor/y",50);
	set("coor/z",10);
	set("coor/x",-40);
	set("coor/y",50);
	set("coor/z",10);
	setup();
        replace_program(ROOM);
}

