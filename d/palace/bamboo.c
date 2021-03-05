
inherit ROOM;

void create()
{
        set("short", "翠竹林");
        set("long", @LONG
这是一片翠绿的竹林。竹林中隐约可见一些亭台楼阁，翠绿中掩映著白墙红瓦，
给人以精致已极的感觉。一道小溪从林中缓缓流过，几片仍是翠绿的竹叶，随风飘
舞。有几片轻柔地落在溪面上，伴著不知从何处落下的粉红色的花瓣，静静地随著
小溪漂流而下。
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"jinghouse",
  "south" : __DIR__"bamboo2",
  "west" : __DIR__"house",
]));
        set("outdoors", "palace");
        set("resource/water",1);
        set("liquid/name","翠竹溪水");
	set("coor/x",40);
	set("coor/y",40);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}

