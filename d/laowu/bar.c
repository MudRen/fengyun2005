
inherit ROOM;

void create()
{
        set("short", "不醉无归小酒家");
        set("long", @LONG
小酒家几乎从不打烊，酒铺看起来不差，老板娘长得很不错，但不知为什么，
里边冷冷清清，看不见一个客人。一块“太白遗风”的木板招牌孤零零的在寒风中
摇曳。
LONG
        );
        set("exits", ([ 
  "south" : __DIR__"street1",
]));

        set("objects", ([
        __DIR__"npc/dang" : 1,
                        ]) );
	set("coor/x",10);
	set("coor/y",20);
	set("coor/z",0);
	setup();
        replace_program(ROOM);

}

