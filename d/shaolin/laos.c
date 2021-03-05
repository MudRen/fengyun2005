// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "长老院");
        set("long", @LONG
少林历代以来，除方丈外，还有四位护寺长老，武功必须绝高，且佛法精深，
四长老执掌僧监，维护少林安全和声誉，辈分不在方丈之下，具传现在这四位长老
是少林千年来最出色的四位，近五十年来还无人能逃出少林僧监。
LONG
        );
        set("exits", ([ 
  "north" : __DIR__"jian",
  "northeast" : __DIR__"laoe",
  "northwest": __DIR__"lao",
]));
        set("objects", ([
                __DIR__"npc/master_17_5" : 1,
       ]) );
	set("coor/x",20);
	set("coor/y",110);
	set("coor/z",20);
	setup();
        replace_program(ROOM);
}
